#ifndef _SPRITE_H
#define _SPRITE_H

#include "Component.h"
#include "Texture.h"

class Sprite :public component::DrawableObject{
protected:
	std::shared_ptr<const asset::Texture> p_tex;
	int m_position_x = 0;
	int m_position_y = 0;
	int m_scale_x = 1;
	int m_scale_y = 1;
	double m_rot = 0;
public:
	inline const int& getXSize()const{
		return p_tex->getWidth();
	}
	inline const int& getYSize()const{
		return p_tex->getHeight();
	}
	inline int getXAxis()const{
		return m_position_x;
	}
	inline int getYAxis()const{
		return m_position_y;
	}
	inline int getXScale()const{
		return m_scale_x;
	}
	inline int getYScale()const{
		return m_scale_y;
	}
	inline double getRotation()const{
		return m_rot;
	}
	inline void setTexture(const std::shared_ptr<const asset::Texture> tex){
		p_tex = tex;
	}
	inline void setPosition(const int& x, const int& y){
		m_position_x = x;
		m_position_y = y;
	}
	inline void setScale(int& x, const int& y){
		m_scale_x = x;
		m_scale_y = y;
	}
	inline void setRotation(const double& rot){
		m_rot = rot;
	}
	virtual void draw()const override;
};

#endif