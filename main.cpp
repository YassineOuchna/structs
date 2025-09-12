#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "utils.h"
#include "DataStructureFactory.h"



int main() {
    std::cout << "Choose a data struture\n";
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

    std::cout << "You chose " << DataStructureFactory::getStructName(structure_index) << '\n';

    DataStructure* ds = DataStructureFactory::getDataStructure(structure_index);
    std::cout << "Type a series of spaced out integers" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    std::vector<int> values = utils::parseInputValues(input);

    // Populating data structure
    ds->build(values);

    // Displaying data structure
    ds->display();

    std::cin.get();
    return 0;
}
