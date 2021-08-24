#pragma once
#include <iostream>

#include "Patient.h"
using namespace std;

class Clinic {
    string clinicName;
    int patientID;
    long appointmentID;
    Colecao<Patient> patients;
    Colecao<Appointment> appointments;
public:
    Clinic();
    Clinic(string, int, long);
    bool operator<(const Clinic& a) const;
    bool registerPatient(string);
    bool registerAppointment(int, string, string, int);
    void addExamToAppointment(long, string, string, int cost);

    Appointment* findappointment(long);
    Patient* findPatient(int);


    int get_total_amount_for_appointments(long);
    int get_total_amount(int);
    int get_num_of_appointments_of_patient(int);
    int get_num_of_patient_registered();

    void display_all_patient_registered();
    void display_all_exams_of_app(long);
    void display_total_cost_of_appointment(int);
    void display_total_overall_cost_of_patient(int);
    void displayPatientInfo(int, long);
    void display_all_appointment(int);


    void setNameOfPatient(int id, string name);
    void removeAppointment_by_id(long);
    void deletePatient_by_id(int);
    void removeExam_of_app_by_id(long, long);
};