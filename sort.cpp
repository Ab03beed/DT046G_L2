//
// Created by abdah on 2024-01-27.
//

#include "sort.h"

//Worst case Time complexity O(N^2), efficient for data sets that are already substantially sorted
void sort::insertion(std::vector<int> &vec, size_t loopCount) {

    int prevElement = 0, currentElement = 0;

    for (int i = 1; i < vec.size(); ++i) {
        currentElement = vec[i];
        prevElement = i-1;

        while(prevElement >= 0 && currentElement < vec[prevElement]){ //Swapping elements when the Left element is grater than the Right element.
            std::swap(vec[prevElement+1], vec[prevElement]);
            prevElement--;
        }
    }
}


//Worst case Time complexity O(N^2)
void sort::selection(std::vector<int>& vec, size_t loopCount) {

    int minIndexJ;

    for (int i = 0; i < vec.size()-1; ++i) {
        minIndexJ = i; //Assume the first element is the smallest.
        for (int j = (i+1); j < vec.size(); ++j) {
            if(vec[j] < vec[minIndexJ]){ //Change the index of the min value if founded.
                minIndexJ = j;
                continue;
            }
        }
        if(minIndexJ != i) std::swap(vec[minIndexJ], vec[i]); //Swapping the values.
    }
}


void sort::quickSortRpivot(std::vector<int> &vec, size_t startIndex, size_t endIndex){


    //Partition step
    int pivot = vec[endIndex];
    std::cout << "pivot: " << pivot << '\n';

    int i = startIndex;

    for (int j = i; j < endIndex-1; ++j) {
        if(vec[j] <= pivot){
            std::swap(vec[i], vec[j]);
            i++;
        }
    }
    std::swap(vec[i], vec[endIndex]);


    for (int e: vec) {
            std::cout << e << ' ';
    }


}





bool sort::isSorted(std::vector<int>& vec){

    for (int i = 0; i < vec.size()-1; ++i) {
        if(vec[i] > vec[i+1])
            return false;
    }
    return true;
}