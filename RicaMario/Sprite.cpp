#include "Sprite.h"

void Sprite::draw()const{
	const int center_x = p_tex->getWidth() / 2;
	const int center_y = p_tex->getHeight() / 2;
	DrawRotaGraph3(m_position_x, m_position_y, center_x, center_y, m_scale_x, m_scale_y, m_rot, p_tex->getHandle(), TRUE);
}