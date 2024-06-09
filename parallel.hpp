#pragma once
#include <thread>
#include "read_array.hpp"

//using namespace std;

//thread thread_obj();

std::vector<std::vector<std::string>> splitFileIntoChunks(const std::string& filename, int numChunks) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    if (numChunks <= 0) {
        std::cerr << "Number of chunks must be greater than zero." << std::endl;
        return {};
    }

    size_t totalLines = lines.size();
    size_t linesPerChunk = totalLines / numChunks;
    size_t extraLines = totalLines % numChunks;

    std::vector<std::vector<std::string>> chunks(numChunks);
    auto it = lines.begin();
    for (int i = 0; i < numChunks; ++i) {
        size_t currentChunkSize = linesPerChunk + (i < extraLines ? 1 : 0);
        for (size_t j = 0; j < currentChunkSize; ++j) {
            chunks[i].push_back(*it);
            ++it;
        }
    }

    return chunks;
}