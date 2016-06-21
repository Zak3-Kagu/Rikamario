#ifndef _MAPCLASS_H
#define _MAPCLASS_H

#define MAP_XSIZE 20
#define MAP_YSIZE 15

#include "BlockObjectBase.h"
#include "Block0.h"
#include "Block1.h"

class MapClass{
private:
	//�}�b�v�̃f�[�^
	std::vector<std::vector<int>> m_mapdata;
	std::vector<std::vector<std::unique_ptr<BlockObjBase>>> m_blocks;

	//�u���b�N�̕ύX
	void changeBlock(const int x, const int y, const int id, const std::unique_ptr<Root>& root);
public:
	//������
	void init();

	//���[�h
	void loadTexture(const std::unique_ptr<Root>& root);
	
	//�ݒ�
	void set(const std::unique_ptr<Root>& root);

	//�X�V
	void update();

	//���̑�
	void setDrawIn(const std::unique_ptr<Root>& root);
	void setDrawOut(const std::unique_ptr<Root>& root);
};
#endif