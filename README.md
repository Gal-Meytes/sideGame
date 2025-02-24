# 🎬 Project Overview

## 🚀 Introduction

Welcome to the **ultimate storage solution** for movie streaming platforms! This project powers a seamless **user watch history and recommendation engine**, ensuring an optimized viewing experience.

---
## 🔥 Core Services

📌 **Storage Device Services** – Securely store and manage user watch history.  
📌 **Movie Recommendation Engine** – Deliver personalized movie suggestions based on user data.

---
## 📌 Key Details

✅ Tracks watched movies per user (but **does not** store actual movies or user files).  
✅ Users and movies are identified by **unique string-based IDs**.  
✅ Users **must exist** before modifying watch history.

---
## ✅ What This Project Does & ❌ Doesn't Do

### ✅ What It Does:
- Stores and manages user watch history efficiently.
- Provides tailored movie recommendations based on watched content.
- Serves as the backend infrastructure for a movie streaming platform.

### ❌ What It Doesn't Do:
- Store actual movie files—only metadata and watch history are saved.
- Manage user authentication or personal data beyond watch history.
- Stream movies—this is a data management and recommendation system.


---
## ⚙️ Running the Project

### 📌 Prerequisites
Ensure you have installed:
✅ **Docker** (Version 20+ recommended)  
✅ **Docker Compose** (Version 1.27+ recommended)  

🔗 [Official Docker installation guide](https://docs.docker.com/get-docker/)

### 🏗 Setup Instructions

#### 📁 Step 1: Set Up the Project Directory
Navigate to your project folder:
```bash
cd /path/to/your/project
```
#### ⚙️ Step 2: Modify the Data Path (IMPORTANT)
📌 **The server relies on a data folder on the local machine**
- If this is your **first time**, create an **empty folder** in any location. Keep the path for later.
- If you have run the server before, you may reuse the previous data folder. The server will automatically access saved data.

Modify `docker-compose.yml` to include a volume mapping:
- **Change** `/absolute/path/to/data` to the actual path of your data folder.
- **Do not modify** `:/app/data`—it must remain unchanged.

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
      - /absolute/path/to/data:/app/data   # Change the path here
    networks:
      - app-network
```


#### 🔨 Step 3: Build the Docker Images
```bash
docker-compose build
```

#### 🚀 Step 4: Start the Server in the Background
```bash
docker-compose up -d server
```
🔎 Check if it's running:
```bash
docker ps
```

#### 🎬 Step 5: Connect Clients to the Server
Run the following command on a new terminal for each new client:
```bash
docker-compose run --rm python-client
```
📌 **Note:** This command should be run in the directory where `docker-compose.yml` is located. To exit, type `exit` and press Enter.

#### 🧪 Step 6: Running Tests (Manually)
Tests do **not** run automatically. To manually invoke tests:
```bash
docker-compose run --rm tests
```

#### 🛑 Step 7: Stop the Server
```bash
docker-compose down
```

---
## 📌 Additional Commands

🔍 **View Server Logs:**
```bash
docker logs ex2-server
```

🔄 **Restart the Server:**
```bash
docker-compose restart server
```

🗑 **Remove All Containers and Volumes:**
```bash
docker-compose down -v
```
---
## 🛠 Hands-On API Usage
**invoke the following commands from the client side (see step 5 for client invocation)**  
📢 **Note:** A user may have watched no movies, but upon creating a new user, a watched movie must be added (a project requirement). To keep an empty user watch history, add a user with an anonymous movie, then remove it using the **DELETE** command.

### 🔄 DELETE [userId] [movieIds] ...
🗑 Removes movies from a user's watch history. Returns an error if the movie isn't in the history or if the user doesn't exist.
```
DELETE user123 movieA movieB
```

### 🔍 GET [userId] [movieId]
📌 Provides recommendations for a user based on a specified movie. Returns an error if the user doesn't exist. Only returns unwatched movies.
```
GET user123 movieA
```

### ➕ PATCH [userId] [movieIds] ...
🎥 Adds movies to a user’s watch history. Returns an error if the user doesn't exist.
```
PATCH user123 movieC movieD
```

### 🆕 POST [userId] [movieIds] ...
📂 Creates a new user with an initial movie watch history. At least one movie must be included.
```
POST newUser456 movieX
```

### 🆘 help
📖 Returns the API interface documentation.
```
help
```

---
## 🎯 Usage Examples

### ✅ Valid API Commands
```
POST user001 movieA  # Create a new user with an initial watched movie
PATCH user001 movieB movieC  # Add movies to an existing user
DELETE user001 movieA  # Remove a watched movie
GET user001 movieB  # Get movie recommendations based on a watched movie
help  # Retrieve API command list
```

### ❌ Invalid API Commands
```
POST user002  # Error: A new user must have at least one movie
DELETE user003 movieX  # Error: User does not exist or movie not watched
PATCH user004  # Error: At least one movie must be provided
GET user999 movieY  # Error: User does not exist
```

---
## 🏁 Summary of Commands

| 🛠 Action | 💻 Command |
|----------|-----------|
| 🚀 Build the project | `docker-compose build` |
| ▶️ Start the server (background) | `docker-compose up -d server` |
| 🎬 Run a new client | `docker-compose run --rm python-client` |
| 🧪 Run tests (manually) | `docker-compose run --rm tests` |
| 🛑 Stop the server | `docker-compose down` |
| 🔄 Restart the server | `docker-compose restart server` |
| 📜 View server logs | `docker logs ex2-server` |

---

