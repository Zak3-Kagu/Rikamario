#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include "OperableObject.h"
#include "TextureFactory.h"
#include "SoundFactory.h"
#include "Sprite.h"
#include "Root.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

class Player:public component::OperableObject{
private:
	
	//座標
	int m_x;
	int m_y;

	//プレイヤーのスプライト
	std::shared_ptr<Sprite> m_player;
public:
	//初期化系
	void init(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container, AssetContainer<asset::Sound>& sound_container);

	//プレイヤースプライトのセット
	void initPlayerSprite(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container);

	//更新系
	void inputAction(const Controller& controller)override;

	void update();

	//取得・設定系
	void setDrawIn(const std::unique_ptr<Root>& root);

	void setDrawOut(const std::unique_ptr<Root>& root);

	const int getPosition(int& select)const;

	void setPosition(const int& select, const int& arg);
};
#endif 