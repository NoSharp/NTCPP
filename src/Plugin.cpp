#include "Plugin.hpp"
#include "Helpers.hpp"
#include <stdio.h> 
#ifdef __WIN32__
# include <winsock2.h>
#else
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <netdb.h>
#endif
#include <string.h>
#include <unistd.h>

#define UNUSED(x) (void) x;

#ifdef LUA_DEFINE
	#undef LUA_DEFINE
#endif

#define LUA_DEFINE(name) Define(#name, [](lua_State *L) -> int

Plugin::Plugin() {

    // I've gotten a refresher on how to do basic socket stuff here: https://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/client.c
    LUA_DEFINE( sock_connect ) {
        if(lua_gettop(L) != 2){
            return 0;
        }

        struct hostent *server;
        struct sockaddr_in serverAddress;

        const char* address = lua_tostring(L,1);
        int port = lua_tonumber(L, 2);

        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockFd < 0){
            callEvent(L, "OnSocketError", "Can't open socket");
            return 0;
        }
        //Onset::Plugin::Get()->Log("Got here!");

        server = gethostbyname(address);
        if (server == NULL){
            callEvent(L, "OnSocketError", "Can't find server.");
            return 0;
        }
        //Onset::Plugin::Get()->Log("Got here!2");

        bzero((char *) &serverAddress, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(port);

        bcopy((char*)server->h_addr,
             (char*)&serverAddress.sin_addr.s_addr,
             server->h_length
        );

        int con = connect(sockFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
        if (con < 0){
            callEvent(L, "OnSocketError", "Can't connect to server's socket.");
            return 0;
        }else {
            lua_pushnumber(L, sockFd);
            return 1;
        }

    });

    LUA_DEFINE(sock_read){
         if(lua_gettop(L) != 2){
             return 0;
         }

         int sockFd = lua_tonumber(L, 1);
         int bytesToRead = lua_tonumber(L,2);

         char buffer[bytesToRead];
         read(sockFd, buffer, bytesToRead);

    });

    LUA_DEFINE(sock_write){
         if(lua_gettop(L) != 2){
             return 0;
         }

         int sockFd = lua_tonumber(L, 1);
         const char* dataToSend = lua_tostring(L,2);

         send(sockFd, dataToSend, strlen(dataToSend), 0);

         return 1;

    });

}