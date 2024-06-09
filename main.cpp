#include <iostream>
#include <fstream>
#include <chrono>
#include <complex>

#include "Generator.h"
#include "sort.h"
double average_value(const std::vector<double> data);
double std_dev(const std::vector<double> data);


int main() {

    const int SIZE = 10000;
    const int REPETITIONS = 10;
    const int SAMPLES = 5;

    std::vector<int> data;
    std::vector<int> copy;
    std::vector<double> period(SAMPLES);

    std::string file[] = { "../SortingResult/SelectionSort/selectionSortRand.data",
                           "../SortingResult/SelectionSort/selectionSortConst.data",
                           "../SortingResult/SelectionSort/selectionSortInc.data",
                           "../SortingResult/SelectionSort/selectionSortDec.data",
                           "../SortingResult/InsertionSort/insertionSortRand.data",
                           "../SortingResult/InsertionSort/insertionSortConst.data",
                           "../SortingResult/InsertionSort/insertionSortInc.data",
                           "../SortingResult/InsertionSort/insertionSortDec.data" ,
                           "../SortingResult/QuickSortRP/quickSortRpRand.data",
                           "../SortingResult/QuickSortRP/quickSortRpConst.data",
                           "../SortingResult/QuickSortRP/quickSortRpInc.data",
                           "../SortingResult/QuickSortRP/quickSortRpDec.data",
                           "../SortingResult/QuickSortMOT/quickSortMotRand.data",
                           "../SortingResult/QuickSortMOT/quickSortMotConst.data",
                           "../SortingResult/QuickSortMOT/quickSortMotInc.data",
                           "../SortingResult/QuickSortMOT/quickSortMotDec.data",
                           "../SortingResult/StandardSort/standardSortRand.data",
                           "../SortingResult/StandardSort/standardSortConst.data",
                           "../SortingResult/StandardSort/standardSortInc.data",
                           "../SortingResult/StandardSort/standardSortDec.data" };

    sort s;

    std::ofstream os;

    os.open(file[16], std::ios::out);

    if (os.is_open())
    {
        os << "N\t" << "T[ms]\t" << "dev[ms]\t" << "Samples\n";
        std::cout << " N\t\t\t" << "  T[ms]\t\t\t  " << "dev[ms]\t\t" << "Samples\n";

        int increment = 0;
        for (int iter = 1; iter <= REPETITIONS; iter++){
            increment++;
            // for each iteration, enlarge the vector
            data.resize(SIZE * increment);

            GenerateRandom(data, data.size());
            //GenerateConstant(data, data.size());
            //GenerateAscending(data, data.size());
            //GenerateDescending(data, data.size());

            // perform x amount of samples within one iteration
            for (int i = 0; i < SAMPLES; i++)
            {
                // Copy dataset
                copy = data;
                // period[i]= S.insertion_sort_stl(copy);
                auto start = std::chrono::steady_clock::now();

                //s.selection(copy, 0);
                //s.insertionSort(copy ,0);
                //s.quickRP(copy,0,copy.size()-1);
                //s.quickMOT(copy,0,copy.size()-1);
                s.standardSort(copy);
                auto end = std::chrono::steady_clock::now();
                period.push_back(std::chrono::duration<double, std::milli>(end - start).count());

            }
            // write each data iteration to file
            os << SIZE * increment << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';

            std::cout << SIZE * increment << "\t\t  " << average_value(period) << "\t\t  " << std_dev(period) << "\t\t  " << SAMPLES << '\n';

        }
        os.close();
    }else{
        std::cout << "gg";
    }





    return 0;
}



double average_value(const std::vector<double> data) {

    double sum = 0;
    for (const auto& val : data) {
        sum += val;
    }
    return sum / data.size();
}

double std_dev(const std::vector<double> data) {
    double mean = average_value(data);
    double variance = 0;
    for (const auto& val : data) {
        variance += std::pow(val - mean, 2);
    }
    variance /= data.size() - 1;
    return std::sqrt(variance)/ std::sqrt(data.size());
}


