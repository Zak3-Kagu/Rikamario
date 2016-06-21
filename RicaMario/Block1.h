#ifndef BLOCK1_H
#define BLOCK1_H

#include "BlockObjectBase.h"

class Block1 :public BlockObjBase{
private:
public:
	
	//初期化
	virtual void init(const std::unique_ptr<Root>& root)override;

	//load系
	virtual void loadTexture(const std::unique_ptr<Root>& root)override;

	//更新
	virtual void update()override;

	virtual void setDrawIn(const std::unique_ptr<Root>& root)override{
		root->layers[0].push_back(sp_block);
	}

	virtual void setDrawOut(const std::unique_ptr<Root>& root)override{
		root->layers[0].remove(sp_block);
	}

};

#endif