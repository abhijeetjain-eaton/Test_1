#ifndef IFILEPROCESSOR_H
#define IFILEPROCESSOR_H

#include <string>
#include <vector>

/// @brief Abstract interface for processing file content.
///        New processing strategies can be added without modifying existing
///        code (Open/Closed Principle).
class IFileProcessor {
public:
    virtual ~IFileProcessor() = default;

    /// @brief Process the given lines and return a result string.
    /// @param lines The file content as a vector of lines.
    /// @return A string describing the processing result.
    virtual std::string process(const std::vector<std::string>& lines) = 0;
};

#endif // IFILEPROCESSOR_H
