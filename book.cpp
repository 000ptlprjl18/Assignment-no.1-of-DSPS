#include<iostream>
#include<iomanip>  // Fixed the typo here
#include<string>
using namespace std;

class book
{
    public:
     string title;
     string author;
     string publisher;
     int stock;
     float price;

    void storedetails(string t, string a, string pub, int s, float p)
    {
        title = t;
        author = a;
        publisher = pub;
        stock = s;
        price = p;
        
    }

    void display(int i)
    {
        if(stock >= 0)
        {
            cout << "+---------------------------------------+" << endl;
            cout << "BOOK " << i+1 << " DETAILS:" << endl;
            cout << left << setw(15) << "TITLE:" << title << endl;
            cout << left << setw(15) << "AUTHOR:" << author << endl;
            cout << left << setw(15) << "PUBLISHER:" << publisher << endl;
            cout << left << setw(15) << "PRICE:" << price << endl;
            cout << left << setw(15) << "STOCK:" << stock << " copies are available" << endl;
            cout << "+---------------------------------------+" << endl;
        }
    }

    int searchbook(string t, string a)
    {
        if(title == t && author == a)
        {
            return 1;
        }
        return 0;
    }

    float sellbook(int quantity)
    {
        if(stock >= quantity)
        {
            stock -= quantity;
            return price * quantity;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int size = 10, ch, n = 0;
    book booklist[size];

    do
    {
        cout << "Main Menu:" << endl;
        cout << "1. ADD A NEW BOOK TO THE INVENTORY" << endl;
        cout << "2. SEARCH BOOK" << endl;
        cout << "3. DISPLAY ALL BOOK DETAILS" << endl;
        cout << "4. EXIT..." << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
            {
                if(n >= size)
                {
                    cout << "Inventory is full!" << endl;
                    break;
                }
                
                int x;
                cout << "How many books do you want to add to the inventory?" << endl;
                cin >> x;
                
                for(int j = 0; j < x && n < size; j++)
                {
                    string title, author, publisher;
                    int stock;
                    float price;

                    cout << "ENTER DETAILS FOR BOOK " << n+1 << ":\n";
                    cout << "BOOK TITLE: ";
                    
                    cin>>title;
                    cout << "BOOK AUTHOR: ";
                    cin>>author;
                    cout << "PUBLISHER: ";
                    cin>>publisher;
                    cout << "PRICE: ";
                    cin >> price;
                    cout << "STOCK: ";
                    cin >> stock;

                    booklist[n].storedetails(title, author, publisher, stock, price);
                    n++;
                }
                break;
            }

            case 2:
            {
                string searchtitle, searchauthor;
                int quantity, flag = 0;

                cout << "ENTER TITLE OF THE BOOK YOU WANT TO SEARCH: ";
                cin >> ws;  // Clear leading whitespace
                getline(cin, searchtitle);
                cout << "ENTER AUTHOR NAME OF THE BOOK: ";
                getline(cin, searchauthor);

                for(int i = 0; i < n; i++)
                {
                    if(booklist[i].searchbook(searchtitle, searchauthor))
                    {
                        flag = 1;
                        cout << "Book found!" << endl;
                        booklist[i].display(i);
                        
                        cout << "Enter the quantity of books you want to buy: ";
                        cin >> quantity;

                        float totalcost = booklist[i].sellbook(quantity);
                        if(totalcost != -1)
                        {
                            cout << "Total cost is: " << totalcost << endl;
                        }
                        else
                        {
                            cout << "Insufficient stock" << endl;
                        }
                        break;
                    }
                }

                if(flag == 0)
                {
                    cout << "Book not found!" << endl;
                }
                break;
            }

            case 3:
            {
                cout << "ALL BOOKS IN INVENTORY:" << endl;
                for(int i = 0; i < n; i++)
                {
                    booklist[i].display(i);
                }
                break;
            }

            case 4:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while(ch != 4);

    return 0;
}
