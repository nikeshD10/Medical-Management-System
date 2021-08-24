#pragma once
#include <iostream>
#include "Colecao.h"
using namespace std;

class Service {
public:
    Service(long, string, int);
    bool operator<(const Service& a) const;
    int getServiceCost() const;
    long getServiceID() const;
    void displayCost() const;

protected:
    long service_id;
    string service_date;
    int costOfService;
    int patient_id;
};

