#pragma once

#include "node.h"

template <typename List, int Value>
struct push_front {
	typedef node<Value, List> result;
};
