#include <bits/stdc++.h>
#include "manager.h"
#include "customerQueue.h"
#include "animation.h"

#ifndef customerCart
#define customerCart

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

struct cart
{
    int num;
    cart *link;
} *top;

void push(int cartNum)
{
    cart *newNode = new cart;

    if (!newNode)
    {
        cout << "Heap Overflow" << endl;
        return;
    }

    newNode->num = cartNum;
    newNode->link = top;
    top = newNode;
}

void cCart()
{
    system("cls");

    cout << endl;
    cout << "\t\t\t\t                  ___" << endl;
    cout << "\t\t\t\t                 /  |" << endl;
    cout << "\t\t\t\t  ______________/   --" << endl;
    cout << "\t\t\t\t |___/__ /___/_|     " << endl;
    cout << "\t\t\t\t |__/___/___/__|     " << endl;
    cout << "\t\t\t\t |_/___/___/___|     " << endl;
    cout << "\t\t\t\t    _______/         " << endl;
    cout << "\t\t\t\t     O   O           " << endl;

    gotoxy(35, 11);
    cout << "Please Grab a Cart \\_/`";

    cart *temp = top;

    if (top == nullptr)
    {
        gotoxy(35, 13);
        cout << "Carts Not Available Now" << endl; // Stack Underflow
    }
    else
    {
        gotoxy(35, 13);
        cout << "Your Cart Number is : " << top->num << endl;
        top = top->link;
        top->link = nullptr;
        delete temp;
    }
    gotoxy(30, 21);
    system("pause");
    system("cls");
}

void displayCart()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Display Cart                          |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";
    cart *temp = top;

    if (top == nullptr)
    {
        gotoxy(35, 7);
        cout << "Carts Not Available Now" << endl; // Stack Underflow
    }
    else
    {
        gotoxy(25, 7);
        cout << "Existing carts are : ";
        int xPos = 30, yPos = 9;
        for (int i = 0; temp != nullptr; i++)
        {
            if (i == 10 || i == 20 || i == 30 || i == 40 || i == 50)
            {
                xPos += 8;
                yPos -= 10;
            }
            gotoxy(xPos, yPos + i);
            cout << temp->num;
            temp = temp->link;
        }
    }
    gotoxy(30, 21);
    system("pause");
    system("cls");
}

void searchProduct()
{
    system("cls");

    product *temp = head;

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                        Search Product                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

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
            break;
        }
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        gotoxy(25, 10);
        cout << "Product Not Found . . . \n";
    }
    gotoxy(30, 20);
    system("pause");
    system("cls");
}

void buyProduct()
{
    system("cls");
    displayProduct();

    if (head == nullptr)
    {
        cout << "There is no Product to Buy\n\n\n";
    }
    else
    {
        int number;
        cout << "\t\tHow many different products you wanna buy : ";
        cin >> number;
        int total = countProduct();
        string products[total];
        int quantities[total];

        int c = 0, bill = 0, totalBill = 0;

        for (int i = 0; i < number; i++)
        {
        again:
            product *temp = head;
            int id;
            cout << "\n\t\tEnter the Product's ID : ";
            cin >> id;

            while (temp != nullptr)
            {
                if (temp->proId == id)
                {
                    int quantity;
                    cout << "\t\tHow many quantities you wanna buy : ";
                    cin >> quantity;

                    if (quantity > temp->proNum)
                    {
                        cout << "\n\n\t\tThe quantity you enterd is NOT Available\n\n";
                        cout << "\t\t-> press <-- to go back\n";
                        cout << "\t\t-> Press Enter to Continue\n";
                        if (getch() == 8)
                        {
                            system("cls");
                            return;
                        }
                        else if (getch() == 18)
                        {
                            goto again;
                        }
                    }
                    else 
                    {
                        products[c] = temp->proName;
                        quantities[c] = quantity;
                        c++;

                        bill = bill + (temp->proPrice * quantity);
                        temp->proNum = temp->proNum - quantity;
                        break;
                    }
                }
                else 
                    temp = temp->next;
            }
            if (temp == nullptr)
            {
                cout << "No Product Found\n\n";
            }
        }
        string customerName;
        cin.ignore();
        cout << "Enter Your name : ";
        getline(cin, customerName);

        system("cls");

        gotoxy(15, 2);
        cout << "+---------------------------------------------------------------+";
        gotoxy(15, 3);
        cout << "|                     Payment Confirmation                      |";
        gotoxy(15, 4);
        cout << "+---------------------------------------------------------------+";

        gotoxy(25, 7);
        cout << "You Have bought : \n";
        for (int i = 1; i <= number; i++)
        {
            gotoxy(25, 7+i);
            cout << i << " | " << products[i - 1] << " (" << quantities[i-1] << ")"<< endl;
        }
        
        totalBill = bill * (0.90); // 10% Discount
        cout << "\t\t\tTotal sum of Bill : " << bill << endl;
        cout << "\t\t\tWith 10% Discount. Your Payable Bill is : " << totalBill << endl << endl;
        cout << "\t\t\t\tThank you for shopping here\n\n";
        enqueue(customerName, totalBill);
    }
    system("pause");
    system("cls");
}

#endif