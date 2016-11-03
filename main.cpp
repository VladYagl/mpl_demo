#include <iostream>
#include <cstdlib>
#include "template_list.h"
#include <cassert>

#if defined(_MSC_VER)                                                 \
 || defined(__GNUC__) && __GNUC__ < 6
// MSVC and GCC (pre 6.x) don't support C++17 terse static assert
#define static_assert(x) static_assert(x, #x)
#endif

typedef node<1, nil> list_1;
typedef node<1, node<2, nil>> list_12;
typedef node<1, node<2, node<3, nil>>> list_123;

static_assert(is_nil<list_1::next>::value);
static_assert(list_12::data == 1  && list_12::next::data == 2  && is_nil<list_12::next::next>::value);
static_assert(list_123::data == 1 && list_123::next::data == 2 && list_123::next::next::data == 3 && is_nil<list_123::next::next::next>::value);

static_assert((std::is_same<list_12, push_back<list_1, 2>::result>::value));
static_assert((std::is_same<list_123, push_back<list_12, 3>::result>::value));

typedef node<1, nil> front_list_1;
typedef node<2, node<1, nil>> front_list_21;
typedef node<3, node<2, node<1, nil>>> front_list_321;

static_assert((std::is_same<front_list_21, push_front<front_list_1, 2>::result>::value));
static_assert((std::is_same<front_list_321, push_front<front_list_21, 3>::result>::value));

static_assert((std::is_same<pop_back<list_12>::result, list_1>::value));
static_assert((std::is_same<pop_back<list_123>::result, list_12>::value));

int main()
{
	assert(size<list_123>::result == 3);
	assert(size<list_12>::result == 2);
	assert(size<list_1>::result == 1);
	assert(size<front_list_321>::result == 3);
	assert(size<front_list_21>::result == 2);
	assert(size<front_list_1>::result == 1);


    std::cout << list_1() << std::endl;
    std::cout << list_12() << std::endl;
    std::cout << list_123() << std::endl;
	std::cout << "________________________________________" << std::endl;

	std::cout << erase<list_123, 0>::result() << std::endl;
	std::cout << erase<list_123, 1>::result() << std::endl;
	std::cout << erase<list_123, 2>::result() << std::endl;
	std::cout << "________________________________________" << std::endl;


	std::cout << insert<list_123, 5, 0>::result() << std::endl;
	std::cout << insert<list_123, 5, 1>::result() << std::endl;
	std::cout << insert<list_123, 5, 2>::result() << std::endl;
	std::cout << insert<list_123, 5, 3>::result() << std::endl;
	std::cout << "________________________________________" << std::endl;

	std::cout << reverse<list_123>::result() << std::endl;
	std::cout << reverse<front_list_321>::result() << std::endl;
	std::cout << "________________________________________" << std::endl;

	std::cout << pop_back<list_12>::result() << std::endl;

	system("pause");
}
