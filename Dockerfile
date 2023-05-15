# Use alpine to simplify the installation of cmake and make
FROM alpine:latest
RUN apk add --no-cache cmake make gcc g++

# Create a directory for the project
RUN mkdir /amadeus
WORKDIR /amadeus
COPY CMakeLists.txt .
COPY main.c .

# By default, build the project
CMD ["/bin/sh", "-c", "cmake -S . -B cmake-build && cmake --build cmake-build"]
