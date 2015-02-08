#include "Controller.h"
#include "OperableObject.h"

input::KeyBoard* Controller::Button::p_keyboard = nullptr;
input::Mouse* Controller::Button::p_mouse = nullptr;

void Controller::exec(const std::unique_ptr<input::KeyBoard>& keyboard, const std::unique_ptr<input::Mouse>& mouse){
	// ボタンの更新
	Button::Update(keyboard, mouse);
	//リストに含まれる全オブジェクトに対して自分の状態を渡してオブジェクトを操作する
	for (const auto& obj : *this){
		obj->inputAction(*this);
	}
}