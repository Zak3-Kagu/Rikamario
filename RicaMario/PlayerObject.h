#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include "OperableObject.h"
#include "TextureFactory.h"
#include "SoundFactory.h"
#include "Sprite.h"
#include "Root.h"

class Player:public component::OperableObject{
private:
	
	//���W
	int m_x;
	int m_y;

	int m_vx;
	int m_vy;
	int m_vx_max_walk;
	int m_vx_max_dash;
	int m_vy_max;

	int m_ax;
	int m_ay;

	int m_timer_x;
	int m_timer_y;

	//�e��t���O
	int m_jumpflag;
	int m_dashflag;

	//�v���C���[�̃X�v���C�g
	std::shared_ptr<Sprite> sp_player;
public:
	//�������n
	void init();

	//load�n
	void loadTexture(const std::unique_ptr<Root>& root);

	//�v���C���[�X�v���C�g�̃Z�b�g
	void setPlayerSprite(const std::unique_ptr<Root>& root);

	//�X�V�n
	void inputAction(const Controller& controller)override;

	void update();

	//�擾�E�ݒ�n
	void setDrawIn(const std::unique_ptr<Root>& root);

	void setDrawOut(const std::unique_ptr<Root>& root);

	const int getPosition(int& select)const;

	void setPosition(const int& select, const int& arg);

	const int getFlag(int& select)const;

	void setFlag(const int& select, const int& arg);
};
#endif 