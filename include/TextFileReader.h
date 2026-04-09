#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include "IFileReader.h"

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

/// @brief Concrete file reader that uses RAII to manage the file handle.
///        Single Responsibility: only concerned with reading a text file.
class TextFileReader : public IFileReader {
public:
    /// @brief Construct a TextFileReader for the given path.
    /// @param filePath Path to the file to read.
    /// @throws std::runtime_error if the file cannot be opened.
    explicit TextFileReader(const std::filesystem::path& filePath);

    // The destructor automatically closes the file (RAII).
    ~TextFileReader() override = default;

    // Non-copyable, movable.
    TextFileReader(const TextFileReader&) = delete;
    TextFileReader& operator=(const TextFileReader&) = delete;
    TextFileReader(TextFileReader&&) noexcept = default;
    TextFileReader& operator=(TextFileReader&&) noexcept = default;

    std::vector<std::string> readLines() override;
    std::string readAll() override;

private:
    std::filesystem::path filePath_;
    std::ifstream stream_;

    /// @brief Reset the stream to the beginning of the file.
    void resetStream();
};

#endif // TEXTFILEREADER_H
