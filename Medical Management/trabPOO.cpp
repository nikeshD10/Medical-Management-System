#include <iostream>
#include "Clinic.h"
using namespace std;

int main() {
    Clinic clinic;
    clinic.registerPatient("X name");
    clinic.registerAppointment(1, "Diagnosis1", "Date1", 200);
    //    clinic.registerAppointment(1, "Diagnosis2", "Date2", 500);
    clinic.addExamToAppointment(1000, "Exam1", "Date3", 300);
    clinic.addExamToAppointment(1000, "Exam2", "Date4", 600);

    clinic.displayPatientInfo(1, 1000);
    clinic.setNameOfPatient(1, "John");
    clinic.displayPatientInfo(1, 1000);

    /*clinic.display_all_exams_of_app(1000);
    clinic.removeExam_of_app_by_id(1000, 1000);*/
    //    clinic.display_all_patient_registered();
    //    clinic.registerPatient("John");
    //    clinic.registerAppointment(2, "Broken back", "2021-5-28", 300);
    //    clinic.addExamToAppointment(1001, "X-ray", "2021-5-28", 300);

    //    clinic.display_all_appointment(1);
    //    clinic.displayPatientInfo(1, 1000);
    //    clinic.displayPatientInfo(2, 1001);
    //    clinic.display_total_overall_cost_of_patient(1);


    /*              Checking the delete method      */
    //    clinic.deletePatient_by_id(1);
    //    printf("\n\n\n\n");
    //    clinic.display_total_overall_cost_of_patient(1);

    return 0;
}
