#include "FileReaderService.h"

#include <iostream>
#include <utility>

FileReaderService::FileReaderService(
    std::unique_ptr<IFileReader> reader,
    std::vector<std::unique_ptr<IFileProcessor>> processors)
    : reader_{std::move(reader)}
    , processors_{std::move(processors)}
{
}

void FileReaderService::addProcessor(std::unique_ptr<IFileProcessor> processor)
{
    processors_.push_back(std::move(processor));
}

void FileReaderService::execute()
{
    auto lines = reader_->readLines();

    for (const auto& processor : processors_) {
        std::cout << processor->process(lines) << "\n";
    }
}
