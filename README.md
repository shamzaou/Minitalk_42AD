# Minitalk

Minitalk is a simple server-client program that demonstrates the use of UNIX signals for inter-process communication (IPC). The server can receive and display messages sent by the client, using only `SIGUSR1` and `SIGUSR2` signals.

## Features

- Uses UNIX signals for communication
- Server can handle multiple clients
- Server acknowledges each received message

## Compilation

To compile the program, run the following command in your terminal:

```sh
make all
```

This will compile the server and client executables using the provided Makefile.

## Usage

### Server

To start the server, run the following command:

```sh
./server
```

The server will display its process ID (PID) upon starting. Keep note of this PID, as it will be used by the client to send messages.

### Client

To send a message to the server, run the client with the server's PID and your desired message as arguments:

```sh
./client <server_pid> "Your message here"
```

Replace `<server_pid>` with the PID of the running server. The message can be any string enclosed in double quotes.

For example:

```sh
./client 12345 "Hello, Minitalk!"
```

Upon receiving the message, the server will display the content and send an acknowledgment signal back to the client.

## Implementation

The Minitalk project is divided into two parts: the server and the client.

### Server

The server listens for incoming signals using an infinite loop, registering signal handlers for `SIGUSR1` and `SIGUSR2`. It decodes the received signals to reconstruct the original message character by character. When a full character (8 bits) has been received, the server prints the character and sends an acknowledgment signal to the client.

### Client

The client sends messages to the server by encoding each character of the message as a series of `SIGUSR1` and `SIGUSR2` signals. The client sends one signal per bit, representing '1' as `SIGUSR1` and '0' as `SIGUSR2`. After sending each character, the client waits for an acknowledgment signal from the server before sending the next character.
