#include "tokensier.h"

std::vector<std::string> Tokensier::DelimiterBasedTokensier(std::string inputString, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream inputStringStream(inputString);
    std::string token;
    while (!inputStringStream.eof()) {
        std::getline(inputStringStream, token, delimiter);
        tokens.push_back(token);
    }
    return tokens;
}