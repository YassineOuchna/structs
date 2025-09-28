#include "DataStructureFactory.h"
#include <iostream>
#include <vector>
#include <Array.h>
#include <LinkedList.h>


std::vector<std::string> DataStructureFactory::DATASTRUCTURES = {
    "Array",
    "Linked List"
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
    if (dsId == 1) {
        DataStructure* ds = new LinkedList();
        return ds;
    }
    return nullptr;
}

