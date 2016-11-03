#pragma once

#include "node.h"

template <typename List, int size>
struct size_impl {
	static const int result = size_impl<typename List::next, size + 1>::result;
};

template <int size> 
struct size_impl<nil, size> {
	static const int result = size;
};

template <typename List>
struct size {
	static const int result = size_impl<List, 0>::result;
};