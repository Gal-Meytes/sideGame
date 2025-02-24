# Dockerfile for C++ Server
FROM ubuntu:22.04

WORKDIR /app

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential cmake

# Copy C++ project files
COPY ./server /app

# Build the C++ project
RUN cmake . && make

# Expose the port dynamically (will get passed at runtime)
CMD ["./project_exe", "8080"]
