//
// Created by abdah on 2024-01-27.
//

#include <iostream>
#include <vector>


#ifndef DT046G_L2_SORT_H
#define DT046G_L2_SORT_H


class sort {
public:
    void insertion(std::vector<int> &vec, size_t loopCount);
    void selection(std::vector<int> &vec, size_t loopCount);
    void quickSortRpivot(std::vector<int> &vec, size_t start, size_t end);


    bool isSorted(std::vector<int> &vec);

private:
    std::vector<int> generate;

};


#endif //DT046G_L2_SORT_H
