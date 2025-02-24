# README: Running the Project

## Prerequisites
Before starting, ensure you have the following installed on your system:
- **Docker** (Version 20+ recommended)
- **Docker Compose** (Version 1.27+ recommended)

If you don't have Docker installed, refer to the [official Docker installation guide](https://docs.docker.com/get-docker/).

## Setup Instructions

### Step 1: Set Up the Project Directory
Ensure your project files are inside a directory. Open a **terminal** and navigate to where the `docker-compose.yml` file is located:
```bash
cd /path/to/your/project
```

### Step 2: Modify the Data Path (IMPORTANT)
The server needs access to a **real data folder** on your local machine at `"path.."`. Modify `docker-compose.yml` to include a volume mapping:
```yaml
services:
  server:
    container_name: ex2-server
    build:
      context: .
      dockerfile: Dockerfile.server
    ports:
      - "8080:8080"
    environment:
      - SERVER_PORT=8080
    volumes:
      - /absolute/path/to/data:/app/data  # Change this to your actual data path
    networks:
      - app-network
```
Replace `/absolute/path/to/data` with the actual full path of your data folder.

### Step 3: Build the Docker Images
Run the following command to build all necessary Docker containers:
```bash
docker-compose build
```

### Step 4: Start the Server in the Background
To start the server in detached mode:
```bash
docker-compose up -d server
```
Check if it's running:
```bash
docker ps
```

### Step 5: Connect Clients to the Server
Run a new client session:
```bash
docker-compose run --rm python-client
```
Run this command multiple times for multiple clients.

### Step 6: Running Tests (Manually)
Tests do NOT run automatically. To manually invoke tests:
```bash
docker-compose run --rm tests
```

### Step 7: Stop the Server
```bash
docker-compose down
```

## Additional Commands
### View Server Logs
```bash
docker logs ex2-server
```

### Restart the Server
```bash
docker-compose restart server
```

### Remove All Containers and Volumes
```bash
docker-compose down -v
```

## Summary of Commands
| Action | Command |
|--------|---------|
| Build the project | `docker-compose build` |
| Start the server (background) | `docker-compose up -d server` |
| Run a new client | `docker-compose run --rm python-client` |
| Run tests (manually) | `docker-compose run --rm tests` |
| Stop the server | `docker-compose down` |
| Restart the server | `docker-compose restart server` |
| View server logs | `docker logs ex2-server` |

---

## Dockerfile Configurations

### Dockerfile for C++ Server
```Dockerfile
FROM ubuntu:22.04
WORKDIR /app
RUN apt-get update && apt-get install -y \
    build-essential cmake
COPY . /app
RUN rm -rf build && mkdir -p build
WORKDIR /app/build
RUN cmake .. && make -j$(nproc)
CMD ["./server_exe", "8080"]
```

### Dockerfile for Tests
```Dockerfile
FROM ubuntu:22.04
WORKDIR /app
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make \
    git \
    wget \
    unzip
COPY . /app
RUN mkdir -p build && rm -f build/CMakeCache.txt && rm -rf build/CMakeFiles
CMD ["./build/tests_exe"]
```

### Dockerfile for Python Client
```Dockerfile
FROM python:3.9-slim
WORKDIR /app
COPY ./client /app
RUN pip install -r requirements.txt
CMD ["python", "client.py", "server", "8080"]
```

This README provides step-by-step instructions to ensure an easy setup for users of all experience levels. Let me know if you need any adjustments!

