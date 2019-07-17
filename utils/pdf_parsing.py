from pdfminer3.pdfparser import PDFParser
from pdfminer3.pdfdocument import PDFDocument


def createPDFDoc(fpath):
    fp = open(fpath, 'rb')
    parser = PDFParser(fp)
    document = PDFDocument(parser, password='')
    # Check if the document allows text extraction. If not, abort.
    assert document.is_extractable
    return document

