#include "manager.h"


int mode = 0; //0 client, 1 server
int port = 53010;

int startNetwork() {
	/*
	if (mode == 0) {

		std::string ip;
		std::cout << "Server-IP-Adress: XXX.XXX.XXX.XXX\n";
		std::cin >> ip;

		sf::TcpSocket socket;
		//socket.setBlocking(false);

		sf::Socket::Status status = socket.connect(ip, port, sf::seconds(5));
		if (status != sf::Socket::Done){

			std::cout << "can't connect to server" << "\n";

		}

	}
	else if(mode == 1) {

		std::thread listener(listen);
		
	}
	*/
	return 0;

}

void listen() {
	/*
	sf::TcpListener listener;
	

	while (true) {

		// bind the listener to a port
		if (listener.listen(port) != sf::Socket::Done)
		{
			std::cout << "can't bind server to socket \n";
		}

		// accept a new connection
		sf::TcpSocket client;
		if (listener.accept(client) != sf::Socket::Done)
		{
			std::cout << "can't connect to client";
		}
		
		clients.push_back(&client);

		// use "client" to communicate with the connected client,
		// and continue to accept new connections with the listener

	}
	*/
}
