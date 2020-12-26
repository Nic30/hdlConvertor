FROM python:2

WORKDIR /usr/src/hdlConvetor
COPY . ./

RUN apt update && apt install -y cmake ninja-build libantlr4-runtime-dev antlr4
RUN pip install git+https://github.com/Nic30/hdlConvertorAst.git
RUN pip install -e .

#CMD ["python", "-m", "tests.all"]
