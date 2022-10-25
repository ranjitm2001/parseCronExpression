#ifndef PROCESSER_H
#define PROCESSER_H

#include <iostream>
#include <vector>
#include <string>
#include "tokensier.h"

class Processor {
private:
	Tokensier tokensier;

	std::vector<int> getVIntegerFromVString(std::vector<std::string>& vStr);
	std::vector<int> getVIntegerBetweenLimAandLimBWithJump(int jump, int startValue, int lastValue);
	std::vector<int> getVIntegerAllValues(int startValue, int lastValue);
	bool isValidValues(std::vector<int> vInt, int startValue, int lastValue);

public:
	std::vector<int> GetValuesFromToken(std::string subExpression, int startValue, int lastValue);
};

#endif // !PROCESSER_H