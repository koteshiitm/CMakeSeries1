#include<iostream>
#include <vector>
#include "stats.h"

int main(int argc, char** argv)
{
	std::vector<int> v = {2,3,4,5};
	
	int avg = mean(v.data(), v.size());	
	std::cout<<"mean:"<<avg<<std::endl;
	
	return 0;
}