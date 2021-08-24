#include <iostream>
#include "Service.h"
using namespace std;

Service::Service(long id, string date, int cost) {
    service_id = id;
    service_date = date;
    costOfService = cost;
}

bool Service::operator<(const Service& a) const {
    return service_id < a.service_id;
}

long Service::getServiceID() const {
    return service_id;
}

void Service::displayCost() const {
    cout << "The Service Cost is: " << costOfService << endl;
}