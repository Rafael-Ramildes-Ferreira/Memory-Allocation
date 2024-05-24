#include "unit_test.h"
#include "Criterion.h"
#include <iostream>

int main()
{
	static_assert(has_choose_slot<Criterion>::value);
	static_assert(has_choose_slot<BestFit>::value);
	static_assert(has_choose_slot<FirstFit>::value);
	// static_assert(has_choose_slot<MemorySlot>::value);

	return 0;
}