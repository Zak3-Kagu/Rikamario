class GameManager;

class AppManager{
private:
	const std::unique_ptr<GameManager> p_game;

public:
	/*
	@param game_mgr ゲームマネージャクラスのポインタ
	*/
	AppManager(GameManager* game_mgr) : p_game(game_mgr){}
	// アプリを動かす
	void run();
};