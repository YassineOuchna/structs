#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "utils.h"
#include "DataStructureFactory.h"



int main() {
    std::cout << "Choose a data struture by inputing its index\n";
    DataStructureFactory::showAvailableStructures();
    size_t num_structures = DataStructureFactory::getNumStructures();
    size_t structure_index;
    while (true) {
        std::cin >> structure_index;
        std::cin.ignore();
        if (structure_index >= num_structures) {
            std::cout << "Invalid input" << '\n';
        } else {
            break;
        }
    }

    DataStructure* ds = DataStructureFactory::getDataStructure(structure_index);
    std::cout << "Type a series of spaced out integers" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    std::vector<int> values = utils::parseInputValues(input);

    // Populating data structure
    std::cout << "Populating " << DataStructureFactory::getStructName(structure_index)  << std::endl;
    ds->build(values);


    std::cout << "Sorting " << DataStructureFactory::getStructName(structure_index)  << std::endl;
    ds->sort();
    std::cout << "Sorted " << DataStructureFactory::getStructName(structure_index)  << std::endl;
    ds->display();

    std::cin.get();
    return 0;
}
