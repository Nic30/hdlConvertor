# note that this Dockerfile is meant for notebooks and you can install this package directly
FROM ubuntu:19.10
# https://github.com/binder-examples/minimal-dockerfile
ARG NB_USER=jovyan
ARG NB_UID=1000
ENV USER ${NB_USER}
ENV NB_UID ${NB_UID}
ENV HOME /home/${NB_USER}

RUN adduser --disabled-password \
    --gecos "Default user" \
    --uid ${NB_UID} \
    ${NB_USER}


RUN apt update && apt upgrade -yq &&\
    apt install build-essential uuid-dev cmake default-jre\
                python3 python3-dev python3-pip libantlr4-runtime-dev\
                antlr4 libssl-dev -yq
RUN pip3 install scikit-build Cython notebook
# RUN pip3 install hdlConvertor

# [mybinder specific]
# Make sure the contents of our repo are in ${HOME}
COPY . ${HOME}
USER root

WORKDIR ${HOME}
RUN python3 setup.py install

RUN chown -R ${NB_UID} ${HOME}
USER ${NB_USER}
