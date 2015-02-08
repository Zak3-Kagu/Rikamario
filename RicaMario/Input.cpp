#include "Input.h" 

input::KeyBoard::KeyBoard(){
	// バッファの初期化
	ZeroMemory(pre_buffer, sizeof(char)* 256);
	ZeroMemory(now_buffer, sizeof(char)* 256);
}

void input::KeyBoard::acquireState(){
	// 現在のキーの状態を取得
	GetHitKeyStateAll(now_buffer);
}

void input::KeyBoard::end(){
	// 現在のキーの状態をpre_bufferにコピーする
	memcpy_s(pre_buffer, sizeof(char)* 256, now_buffer, sizeof(char)* 256);
}

void input::Mouse::acquireState(){
	// 位置を取得
	GetMousePoint(&x, &y);
	// どのボタンが押されたか取得
	now_buffer = 0xffffffff;
	now_buffer &= GetMouseInput();
}

void input::Mouse::end(){
	// 現在の状態をpre_bufferに移す
	pre_buffer = now_buffer;
}
