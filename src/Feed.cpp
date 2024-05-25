#include "Feed.h"
#include <fstream>
#include <cassert>
#include "Criterion.h"
#include "linkedListMMU.hpp"


enum manegment_algorithm {MA_INVALID, BIT_MAP, LINKED_LIST};
// enum allocation_algorithm {AA_INVALID, BEST_FIT, FIRST_FIT};


Feed::Feed(char * path)
{
	this->path = path;
}

Feed::~Feed()
{
	// delete mmu;	// Acho que mmu não é pra pertencer ao Feed
}

void Feed::read()
{
	// Opens file
	std::fstream file;
	file.open(this->path);

	assert(!file.is_open());

	// Reads configurations
	unsigned int man_alg, men_size, smallest_block, alloc_alg;
	file >> man_alg >> men_size >> smallest_block >> alloc_alg;
	LinkedListMMU teste;
	MMU<Criterion> *mmu = nullptr;
	switch (alloc_alg)
	{
	case BEST_FIT:
		{
			MMU<BestFit> aux(smallest_block,(allocation_algorithm)alloc_alg,teste);
			mmu = (MMU<Criterion>*) &aux;
		}
		break;

	case FIRST_FIT:
		{
			MMU<FirstFit> aux(smallest_block,(allocation_algorithm)alloc_alg,teste);
			mmu = (MMU<Criterion>*) &aux;
		}
		break;
	
	default:
		break;
	}

	// Read commands
	char command;
	unsigned int size, id;
	while (1)
	{	
		file >> command;
		switch(command)
		{
			case 'A':
				file >> size >> id;
				mmu->allocate(size,id);
				break;
			case 'D':
				file >> id;
				mmu->deallocate(id);
				break;
			default:
				return;
		}
	}
}

void Feed::print_info()
{

}