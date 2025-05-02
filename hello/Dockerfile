FROM ubuntu:latest
WORKDIR /app
COPY . .
RUN apt-get update && apt-get install -y \
    g++ \
    valgrind
CMD g++ main.cpp -o bin/main && valgrind ./bin/main
