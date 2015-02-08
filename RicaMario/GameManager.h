// defineは二重インクルード防止のため
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "FpsManager.h"
#include "Root.h"
#include "SceneBase.h"

class GameManager{
private:
	std::unique_ptr<scene::Base> now_scene;
	const std::unique_ptr<FpsManager> fps_mgr;
	const std::unique_ptr<Root> root;
	// ゲームの更新
	int update();
	// ゲームの描画
	int draw() const;
public:
	/*
	@param first_scene アプリ開始後のシーン
	*/
	GameManager(scene::Base* first_scene) :root(new Root), fps_mgr(new FpsManager), now_scene(first_scene){}
	~GameManager() = default;
	// 主にライブラリの初期化を行う 正常に初期化できた時0を返す
	int initialize();
	// ライブラリの解放を行う
	void terminate();
	// ゲームを実行する 正常に動作しているとき0を返す
	int run();
};
#endif