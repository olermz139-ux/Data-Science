#include "Turbine.h"
#include <vector>
#include <iostream>
using namespace std;


int main() {
    vector<Turbine> turbines;
    float meanAPw, meanTPw, percentage;

   if(getDataFromFile(turbines)) {
       // Printing table
       for (int i = 0; i < turbines.size()-1; ++i) {
           cout << turbines[i] << endl;
       }
       //Operation call function
       meanAPw = meanActivePw(turbines);
       meanTPw = meanTheoPw(turbines);
       percentage = (meanAPw/meanTPw)* 100;

       //Printing operations
       cout << "" << endl;
       cout << "The mean active power output is: " << meanAPw << endl;
       cout << "The mean theoretical power output is: " << meanTPw << endl;
       cout << "The mean active power output is " << percentage << "% of the theoretical power output." << endl;
   }
return 0;
}