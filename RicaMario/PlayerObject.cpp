#include "PlayerObject.h"

void Player::init(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container, AssetContainer<asset::Sound>& sound_container){
	initPlayerSprite(root, tex_container);
}

void Player::initPlayerSprite(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container){
	m_player.reset(new Sprite());
	m_player->setTexture(tex_container.findAssetByname("Player"));
}

void Player::inputAction(const Controller& controller){
	if (controller.LeftKey->isBeingPressed()){
		m_x = m_x - 2;
	}
	if (controller.RightKey->isBeingPressed()){
		m_x = m_x + 2;
	}
}

void Player::update(){

}

void Player::setDrawIn(const std::unique_ptr<Root>& root){
	root->layers[1].push_back(m_player);
}
void Player::setDrawOut(const std::unique_ptr<Root>& root){
	root->layers[1].remove(m_player);
}

const int Player::getPosition(int& select)const{
	if (select == 0){
		return m_x;
	}
	if (select == 1){
		return m_y;
	}
}

void Player::setPosition(const int& select, const int& arg){
	if (select == 0){
		m_x = arg;
	}
	if (select == 1){
		m_y = arg;
	}
}