# Use an official Ubuntu base image
FROM ubuntu:22.04

# Set environment variables to prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install required tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    libstdc++6 \
    && apt-get clean

# Set the working directory inside the container
WORKDIR /app

# Copy the entire project into the container
COPY . .

# Create a build directory, configure the project with CMake, and build it
RUN mkdir build && cd build && cmake .. && make

# Set the default command to run the built executable
CMD ["./build/my_executable"]
