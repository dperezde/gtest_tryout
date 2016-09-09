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
	if (numbers.length()>0) {
		if(numbers.find("//")==0) {
			delimiter=numbers.substr(2,1);
			int pos = numbers.find(delimiter);
			if(numbers.substr(pos+ delimiter.size())!="\n") {
				printf("Wrong delimiter formatting. It should be: //[delimiter]\\n[numbers…]\n");
				return 0;
			}
			else{
				ss << numbers.substr(numbers.find('\n') + 1 );
			}
		}
	}

	while(ss >> i)
	{
		sum+=i;

		if(ss.peek() == ',' || ss.peek() == '\n')
			ss.ignore();
	}

	return sum;
}
