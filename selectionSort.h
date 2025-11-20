#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "sorting-algorithms/printVec.h"

template<typename Comparable>
vector<Comparable> selectionSort(vector<Comparable> vec, int& reads, int& writes) {
    int swapIndex, i, minIndex;
    Comparable temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            if (vec[i] < vec[minIndex]) {
                // We have a new minimum
                minIndex = i;
                reads += 2;
            }
        }
        // Swap min value into swapIndex spot in vector
        temp = vec[swapIndex];
        vec[swapIndex] = vec[minIndex];
        vec[minIndex] = temp;

        reads += 3;
        writes += 3;
        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    cout << "Selection Sort" << endl;
    cout << "Reads: " << reads << endl;
    cout << "Writes: " << writes << endl;
    return vec;
}

#endif
