#include<iostream>
#include<cstring>
using namespace std;

class book 
{
    public:
    string book_name;
    string book_author;
    int ISBN;
    bool avaibility;
    book* next;

    book(string name, string author, int no, bool available) 
    {
        book_name = name;
        book_author = author;
        ISBN = no;
        avaibility = available;
        next = NULL;
    }
};

void insertbook(book* &head, string name, string author, int no, bool available) 
{
    book* new_book = new book(name, author, no, available);
    
    // If the list is empty, make the new book the head
    if (head == NULL) {
        head = new_book;
        return;
    }
    
    // Otherwise, traverse to the end of the list
    book* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the new book at the end
    temp->next = new_book;
}

void display(book* head) {
    book* temp = head;
    if (temp == NULL) {
        cout << "\nThere is no such book available.";
        return;
    }
    while (temp != NULL) {
        cout << "\nBook name:\t" << temp->book_name;
        cout << "\nBook author:\t" << temp->book_author;
        cout << "\nISBN:\t" << temp->ISBN;
        if (temp->avaibility != true) {
            cout << "\nBook is not available.";
        } else {
            cout << "\nBook is available.";
        }
        temp = temp->next;
    }
    cout << endl;
}

void searchbook(book* &head, string name, string author) {
    book* temp = head;
    int flag = 0;
    while (temp != NULL) {
        if (name == temp->book_name && author == temp->book_author) {
            flag = 1;
            cout << "\nBook Found.";
            break;
        }
        temp = temp->next;
    }
    if (flag != 1) {
        cout << "\nBook Not Found.";
    }
}

void deletebook(book*& head, string name, string author) {
    book* temp = head;
    book* prev = NULL;

    
    while (temp != NULL) {
        if (temp->book_name == name && temp->book_author == author) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nBook not found." << endl;
        return;
    }

  
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "\nBook deleted successfully." << endl;
}

int main() {
    book* head = NULL;
    int ch;
    string name, author;
    int no;
    string availability_input;
    bool available;

    do {
        cout << "\nEnter your choice:-\n";
        cout << "\n1. Insert the book details\n";
        cout<<"\n2. Display the book details present in library \n";
        cout<<"\n3. Delete book specific book details\n";
        cout<<"\n4. Search book\n";
        cout<<"\n5. Exit\n";
        cout << "\nChoice: \n";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter the book name:\t";
                cin>>name;
                cout << "Enter the book author:\t";
                cin>>author;
                cout << "Enter ISBN:\t";
                cin >> no;
                cout << "Is the book available (true/false):\t";
                cin >> availability_input;
                available = (availability_input == "true");
                insertbook(head, name, author, no, available);
                break;
            case 2:
                cout << "\nLibrary Collection:";
                display(head);
                break;
            case 3:
                cout << "\nEnter the book name to delete:\t";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter the book author:\t";
                getline(cin, author);
                deletebook(head, name, author);
                break;
            case 4:
                cout << "\nEnter the book name to search:\t";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter the book author:\t";
                getline(cin, author);
                searchbook(head, name, author);
                break;
            case 5:
                cout << "\nExiting the program.";
                break;
            default:
                cout << "\nInvalid choice. Please try again.";
        }
    } while (ch != 5);

    return 0;
}
