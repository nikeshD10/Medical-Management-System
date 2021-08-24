#include <iostream>
#include "Exam.h"
using namespace std;

Exam::Exam(long app_id, string examTypology, string date_of_exam, int cost) : Service(app_id, date_of_exam, cost) {
    typology = examTypology;
}

bool Exam::operator<(const Exam& a) const {
    return service_id < a.service_id;
}

int Exam::getExamCost() const {
    return costOfService;
}

string Exam::get_typology() const {
    return typology;
}

void Exam::displayExam() const {
    cout << "    \t\t" << this->typology << " \t\t\t\t\t\t\t\t " << this->costOfService << "\t\t\t\t\t\t" << this->service_date << "\t\t\t\t\t\t" << this->service_id << endl;
}

