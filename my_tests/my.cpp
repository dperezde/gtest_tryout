#include "my.hpp"

#include <iostream>
#include <sstream> 

/* Got the idea for this from here:
 * http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring*/
int Add(std::string numbers)
{
	std::string delimiter {","};
	int sum {0};

	size_t p = 0;

	int i;
	if (numbers.length()>0) {
		if(numbers.find("//")==0) {
			p = numbers.find('\n');
			if (p == std::string::npos) {
				printf("Wrong delimiter formatting. It should be: //[delimiter]\\n[numbers…]\n");
				return 0;
			}

			delimiter=numbers.substr(2,p-2);
			for (size_t x; x != std::string::npos; x = numbers.find(delimiter))
			      {
			      numbers.replace(x,delimiter.length(),",");

			      }
			p = numbers.find('\n');

		}
	}

	std::stringstream ss(numbers.substr(p));
	while(ss >> i)
	{
		sum+=i;

		if(ss.peek() == ',' || ss.peek() == '\n')
			ss.ignore();
	}

	return sum;
}
