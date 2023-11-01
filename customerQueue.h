#include <bits/stdc++.h>

#ifndef customerQueue
#define customerQueue

using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct customer
{
    string cname;
    int cbill;
    customer *nextNode;
} *front = nullptr, *rear = nullptr;

void saveNewCustomerToFile(customer *temp);
void saveAllCustomerToFile();
void loadCustomerFromFile();

void display1stCustomer()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         1st Customer                          |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";
    if (front == nullptr)
    {
        gotoxy(20, 7);
        cout << "No Customer in Queue" << endl;
    }
    else
    {
        gotoxy(20, 7);
        cout << "Customer at the front is : \" " << front->cname << " \" & Bill is : " << front->cbill << endl;
    }
}

void customerList()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                        Customer Queue                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";
    customer *temp = front;
    int i = 1;

    if (front == nullptr)
    {
        gotoxy(35, 7);
        cout << "No Customer in Queue\n";
    }
    else
    {
        for (i = 1; temp != nullptr; i++)
        {
            gotoxy(30, 6 + i);
            cout << "\t" << i << ". " << temp->cname << endl;
            temp = temp->nextNode;
        }
    }
    gotoxy(25, 7 + i);
    system("pause");
    system("cls");
}

void enqueue(string customerName, int totalBill)
{
    customer *newNode = new customer;

    newNode->cname = customerName;
    newNode->cbill = totalBill;
    newNode->nextNode = nullptr;

    if (front == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->nextNode = nullptr;
        rear->nextNode = newNode;
        rear = newNode;
    }
    saveNewCustomerToFile(newNode);
}

void dequeue()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Cash Counter                          |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    customer *temp = front;

    if (front == nullptr)
    {
        gotoxy(35, 7);
        cout << "No Customer in Queue" << endl;
    }
    else
    {
        char choice;

        front = front->nextNode;
        gotoxy(25, 7);
        cout << temp->cname << " Please select any payment method : ";
        gotoxy(35, 9);
        cout << "1. Bkash / Rocket / Nagad";
        gotoxy(35, 10);
        cout << "2. Credit Card / Debit Card";
        gotoxy(35, 11);
        cout << "3. Cash Payment";
        gotoxy(40, 13);
        cout << "Enter Any : ";
        do
        {
            choice = getch();
            switch (choice)
            {
            case '1':
                gotoxy(25, 15);
                cout << "Your Payment Method : \"Bkash / Rocket / Nagad\"";
                break;
            case '2':
                gotoxy(25, 15);
                cout << "Your Payment Method : \"Credit Card / Debit Card\"";
                break;
            case '3':
                gotoxy(25, 15);
                cout << "Your Payment Method : \"Cash Payment\"";
                break;
            case 8:
                break;
            }
        } while (choice != 8 && choice != '1' && choice != '2' && choice != '3');

        gotoxy(25, 17);
        cout << "Successful Payment by Customer : " << temp->cname << endl;
        gotoxy(25, 18);
        cout << "Bill Paid                       : " << temp->cbill << endl;
        gotoxy(40, 19);
        cout << "Thank You\n";
        delete temp;

        if (front == nullptr)
        {
            rear == nullptr;
        }
        saveAllCustomerToFile();
    }
    gotoxy(25, 20);
    system("pause");
    system("cls");
}

//==============================================================
//=========================File Handeling=======================
//==============================================================

void saveNewCustomerToFile(customer *temp)
{
    ofstream file("c.csv", ios::app); // ios::app (append) to go to the last fo the file.
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else
    {
        file << temp->cname << endl;
    }
    file.close();
}

void saveAllCustomerToFile()
{
    ofstream file("c.csv");
    if (!file.is_open())
    {
        cout << "File is unable to open\n";
    }
    else
    {
        if (file.tellp() == 0)
        {
            file << "Customer Name,Payment\n";
        }
        customer *temp = front;
        while (temp)
        {
            file << temp->cname << endl;
            temp = temp->nextNode;
        }
    }
    file.close();
}

void loadCustomerFromFile()
{
    ifstream file("c.csv");
    if (!file.is_open())
    {
        cout << "Unable to open File.\n";
    }
    else
    {
        string line;
        bool headerskipped = false;
        while (getline(file, line))
        {
            if (!headerskipped)
            {
                headerskipped = true;
                continue;
            }
            istringstream ss(line);
            string s1, s2;
            if (getline(ss, s1, ',') && getline(ss, s2, ','))
            {
                int i2;
                istringstream(s2) >> i2; // Convert s2 to an integer i2
                customer *newNode = new customer{s1, i2, nullptr};
                if (front == nullptr)
                {
                    front = rear = newNode;
                }
                else
                {
                    rear->nextNode = newNode;
                    rear = newNode;
                }
            }
        }
    }
    file.close();
}

#endif