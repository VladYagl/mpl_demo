#pragma once

#include "node.h"

template <typename List>
struct pop_front {
	typedef typename List::next result;
};