#include "processor.h"

std::vector<int> Processor::getVIntegerFromVString(std::vector<std::string>& vStr) {
    std::vector<int> vInt;
    for (auto i : vStr) {
        vInt.push_back(stoi(i));
    }
    return vInt;
}

std::vector<int> Processor::getVIntegerBetweenLimAandLimBWithJump(int jump, int startValue, int lastValue) {
    std::vector<int> vInt;
    for (int i = startValue; i <= lastValue; i += jump) {
        vInt.push_back(i);
    }
    return vInt;
}

std::vector<int> Processor::getVIntegerAllValues(int startValue, int lastValue) {
    std::vector<int> vInt;
    for (int i = startValue; i <= lastValue; i++) {
        vInt.push_back(i);
    }
    return vInt;
}

bool Processor::isValidValues(std::vector<int> vInt, int startValue, int lastValue) {
    for (auto value : vInt) {
        if (value < startValue || value > lastValue) {
            return false;
        }
    }
    return true;
}

std::vector<int> Processor::GetValuesFromToken(std::string subExpression, int startValue, int lastValue) {
    std::vector<int> vInt;
    if (subExpression.find(',') != std::string::npos) {
        // ifContains(,) {}
        std::vector<std::string> sValues = tokensier.DelimiterBasedTokensier(subExpression, ',');
        vInt = getVIntegerFromVString(sValues);
    } else if (subExpression.find('-') != std::string::npos) { 
        // ifContains(-) {}
        std::vector<std::string> sValues = tokensier.DelimiterBasedTokensier(subExpression, '-');
        int limA = stoi(sValues[0]);
        int limB = stoi(sValues[1]);
        vInt = getVIntegerBetweenLimAandLimBWithJump(1, limA, limB);
    } else if (subExpression.find('/') != std::string::npos) { 
        // ifContains(/) {}
        std::vector<std::string> sValues = tokensier.DelimiterBasedTokensier(subExpression, '/');
        if (sValues.size() != 2) {
            std::cout << "ERR: incorrect expression" << std::endl;
            return vInt;
        }
        int jump = stoi(sValues[1]);
        int initValue = 0;
        if (sValues[0].compare("*") != 0) {
            initValue = stoi(sValues[0]);
        }
        vInt = getVIntegerBetweenLimAandLimBWithJump(jump, initValue, lastValue);
    } else if (subExpression.find('*') != std::string::npos) { 
        // ifContains(*) {}, but not (/)
        vInt = getVIntegerAllValues(startValue, lastValue);
    } else { 
        // ifContainsOnlyNumber() {}
        int num = stoi(subExpression);
        if (num > lastValue) {
            std::cout << "ERR: Out of bound values" << std::endl;
            return vInt;
        }
        vInt.push_back(num);
    }
    if (!isValidValues(vInt, startValue, lastValue)) {
        vInt.clear();
        return vInt;
    }
    return vInt;
} 
