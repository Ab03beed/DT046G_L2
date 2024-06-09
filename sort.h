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

    int partitionRP(std::vector<int> &vec, int low, int high);
    void quickSortRP(std::vector<int> &vec, int low, int high);

    int MOT(std::vector<int> &vec, int low, int high);
    void quicksortMOT(std::vector<int> &vec, int left, int right);
    int partitionMOT(std::vector<int> &vec, int left, int right, int pivot);
    double standardSort(std::vector<int> &vec);
    bool isSorted(std::vector<int> &vec);


private:
    std::vector<int> generate;

};


#endif //DT046G_L2_SORT_H
