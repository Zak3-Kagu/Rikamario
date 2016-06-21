#include "GameScene.h"

scene::Game::Game() :now_state(new Init()){

}

//�������X�e�[�g
void scene::Game::Init::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	root->layers.resize(3);
	parent.m_player.reset(new Player());
	parent.m_player->init();
	parent.m_map.reset(new MapClass());
	parent.m_map->init();
	new_state.reset(new Load());
}

//���[�h�X�e�[�g
void scene::Game::Load::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	parent.m_player->loadTexture(root);
	parent.m_map->loadTexture(root);

	//�ǂݍ��݂Ɏ��s�����ꍇ�̓��b�Z�[�W��\��
	if (root->tex_container.includeInvalidObject()){
		MessageBox(nullptr, "�e�N�X�`���t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", "�G���[", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	if (root->sound_container.includeInvalidObject()){
		MessageBox(nullptr, "�T�E���h�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", "�G���[", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	new_state.reset(new Set());
}

//�ݒ�X�e�[�g
void scene::Game::Set::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	//�v���C���[�̐ݒ�
	parent.m_player->setPlayerSprite(root);
	parent.m_player->setPosition(0, 16);
	parent.m_player->setPosition(1, 480 - 16);
	parent.m_player->update();
	parent.m_player->setDrawIn(root);
	root->controller_factory.find(1)->push_back(parent.m_player);

	//�}�b�v�̐ݒ�
	parent.m_map->set(root);
	parent.m_map->update();
	parent.m_map->setDrawIn(root);
	SetDrawBright(255, 255, 255);
	new_state.reset(new Play());
}

//�v���C�X�e�[�g
void scene::Game::Play::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	parent.m_player->update();
	m_time++;
}

void scene::Game::update(std::unique_ptr<Base>& new_scene, const std::unique_ptr<Root>& root){
	now_state->update(*this, now_state, root);
	if (now_state == nullptr){
		new_scene.reset(nullptr);
		return;
	}
}