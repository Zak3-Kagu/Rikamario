#ifndef _ASSET_CONTAINER_H
#define _ASSET_CONTAINER_H

template < class Asset >
class AssetContainer{
protected:
	std::map<std::string, std::shared_ptr<Asset>> m_container;
public:
	AssetContainer() = default;
	virtual ~AssetContainer() = default;
	/*オブジェクトを登録する
	**@param new_obj 登録するオブジェクトのポインタ
	**@param name 登録する名前
	*/
	void registerObject(Asset* new_obj, const std::string& name){
		m_container.insert(std::make_pair(name, std::shared_ptr<Asset>(new_obj)));
	}
	/*登録したオブジェクトの中から名前で探す
	**@param 登録した名前
	*/
	const std::shared_ptr<Asset> findAssetByname(const std::string& name){
		return m_container.find(name)->second;
	}

	//登録したデータに不正なデータが入っていた場合、trueを返す
	const bool includeInvalidObject()const{
		for (const auto& obj : m_container){
			if (obj.second->getHandle() == -1){
				return true;
			}
		}
		return false;
	}
};

#endif