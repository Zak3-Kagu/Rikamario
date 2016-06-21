#ifndef _ROOT_H
#define _ROOT_H

#include "Component.h"
#include "InputManager.h"
#include "ControllerFactory.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

class Root{
public:
	std::list<std::shared_ptr<component::UpdateObject>> update_list;

	std::vector<std::list<std::shared_ptr<component::DrawableObject>>> layers;

	InputManager input_mgr;

	ControllerFactory controller_factory;

	//�e�N�X�`���R���e�i
	AssetContainer<asset::Texture> tex_container;

	//�T�E���h�R���e�i
	AssetContainer<asset::Sound> sound_container;
};

#endif