#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "printer.h"
#include "tokensier.h"
#include "processor.h"
#include "../constants/constants.h"

class Expression {
private:
	Printer printer;
	Processor processor;
	Tokensier tokensier;

	std::vector<std::string> getStringFromToken(std::string subExpression);
    void processSubExpression(std::string subExpression, std::string subText, int startValue, int lastValue);
	void processTextExpression(std::string textExpression, std::string subText);

public:
	void ParseCronExpression(std::string inputStr);
};


#endif // !EXPRESSIONS_H