#pragma once

#include "node.h"
#include "pop_front.h"

template <typename Result, typename List>
struct reverse_impl {
	typedef typename reverse_impl<typename push_front<Result, List::data>::result, typename List::next>::result result;
};

template <typename Result>
struct reverse_impl<Result, nil> {
	typedef Result result;
};

template <typename List>
struct reverse {
	typedef typename reverse_impl<nil, List>::result result;
};
