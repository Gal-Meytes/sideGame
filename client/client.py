import socket
import sys

def main():
    # Ensure the program is called with correct arguments
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <server_ip> <server_port>")
        return

    server_ip = sys.argv[1]
    server_port = int(sys.argv[2])

    # Create a socket and connect to the server
    try:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((server_ip, server_port))
        print(f"Connected to server at {server_ip}:{server_port}")
    except Exception as e:
        print(f"Failed to connect to server: {e}")
        return

    try:
        # Infinite loop for sending and receiving messages
        while True:
            # Get user input
            message = input()
            #if message.lower() == 'exit':
            #    print("Closing connection.")
            #    break

            # Send message to server
            client_socket.sendall(message.encode())

            # Receive response from server
            response = client_socket.recv(2048)  # Buffer size of 1024 bytes
            if not response:
                print("Server closed the connection.")
                break

            print(f"{response.decode()}", end="")

    except Exception as e:
        print(f"An error occurred: {e}")

    finally:
        client_socket.close()

if __name__ == "__main__":
    main()