#include "LineCountProcessor.h"

#include <string>

std::string LineCountProcessor::process(const std::vector<std::string>& lines)
{
    return "Line count: " + std::to_string(lines.size());
}
