#include <iostream>
using namespace std;

int queue[10];  
int front = -1;
int rear = -1;
int size;  

void rear_insertion(int n) 
{
    if (rear == size - 1) {
        cout << "\nDeque is overflow....";
    } else {
        if (front == -1) 
        front = 0;  
        rear++;
        queue[rear] = n;
    }
}

void rear_deletion() 
{
    if (rear == -1 || rear < front) 
    {
        cout << "\nDeque is empty.";
    } else
     {
        int n = queue[rear];
        rear--;
        cout << "\n" << n << " deleted...";

        
        if (rear < front) {
            front = -1;
            rear = -1;
        }
    }
}

void front_insert(int n)
{
    if(front == 0)
    {
        cout<<"OVERFLOW"<<endl;
        
    }
    else
    { 
        if(front == -1)
        {
            front =0;
            rear = 0;
        }
        front --;
        queue[front] = n;

    }
}

void front_deletion() 
{
    if (front == -1 || front > rear)
    {
        cout << "\nDeque is empty";
    } 
    else 
    {
        int n = queue[front];
        front++;
        cout << "\n" << n << " deleted...";

        
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}





void display() {
    if (front == -1)
     {
        cout << "\nDeque is empty.";
        return;
    }
    cout << "\nDeque elements are: ";
    for (int i = front; i <= rear; i++) 
    {
        cout << queue[i] << " ";
    }
    
    cout << "\nFront is at index: " << front;
    cout << "\nRear is at index: " << rear;
}

int main() 
{
    int n;
    int ch;

    
    cout << "Enter the size of the deque: ";
    cin >> size;

    do {
        cout << "\nMAIN MENU";
        cout << "\n1. Insert at rear";
        cout << "\n2. Insert at front";
        cout << "\n3. Delete at front";
        cout << "\n4. Delete at rear";
        cout << "\n5. Display";
        cout << "\n6. Exit:";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter element:\t";
                cin >> n;
                rear_insertion(n);
                break;
            case 2:
                cout << "\nEnter element:\t";
                cin >> n;
                front_insert(n);
                break;
            case 3:
                front_deletion();
                break;
            case 4:
                rear_deletion();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "\nExiting....!";
                break;
            default:
                cout << "\nInvalid choice!";
                break;
        }
    } while (ch != 6);

    return 0;
}
