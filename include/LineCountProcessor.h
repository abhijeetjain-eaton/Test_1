#ifndef LINECOUNTPROCESSOR_H
#define LINECOUNTPROCESSOR_H

#include "IFileProcessor.h"

/// @brief A sample processor that counts the number of lines.
///        Demonstrates how to add new features via the IFileProcessor interface.
class LineCountProcessor : public IFileProcessor {
public:
    std::string process(const std::vector<std::string>& lines) override;
};

#endif // LINECOUNTPROCESSOR_H
