#include <bits/stdc++.h>
#include "manager.h"
#include "customerQueue.h"
#include "animation.h"

#ifndef customerCart
#define customerCart

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const int totalCart = 50;

//=================================================================
//============================= Cart ==============================
//=================================================================
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

    int totalCustomer = countCustomer();
    int remainCart = totalCart - totalCustomer;
    if (remainCart == 0)
    {
        gotoxy(35, 13);
        cout << "Cart Not Available Now" << endl;
    }
    else 
    {
        int cartNum = remainCart;
        gotoxy(35, 13);
        cout << "Your Cart Number is : " << cartNum << endl;
    }
    gotoxy(30, 21);
    system("pause");
    system("cls");
}

//=================================================================
//========================= Display Cart ==========================
//=================================================================
void displayCart()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Display Cart                          |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    int totalCustomer = countCustomer();
    int remainCart = totalCart - totalCustomer;
    if (remainCart == 0)
    {
        gotoxy(35, 13);
        cout << "Cart Not Available Now" << endl;
    }
    else 
    {
        gotoxy(25, 7);
        cout << "Existing carts are : ";
        int xPos = 30, yPos = 9;
        int j = remainCart;
        for (int i = 0; i < remainCart; i++)
        {
            if (i == 10 || i == 20 || i == 30 || i == 40 || i == 50)
            {
                xPos += 8;
                yPos -= 10;
            }
            gotoxy(xPos, yPos + i);
            cout << j--;
        }
    }
    gotoxy(30, 21);
    system("pause");
    system("cls");
}

//=================================================================
//======================== Search Product =========================
//=================================================================
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

    string name;
    gotoxy(20, 7);
    cout << "Product Name is Case Sencetive";
    gotoxy(20, 7);
    // cin.ignore();
    cout << "Enter Product's Name : ";
    getline(cin, name);

    while (temp != nullptr)
    {
        if (temp->proName == name)
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

//=========================================================================
//=========================== Buy Product =================================
//=========================================================================
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
    here:
        int number;
        cout << "\t\tHow many different products you wanna buy : ";
        cin >> number;
        int total = countProduct();
        if (number > total)
        {
            cout << "\t\t\tSorry, Invalid Number of Products";
            goto here;
        }
        string products[total];
        int quantities[total];

        int c = 0;
        double bill = 0, totalBill = 0;

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
        string customerName, customerPhone;
        cin.ignore();
        cout << "\t\t\tEnter Your name : ";
        getline(cin, customerName);
        cin.ignore();
        cout << "\t\t\tEnter Phone No. : ";
        cin >> customerPhone;

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
        enqueue(customerName, customerPhone, totalBill);
    }
    system("pause");
    system("cls");
}

#endif