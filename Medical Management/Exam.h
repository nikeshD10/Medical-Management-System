#pragma once
#include <iostream>
#include "Service.h"
using namespace std;

class Exam :public Service {
public:
    Exam(long, string, string, int);
    bool operator<(const Exam& a) const;
    int getExamCost() const;
    string get_typology() const;
    void displayExam() const;

private:
    string typology;
};