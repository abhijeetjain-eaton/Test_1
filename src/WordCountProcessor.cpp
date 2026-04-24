#include "WordCountProcessor.h"

#include <sstream>
#include <string>

std::string WordCountProcessor::process(const std::vector<std::string>& lines)
{
    std::size_t wordCount = 0;
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            ++wordCount;
        }
    }
    return "Word count: " + std::to_string(wordCount);
}
