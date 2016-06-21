#include "Block0.h"


//load�n

void Block0::loadTexture(const std::unique_ptr<Root>& root) {
	auto new_tex = assetfactory::TextureFactory::createFromFile("image/block0.bmp");
	root->tex_container.registerObject(new_tex, "Block0");
}


//������
void Block0::init(const std::unique_ptr<Root>& root){
	m_blocktype = 1;
	m_blockstat = 0;
	sp_block.reset(new Sprite());
	sp_block->setTexture(root->tex_container.findAssetByname("Block0"));
}

//�X�V
void Block0::update(){
	sp_block->setPosition(m_x, m_y);
}
