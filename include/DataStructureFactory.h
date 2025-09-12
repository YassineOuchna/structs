#pragma once
#include "DataStructure.h"
#include <memory>
#include <string>
#include <vector>

class DataStructureFactory {

private:
    static std::vector<std::string> DATASTRUCTURES;

public:
    DataStructureFactory();
    static void showAvailableStructures();
    static size_t getNumStructures();
    static std::string getStructName(int dsId);
    static DataStructure* getDataStructure(int dsId);
};
