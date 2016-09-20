#include "my.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

constexpr size_t single_delim = 3;
constexpr int big_number_limit = 1001;

void prep_input(std::string& numbers, const std::string& delimiter)
{
	for(size_t x = 0; x != std::string::npos; x = numbers.find(delimiter))
	{
		numbers.replace(x, delimiter.length(), ",");
	}
	return;
}

/* Got the idea for this from here:
 * http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring*/
int Add(std::string numbers)
{
	std::string delimiter {","};
	int sum {0};

	size_t p {0};
	size_t q {0};

	int i;
	if (numbers.length()>0) {
		if(numbers.find("//")==0) {
			p = numbers.find('\n');
			if (p == std::string::npos) {
				throw std::logic_error("Wrong delimiter formatting. It should be: //[delimiter]\\n[numbers…]");

			}

			if (p > single_delim) {
				if (numbers.find("//[") == 0){
					p = numbers.find("[");
					while ( p != std::string::npos) {
						q = numbers.find("]");
						if (q !=  std::string::npos) {
							delimiter = numbers.substr(p+1, q-p-1);


							numbers.erase(numbers.begin()+q);
							numbers.erase(numbers.begin()+p);

							prep_input(numbers, delimiter);

						}
						else {
							throw std::logic_error(" Wrong formatting");
						}
						p = numbers.find("[");
					}
				}else {
					throw std::logic_error(" Wrong formatting");
				}
			}
			else{
				delimiter = numbers.substr(2,p-2);
			}

			prep_input(numbers, delimiter);
			p = numbers.find('\n');

		}
	}


	std::stringstream ss(numbers.substr(p));
	while(ss >> i)
	{

		sum+=i;
		if (i < 0) throw std::invalid_argument("Negatives not allowed " + i);

		if(ss.peek() == ',' || ss.peek() == '\n')
			ss.ignore();
	}

	return sum%big_number_limit;
}
