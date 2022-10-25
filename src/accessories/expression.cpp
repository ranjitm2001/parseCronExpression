#include "expression.h"

std::vector<std::string> Expression::getStringFromToken(std::string subExpression) {
    std::vector<std::string> vStr;
    vStr.push_back(subExpression);
    return vStr;
}

void Expression::processSubExpression(std::string subExpression, std::string subText, int startValue, int lastValue) {
    std::vector<int> viItem = processor.GetValuesFromToken(subExpression, startValue, lastValue);
    std::cout << subText << std::setw(SET_WIDTH - subText.size()) << "";
    printer.PrintVectorInteger(viItem);
}

void Expression::processTextExpression(std::string textExpression, std::string subText) {
    std::vector<std::string> vsItem = getStringFromToken(textExpression);
    std::cout << subText << std::setw(SET_WIDTH - subText.size()) << "";
    printer.PrintVectorString(vsItem);
}

void Expression::ParseCronExpression(std::string inputStr) {
    std::vector<std::string> cronTokens = tokensier.DelimiterBasedTokensier(inputStr, ' ');
    if (cronTokens.size() != 6) {
        std::cout << "ERR: incorrect cron expression" << std::endl;
        return;
    }
    processSubExpression(cronTokens[0], "minute", START_MINUTE, LAST_MINUTE);
    processSubExpression(cronTokens[1], "hour", START_HOUR, LAST_HOUR);
    processSubExpression(cronTokens[2], "day of month", START_DAY_OF_MONTH, LAST_DAY_OF_MONTH);
    processSubExpression(cronTokens[3], "month", START_MONTH, LAST_MONTH);
    processSubExpression(cronTokens[4], "day of week", START_DAY_OF_WEEK, LAST_DAY_OF_WEEK);
    processTextExpression(cronTokens[5], "command");
}

