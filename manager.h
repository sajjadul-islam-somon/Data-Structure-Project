#include <bits/stdc++.h>
#include "animation.h"

#ifndef manager
#define manager

using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct product
{
    int proId;
    string proName;
    double proPrice;
    int proNum;
    product *next;
} *head = nullptr;

void saveNewProductToFile(product *temp);
void saveAllProductToFile();
void loadProductFromFile();
void deleteList();

//=================================================================
//========================= Count Product =========================
//=================================================================
int countProduct()
{
    product *temp = head;

    if (head == nullptr)
        return 0;
    int i;
    for (i = 0; temp != nullptr; i++)
    {
        temp = temp->next;
    }
    return i;
}

//=================================================================
//========================= Count Product =========================
//=================================================================
void deleteList()
{
    //Clear List
    product *temp = head;
    while (temp != nullptr)
    {
        product *deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
    head = nullptr;     //indicate an empty list
}

void addProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                       Add New Product                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head, *newNode;
    newNode = new product; // new mamory allocation & object creation

    gotoxy(15, 6);
    cout << "Enter Product Info:";

    gotoxy(20, 8);
    cout << "Product Name     : ";
    cin.ignore();
    getline(cin, newNode->proName);
    gotoxy(20, 9);
    cout << "Product ID       : ";
    cin >> newNode->proId;
    gotoxy(20, 10);
    cout << "Product Price    : ";
    cin >> newNode->proPrice;
    gotoxy(20, 11);
    cout << "Product Quantity : ";
    cin >> newNode->proNum;

    saveNewProductToFile(newNode);

    if (head == nullptr)
    {
        newNode->next = nullptr;
        head = newNode;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        newNode->next = nullptr;
        temp->next = newNode;
    }
    gotoxy(25, 14);
    cout << "Product \"" << newNode->proName << "\" is added Successfully";
    gotoxy(25, 21);
    system("pause");
    system("cls");
}

void displayProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                   Displaying All Products                     |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head;
    int totalProduct = 0;

    if (head == nullptr)
    {
        gotoxy(34, 7);
        cout << "No Product is Found . . . \n\n\n\n\n\n";
    }
    else
    {
        gotoxy(15, 7);
        cout << "Existing Product are:";
        gotoxy(12, 9);
        cout << left;
        cout << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(15) << "Price" << setw(10) << "Quantity" << endl;
        gotoxy(12, 10);
        cout << "======================================================================\n";
        int yPos = 11;
        while (temp != nullptr)
        {
            gotoxy(12, yPos);
            cout << left;
            cout << setw(15) << temp->proId << setw(30) << temp->proName << setw(15) << temp->proPrice << setw(10) << temp->proNum << endl;

            temp = temp->next;
            totalProduct++;
            yPos++;
        }
        gotoxy(12, yPos);
        cout << "______________________________________________________________________\n";
        cout << "\t\t\tTotal Products in our Store : " << totalProduct << endl
             << endl;
    }
}

void modifyProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Modify Product                        |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head;
    if (head == nullptr)
    {
        gotoxy(34, 7);
        cout << "Store is Empty . . ." << endl;
    }
    else
    {
        int id;
        gotoxy(20, 7);
        cout << "Enter Product's ID : ";
        cin >> id;

        while (temp != nullptr)
        {
            if (temp->proId == id)
            {
                gotoxy(12, 9);
                cout << left;
                cout << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(15) << "Price" << setw(10) << "Quantity" << endl;
                gotoxy(12, 10);
                cout << "======================================================================\n";
                gotoxy(12, 11);
                cout << left;
                cout << setw(15) << temp->proId << setw(30) << temp->proName << setw(15) << temp->proPrice << setw(10) << temp->proNum << endl;

                gotoxy(20, 13);
                cout << "Enter Modify Product Info : \n";
                cout << "New Product ID       : ";
                cin >> temp->proId;
                cout << "New Product Name     : ";
                cin.ignore();
                getline(cin, temp->proName);
                cout << "New Product Price    : ";
                cin >> temp->proPrice;
                cout << "New Product Quantity : ";
                cin >> temp->proNum;
                gotoxy(20, 19);
                cout << "Product \" " << temp->proName << " \" is modified" << endl;

                saveAllProductToFile();
                loadProductFromFile();
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            gotoxy(20, 21);
            cout << "No Product Found";
        }
    }
    gotoxy(25, 21);
    system("pause");
    system("cls");
}

void deleteProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                        Delete Product                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head, *prev = nullptr;

    if (head == nullptr)
    {
        gotoxy(34, 7);
        cout << "Store is Empty . . .";
    }
    else
    {
        int id;
        gotoxy(20, 7);
        cout << "Enter Product's ID : ";
        cin >> id;

        while (temp != nullptr)
        {
            if (temp->proId == id)
            {
                gotoxy(12, 9);
                cout << left;
                cout << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(15) << "Price" << setw(10) << "Quantity" << endl;
                gotoxy(12, 10);
                cout << "======================================================================\n";
                gotoxy(12, 11);
                cout << left;
                cout << setw(15) << temp->proId << setw(30) << temp->proName << setw(15) << temp->proPrice << setw(10) << temp->proNum << endl;
                gotoxy(25, 13);
                cout << "Are sure!!! You want to delete" << temp->proName << endl;
                gotoxy(25, 21);
                system("pause");
                break;
            }
            temp = temp->next;
        }

        temp = head;
        if (head->proId == id)
        {
            gotoxy(25, 17);
            cout << "Product \" " << head->proName << " \" is deleted Successfully" << endl;
            head = head->next;
            delete temp;
        }
        else
        {
            while (temp != nullptr)
            {
                if (temp->proId == id)
                {
                    gotoxy(25, 17);
                    cout << "Product \" " << temp->proName << " \" is deleted Successfully" << endl;
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
    saveAllProductToFile();
    loadProductFromFile();
    gotoxy(25, 21);
    system("pause");
    system("cls");
}


//==============================================================
//=========================File Handeling=======================
//==============================================================

void saveNewProductToFile(product *temp)
{
    ofstream file("p.csv", ios::app); //ios::app (append) to go to the last fo the file.
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else 
    {
        file << temp->proId << "," << temp->proName << "," << temp->proPrice << "," << temp->proNum << endl;
    }
    file.close();
}

void saveAllProductToFile()
{
    ofstream file("p.csv");
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else 
    {
        if (file.tellp() == 0)
        {
            file << "ID,Name,Price,Quantity\n";
        }
        product *temp = head;
        while (temp != nullptr)
        {
            file << temp->proId << "," << temp->proName << "," << temp->proPrice << "," << temp->proNum << endl;
            temp = temp->next;
        }
    }
    file.close();
}

void loadProductFromFile()
{
    deleteList();
    ifstream file("p.csv");
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
            string s1, s2, s3, s4;
            if (getline(ss, s1, ',') && getline(ss, s2, ',') && getline(ss, s3, ',') && getline(ss, s4, ','))
            {
                int i1, i4;
                double i3;
                istringstream(s1) >> i1;    //Convert s2 to an integer
                istringstream(s3) >> i3;
                istringstream(s4) >> i4;

                product *newNode = new product{i1, s2, i3, i4, nullptr};
                if (!head)
                {
                    head = newNode;
                }
                else 
                {
                    product *temp = head;
                    while (temp->next)
                    {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
        }
    }
    file.close();
}

#endif