#pragma once
#include "MyVector.hpp"
#include "Commands.h"

class CommandsManager
{

private:
	MyVector<Command*> commands;

	CommandsManager();
	CommandsManager(const CommandsManager& other) = delete;
	CommandsManager& operator=(const CommandsManager& other) = delete;
public:
	const MyVector<Command*>& getCommands() const;
	static CommandsManager& getInstance();

};