# Build with: sudo docker build -t dlx .
# Run with: sudo docker run --name dlx_bash --rm -i -t dlx bash  

FROM ubuntu:18.10

RUN apt-get update

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
RUN apt-get install -y --no-install-recommends apt-utils
RUN apt-get install -y gcc python build-essential curl vim

WORKDIR /home/cweb
RUN curl -O -s ftp://ftp.cs.stanford.edu/pub/cweb/cweb.tar.gz
RUN tar -xzvf cweb.tar.gz
RUN make
ENV PATH ${PATH}:/home/cweb

WORKDIR /home/sgb
RUN curl -O -s ftp://ftp.cs.stanford.edu/pub/sgb/sgb.tar.gz
RUN tar -zxvf sgb.tar.gz
RUN make tests

WORKDIR /home/dlx
RUN for f in dlx1 dlx2 dlx3 dlx-pre ; do curl -O -s https://www-cs-faculty.stanford.edu/~knuth/programs/$f.w ; done
COPY ./Makefile /home/dlx
RUN make
ENV PATH ${PATH}:/home/dlx

WORKDIR /home
COPY ./sample.dlx /home
COPY ./rundlx.py /home
RUN chmod u+x rundlx.py
