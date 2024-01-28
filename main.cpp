#include <iostream>

#include "Generator.h"
#include "sort.h"

int main() {

    std::vector<int> randVec;


    GenerateRandom(randVec, 10);


    for (int e: randVec) {
        std::cout << e << ' ';
    }

    std::cout << "\n\n\n";

    sort s;

    s.quickSortRpivot(randVec, 0, randVec.size()-1);

    /*for (int e: randVec) {
        std::cout << e << ' ';
    }*/
    std::cout << "\n";

    std::cout << "isSorted(): " <<  s.isSorted(randVec) << '\n';


    return 0;
}
