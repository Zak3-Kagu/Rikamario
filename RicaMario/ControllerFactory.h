#ifndef _CONTROLLER_FACTORY_H
#define _CONTROLLER_FACTORY_H

class Controller;

class ControllerFactory{
private:
	std::vector<std::shared_ptr<Controller>> controllers;
	Controller* create(const unsigned int& player_number);
public:
	ControllerFactory();
	std::shared_ptr<Controller> find(const unsigned int& player_number);
};

#endif