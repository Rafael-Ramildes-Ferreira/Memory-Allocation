#ifndef __FEED_H
#define __FEED_H

#include "mmu.hpp"


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