//
// Created by Roberto Boldini on 3/9/22.
//

#include "Channel.hpp"

Channel::Channel(const std::string &name, const std::string &password, Client *admin)
	: _name(name), _password(password), _admin(admin) {
	_clients.push_back(admin);
};

Channel::~Channel() {};

std::vector<Client *>::iterator Channel::getClient(Client *client) {
	for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it) == client) {
			return it;
		}
	}
	return _clients.end();
}

void Channel::removeClient(Client *client) {
	client_iter it;
	if ((it = getClient(client)) != _clients.end()) {
		_clients.erase(it);
		std::cout << " Client kicked." << std::endl;
//		TODO: reply to channel "[USERNAME] KICKED."
	}
	else {
		std::cout << " Client doesn't exist." << std::endl;
	}
}
