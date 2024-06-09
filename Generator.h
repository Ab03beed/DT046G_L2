//
// Created by abdah on 2024-01-28.
//

#include <vector>
#include <iostream>
#include <algorithm>

#ifndef DT046G_L2_GENERATOR_H
#define DT046G_L2_GENERATOR_H

#endif //DT046G_L2_GENERATOR_H

enum Types{ Constant = 1, Ascending = 2, Descending = 3, Random = 4 };

static void GenerateConstant(std::vector<int>& vec, size_t size){

    for(int i=0; i<size; i++){
        vec.push_back(10);
    }

}


static void GenerateAscending(std::vector<int>& vec, size_t size){

    for(int i=0; i<size; i++){
        vec.push_back(i);
    }

}
static void GenerateDescending(std::vector<int>& vec, size_t size){
    for(int i=size; i>0; i--){
        vec.push_back(i);
    }
}

static void GenerateRandom(std::vector<int>& vec, size_t size){

    srand(time(0));

    int num = 0;

    for(int i=0; i<size; i++){
        num = rand() % 100;
        vec.push_back(num);
    }

}