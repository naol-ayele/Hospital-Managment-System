///-----------------------------------------------
//----------PARTICIPATED STUDENT------------------
//-----------NAME-------------------ID------------
//     1. NAOL AYELE           UGR/25391/14
//     2. LENCHO LACHISA       UGR/25323/14
//     3. NAHUNDA BEKELE       UGR/25968/14
//     4. WAKJIRA MEGERSA      UGR/25924/14
//     5. GETU DIRIBA          UGR/26021/14
//     6. EYERUSALEM ASHENAFI  UGR/26520/14

//------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // add sstream header file
using namespace std;

// Define a patient struct to store patient information
struct Patient {
    string name;
    int age;
    string gender;
    string illness;
    Patient *next;
};

// Define a Hospital class to manage patient records
class Hospital {
private:
    Patient *head;
public:
    Hospital() {
        head = NULL;
    }

    // Function to add a new patient record to the linked list
    void addPatient() {
        Patient *newPatient = new Patient;
        cout << "Enter Patient Name: ";
        getline(cin, newPatient->name);

        string ageStr;
        int age;
        while (true) {
            cout << "Enter Patient Age: ";
            getline(cin, ageStr);
            stringstream ss(ageStr);
            if (ss >> age && ss.eof()) { // check if input is a valid integer
                newPatient->age = age;
                break;
            }
            cout << "Invalid input. Please enter a valid integer for age." << endl;
        }

        cout << "Enter Patient Gender: ";
        cin >> newPatient->gender;
        cout << "Enter Patient Illness: ";
        cin >> newPatient->illness;
        newPatient->next = NULL;

        if (head == NULL) {
            head = newPatient;
        }
        else {
            Patient *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        cout << "Patient record added successfully!" << endl;
    }

    // Function to display all patient records in the linked list
    void displayPatients() {
        if (head == NULL) {
            cout << "No patient records found!" << endl;
            return;
        }

        Patient *temp = head;
        cout << "Patient Records:\n";
        while (temp != NULL) {
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Illness: " << temp->illness << endl << endl;
            temp = temp->next;
        }
    }

    // Function to search for a patient record by name
    void searchPatient(string name) {
        if (head == NULL) {
            cout << "No patient records found!" << endl;
            return;
        }

        Patient *temp = head;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << "Patient Found:\n";
                cout << "Name: " << temp->name << endl;
                cout << "Age: " << temp->age << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Illness: " << temp->illness << endl << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found!" << endl;
    }

    // Function to delete a patient record by name
    void deletePatient(string name) {
        if (head == NULL) {
            cout << "No patient records found!" << endl;
            return;
        }

        if (head->name == name) {
            Patient *temp = head;
            head = head->next;
            delete temp;
            cout << "Patient record deleted successfully!" << endl;
            return;
        }

        Patient *prev = head;
        Patient *temp = head->next;
        while (temp != NULL) {
            if (temp->name == name) {
                prev->next = temp->next;
                delete temp;
                cout << "Patient record deleted successfully!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Patient not found!" << endl;
    }

    // Function to modify a patient record by name
    void modifyPatient(string name) {
        if (head == NULL) {
            cout << "No patient records found!" << endl;
            return;
        }
Patient *temp = head;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << "Enter new patient information:\n";
                cout << "Name: ";
                getline(cin, temp->name);

                string ageStr;
                int age;
                while (true) {
                    cout << "Age: ";
                    getline(cin, ageStr);
                    stringstream ss(ageStr);
                    if (ss >> age && ss.eof()) { // check if input is a valid integer
                        temp->age = age;
                        break;
                    }
                    cout << "Invalid input. Please enter a valid integer for age." << endl;
                }

                cout << "Gender: ";
                cin >> temp->gender;
                cout << "Illness: ";
                cin >> temp->illness;
                cout << "Patient record modified successfully!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found!" << endl;
    }

    // Function to write patient records to a file
    void writePatientsToFile() {
        ofstream outfile("patients.txt");
        if (!outfile) {
            cout << "Error: Unable to open file for writing!" << endl;
            return;
        }

        Patient *temp = head;
        while (temp != NULL) {
            outfile << temp->name << endl;
            outfile << temp->age << endl;
            outfile << temp->gender << endl;
            outfile << temp->illness << endl;
            temp = temp->next;
        }
        outfile.close();
        cout << "Patient records written to file successfully!" << endl;
    }

    // Function to read patient records from a file
    void readPatientsFromFile() {
        ifstream infile("patients.txt");
        if (!infile) {
            cout << "Error: Unable to open file for reading!" << endl;
            return;
        }

        string name, ageStr, gender, illness;
        int age;
        while (getline(infile, name)) {
            getline(infile, ageStr);
            stringstream ss(ageStr);
            if (ss >> age && ss.eof()) { // check if input is a valid integer
                getline(infile, gender);
                getline(infile, illness);

                Patient *newPatient = new Patient;
                newPatient->name = name;
                newPatient->age = age;
                newPatient->gender = gender;
                newPatient->illness = illness;
                newPatient->next = NULL;

                if (head == NULL) {
                    head = newPatient;
                }
                else {
                    Patient *temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newPatient;
                }
            }
        }
        infile.close();
        cout << "Patient records read from file successfully!" << endl;
    }
};

int main() {
    Hospital hospital;
    int choice;
    string name;

    while (true) {
        cout << "Enter your choice:\n";
        cout << "1. Add Patient Record\n";
        cout << "2. Display Patient Records\n";
        cout << "3. Search for a Patient Record\n";
        cout << "4. Delete a Patient Record\n";
        cout << "5. Modify a Patient Record\n";
        cout << "6. Write Patient Records to File\n";
        cout << "7. Read Patient Records from File\n";
        cout << "8. Exit\n";
        cin >> choice;
        cin.ignore(); // ignore the newline character left in the input stream

        switch (choice) {
        case 1:
            hospital.addPatient();
            break;
        case 2:
            hospital.displayPatients();
break;
        case 3:
            cout << "Enter Patient Name to search: ";
            getline(cin, name);
            hospital.searchPatient(name);
            break;
        case 4:
            cout << "Enter Patient Name to delete: ";
            getline(cin, name);
            hospital.deletePatient(name);
            break;
        case 5:
            cout << "Enter Patient Name to modify: ";
            getline(cin, name);
            hospital.modifyPatient(name);
            break;
        case 6:
            hospital.writePatientsToFile();
            break;
        case 7:
            hospital.readPatientsFromFile();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
        }
    }

    return 0;
}
