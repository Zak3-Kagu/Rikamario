#ifndef _STATE_H
#define _STATE_H

#include "Root.h"

template<class PARENT>
	class State{
	public:
		virtual void update(PARENT& parent, std::unique_ptr<State<PARENT>>& new_state,const std::unique_ptr<Root>& root) = 0;
		State() = default;
		virtual ~State() = default;
};
#endif