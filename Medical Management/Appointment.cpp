#include <iostream>
#include "Appointment.h"
using namespace std;

Appointment::Appointment(long appId, int patientID, string appText, string dateApp, int cost) : Service(appId, dateApp, cost) {
    diagonis = appText;
    patient_id = patientID;
}

bool Appointment::operator<(const Appointment& a) const {
    return service_id < a.service_id;
}

bool Appointment::takeExam(long app_id, string typology, string date, int cost) {
    int size_of_exams = total_num_of_exams();
    app_id += size_of_exams;
    Exam exam(app_id, typology, date, cost);
    bool examInserted = exams.insert(exam);
    if (examInserted) {
        cout << "Exam Inserted \t: " << "Yes" << endl;
        return examInserted;
    }
    else {
        cout << "Exam Inserted \t: " << "No" << endl;
        return false;
    }
}

int Appointment::get_appointment_cost() {
    return costOfService;
}

int Appointment::get_patient_id() {
    return patient_id;
}

int Appointment::get_total_exam_cost() {
    Colecao<Exam>::iterator it;
    int total_exam_cost = 0;
    for (it = exams.begin(); it != exams.end(); it++) {
        Exam exam = (*it);
        total_exam_cost += exam.getExamCost();
    }
    return total_exam_cost;
}

int Appointment::total_num_of_exams() {
    return exams.size();
}

void Appointment::displayAppointment() const {
    cout << "|      Appointment \t\t\t: " << diagonis << endl;
    cout << "|      App ID      \t\t\t: " << diagonis << endl;
    cout << "|      Cost of App \t\t\t: " << costOfService << endl;
    cout << "|      Date of App \t\t\t: " << service_date << endl;
}

void Appointment::display_exams_for_app() {
    cout << "\n---------------------------------------------------  Exams  -------------------------------------------------\n" << endl;
    cout << "\t\t Typology\t\t\t\t\t\t\t\tCost\t\t\t\t\t\tDate\t\t\t\t\t\tID\n" << endl;
    Colecao<Exam>::iterator ext;
    for (ext = exams.begin(); ext != exams.end(); ext++) {
        Exam temp_exam = (*ext);
        temp_exam.displayExam();
    }
}

void Appointment::print() {
    cout << "App ID \t\t\t: " << service_id << endl;
}

void Appointment::removeExam(long e_id) {
    Exam exam(e_id, "", "", 0);
    exams.erase(exam);
    cout << "\nExam with ID : " << e_id << " has been successfully deleted.\n" << endl;
}