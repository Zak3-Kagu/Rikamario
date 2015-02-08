#include "AppManager.h"
#include "GameManager.h"

void AppManager::run(){
	if (p_game->initialize() != 0) return; // 初期化が失敗した場合その場で終了
	while (p_game->run() == 0); // ループ処理が成功しているまで無限ループ
	p_game->terminate(); // デバイス等の解放(後処理)
}
