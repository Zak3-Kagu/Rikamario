#ifndef _OPERABLE_OBJECT_H
#define _OPERABLE_OBJECT_H

#include "Controller.h"

namespace component{
	class OperableObject{
	public:
		virtual ~OperableObject() = default;
		// コントローラーオブジェクトを受け取って対応した動作を行う
		virtual void inputAction(const Controller& controller) = 0;
		// マウスの位置などを知る必要がある場合、別途関数を用意する
		// virtual void mouseAction(const input::Mouse& mouse){}
	};
}
#endif