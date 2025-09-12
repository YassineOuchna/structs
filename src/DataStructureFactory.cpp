#include "DataStructureFactory.h"
#include <iostream>
#include <vector>
#include <Array.h>


std::vector<std::string> DataStructureFactory::DATASTRUCTURES = {
    "Array"
};
    
void DataStructureFactory::showAvailableStructures() {
    size_t num_structures = DATASTRUCTURES.size();
    for (size_t i = 0; i < num_structures; i++) {
        std::cout << i << " : " << DATASTRUCTURES.at(i) << "\n";
    };
};

size_t DataStructureFactory::getNumStructures() {
    return DATASTRUCTURES.size();
}


std::string DataStructureFactory::getStructName(int dsId) {
    return DATASTRUCTURES.at(dsId);
}


DataStructure* DataStructureFactory::getDataStructure(int dsId) {
    if (dsId == 0) {
        DataStructure* ds = new Array();
        return ds;
    }
    return nullptr;
}

