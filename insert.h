#pragma once

#include "node.h"

template <typename List, int Value, int Pos>
struct insert {
	typedef node<List::data, typename insert<typename List::next, Value, Pos - 1>::result> result;
};

template <typename List, int Value>
struct insert<List, Value, 0> {
	typedef typename node<Value, node <List::data, typename List::next>> result;
};

template <int Value>
struct insert<nil, Value, 0> {
	typedef typename node<Value, nil> result;
};