//
// Created by Roberto Boldini on 3/11/22.
//
#include "commands/Command.hpp"

QuitCommand::QuitCommand(Server *server, bool authRequired) : Command(server, authRequired) {}

QuitCommand::~QuitCommand() {}

void QuitCommand::execute(Client *client, std::vector<std::string> arguments) {
	client->sendMessage("ERROR :Connection closed successfully.");
}