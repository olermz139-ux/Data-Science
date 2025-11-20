#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "QuadraticProbing.h"
#include "Turbine.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//Method one for obtaining key using sample id
string getKey1(Turbine turbine){
    return to_string(turbine.getSampleID());
}

//Method one for obtaining key using sample id plus the theoretical power which has more variability than other attributes
string getKey2(Turbine turbine){
    return to_string(turbine.getSampleID() + turbine.getTheoreticalPw());
}

int main() {
    fstream outfile; //File to save output
    vector<Turbine> turbines;

    //Declaring all table sizes
    const unsigned long TABLE_SIZE1 = 4000; // 184 more spaces (slightly bigger)
    const unsigned long TABLE_SIZE2 = 7632; //double the size of elements in vector
    const unsigned long TABLE_SIZE3 = 8000; // slightly bigger than half of the table
    const unsigned long TABLE_SIZE4 = 10000; // 2368  more spaces
    const unsigned long TABLE_SIZE5 = 12000; // close to 3 times the amount of elements in vector

    outfile.open("../OutFile.csv");

    getDataFromFile(turbines); //getting all items in file on vector

    //Declaring all table objects
    //Separate Chaining
    SeparateChaining<Turbine> SCtable1 (TABLE_SIZE1);
    SeparateChaining<Turbine> SCtable2 (TABLE_SIZE2);
    SeparateChaining<Turbine> SCtable3 (TABLE_SIZE3);
    SeparateChaining<Turbine> SCtable4 (TABLE_SIZE4);
    SeparateChaining<Turbine> SCtable5 (TABLE_SIZE5);
    SeparateChaining<Turbine> SCtable6 (TABLE_SIZE1);
    SeparateChaining<Turbine> SCtable7 (TABLE_SIZE2);
    SeparateChaining<Turbine> SCtable8 (TABLE_SIZE3);
    SeparateChaining<Turbine> SCtable9 (TABLE_SIZE4);
    SeparateChaining<Turbine> SCtable10 (TABLE_SIZE5);
    //Linear Probing
    LinearProbing<Turbine> LPtable1(TABLE_SIZE1);
    LinearProbing<Turbine> LPtable2(TABLE_SIZE2);
    LinearProbing<Turbine> LPtable3(TABLE_SIZE3);
    LinearProbing<Turbine> LPtable4(TABLE_SIZE4);
    LinearProbing<Turbine> LPtable5(TABLE_SIZE5);
    LinearProbing<Turbine> LPtable6(TABLE_SIZE1);
    LinearProbing<Turbine> LPtable7(TABLE_SIZE2);
    LinearProbing<Turbine> LPtable8(TABLE_SIZE3);
    LinearProbing<Turbine> LPtable9(TABLE_SIZE4);
    LinearProbing<Turbine> LPtable10(TABLE_SIZE5);
    //Quadratic Probing
    QuadraticProbing<Turbine> QPtable1(TABLE_SIZE1);
    QuadraticProbing<Turbine> QPtable2(TABLE_SIZE2);
    QuadraticProbing<Turbine> QPtable3(TABLE_SIZE3);
    QuadraticProbing<Turbine> QPtable4(TABLE_SIZE4);
    QuadraticProbing<Turbine> QPtable5(TABLE_SIZE5);
    QuadraticProbing<Turbine> QPtable6(TABLE_SIZE1);
    QuadraticProbing<Turbine> QPtable7(TABLE_SIZE2);
    QuadraticProbing<Turbine> QPtable8(TABLE_SIZE3);
    QuadraticProbing<Turbine> QPtable9(TABLE_SIZE4);
    QuadraticProbing<Turbine> QPtable10(TABLE_SIZE5);

    //Loop to insert all objects in tables
    outfile << "Key" << "," << "Hashing"<< ","<< "Indice" << "," << "Collisions TS1"  << "," << "Collisions TS2" << "," "Collisions TS3" << "," << "Collisions TS4" << "," <<  "Collisions TS5"<< endl;
    for (int i = 0; i < turbines.size(); ++i) {
        //KEY ONE

        //SEPARATE CHAINING
        SCtable1.insert(getKey1(turbines[i]), turbines[i]);
        SCtable2.insert(getKey1(turbines[i]), turbines[i]);
        SCtable3.insert(getKey1(turbines[i]), turbines[i]);
        SCtable4.insert(getKey1(turbines[i]), turbines[i]);
        SCtable5.insert(getKey1(turbines[i]), turbines[i]);
        //LINEAR PROBING
        LPtable1.insert(getKey1(turbines[i]), turbines[i]);
        LPtable2.insert(getKey1(turbines[i]), turbines[i]);
        LPtable3.insert(getKey1(turbines[i]), turbines[i]);
        LPtable4.insert(getKey1(turbines[i]), turbines[i]);
        LPtable5.insert(getKey1(turbines[i]), turbines[i]);
        //QUADRATIC PROBING
        QPtable1.insert(getKey1(turbines[i]), turbines[i]);
        QPtable2.insert(getKey1(turbines[i]), turbines[i]);
        QPtable3.insert(getKey1(turbines[i]), turbines[i]);
        QPtable4.insert(getKey1(turbines[i]), turbines[i]);
        QPtable5.insert(getKey1(turbines[i]), turbines[i]);

        //Writing results in output file
        outfile << "1" << "," << "SC" << "," << i << "," << SCtable1.getCollisions() << "," << SCtable2.getCollisions()
                << "," << SCtable3.getCollisions() << "," << SCtable4.getCollisions() << "," << SCtable5.getCollisions()
                << endl;
        outfile << "1" << "," << "LP" << "," << i << "," << LPtable1.getCollisions() << "," << LPtable2.getCollisions()
                << "," << LPtable3.getCollisions() << "," << LPtable4.getCollisions() << "," << LPtable5.getCollisions()
                << endl;
        outfile << "1" << "," << "QP" << "," << i << "," << QPtable1.getCollisions() << "," << QPtable2.getCollisions()
                << "," << QPtable3.getCollisions() << "," << QPtable4.getCollisions() << "," << QPtable5.getCollisions()
                << endl;
    }
    outfile << "" << endl;
    for (int i = 0; i < turbines.size(); ++i){
        //KEY TWO

        //SEPARATE CHAINING
        SCtable6.insert(getKey2(turbines[i]), turbines[i]);
        SCtable7.insert(getKey2(turbines[i]), turbines[i]);
        SCtable8.insert(getKey2(turbines[i]), turbines[i]);
        SCtable9.insert(getKey2(turbines[i]), turbines[i]);
        SCtable10.insert(getKey2(turbines[i]), turbines[i]);
        //LINEAR PROBING
        LPtable6.insert(getKey2(turbines[i]), turbines[i]);
        LPtable7.insert(getKey2(turbines[i]), turbines[i]);
        LPtable8.insert(getKey2(turbines[i]), turbines[i]);
        LPtable9.insert(getKey2(turbines[i]), turbines[i]);
        LPtable10.insert(getKey2(turbines[i]), turbines[i]);
        //QUADRATIC PROBING
        QPtable6.insert(getKey2(turbines[i]), turbines[i]);
        QPtable7.insert(getKey2(turbines[i]), turbines[i]);
        QPtable8.insert(getKey2(turbines[i]), turbines[i]);
        QPtable9.insert(getKey2(turbines[i]), turbines[i]);
        QPtable10.insert(getKey2(turbines[i]), turbines[i]);

        //Writing collisions in output file
        outfile << "2" << "," << "SC"<< ","<< i << "," << SCtable6.getCollisions() << "," << SCtable7.getCollisions()<< "," << SCtable8.getCollisions() << "," << SCtable9.getCollisions()<< "," << SCtable10.getCollisions() << endl;
        outfile << "2" << "," << "LP"<< ","<< i << "," << LPtable6.getCollisions() << "," << LPtable7.getCollisions()<< "," << LPtable8.getCollisions() << "," << LPtable9.getCollisions()<< "," << LPtable10.getCollisions() << endl;
        outfile << "2" << "," << "QP"<< ","<< i << "," << QPtable6.getCollisions() << "," << QPtable7.getCollisions()<< "," << QPtable8.getCollisions() << "," << QPtable9.getCollisions()<< "," << QPtable10.getCollisions() << endl;
    }

    //Printing sizes of original table to see if it rehashed for both open adressing
    outfile << "" << endl;
    outfile << "Method" << "," << "Table Size Original" << "," << "Table Size After Adding Objects" << endl,
    outfile << "LP" << "," << TABLE_SIZE1 << "," << LPtable1.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE2 << "," << LPtable2.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE3 << "," << LPtable3.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE4 << "," << LPtable4.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE5 << "," << LPtable5.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE1 << "," << LPtable6.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE2 << "," << LPtable7.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE3 << "," << LPtable8.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE4 << "," << LPtable9.getTableSize()<< endl;
    outfile << "LP" << "," << TABLE_SIZE5 << "," << LPtable10.getTableSize()<< endl;
    outfile << "" << endl;
    outfile << "QP" << "," << TABLE_SIZE1 << "," << QPtable1.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE2 << "," << QPtable2.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE3 << "," << QPtable3.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE4 << "," << QPtable4.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE5 << "," << QPtable5.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE1 << "," << QPtable6.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE2 << "," << QPtable7.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE3 << "," << QPtable8.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE4 << "," << QPtable9.getTableSize()<< endl;
    outfile << "QP" << "," << TABLE_SIZE5 << "," << QPtable10.getTableSize()<< endl;

    outfile.close();
    return 0;
}