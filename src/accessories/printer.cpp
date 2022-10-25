#include "printer.h"

// Print vector<string> objects
void Printer::PrintVectorString(std::vector<std::string>& items) {
	for (auto item : items) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

// Print vector<int> objects
void Printer::PrintVectorInteger(std::vector<int>& items) {
	for (auto item : items) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
}