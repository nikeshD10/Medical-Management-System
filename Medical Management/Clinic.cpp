#include "Clinic.h"

Clinic::Clinic() {
    clinicName = "blank";
    patientID = 1;
    appointmentID = 1000;
}

Clinic::Clinic(string nameOfClinic, int p_id_to_start_from, long app_id_to_start_form) {
    clinicName = nameOfClinic;
    patientID = p_id_to_start_from;
    appointmentID = app_id_to_start_form;
}

bool Clinic::operator<(const Clinic& a) const {
    return clinicName < a.clinicName;
}

bool Clinic::registerPatient(string nameOfPatience) {
    Patient patient(patientID, nameOfPatience);
    bool successfully_inserted = patients.insert(patient);
    if (successfully_inserted) {
        patient.print_id();
        patientID++;
        return successfully_inserted;
    }
    else {
        cout << "\nSystem isn't able to insert the patient " << nameOfPatience << endl;
        return false;
    }
}

bool Clinic::registerAppointment(int patient_id, string diagonis, string dateOfAppointment, int cost) {
    Patient* patient = findPatient(patient_id);
    if (patient != NULL) {
        Appointment appointment(appointmentID, patient_id, diagonis, dateOfAppointment, cost);
        bool appointmentInserted = appointments.insert(appointment);
        if (appointmentInserted) {
            appointment.print();
            appointmentID++;
            return appointmentInserted;
        }
        else {
            cout << "\nSorry there is an error to create an appointment" << endl;
            return false;
        }
    }
    else {
        cout << "\nSorry the patient with ID: " << patient_id << " doesn't exitst!!!" << endl;
        return false;
    }
}

void Clinic::addExamToAppointment(long app_id, string typology, string date, int cost) {
    Appointment* appointment = findappointment(app_id);
    if (appointment != NULL) {
        appointment->takeExam(app_id, typology, date, cost);
    }
    else {
        cout << "\nSorry the appointment with ID: " << app_id << " doesn't exist!!" << endl;
    }
}

Appointment* Clinic::findappointment(long app_id) {
    Appointment appointment(app_id, 0, "", "", 0);
    return appointments.find(appointment);
}

Patient* Clinic::findPatient(int patient_ID) {
    Patient patient(patient_ID, "");
    return patients.find(patient);
}

int Clinic::get_total_amount_for_appointments(long app_id) {
    int total_amount_for_appointment = 0;
    Appointment* appointment = findappointment(app_id);
    total_amount_for_appointment += appointment->get_appointment_cost();
    total_amount_for_appointment += appointment->get_total_exam_cost();
    return total_amount_for_appointment;
}

int Clinic::get_total_amount(int patient_id) {
    int total_amount = 0;
    Colecao<Appointment>::iterator it;
    for (it = appointments.begin(); it != appointments.end(); it++) {
        Appointment appointment = (*it);
        if (appointment.get_patient_id() == patient_id) {
            long app_id = appointment.getServiceID();
            total_amount += get_total_amount_for_appointments(app_id);
        }
    }
    return total_amount;
}

int Clinic::get_num_of_appointments_of_patient(int patient_id) {
    int num_of_app_for_patient = 0;
    Patient* patient = findPatient(patient_id);
    if (patient != NULL) {
        Colecao<Appointment>::iterator it;
        for (it = appointments.begin(); it != appointments.end(); it++) {
            Appointment appointment = (*it);
            if (appointment.get_patient_id() == patient_id) {
                num_of_app_for_patient++;
            }
        }
        return num_of_app_for_patient;
    }
    else {
        return 0;
    }
}

int Clinic::get_num_of_patient_registered() {
    return patients.size();
}


void Clinic::display_all_patient_registered() {
    int num_of_patient = get_num_of_patient_registered();
    cout << "============== ******** ================" << endl;
    cout << "Number of patient registered : " << num_of_patient << endl;
    Colecao<Patient>::iterator it;
    for (it = patients.begin(); it != patients.end(); it++) {
        Patient patient = (*it);
        patient.displayPatientInfo();
    }
}

