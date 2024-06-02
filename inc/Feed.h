#ifndef __FEED_H
#define __FEED_H

#include "mmu.hpp"
#include <string>


class Feed
{
private:
	// MMU<T> * mmu;
	std::string path;
public:
	Feed(std::string path);
	~Feed();
	void read();
	void print_info();
};


#endif