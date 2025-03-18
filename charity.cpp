#include <iostream>
#include <string>
using namespace std;

class Charity {
public:
    int donation_id;
    string donor_name;
    int donation_amount;
    Charity* next;

    Charity(int id, int amount, string name) {
        donation_id = id;
        donation_amount = amount;
        donor_name = name;
        next = NULL;
    }
};

class DonationInfo {
private:
    Charity* head;

public:
    DonationInfo() {
        head = NULL;
    }

    // Modified addinfo method to insert at the end
    void addinfo(int id, int amount, string name) {
        Charity* new_donor = new Charity(id, amount, name); // Renamed from temp to new_donor
        if (head == NULL) {
            // If the list is empty, make the new node the head
            head = new_donor;
        } else {
            // Traverse to the end of the list
            Charity* temp = head; // Renamed from current to temp
            while (temp->next != NULL) {
                temp = temp->next;
            }
            // Link the new node at the end
            temp->next = new_donor;
        }
    }

    void display() {
        Charity* temp = head;
        if (head == NULL) {
            cout << "\nThere is no data available." << endl;
            return;
        }
        while (temp != NULL) {
            cout << "\nDonor Name: " << temp->donor_name;
            cout << "\nDonation ID: " << temp->donation_id;
            cout << "\nDonation Amount: " << temp->donation_amount << endl;
            temp = temp->next;
        }
    }

    void updatedata(int id, int amount, string name) {
        Charity* temp = head;
        int flag =0;;
        while (temp != NULL) {
            if (id == temp->donation_id) {
                temp->donor_name = name;
                temp->donation_amount = amount;
                flag =1;
                cout << "\nData updated successfully." << endl;
                break;
            }
            temp = temp->next;
        }
        if (flag == 0) {
            cout << "\nInvalid donor ID." << endl;
        }
    }

    void remove(int id) {
        Charity* temp = head;
        Charity* prev = NULL;

        while (temp != NULL && temp->donation_id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nDonor not found." << endl;
            return;
        }

        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "\nInformation deleted successfully." << endl;
    }

    void search(int id) {
        Charity* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->donation_id == id) {
                cout << "\nDonor found:";
                cout << "\nDonor Name: " << temp->donor_name;
                cout << "\nDonation ID: " << temp->donation_id;
                cout << "\nDonation Amount: " << temp->donation_amount << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\nDonor not found." << endl;
        }
    }
};

int main() {
    DonationInfo obj1;
    int ch, id, amount;
    string name;

    do {
        cout << "\nEnter your choice\n1. Insert donation info \n2. Display \n3. Update \n4. Remove \n5. Search \n6. Exit:\t";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter Donor Name:\t";
                cin >> name;
                cout << "\nEnter Donation ID:\t";
                cin >> id;
                cout << "\nEnter Donation Amount:\t";
                cin >> amount;
                obj1.addinfo(id, amount, name);
                break;

            case 2:
                obj1.display();
                break;

            case 3:
                cout << "\nEnter Donation ID to update:\t";
                cin >> id;
                cout << "\nEnter New Donor Name:\t";
                cin >> name;
                cout << "\nEnter New Donation Amount:\t";
                cin >> amount;
                obj1.updatedata(id, amount, name);

                break;

            case 4:
                cout << "\nEnter Donation ID to remove:\t";
                cin >> id;
                obj1.remove(id);
                break;

            case 5:
                cout << "\nEnter Donation ID to search:\t";
                cin >> id;
                obj1.search(id);
                break;

            case 6:
                cout << "\nExiting program." << endl;
                break;

            default:
                cout << "\nInvalid choice" << endl;
                break;
        }
    } while (ch != 6);

    return 0;
}