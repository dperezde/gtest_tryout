#include "my.hpp"

#include <iostream>
#include <sstream> 

/* Got the idea for this from here:
 * http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring*/
int Add(std::string numbers)
{
	std::string delimiter {","};
	int sum {0};

	std::stringstream ss(numbers);

	int i;

	while(ss >> i)
	{
		sum+=i;

		if(ss.peek() == ',')
			ss.ignore();
	}

	return sum;
}
