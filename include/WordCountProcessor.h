#ifndef WORDCOUNTPROCESSOR_H
#define WORDCOUNTPROCESSOR_H

#include "IFileProcessor.h"

/// @brief Processor that counts the total number of words across all lines.
class WordCountProcessor : public IFileProcessor {
public:
    std::string process(const std::vector<std::string>& lines) override;
};

#endif // WORDCOUNTPROCESSOR_H
