#include "mmu.hpp"
#ifndef __FEED_H
#define __FEED_H

class Feed
{
private:
	MMU * mmu;
	char * path;
public:
	Feed(char * path);
	~Feed();
	void read();
	void print_info();
};


#endif