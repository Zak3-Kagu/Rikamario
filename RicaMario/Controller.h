#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "Input.h"

namespace component{
	class OperableObject;
}

class Controller : public std::list<std::shared_ptr<component::OperableObject>>{
public:
	// ボタンクラス
	class Button{
	private:
		static input::KeyBoard* p_keyboard;
		static input::Mouse* p_mouse;
	protected:
		// ボタンに対応するキーボードのキーID
		unsigned int m_keyboard_key;
		// ボタンに対応するマウスのボタンID
		//unsigned int m_mouse_button;
	public:
		// ボタンの更新を行う
		static void Update(const std::unique_ptr<input::KeyBoard>& keyboard, const std::unique_ptr<input::Mouse>& mouse){
			p_keyboard = keyboard.get();
			p_mouse = mouse.get();
		}
		Button(unsigned int keyboad_key = 0) : m_keyboard_key(keyboad_key){}
		inline bool isPressed() const{
			return p_keyboard->isPressed(m_keyboard_key);
		}
		inline bool isBeingPressed() const{
			return p_keyboard->isBeingPressed(m_keyboard_key);
		}
		inline bool isReleased() const{
			return p_keyboard->isReleased(m_keyboard_key);
		}
	};

	// 6つのボタン
	std::unique_ptr<Button> AButton;
	std::unique_ptr<Button> BButton;
	std::unique_ptr<Button> CButton;
	std::unique_ptr<Button> DButton;
	std::unique_ptr<Button> EButton;
	std::unique_ptr<Button> FButton;
	// 十字キー
	std::unique_ptr<Button> UpKey;
	std::unique_ptr<Button> RightKey;
	std::unique_ptr<Button> DownKey;
	std::unique_ptr<Button> LeftKey;
	// 特殊なボタン
	std::unique_ptr<Button> SelectButton;
	std::unique_ptr<Button> StartButton;

	virtual ~Controller() = default;

	// 操作可能オブジェクトを操作する
	void exec(const std::unique_ptr<input::KeyBoard>& keyboard, const std::unique_ptr<input::Mouse>& mouse);
};

#endif
