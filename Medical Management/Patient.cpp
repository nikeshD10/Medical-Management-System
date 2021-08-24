#include <iostream>
#include "Patient.h"
using namespace std;


Patient::Patient(int patientID, string PatienceName) {
    ID = patientID;
    name = PatienceName;
}

bool Patient::operator<(const Patient& p) const {
    return ID < p.ID;
}

void Patient::SetName(string newName) {
    name = newName;
}

string Patient::getName() {
    return name;
}

int Patient::getID() {
    return ID;
}

void Patient::displayPatientInfo() {
    cout << "|      Name \t\t\t\t: " << name << endl;
    cout << "|      Id \t\t\t\t\t: " << ID << endl;
    cout << "\n";
}

void Patient::print_id() {
    cout << name << " ID\t\t: " << ID << endl;
}