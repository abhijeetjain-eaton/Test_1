#include "FileReaderService.h"
#include "LineCountProcessor.h"
#include "TextFileReader.h"
#include "WordCountProcessor.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>\n";
        return EXIT_FAILURE;
    }

    try {
        // --- Build the reader (RAII: file opened in constructor) ---
        auto reader = std::make_unique<TextFileReader>(argv[1]);

        // --- Build the processor pipeline (Open/Closed: add new processors here) ---
        std::vector<std::unique_ptr<IFileProcessor>> processors;
        processors.push_back(std::make_unique<LineCountProcessor>());
        processors.push_back(std::make_unique<WordCountProcessor>());

        // --- Compose and run ---
        FileReaderService service{std::move(reader), std::move(processors)};
        service.execute();

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
