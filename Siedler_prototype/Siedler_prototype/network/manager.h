#pragma once

#include <SFML/Network.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <list>

//static std::list<sf::TcpSocket*> clients;

int startNetwork();
void listen();