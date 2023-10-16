# note that this Dockerfile is meant for notebooks and you can install this package directly
# https://github.com/binder-examples/minimal-dockerfile

# When compiling specify build args to have ownership and permissions compatible with host
# docker build -t hdlConvertor --build-arg "NB_USER=$USER" --build-arg "NB_UID=$UID" .
# docker run --rm -it hdlConvertor /bin/bash 
# python3 -m tests.all

FROM ubuntu:23.10
ARG NB_USER=jovyan
ARG NB_UID=1000
ENV USER ${NB_USER}
ENV NB_UID ${NB_UID}
ENV HOME /home/${NB_USER}

RUN apt update && apt upgrade -yq
RUN apt-get install adduser
# create or rename default user
RUN if id -un -- ${NB_UID} >/dev/null 2>&1 ; then\
  	  echo "Delete user with colliding UID ${NB_UID}";\
  	  deluser $(id -un -- ${NB_UID}) ;\
  	fi
RUN adduser --disabled-password \
	    --gecos "Default user" \
	    --uid ${NB_UID} \
	    ${NB_USER} 

RUN apt install build-essential uuid-dev cmake default-jre\
                python3 python3-dev python3-pip libantlr4-runtime-dev\
                antlr4 libssl-dev -yq
RUN pip3 install scikit-build Cython notebook --break-system-packages
# RUN pip3 install hdlConvertor

# [mybinder specific]
# Make sure the contents of our repo are in ${HOME}
USER ${NB_USER}
COPY . ${HOME}
#USER root

WORKDIR ${HOME}
RUN pip3 install . --break-system-packages
RUN mv hdlConvertor _hdlConvertor # rename so folder does not interfere with the installation

#RUN chown -R ${NB_UID} ${HOME}
#USER ${NB_USER}