void Clinic::display_all_exams_of_app(long app_id) {
    Appointment* appointment = findappointment(app_id);
    int num_of_exams = appointment->total_num_of_exams();
    cout << "============== ******** ================" << endl;
    cout << "Number of exam taken : " << num_of_exams << endl;
    appointment->display_exams_for_app();
}

void Clinic::display_total_cost_of_appointment(int cost) {
    cout << "\n--------------------------" << endl;
    cout << "Total Cost\t:\t" << cost << endl;
}

void Clinic::display_total_overall_cost_of_patient(int patient_id) {
    cout << "\n**************************************************\n";
    cout << "Total Overall Cost for patient with ID : " << patient_id << " is " << get_total_amount(patient_id) << endl;
    cout << "**************************************************\n";
}

void Clinic::displayPatientInfo(int patient_id, long app_id) {
    cout << "\n***********************     PATIENT INFORMATION       ***********************\n\n";
    Patient* patient = findPatient(patient_id);
    if (patient != NULL) {
        patient->displayPatientInfo();
        Appointment* appointment = findappointment(app_id);
        if (appointment != NULL) {
            appointment->displayAppointment();
            appointment->display_exams_for_app();
            int total_cost_for_app = get_total_amount_for_appointments(app_id);
            display_total_cost_of_appointment(total_cost_for_app);
            cout << "\n\n***********************     Thank you !!!     *******************************\n\n";
        }
        else {
            cout << "\nAppointment with ID: " << app_id << " doesn't exist" << endl;
        }
    }
    else {
        cout << "\nPatient with ID: " << patient_id << " doesn't exist" << endl;
    }
}

void Clinic::display_all_appointment(int patient_id) {
    Patient* patient = findPatient(patient_id);
    if (patient != NULL) {
        int num_of_app = get_num_of_appointments_of_patient(patient_id);
        cout << "Number of the Appointment : " << num_of_app << endl;
        Colecao<Appointment>::iterator it;
        for (it = appointments.begin(); it != appointments.end(); it++) {
            cout << "\n================== **** ===================\n\n";
            Appointment appointment = (*it);
            appointment.displayAppointment();
        }
    }
}

void Clinic::setNameOfPatient(int id, string name) {
    Patient* patient = findPatient(id);
    if (patient != NULL) {
        patient->SetName(name);
    }
    else {
        cout << "\nSorry the Patient with ID : " << id << " doesn't exist!!!" << endl;
    }
}

void Clinic::removeAppointment_by_id(long app_id) {
    Appointment* appointment = findappointment(app_id);
    if (appointment != NULL) {
        appointments.erase(*appointment);
        cout << "\nSuccessfully deleted the appointment with ID: " << app_id << endl;
    }
    else {
        cout << "\nSorry the appointment doesn't exist !!!" << endl;
    }
}

void Clinic::deletePatient_by_id(int patient_id) {
    Patient* patient = findPatient(patient_id);
    if (patient != NULL) {
        Colecao<Appointment>::iterator  it;
        for (it = appointments.begin(); it != appointments.end(); it++) {
            Appointment appointment = (*it);
            if (appointment.get_patient_id() == patient_id) {
                removeAppointment_by_id(appointment.getServiceID());
            }
        }
        patients.erase(*patient);
        cout << "\nSuccessfully deleted the patient with ID : " << patient_id << endl;
    }
    else {
        cout << "\nSorry the patient with ID : " << patient_id << " doesn't exist!!! " << endl;
    }

}

void Clinic::removeExam_of_app_by_id(long app_id, long e_id) {
    Appointment* appointment = findappointment(app_id);
    if (appointment != NULL) {
        appointment->removeExam(e_id);
    }
    else {
        cout << "\nSorry the Exam of Appointment you want to dlt doesn't exist!!!\n" << endl;
    }
}

