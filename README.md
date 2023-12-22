# Synthesys Practical Work – TFTP Client (FRANCILLONNE Radji/GAMIETTE David)
Objectives : Develop a TFTP client using RFC specifications and Wireshark captures.

## Q1) Use command-line arguments for the gettftp and puttftp programs to obtain request information (server and file)
We use the `argv` passed as an argument to the main function to retrieve the arguments for the `gettftp` and `puttftp` programs.

## Q2) Call getaddrinfo to obtain the server’s address
```c
getaddrinfo(hostname, NULL, &hints, &res);
```
In our scenario, `hints` is the configured address. `res` is the result and points to it.

## Q3) Reserve a connection socket to the server
