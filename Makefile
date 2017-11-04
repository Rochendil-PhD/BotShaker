all: client server

client: src/client.cpp src/util.cpp src/util.h
	g++ -o bin/client src/client.cpp src/util.cpp -lpthread -g -Wall

server: src/server.cpp src/util.cpp src/util.h
	g++ -o bin/server src/server.cpp src/util.cpp -lpthread -g -Wall

