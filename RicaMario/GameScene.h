#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#define MAP_XSIZE 20
#define MAP_YSIZE 15

#include "SceneBase.h"
#include "State.h"
#include "Sprite.h"
#include "TextureFactory.h"

namespace scene{
	class Game :public scene::Base{
	private:

		//変数

		//ポインタ
		std::unique_ptr<State<scene::Game>> now_state;

		//クラス
		class Init :public State < Game > {
			
		};

	public:
		Game();
		void update(std::unique_ptr<Base>& new_scene, const std::unique_ptr<Root>& root)override{
			now_state->update(*this,now_state,root);
			if (now_state == nullptr){
				new_scene.reset(nullptr);
				return;
			}
		}
	};
}

#endif