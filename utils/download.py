#!/usr/bin/env python3
"""
We use SystemExit as this will not blast the whole traceback to Meson.
Usually just a terse stderr will suffice and not overwhelm the Meson user.

https://www.scivision.dev/meson-file-download/
"""

from pathlib import Path
import urllib.request
import urllib.error
import hashlib
import argparse
import socket


def url_retrieve(
    url: str,
    outfile: Path,
    filehash: tuple[str, str]=None,
    overwrite: bool=False,
):
    """
    Parameters
    ----------
    url: str
        URL to download from
    outfile: pathlib.Path
        output filepath (including name)
    filehash: tuple of str, str
        hash type (md5, sha1, etc.) and hash
    overwrite: bool
        overwrite if file exists
    """
    outfile = Path(outfile).expanduser().resolve()
    if outfile.is_dir():
        raise ValueError("Please specify full filepath, including filename")
    # need .resolve() in case intermediate relative dir doesn't exist
    if overwrite or not outfile.is_file():
        outfile.parent.mkdir(parents=True, exist_ok=True)
        try:
            urllib.request.urlretrieve(url, str(outfile))
        except (socket.gaierror, urllib.error.URLError) as err:
            raise SystemExit(
                "ConnectionError: could not download {} due to {}".format(url, err)
            )

    if filehash:
        hashMode, expectedHash = filehash
        h = hashlib.new(hashMode)
        h.update(outfile.read_bytes())
        hashRes = h.hexdigest()
        if hashRes != expectedHash:
            raise SystemExit("HashError: {} got: {}, expected: {}".format(outfile, hashRes, expectedHash))


if __name__ == "__main__":
    p = argparse.ArgumentParser()
    p.add_argument("url", help="URL to file download")
    p.add_argument("outfile", help="filename to download to")
    p.add_argument("--hash", help="expected hash", nargs=2)
    P = p.parse_args()

    url_retrieve(P.url, P.outfile, P.hash)
