#ifndef IFILEREADER_H
#define IFILEREADER_H

#include <string>
#include <vector>

/// @brief Abstract interface for reading file contents.
///        Supports the Dependency Inversion Principle: high-level modules
///        depend on this abstraction rather than concrete file-reading logic.
class IFileReader {
public:
    virtual ~IFileReader() = default;

    /// @brief Read the entire file and return its lines.
    /// @return A vector of strings, one per line.
    virtual std::vector<std::string> readLines() = 0;

    /// @brief Read the entire file and return it as a single string.
    /// @return The full file content.
    virtual std::string readAll() = 0;
};

#endif // IFILEREADER_H
