#ifndef DELIMITER_H
#define DELIMITER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Tokensier {
public:
    std::vector<std::string> DelimiterBasedTokensier(std::string inputString, char delimiter);
};

#endif // !DELIMITER_H