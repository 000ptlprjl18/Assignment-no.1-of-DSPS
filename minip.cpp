#include <iostream>
#include <vector>
#include <string>
#include <map>

struct Patient {
    int id;
    std::string name;
    int age;
    std::string medicalHistory;
};

class PatientManagement {
    std::vector<Patient> patients;
public:
    void addPatient(int id, const std::string& name, int age, const std::string& medicalHistory) {
        patients.push_back({id, name, age, medicalHistory});
    }

    const std::vector<Patient>& getPatients() const {
        return patients;
    }

    void displayPatients() const {
        for (const auto& p : patients) {
            std::cout << "ID: " << p.id << ", Name: " << p.name 
                      << ", Age: " << p.age << ", Medical History: " << p.medicalHistory << std::endl;
        }
    }
};

struct Appointment {
    int patientId;
    std::string doctorName;
    std::string date;
    std::string time;
};

class AppointmentManagement {
    std::map<int, std::vector<Appointment>> appointments;
public:
    void scheduleAppointment(int patientId, const std::string& doctorName, 
                             const std::string& date, const std::string& time) {
        appointments[patientId].push_back({patientId, doctorName, date, time});
    }

    void displayAppointments() const {
        for (const auto& [id, appts] : appointments) {
            for (const auto& appt : appts) {
                std::cout << "Patient ID: " << appt.patientId << ", Doctor: " << appt.doctorName 
                          << ", Date: " << appt.date << ", Time: " << appt.time << std::endl;
            }
        }
    }
};

struct Staff {
    int id;
    std::string name;
    std::string role;
};

class StaffManagement {
    std::vector<Staff> staffMembers;
public:
    void addStaff(int id, const std::string& name, const std::string& role) {
        staffMembers.push_back({id, name, role});
    }

    void displayStaff() const {
        for (const auto& s : staffMembers) {
            std::cout << "ID: " << s.id << ", Name: " << s.name << ", Role: " << s.role << std::endl;
        }
    }
};

struct Room {
    int roomNumber;
    bool isOccupied;
    int patientId;
};

class RoomManagement {
    std::vector<Room> rooms;
public:
    void addRoom(int roomNumber) {
        rooms.push_back({roomNumber, false, -1});
    }

    void allocateRoom(int roomNumber, int patientId) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                room.isOccupied = true;
                room.patientId = patientId;
                break;
            }
        }
    }

    void displayRooms() const {
        for (const auto& room : rooms) {
            std::cout << "Room: " << room.roomNumber << ", Occupied: " << (room.isOccupied ? "Yes" : "No") 
                      << ", Patient ID: " << (room.isOccupied ? std::to_string(room.patientId) : "N/A") << std::endl;
        }
    }
};

struct Bill {
    int patientId;
    double amount;
};

class BillingSystem {
    std::vector<Bill> bills;
public:
    void generateBill(int patientId, double amount) {
        bills.push_back({patientId, amount});
    }

    void displayBills() const {
        for (const auto& bill : bills) {
            std::cout << "Patient ID: " << bill.patientId << ", Amount: $" << bill.amount << std::endl;
        }
    }
};

class SearchSystem {
public:
    void searchPatient(const std::vector<Patient>& patients, int id) const {
        for (const auto& p : patients) {
            if (p.id == id) {
                std::cout << "Found Patient - ID: " << p.id << ", Name: " << p.name << std::endl;
                return;
            }
        }
        std::cout << "Patient not found." << std::endl;
    }
};

class ReportGeneration {
public:
    void generateReport(const std::vector<Patient>& patients) const {
        for (const auto& p : patients) {
            std::cout << "Patient Report - ID: " << p.id << ", Name: " << p.name 
                      << ", Age: " << p.age << ", Medical History: " << p.medicalHistory << std::endl;
        }
    }
};

int main() {
    PatientManagement patientMgmt;
    AppointmentManagement appointmentMgmt;
    StaffManagement staffMgmt;
    RoomManagement roomMgmt;
    BillingSystem billing;
    SearchSystem search;
    ReportGeneration report;

    int choice;
    do {
        std::cout << "\nHospital Management System\n";
        std::cout << "1. Manage Patients\n";
        std::cout << "2. Schedule Appointment\n";
        std::cout << "3. Manage Staff\n";
        std::cout << "4. Manage Rooms\n";
        std::cout << "5. Generate Bill\n";
        std::cout << "6. Search Patient\n";
        std::cout << "7. Generate Report\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Flush input buffer before using getline
        std::cin.ignore();

        switch (choice) {
            case 1: {
                int id, age;
                std::string name, medicalHistory;
                std::cout << "Enter Patient ID: ";
                std::cin >> id;
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);  // Read name
                std::cout << "Enter Age: ";
                std::cin >> age;
                std::cout << "Enter Medical History: ";
                std::getline(std::cin, medicalHistory);  // Read medical history
                patientMgmt.addPatient(id, name, age, medicalHistory);
                break;
            }
            case 2: {
                int patientId;
                std::string doctorName, date, time;
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                std::cin.ignore();
                std::cout << "Enter Doctor Name: ";
                std::getline(std::cin, doctorName);
                std::cout << "Enter Date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                std::cout << "Enter Time (HH:MM): ";
                std::getline(std::cin, time);
                appointmentMgmt.scheduleAppointment(patientId, doctorName, date, time);
                break;
            }
            case 3: {
                int id;
                std::string name, role;
                std::cout << "Enter Staff ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Role: ";
                std::getline(std::cin, role);
                staffMgmt.addStaff(id, name, role);
                break;
            }
            case 4: {
                int roomNumber, patientId;
                std::cout << "Enter Room Number: ";
                std::cin >> roomNumber;
                std::cout << "Enter Patient ID to Allocate: ";
                std::cin >> patientId;
                roomMgmt.allocateRoom(roomNumber, patientId);
                break;
            }
            case 5: {
                int patientId;
                double amount;
                std::cout << "Enter Patient ID: ";
                std::cin >> patientId;
                std::cout << "Enter Amount: ";
                std::cin >> amount;
                billing.generateBill(patientId, amount);
                break;
            }
            case 6: {
                int id;
                std::cout << "Enter Patient ID to Search: ";
                std::cin >> id;
                search.searchPatient(patientMgmt.getPatients(), id);
                break;
            }
            case 7: {
                report.generateReport(patientMgmt.getPatients());
                break;
            }
            case 0:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
