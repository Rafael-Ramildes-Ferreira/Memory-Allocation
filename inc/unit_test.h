#ifndef __UNIT_TEST_H
#define __UNIT_TEST_H

#include <type_traits>


template<typename T>
class has_choose_slot
{
private:
    template<typename U>
    static auto test(int) -> decltype(U::choose_slot(nullptr,0,0), std::true_type{});
    
    template<typename U>
    static std::false_type test(...);

public:
	static constexpr bool value = decltype(test<T>(0))::value;
};


#endif