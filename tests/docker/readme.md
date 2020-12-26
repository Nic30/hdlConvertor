# Docker files for tesing purposes

Docker build should be executed from root folder (docker build context should be a root folder)
```sh
docker build -t nic30/python2hdlconvertor -f tests/docker/python2hdlconvertor/Dockerfile .
```

To run use:
```sh
docker run --name test -it nic30/python2hdlconvertor
docker container attach test
docker container exec -it test /bin/bash 
```


