#pragma once
#include <iostream>
#include <string>
#include "Appointment.h"

using namespace std;

class Patient {
public:
    Patient(int, string);
    bool operator<(const Patient& p) const;
    void SetName(string);
    string getName();
    int getID();
    void displayPatientInfo();
    void print_id();
private:
    string name;
    int ID;
   
};
