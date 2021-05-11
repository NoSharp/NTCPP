# NTCPP
## The game this was made for has died, Feel free to use however you like.
## Have a bug? Please post it on the issues or PM me on discord nosharp#8669 :)

NoSharp's TCP plugin for Onset



```lua
  -- Documentation --
  
  -- Connects to a socket
  sock_connect(IpAddress, port) -- IpAddress is a String, Port is an integer. Returns an integer (aka the socket id).
  -- Reads a payload from a server
  sock_read(socketId, bytestoread) -- SocketId is an Integer, BytesToRead is an integer. Returns string.
  -- Send data to the socket.
  sock_send(socketId, data) -- SocketId is an Integer, Data is a string. Returns nothing.

  -- Events --
  OnSocketError, has a string as a parameter (The error message)
```


USING THE ONSET SDK (The entire libs and lib file). 
Credit to OnfireNetworks JNI Wrapper, OnsetIniPlugin (I've taken a lot of Cmake stuff.)
