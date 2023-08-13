

A socket is an endpoint abstraction that consists of:
- local IP
- local port (aka ephemeral port)
- remote IP
- remote port
- protocol (UDP or TCP)


There are 2 types of sockets:
- connectionless (UDP)
- connection oriented (TCP)

There are some common socket operations:

`socket()`: creates and initializes a new socket.
`bind()`: associates a socket with a particular local IP address and port number.
`listen()`: is used on the server to cause a TCP socket to listen for new connections.
`connect()`: is used on the client to set the remote address and port. In the case of TCP, italso establishes a connection.
`accept()`: is used on the server to create a new socket for an incoming TCP connection.
`send()`: and recv() are used to send and receive data with a socket.
`sendto()`: and recvfrom() are used to send and receive data from sockets without a bound remoteaddress.
`close()`: (Berkeley) and closesocket() (Winsock) are used to close a socket. In the case of TCP, this also terminates the connection.
`shutdown()`: close one side of a TCP connection.
`select()`: wait for an event on one or more sockets.
`getnameinfo()`: and getaddrinfo() provide a protocol-independent manner of working withhostnames and addresses.
`setsockopt()` is used to change some socket options.
`fcntl()` (Berkeley) and ioctlsocket() (Winsock) are also used to get and setsome socket options.
`poll()`: (Berkely)
`dup()`: (Berkely)


### Example TCP program flow

TCP client takes an  address (e.g.http://example.com) and uses `getaddrinfo()` to resolve it into a struct addrinfo structure. The client then creates a socket using a call to `socket()`. The client then establishes the new TCP connection by calling `connect()`. At this point, the client can freely exchange data using `send()` and `recv()`.


A TCP server listens for connections on a port number on an interface. The program initializes a struct `addrinfostructure` with the proper listening IP address and port number. The `getaddrinfo()` function is helpful so that you can do this in an IPv4/IPv6 independent way. The server then creates the socket with a call to `socket()`. The socket must be bound to the listening IP address and port. This is accomplished with a call to `bind()`.

The server program then calls `listen()`, which puts the socket in a state where it listens for new connections. The server can then call `accept()`, which will wait until a client establishes a connection to the server. When the new connection has been established, `accept()` returns a new socket. This new socket can be used to exchange data with the client using `send()` and `recv()`. Meanwhile, the first socket remains listening for new connections, and repeated calls to `accept()` allow the server to handle multiple clients.

Note:

windwos linkins: -lws2_32 option to gcc