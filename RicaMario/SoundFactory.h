#ifndef _SOUND_FACTORY_H
#define _SOUND_FACTORY_H

#include "Sound.h"

namespace assetfactory{
	class SoundFactory{
	public:
		static asset::Sound* createfromfile(const std::string& filename){
			auto new_sound = new asset::Sound();
			int handle = LoadSoundMem(filename.c_str());
			new_sound->setHandle(handle);
			return new_sound;
		}
	};
}

#endif