#pragma once

#include "node.h"

template <typename List, int Pos>
struct erase {
	typedef node<List::data, typename erase<typename List::next, Pos - 1>::result> result;
};

template <typename List>
struct erase<List, 0> {
	typedef typename List::next result;
};