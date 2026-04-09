#ifndef FILEREADERSERVICE_H
#define FILEREADERSERVICE_H

#include "IFileProcessor.h"
#include "IFileReader.h"

#include <memory>
#include <vector>

/// @brief High-level service that composes an IFileReader with one or more
///        IFileProcessor instances.  New processors can be added at runtime
///        without touching this class (Open/Closed Principle).
///        Dependencies are injected through the constructor (Dependency Inversion).
class FileReaderService {
public:
    /// @brief Construct the service with a reader and an initial list of processors.
    /// @param reader  Owning pointer to an IFileReader.
    /// @param processors  Owning pointers to IFileProcessor instances.
    FileReaderService(std::unique_ptr<IFileReader> reader,
                      std::vector<std::unique_ptr<IFileProcessor>> processors);

    /// @brief Add another processor to the pipeline.
    void addProcessor(std::unique_ptr<IFileProcessor> processor);

    /// @brief Run all processors against the file content and print results.
    void execute();

private:
    std::unique_ptr<IFileReader> reader_;
    std::vector<std::unique_ptr<IFileProcessor>> processors_;
};

#endif // FILEREADERSERVICE_H
