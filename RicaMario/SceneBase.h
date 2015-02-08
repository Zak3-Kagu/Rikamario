#ifndef _SCENE_BASE_H
#define _SCENE_BASE_H

#include "Root.h"
#include "State.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

namespace scene{
	class Base{
	protected:
		//テクスチャコンテナ
		AssetContainer<asset::Texture> m_tex_container;

		//サウンドコンテナ
		AssetContainer<asset::Sound> m_sound_container;
	public:
		virtual ~Base(){}
		// シーンを変更したいときはnew_sceneを変える
		virtual void update(std::unique_ptr<Base>& new_scene,const std::unique_ptr<Root>& root) = 0;
	};
}

#endif