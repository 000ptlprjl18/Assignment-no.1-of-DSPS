#include<iostream>
#include<string>
using namespace std;

class person
{
    private:
    string name;
    long mobile_no;
    int emp_id;

    public:
    person() {}
    person(string n, long mb_no, int id)
    {
        name = n;
        mobile_no = mb_no;
        emp_id = id;
    }

    int getid() 
    {
        return emp_id;
    }

    void accept()
    {
        cout << "ENTER NAME:" << endl;
        cin >> name;
        cout << "ENTER MOBILE NUMBER:" << endl;
        cin >> mobile_no;
        cout << "ENTER ID:" << endl;
        cin >> emp_id;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Mobile Number: " << mobile_no << endl;
        cout << "ID: " << emp_id << endl;
    }
};

class doctor: virtual public person
{
   public:
   string specialization;
   string qualification;
   int experience;

   void acceptdoc()
   {
    cout << "ENTER SPECIALIZATION OF DOCTOR" << endl;
    cin >> specialization;
    cout << "ENTER QUALIFICATION OF DOCTOR" << endl;
    cin >> qualification;
    cout << "ENTER EXPERIENCE" << endl;
    cin >> experience;
   }
   void displaydoc()
   {
    cout << "SPECIALIZATION: " << specialization << "\n";
    cout << "QUALIFICATION: " << qualification << "\n";
    cout << "EXPERIENCE: " << experience << "\n";
   }
};

class nurse: virtual public person
{
    public: 
    string department;
    string shift;

    void acceptnurse()
    {
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter Shift: ";
        cin >> shift;
    }  

    void displaynurse()
    {
        cout << "Department: " << department << endl;
        cout << "Shift: " << shift << endl;                
    } 
};

class AdminStaff : public doctor, public nurse
{
public:
    void search(int num, doctor d[], nurse n[])
    {
        int ch1;
        do {
            cout << "\nEnter your choice:\n";
            cout<<"1. Search Doctor\n";
            cout<<"2. Search Nurse\n";
            cout<<"3. Exit:\t";
            cin >> ch1;
            switch (ch1)
            {
                case 1: {
                    int search_id;
                    cout << "\nEnter Doctor's ID to search:\t";
                    cin >> search_id;
                    int flag = 0;
                    for (int i = 0; i < num; i++)
                    {
                        if (d[i].getid() == search_id)  
                        {
                            cout << "\nDoctor found:\n";
                            d[i].display();
                            d[i].displaydoc();
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        cout << "\nDoctor not found!";
                    }
                    break;
                }
                case 2: {
                    int search_id;
                    cout << "\nEnter Nurse's ID to search:\t";
                    cin >> search_id;
                    int flag = 0;
                    for (int i = 0; i < num; i++)
                    {
                        if (n[i].getid() == search_id)  
                        {
                            cout << "\nNurse found:\n";
                            n[i].display();
                            n[i].displaynurse();
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        cout << "\nNurse not found!";
                    }
                    break;
                }
                case 3:
                    cout << "\nExiting....!";
                    break;
                default:
                    cout << "\nInvalid choice!";
                    break;
            }
        } while (ch1 != 3);
    }
};

int main()
{
    doctor d[5];
    nurse n[5];
    AdminStaff admin;
    int ch;
    int size_d = 0, size_n = 0;

    do
    {
        cout << "1.DOCTOR\n2.NURSE\n3.ADMINISTRATIVE WORK\n4.EXIT\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter the Total no. of doctor staff: ";
                cin >> size_d;
                for (int i = 0; i < size_d; i++)
                {
                    d[i].accept();
                    d[i].acceptdoc();
                }
                break;

            case 2:
                cout << "Enter the Total no. of Nurse staff: ";
                cin >> size_n;
                for (int i = 0; i < size_n; i++)
                {
                    n[i].accept();
                    n[i].acceptnurse();
                }
                break;

            case 3:
                admin.search(max(size_d, size_n), d, n); 
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
                break;
        }
    } while (ch != 4);

    return 0;
}
