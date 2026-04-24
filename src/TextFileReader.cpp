#include "TextFileReader.h"

#include <sstream>
#include <stdexcept>

TextFileReader::TextFileReader(const std::filesystem::path& filePath)
    : filePath_{filePath}
    , stream_{filePath}
{
    if (!stream_.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath_.string());
    }
}

std::vector<std::string> TextFileReader::readLines()
{
    resetStream();

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(stream_, line)) {
        lines.push_back(std::move(line));
    }
    return lines;
}

std::string TextFileReader::readAll()
{
    resetStream();

    std::ostringstream oss;
    oss << stream_.rdbuf();
    if (stream_.bad()) {
        throw std::runtime_error("I/O error while reading file: " + filePath_.string());
    }
    return oss.str();
}

void TextFileReader::resetStream()
{
    stream_.clear();
    stream_.seekg(0, std::ios::beg);
    if (stream_.fail()) {
        throw std::runtime_error("Failed to seek to beginning of file: " + filePath_.string());
    }
}
