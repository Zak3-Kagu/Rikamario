#include "AppManager.h"
#include "GameManager.h"
#include "GameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	AppManager app(new GameManager(new scene::Game()));
	app.run();
	return 0;
}