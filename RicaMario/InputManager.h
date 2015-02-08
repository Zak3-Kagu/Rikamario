#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include "Controller.h"

class InputManager : public std::list<std::shared_ptr<Controller>>{
private:
	const std::unique_ptr<input::KeyBoard> p_keyboard;
	const std::unique_ptr<input::Mouse> p_mouse;
	void beginInput(){
		p_keyboard->acquireState();
		p_mouse->acquireState();
	}
	void endInput(){
		p_keyboard->end();
		p_mouse->end();
	}

public:
	InputManager() : p_keyboard(new input::KeyBoard()), p_mouse(new input::Mouse()){}
	~InputManager() = default;
	void exec(){
		beginInput();
		for (const auto& controller : *this){
			controller->exec(p_keyboard, p_mouse);
		}
		endInput();
	}
};

#endif