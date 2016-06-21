#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include "SceneBase.h"
#include "State.h"
#include "Sprite.h"
#include "TextureFactory.h"
#include "PlayerObject.h"
#include "MapClass.h"

namespace scene{
	class Game :public scene::Base{
	private:

		//�ϐ�


		//�|�C���^
		std::unique_ptr<State<scene::Game>> now_state;
		std::shared_ptr<Player> m_player;
		std::unique_ptr<MapClass> m_map;

		//�N���X
		//�������X�e�[�g
		class Init :public State < Game > {
		private:

		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};
		//���[�h�X�e�[�g
		class Load :public State<Game>{
		private:
		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};
		//�ݒ�X�e�[�g
		class Set :public State < Game > {
		private:
		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};
		//�v���C�X�e�[�g
		class  Play :public State<Game>{
		private:
			int m_time = 0;
		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};

	public:
		Game();
		void update(std::unique_ptr<Base>& new_scene, const std::unique_ptr<Root>& root)override;
	};
}

#endif