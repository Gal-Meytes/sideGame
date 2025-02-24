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

Remote Server API Documentation

Overview

This API allows users to manage their watched movies. Each user is uniquely identified by a string-based user ID, and movies are also identified by string-based movie IDs. Users may have a list of watched movies, but a new user must have at least one watched movie upon creation. Any invalid command will return an error response.

API Commands

1. DELETE [userId] [movieIds] ...

Description: Removes one or more movies from a user's watched history.

If a movie does not exist in the user's watched history, an error will be returned.

If the user does not exist, an error will be returned.

Example:

DELETE user123 movieA movieB

Invalid Example (movie not in watched list):

DELETE user123 movieX

2. GET [userId] [movieId]

Description: Provides movie recommendations for a user based on the specified movie’s correlation to other watched movies.

If the user does not exist, an error will be returned.

If the movie ID is not recognized, an error will be returned.

Example:

GET user123 movieA

Invalid Example (user does not exist):

GET user999 movieA

3. PATCH [userId] [movieIds] ...

Description: Adds one or more movies to a user’s watched history.

If the user does not exist, an error will be returned.

At least one movie must be provided.

Example:

PATCH user123 movieC movieD

Invalid Example (user does not exist):

PATCH user999 movieE

4. POST [userId] [movieIds] ...

Description: Creates a new user with an initial set of watched movies.

A new user must have at least one movie in their watched history.

If the user already exists, an error will be returned.

Example:

POST newUser456 movieX

Invalid Example (no movie provided):

POST newUser456

5. help

Description: Returns the API interface documentation.

Example:

help

Additional Notes

User IDs and Movie IDs are treated as strings, meaning they can contain letters, numbers, and special characters.

Commands with missing or incorrect parameters will be handled with appropriate error messages.

If a user does not exist, commands that assume the user's existence (e.g., PATCH, GET, or DELETE) will return an error response.

Users can have an empty watch history, but they must have at least one movie at the time of creation.

This concludes the API documentation. Use the help command at any time for a refresher on the API interface.
