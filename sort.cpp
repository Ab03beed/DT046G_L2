//
// Created by abdah on 2024-01-27.
//

#include <algorithm>
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
            }
        }
        if(minIndexJ != i) std::swap(vec[minIndexJ], vec[i]); //Swapping the values.
    }
}

void sort::quickSortRP(std::vector<int> &vec, int firstIdx, int lastIdx)
{
    if(firstIdx<lastIdx)
    {
        // pi is the partition return index of pivot
        int pi = partitionRP(vec, firstIdx, lastIdx);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSortRP(vec,firstIdx,pi-1);
        quickSortRP(vec,pi+1,lastIdx);
    }
}

int sort::partitionRP(std::vector<int> &vec, int firstIdx, int lastIdx){
    //Partition step
    int pivot = vec[lastIdx];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i=(firstIdx-1);

    for(int j = firstIdx; j < lastIdx; j++)
    {
        //If current element is smaller than the pivot
        if(vec[j]<pivot)
        {
            //Increment index of smaller element
            i++;
            std::swap(vec[i],vec[j]);
        }
    }
    std::swap(vec[i+1],vec[lastIdx]);
    return (i+1);
}


void sort::quicksortMOT(std::vector<int> &vec, int firstIdx, int lastIdx) {
    if (firstIdx >= lastIdx)
        return;

    // Välj pivot som medianen av vänster, mitten och höger element
    int pivot = MOT(vec, firstIdx, lastIdx);
    // Partitionera enligt Hoares metod
    int new_pivot = partitionMOT(vec, firstIdx, lastIdx, pivot);
    // Rekursivt sortera vänster och höger del av partitionen
    quicksortMOT(vec, firstIdx, new_pivot - 1);
    quicksortMOT(vec, new_pivot, lastIdx);
}

int sort::MOT(std::vector<int> &vec, int firstIdx, int lastIdx) {
    int mid = firstIdx + (lastIdx - firstIdx) / 2;
    if (vec[firstIdx] > vec[mid])
        std::swap(vec[firstIdx], vec[mid]);
    if (vec[mid] > vec[lastIdx])
        std::swap(vec[mid], vec[lastIdx]);
    if (vec[firstIdx] > vec[mid])
        std::swap(vec[firstIdx], vec[mid]);
    return vec[mid];
}

int sort::partitionMOT(std::vector<int> &vec, int firstIdx, int lastIdx, int pivot) {
    //int i = left;
    //int j = right;
    while (firstIdx <= lastIdx) {
        while (vec[firstIdx] < pivot) {
            firstIdx++;
        }
        while (vec[lastIdx] > pivot) {
            lastIdx--;
        }
        if (firstIdx <= lastIdx) {
            std::swap(vec[firstIdx], vec[lastIdx]);
            firstIdx++;
            lastIdx--;
        }
    }
    return firstIdx;
}

double sort::standardSort(std::vector<int> &vec) {
    std::sort(vec.begin(),vec.end());
}


bool sort::isSorted(std::vector<int>& vec){

    for (int i = 0; i < vec.size()-1; ++i) {
        if(vec[i] > vec[i+1])
            return false;
    }
    return true;
}