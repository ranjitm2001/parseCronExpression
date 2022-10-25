#include <iostream>
#include <string>
#include "accessories/expression.h"

int main() {
	// Input from the console
	std::string cronExpression;
	std::getline(std::cin, cronExpression);
	
	// Parse the cron expression
	Expression expression;
	expression.ParseCronExpression(cronExpression);
	return 0;
}