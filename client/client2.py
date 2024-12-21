import random
import socket
import sys
import threading
import time


def main():
    # Ensure the program is called with correct arguments
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <server_ip> <server_port>")
        return

    server_ip = sys.argv[1]
    server_port = int(sys.argv[2])
    client_sockets = []
    # Create a socket and connect to the server
    for i in range(25):
        try:
            client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            client_socket.connect((server_ip, server_port))
            client_sockets.append(client_socket)  # Add socket to the list
            print(f"Connected to server at {server_ip}:{server_port} (Socket {i+1})")
        except Exception as e:
            print(f"Failed to connect to server: {e}")
            return

    for i in range(25):
        threading.Thread(target=act, args=(client_sockets, i)).start()



def act(client_sockets, i):
    random_time = random.uniform(1, 3)
    time.sleep(random_time)
    try:
        if i % 2 == 1:
            message = "DELETE 123 222"
        else:
            message = "PATCH 123 222"
        #if message.lower() == 'exit':
        #    print("Closing connection.")
        #    break

        # Send message to server
        client_sockets[i].sendall(message.encode())

        # Receive response from server
        response = client_sockets[i].recv(2048)  # Buffer size of 1024 bytes
        if not response:
            print("Server closed the connection.")
            return

        print(f"i={i}:{response.decode()}", end="")
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        client_sockets[i].close()


if __name__ == "__main__":
    main()