#pragma once
#include <iostream>
#include "Exam.h"
using namespace std;

class Appointment :public Service {
public:
    Appointment(long, int, string, string, int);
    bool operator<(const Appointment& a) const;

    bool takeExam(long, string, string, int);
    int get_appointment_cost();
    int get_patient_id();
    int get_total_exam_cost();
    int total_num_of_exams();

    void displayAppointment() const;
    void display_exams_for_app();
    void print();
    void removeExam(long);
private:
    string diagonis;
    Colecao<Exam> exams;
};