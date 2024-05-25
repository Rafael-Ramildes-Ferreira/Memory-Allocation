#include "Feed.h"
#include <fstream>
#include <cassert>


enum manegment_algorithm {MA_INVALID, BIT_MAP, LINKED_LIST};
enum allocation_algorithm {AA_INVALID, BEST_FIT, FIRST_FIT};


Feed::Feed(char * path)
{
	this->path = path;
}

Feed::~Feed()
{
	delete mmu;
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
				// this->mmu->allocate(size,id);
				break;
			case 'D':
				file >> id;
				// this->mmu->deallocate(id);
				break;
			default:
				return;
		}
	}
}

void Feed::print_info()
{

}