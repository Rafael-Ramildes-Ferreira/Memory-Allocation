#include "Feed.h"
#include <fstream>
#include <cassert>
#include "Criterion.h"
#include "linkedListMMU.hpp"
#include "bitmapMMU.hpp"


enum manegment_algorithm {MA_INVALID, BIT_MAP, LINKED_LIST};
enum allocation_algorithm {AA_INVALID, BEST_FIT, FIRST_FIT};


Feed::Feed(std::string path)
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
	std::ifstream file;
	file.open(this->path);

	assert(file.is_open());

	// Reads configurations
	unsigned int man_alg, mem_size, smallest_block, alloc_alg;
	file >> man_alg >> mem_size >> smallest_block >> alloc_alg;
	
	AllocationMap *memMap;
	switch(man_alg)
	{
		case BIT_MAP:
			memMap = (AllocationMap*) new BitmapMMU(mem_size,smallest_block);
			break;
		case LINKED_LIST:
			memMap = (AllocationMap*) new LinkedListMMU(mem_size,smallest_block);
			break;
		case MA_INVALID:
			std::cout << "0 in first line of " << this->path << " is invalid" << std::endl;
		default:
			std::cout << "Failed to initialize memory map" << std::endl;
			return;
	}

	Criterion *criterion;
	switch (alloc_alg)
	{
	case BEST_FIT:
		{
			std::cout << "Best Fit:" << std::endl;
			criterion = (Criterion*) new BestFit();
		}
		break;

	case FIRST_FIT:
		{
			std::cout << "First Fit:" << std::endl;
			criterion = (Criterion*) new FirstFit();
		}
		break;
	
	default:
		break;
	}
	
	auto mmu = new MMU(smallest_block,memMap,criterion);

	assert(mmu != nullptr);

	// Read commands
	char command;
	unsigned int size, id;
	while (file >> command)
	{	
		switch(command)
		{
			case 'A':
				file >> size >> id;
				std::cout << "A " << size << " " << id << std::endl;
				mmu->allocate(size,id);
				break;
			case 'D':
				file >> id;
				std::cout << "D " << id << std::endl;
				mmu->deallocate(id);
				break;
			default:
				mmu->printMemory();
				return;
		}
	}

	std::cout << std::endl;
	mmu->printMemory();
}

void Feed::print_info()
{

}