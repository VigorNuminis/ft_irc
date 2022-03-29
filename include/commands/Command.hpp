#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command;

#include <string>
#include "network/Client.hpp"
#include "network/Server.hpp"

class Command
{

protected:
	Server	*_server;
	bool	_authRequired;

public:
	explicit Command(Server *server, bool authRequired = true) : _server(server), _authRequired(authRequired) {};
	virtual ~Command(){};

	bool authRequired() const { return _authRequired; };

	virtual void execute(Client *client, std::vector<std::string> arguments) = 0;
};

class PrivMsgCommand : public Command
{
public:
	PrivMsgCommand(Server *server);
	~PrivMsgCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class PartCommand : public Command
{
public:
	PartCommand(Server *server);
	~PartCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class QuitCommand : public Command
{
public:
	QuitCommand(Server *server, bool authRequired);
	~QuitCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class JoinCommand : public Command
{
public:
	JoinCommand(Server *server);
	~JoinCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class UserCommand : public Command
{
public:
	UserCommand(Server *server, bool authRequired);
	~UserCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class NickCommand : public Command
{
public:
	NickCommand(Server *server, bool authRequired);
	~NickCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class PassCommand : public Command
{
public:
	PassCommand(Server *server, bool authRequired);
	~PassCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

class KickCommand : public Command
{
public:
	KickCommand(Server *server, bool authRequired);
	~KickCommand();

	void execute(Client *client, std::vector<std::string> arguments);
};

#endif // COMMAND_HPP