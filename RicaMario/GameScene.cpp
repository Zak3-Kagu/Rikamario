#include "GameScene.h"

scene::Game::Game() :now_state(){

}

void scene::Game::Init::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	parent.m_player->init(root, parent.m_tex_container, parent.m_sound_container);
}