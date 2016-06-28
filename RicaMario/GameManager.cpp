#include "GameManager.h"

//#define DEBUG

int GameManager::update(){
	fps_mgr->wait();
	fps_mgr->update();
	if (ProcessMessage() != 0){
		return -1;
	}
	// �Q�[���̍X�V����������
	now_scene->update(now_scene, root);
	for (const auto& obj : root->update_list){
		obj->update();
	}
	// InputManager�����s
	root->input_mgr.exec();
	if (now_scene == nullptr){
		return -1;
	}
	return 0;
}

int GameManager::draw() const{
	if (ClearDrawScreen() != 0){
		return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	}
	for (const auto& layer : root->layers){
		for (const auto& obj : layer){
			obj->draw();
		}
	}
#ifdef DEBUG
	fps_mgr->draw();
#endif
	ScreenFlip();//����ʔ��f
	return 0;
}

int GameManager::initialize(){
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	SetOutApplicationLogValidFlag(FALSE);//���O��\�������Ȃ�
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�������Ɨ���ʉ�
	SetWindowText("�q�������l��������");
	SetTransColor(0, 0, 0); //�w�肵���F�𓧖��F�Ƃ���
	SetDrawBright(0,0,0);//�P�x��0�ɃZ�b�g
	root->input_mgr.push_back(root->controller_factory.find(1));
	root->layers.resize(3);
	return 0;
}

int GameManager::run(){
	if (update() != 0) return -1; // �X�V���������s�Ȃ�-1��Ԃ�
	if (draw() != 0) return -1; // �`�揈�������s�Ȃ�-1��Ԃ�
	return 0;
}

void GameManager::terminate(){
	DxLib_End();//�c�w���C�u�����I������
}
