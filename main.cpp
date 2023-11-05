#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "manager.h"
#include "customerCart.h"
#include "customerQueue.h"
#include "animation.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

//===========================================================================
//============================Customer Function==============================
//===========================================================================
void Customer()
{
    system("cls");
    char choice;
    do
    {
        gotoxy(15, 2);
        cout << "+===============================================================+";
        gotoxy(15, 3);
        cout << "|                         Customer Mode                         |";
        gotoxy(15, 4);
        cout << "+===============================================================+";

        gotoxy(40, 7);
        cout << "1. Display All Products";
        gotoxy(40, 8);
        cout << "2. Search Products";
        gotoxy(40, 9);
        cout << "3. Buy Products";
        gotoxy(40, 10);
        cout << "4. Display Cart";
        gotoxy(40, 11);
        cout << "<-- Go Back";
        gotoxy(25, 17);
        cout << "Enter Valid Key . . . ";

        choice = getch();

        switch (choice)
        {
        case '1':
            displayProduct();
            system("pause");
            system("cls");
            break;
        case '2':
            searchProduct();
            break;
        case '3':
            cCart();
            buyProduct();
            break;
        case '4':
            displayCart();
            break;
        case 8:
            system("cls");
            break;

        default:
            gotoxy(30, 20);
            cout << "Please Enter Valid Input." << endl;
            break;
        }
    } while (choice != 8);
}

//===========================================================================
//=============================Manager Function==============================
//===========================================================================


void Manager()
{
    system("cls");
    char choice;
    do
    {
        gotoxy(15, 2);
        cout << "+===============================================================+";
        gotoxy(15, 3);
        cout << "|                         Manager Mode                          |";
        gotoxy(15, 4);
        cout << "+===============================================================+";

        gotoxy(40, 7);
        cout << "1. Add New";
        gotoxy(40, 8);
        cout << "2. Display All";
        gotoxy(40, 9);
        cout << "3. Modify Product";
        gotoxy(40, 10);
        cout << "4. Delete Product";
        gotoxy(40, 11);
        cout << "5. Customer List";
        gotoxy(40, 12);
        cout << "6. Customer Done";
        gotoxy(40, 14);
        cout << "<-- Go Back";
        gotoxy(25, 17);
        cout << "Enter Valid Key. . . ";
        
        choice = getch();

        switch (choice)
        {
        case '1':
            addProduct();
            break;

        case '2':
            displayProduct();
            system("pause");
            system("cls");
            break;

        case '3':
            modifyProduct();
            break;

        case '4':
            deleteProduct();
            break;

        case '5':
            customerList();
            break;

        case '6':
            dequeue();
            break;

        case 8:
            system("cls");
            break;

        default:
            gotoxy(30, 20);
            cout << "\tSorry Please, Enter valid input " << endl;
            break;
        }
    } while (choice != 8);
}

void Login()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                          Admin Login                          |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    gotoxy(32, 7);
    cout << "Login . . . . . . . . . . . . . .";
    gotoxy(32, 8);
    cout << "`````````````````````````````````";
    string username, password;
    gotoxy(30, 10);
    cout << "Admin-Username : ";
    cin >> username;

    gotoxy(30, 11);
    cout << "Password       : ";
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            break;
        }
        if (ch == 8)
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else 
        {
            password.push_back(ch);
            cout << "*";
        }

    }
    if (username == "admin" && password == "1")
    {
        gotoxy(30, 14);
        cout << "Login Susscessfull . . .\n";
        loadingBar();
        Manager();
    }
    else 
    {
        gotoxy(30, 14);
        cout << "Wrong Username or Password . . .\n\n";
        gotoxy(30, 15);
        cout << "Your entered Password :  " << password << endl;
        gotoxy(25, 20);
        system("pause");
        Login();
    }
}


//===========================================================================
//===============================Main Function===============================
//===========================================================================

int main()
{
    system("cls");
    system("color E4");

    for (int i = 1; i <= 50; i++)
    {
        push(i);
    }

    loadProductFromFile();
    loadCustomerFromFile();

    gotoxy(15, 4);
    cout << "+===============================================================+";
    gotoxy(15, 5);
    cout << "|                                                               |";
    gotoxy(15, 6);
    cout << "+===============================================================+";

    char headline[64] = "                         Shoping Mall                          ";
    gotoxy(16, 5);
    for (int i = 0; i < 64; i++)
    {
        Sleep(30);
        cout << headline[i];
    }

    gotoxy(15, 8);
    cout << "                     Data Structure Project";

    gotoxy(15, 10);
    cout << "       By : " << endl;
    gotoxy(15, 11);
    cout << "                   Sajjadul Islam Somon (5749)" << endl;
    gotoxy(15, 12);
    cout << "                   Raduan Ahamed        (4977)" << endl;
    gotoxy(15, 13);
    cout << "                   Akib Mahmud          (4881)" << endl;

    gotoxy(25, 20);
    system("pause");
    system("cls");

    char choice;
    do
    {
        gotoxy(15, 2);
        cout << "+===============================================================+";
        gotoxy(15, 3);
        cout << "|                          Main Menu                            |";
        gotoxy(15, 4);
        cout << "+===============================================================+";

        gotoxy(40, 7);
        cout << "1. manager" << endl;
        gotoxy(40, 8);
        cout << "2. customer" << endl;
        gotoxy(35, 10);
        cout << "Press \"ESC\" to Exit  [->" << endl;
        gotoxy(25, 17);
        cout << "Enter Valid Key . . . ";

        choice = getch();

        switch (choice)
        {
        case '1':
            Login();
            break;

        case '2':
            Customer();
            break;

        case 27:
            cout << "Exit System\n";
            system("\t\t\tcls");
            break;

        default:
            gotoxy(30, 20);
            cout << "\tPlease Enter Valid Input ";
            break;
        }
    } while (choice != 27);
    return 0;
}
