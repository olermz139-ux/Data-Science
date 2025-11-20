#include "stability-test/contactsList.h"
#include "Turbine.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "heapSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"

using namespace std;


void stabilityTest();

int main() {
    ofstream outFile; //File to save all values of read and write
    vector<Turbine> turbines;

   outFile.open("../outfile.csv");
    for (int i=1000; i>= 100; i-= 100) { //Loop to resize turbine vector from 100-1000
        //Read and write have to be reset to zero each time the vector is rized
        int readsBub = 0, writesBub= 0;
        int readsIns = 0, writesIns = 0;
        int readsHeap = 0, writesHeap = 0;
        int readsMerg = 0, writesMerg = 0;
        int readsSel = 0, writesSel = 0;

        if(getDataFromFile(turbines)) { //read csv file of data
            turbines.resize(i);
            outFile << "For size: " << "," << i << endl;
            //unstable algorithm reads
            outFile << "HEAP SORT"  << endl;
            heapSort(turbines, readsHeap , writesHeap);
            outFile << "Reads" << "," << readsHeap << endl;
            outFile << "Writes" << "," << writesHeap << endl;

            outFile << "SELECTION SORT" << endl;
            selectionSort(turbines, readsSel , writesSel);
            outFile << "Reads" << "," << readsSel << endl;
            outFile << "Writes" << "," << writesSel << endl;

            //stable algorithm reads
            outFile << "MERGE SORT" << endl;
            mergeSort(turbines, readsMerg , writesMerg);
            outFile << "Reads" << "," << readsMerg << endl;
            outFile << "Writes" << "," << writesMerg << endl;

            outFile << "BUBBLE SORT" << endl;
            bubbleSort(turbines, readsBub , writesBub);
            outFile << "Reads" << "," << readsBub << endl;
            outFile << "Writes" << "," << writesBub << endl;

            outFile << "INSERTION SORT" << endl;
            insertionSort(turbines, readsIns , writesIns);
            outFile << "Reads" << "," << readsIns << endl;
            outFile << "Writes" << "," << writesIns << endl;



            outFile << "" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    stabilityTest();
    outFile.close();
    return 0;
 }

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

//Method of Sort and print was changed to set a and b equal to zero every time the method is called
    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    cout << endl << "Instertion Sort" << endl;
    people.sortAndPrint(insertionSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    cout << endl << "Merge Sort" << endl;
    people.sortAndPrint(mergeSort<contact>);

    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort<contact>);
}