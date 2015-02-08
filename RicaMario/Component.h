#ifndef _COMPONENT_H
#define _COMPONENT_H

namespace component{
	class UpdateObject{
	public:
		UpdateObject() = default;
		virtual ~UpdateObject() = default;
		virtual void update() = 0;
	};

	class DrawableObject{
	public:
		DrawableObject() = default;
		virtual ~DrawableObject() = default;
		virtual void draw() const = 0;
	};
}

#endif