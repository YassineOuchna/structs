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
    std::string dsName = DataStructureFactory::getStructName(structure_index);
    std::cout << "Type the size of your desired random instance" << std::endl;

    size_t s;
    std::cin >> s;
    std::cin.ignore();
    std::vector<int> values = utils::generateRandomInstance(s);

    // Populating data structure
    std::cout << "Populating " << dsName  << std::endl;
    ds->build(values);


    std::cout << "Different sorting algorithms on " << dsName << std::endl;
    ds->sort();

    std::cin.get();
    return 0;
}
