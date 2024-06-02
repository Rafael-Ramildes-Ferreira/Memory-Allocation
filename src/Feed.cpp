#include "Feed.h"
#include <fstream>
#include <cassert>
#include "Criterion.h"
#include "linkedListMMU.hpp"


enum manegment_algorithm {MA_INVALID, BIT_MAP, LINKED_LIST};
// enum allocation_algorithm {AA_INVALID, BEST_FIT, FIRST_FIT};


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
	unsigned int man_alg, men_size, smallest_block, alloc_alg;
	file >> man_alg >> men_size >> smallest_block >> alloc_alg;
	LinkedListMMU teste(men_size);
	// MMU<Criterion> *mmu = nullptr;
	switch (alloc_alg)
	{
	case BEST_FIT:
		{
			std::cout << "Best Fit:" << std::endl;
			auto mmu = new MMU<BestFit>(smallest_block,(allocation_algorithm)alloc_alg,&teste);
			// mmu = (MMU<Criterion>*) aux;

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
		break;

	case FIRST_FIT:
		{
			std::cout << "First Fit:" << std::endl;
			auto mmu = new MMU<FirstFit>(smallest_block,(allocation_algorithm)alloc_alg,&teste);
			// mmu = (MMU<Criterion>*) aux;

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
		break;
	
	default:
		break;
	}
}

void Feed::print_info()
{

}