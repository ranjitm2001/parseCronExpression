#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <iostream>
#include <vector>
#include <string>

class Printer {
public:
	void PrintVectorString(std::vector<std::string>& items);
	void PrintVectorInteger(std::vector<int>& items);
};

#endif // !PRINT_UTILS_H