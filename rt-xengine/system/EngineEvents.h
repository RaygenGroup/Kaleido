#pragma once
#include "event/Event.h"

#define DECLARE_EVENT_LISTENER(Name, EventName) decltype(EventName)::Listener Name{ EventName }

namespace Event
{
	// int32 width, int32 height
	inline MulticastEvent<int32, int32> OnWindowResize;
}