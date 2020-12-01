from subprocess import check_output
from datetime import datetime

"""
Format git tag messages as changelog
"""

tags = [t.strip() for t in check_output(["git", "tag"]).decode().split() if t.strip()]
package_name = "libhdlconvertor-dev"
footer = " -- Michal Orsak <michal.o.socials@gmail.com>  "
indent = "  "
for t in tags:
    stability = "unstable"
    urgency = "medium"
    msg = check_output(["git", "tag", "-l", t, "--format=%(body)"]).decode()
    date_str = check_output(["git", "log", "-1", "--format=%ai", t]).decode()
    date_obj = datetime.strptime(date_str.strip(), '%Y-%m-%d %H:%M:%S %z')
    date_str = date_obj.strftime("%Y-%m-%d")
    ver = t[1:] + ".0"
    title = f"{ver} / {date_str}"
    header = f"{package_name} ({ver}-1) {stability}; urgency={urgency}"
    print("")
    print(title)
    print("".join(["=" for _ in range(len(title))]))
    print("")
    print(f"{ver} / {date_str}")
    print("")
    for line in msg.strip().split("\n"):
        print(indent + line)
    print('')
    print(footer + date_obj.strftime("%a, %b %d %Y %H:%M:%S %z"))