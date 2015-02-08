#ifndef _TEXTURE_FACTORY_H
#define _TEXTURE_FACTORY_H

#include "Texture.h"

namespace assetfactory{
	class TextureFactory{
	public:
		static asset::Texture* createFromFile(const std::string& filename){
			auto new_tex = new asset::Texture();
			int handle = LoadGraph(filename.c_str());
			new_tex->setHandle(handle);

			int width = 0;
			int height = 0;
			//ハンドルが取得できたとき、サイズを読み取る
			if (handle != -1){
				GetGraphSize(handle, &width, &height);
			}
			new_tex->setWidth(width);
			new_tex->setHeight(height);
			return new_tex;
		}

		static std::vector<asset::Texture*>* createFromFile2(const std::string& filename,const int& XNum, const int& YNum){
			int handle = LoadGraph(filename.c_str());
			int XSize = 0;
			int YSize = 0;
			//ハンドルが取得できたとき、サイズを読み取る
			if (handle != -1){
				GetGraphSize(handle, &XSize, &YSize);
			}
			XSize /= XNum;
			YSize /= YNum;
			auto new_texs = new std::vector<asset::Texture*>;
			int AllNum = XNum*YNum;
			new_texs->resize(AllNum);
			int* handles = new int[AllNum];
			LoadDivGraph(filename.c_str(), AllNum, XNum, YNum, XSize, YSize, handles);
			for (int i = 0; i<AllNum; i++){
				new_texs->at(i) = new asset::Texture();
				new_texs->at(i)->setHandle(handles[i]);

				int width;
				int height;
				if (handles[i] != -1){
					GetGraphSize(handles[i], &width, &height);
				}
				new_texs->at(i)->setWidth(width);
				new_texs->at(i)->setHeight(height);
			}
			DeleteGraph(handle);
			delete[] handles;
			return new_texs;
		}
	};
}

#endif