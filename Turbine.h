//
// Created by zen_1 on 1/27/2024.
// CS 2240
//

#ifndef PROJECT1_TURBINE_H
#define PROJECT1_TURBINE_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl, std::ifstream, std::left, std::ostream, std::right, std::setw, std::string, std::vector;
/*
    Class that represents measurements reading made on a wind turbine
*/

class Turbine {
private:
    float activePw, windSpeed, theoreticalPw, windDir;
    int sampleID;
    string date, time;

public:
    // Constructors
    Turbine() {
        activePw = windSpeed = theoreticalPw = windDir = -1;
        sampleID = 0;
        date = "Unknown";
        time = "Not available";
    }

    Turbine(int sampleID, string date, string time, float activePw, float windSpeed, float theoreticalPw,
            float windDir) {
        this->sampleID = sampleID;
        this->date = date;
        this->time = time;
        this->activePw = activePw;
        this->windSpeed = windSpeed;
        this->theoreticalPw = theoreticalPw;
        this->windDir = windDir;
    }

    // Getters
    int getSampleID() const {
        return sampleID;
    }

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    float getActivePw() const {
        return activePw;
    }

    float getWindSpeed() const {
        return windSpeed;
    }

    float getTheoreticalPw() const {
        return theoreticalPw;
    }

    float getWindDir() const {
        return windDir;
    }

    // Setters
    void setSampleID(int sampleID) {
        this->sampleID = sampleID;
    }

    void setDate(string date) {
        this->date = date;
    }

    void setTime(string time) {
        this->time = time;
    }

    void setActivePw(float activePw) {
        this->activePw = activePw;
    }

    void setWindSpeed(float windSpeed) {
        this->windSpeed = windSpeed;
    }

    void setTheoreticalPw(float theoreticalPw) {
        this->theoreticalPw = theoreticalPw;
    }

    void setWindDir(float windDir) {
        this->windDir = windDir;
    }

    // Overloaded Operator
    friend ostream &operator<<(ostream &outs, const Turbine &lec) {
        outs << left << setw(10) << lec.sampleID;
        outs << left << setw(15) << lec.date;
        outs << left << setw(5) << lec.time;
        outs << right << setw(15) << lec.activePw;
        outs << right << setw(15) << lec.windSpeed;
        outs << right << setw(15) << lec.theoreticalPw;
        outs << right << setw(15) << lec.windDir;
        return outs;
    }

    /**
 * Overload < operator for object comparison
 */
    friend bool operator < (const Turbine& lhs, const Turbine& rhs) {
        return lhs.getSampleID() < rhs.getSampleID();
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const Turbine& lhs, const Turbine& rhs) {
        return lhs.getSampleID() > rhs.getSampleID();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Turbine& lhs, const Turbine& rhs) {
        return lhs.getSampleID() <= rhs.getSampleID();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Turbine& lhs, const Turbine& rhs) {
        return lhs.getSampleID() >= rhs.getSampleID();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Turbine& lhs, const Turbine& rhs) {
        return lhs.getSampleID() == rhs.getSampleID();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const Turbine& lhs, const Turbine& rhs) {
        return lhs.getSampleID() != rhs.getSampleID();
    }
};
    /*
        GLOBAL FUNCTION
        Reading data from file
    */
    bool getDataFromFile(vector<Turbine> &turbines) {
        ifstream fileIn;
        fileIn.open("../WindTurbine-DataSet.csv");

        if(fileIn) {
            string header;
            getline(fileIn, header);

            //Variables to be read
            int sampleID = 0;
            string date = "January-1", time = "0:00";
            float activePw = 0, windSpeed = 0, theoreticalPw = 0, windDir = 0;
            char comma;

            while(fileIn) {
                //Read sample ID
                fileIn >> sampleID;
                fileIn >> comma;
                //Read date
                getline(fileIn, date, ',');
                //Read time
                getline(fileIn, time, ',');
                //Read active power
                fileIn >> activePw;
                fileIn >> comma;
                //Read wind speed
                fileIn >> windSpeed;
                fileIn >> comma;
                //Read theoretical power
                fileIn >> theoreticalPw;
                fileIn >> comma;
                //Read wind direction
                fileIn >> windDir;

                turbines.push_back(Turbine(sampleID, date, time, activePw, windSpeed, theoreticalPw, windDir));
            }
        }else{
          cout << "Error opening file" << endl;
          return false;
        }
        fileIn.close();
        return true;
    }
    /*
        GLOBAL FUNCTION
        Calculate the average value of the actual power output
    */
    float meanActivePw(vector<Turbine> &turbines){
        float totActPw = 0;
        for (int i = 0; i < turbines.size()-1; ++i) {
            totActPw += turbines[i].getActivePw();
        }
       return totActPw/(turbines.size()-1);
    }
   /*
        GLOBAL FUNCTION
        Calculate the average value of the theoretical power output
    */
    float meanTheoPw(vector<Turbine> &turbines) {
        float totTheoPw = 0;
        for (int i = 0; i < turbines.size() - 1; ++i) {
            totTheoPw += turbines[i].getTheoreticalPw();
        }

        return totTheoPw / (turbines.size() - 1);
    }
#endif //PROJECT1_TURBINE_H