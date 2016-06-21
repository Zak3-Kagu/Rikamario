#include "ControllerFactory.h"
#include "Controller.h"

Controller* ControllerFactory::create(const unsigned int& player_number){
	Controller* controller = new Controller();
	if (player_number == 1){
		controller->AButton.reset(new Controller::Button(KEY_INPUT_A));
		controller->BButton.reset(new Controller::Button(KEY_INPUT_S));
		controller->CButton.reset(new Controller::Button(KEY_INPUT_D));
		controller->DButton.reset(new Controller::Button(KEY_INPUT_Z));
		controller->EButton.reset(new Controller::Button(KEY_INPUT_X));
		controller->FButton.reset(new Controller::Button(KEY_INPUT_C));

		controller->UpKey.reset(new Controller::Button(KEY_INPUT_UP));
		controller->RightKey.reset(new Controller::Button(KEY_INPUT_RIGHT));
		controller->DownKey.reset(new Controller::Button(KEY_INPUT_DOWN));
		controller->LeftKey.reset(new Controller::Button(KEY_INPUT_LEFT));

		controller->StartButton.reset(new Controller::Button(KEY_INPUT_RETURN));
		controller->SelectButton.reset(new Controller::Button(KEY_INPUT_SPACE));
	}
	return controller;
}

ControllerFactory::ControllerFactory()
{
	// 1���̃R���g���[���[���m�ۂ��Ă���
	controllers.resize(4);
}

std::shared_ptr<Controller> ControllerFactory::find(const unsigned int& player_number){
	// �ړI�̃R���g���[���[�����݂��Ȃ��ꍇ
	if (controllers.at(player_number - 1) == nullptr)
	{
		// �R���g���[���[���쐬����
		controllers.at(player_number - 1).reset(create(player_number));
	}
	// �R���g���[���[�I�u�W�F�N�g��Ԃ�
	return controllers.at(player_number - 1);
}
