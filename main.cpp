#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "manager.h"
#include "customerCart.h"
#include "customerQueue.h"
#include "animation.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

struct login
{
    string lname;
    string lphone;
    string lusername;
    string lpassword;
    login *linker;
} *first = nullptr;

void Customer();
void loginOrSign();
void customerSignup();
void customerLogin();
void saveNewUserToFile(login *temp);
void loadUsersFromFile();

//===========================================================================
//=========================== Cashier Function ==============================
//===========================================================================
void Cashier()
{
    system("cls");
    char choice;
    do
    {
        gotoxy(15, 2);
        cout << "+===============================================================+";
        gotoxy(15, 3);
        cout << "|                         Cashier Mode                          |";
        gotoxy(15, 4);
        cout << "+===============================================================+";
        gotoxy(37, 7);
        cout << "1. Customer List";
        gotoxy(37, 8);
        cout << "2. Customer Check Out";
        gotoxy(40, 13);
        cout << "<-- Go Back";
        gotoxy(30, 17);
        cout << "Enter Valid Key . . . ";

        choice = getch();

        switch (choice)
        {
        case '1':
            customerList();
            break;

        case '2':
            dequeue();
            break;

        case 8:
            system("cls");
            break;

        default:
            gotoxy(35, 20);
            cout << "Please Enter Valid Input." << endl;
            break;
        }

    } while (choice != 8);
    
}

void cashierLogin()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Cashier Login                         |";
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
    if (username == "admin" && password == "123")
    {
        gotoxy(30, 14);
        cout << "Login Susscessfull . . .\n";
        loadingBar();
        Cashier();
    }
    else 
    {
        gotoxy(30, 14);
        cout << "Wrong Username or Password . . .\n\n";
        gotoxy(30, 15);
        cout << "Your entered Password :  " << password << endl;
        gotoxy(30, 20);
        system("pause");
        cashierLogin();
    }
}

//===========================================================================
//=========================== Customer Function =============================
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

        gotoxy(37, 7);
        cout << "1. Display All Products";
        gotoxy(37, 8);
        cout << "2. Search Products";
        gotoxy(37, 9);
        cout << "3. Buy Products";
        gotoxy(37, 10);
        cout << "4. Display Cart";
        gotoxy(40, 13);
        cout << "<-- Go Back";
        gotoxy(30, 17);
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
            gotoxy(35, 20);
            cout << "Please Enter Valid Input." << endl;
            break;
        }
    } while (choice != 8);
}

void customerLogin()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                        Customer Login                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    gotoxy(30, 7);
    cout << "Login . . . . . . . . . . . . . .";
    gotoxy(30, 8);
    cout << "`````````````````````````````````";
    string username, password;
    gotoxy(30, 10);
    cout << "Customer-Username : ";
    cin >> username;
    gotoxy(30, 11);
    cout << "Password          : ";
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
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
    login *temp = first;
    while (temp != nullptr)
    {
        if (username == temp->lusername && password == temp->lpassword)
        {
            gotoxy(30, 14);
            cout << "Login Susscessfull . . .\n";
            loadingBar();
            Customer();
            break;
        }
        temp = temp->linker;
    }
    if (temp == nullptr)
    {
        gotoxy(30, 14);
        cout << "Wrong Username or Password . . .\n\n";
        gotoxy(30, 15);
        cout << "Your entered Password :  " << password << endl;
        gotoxy(30, 20);
        system("pause");
        loginOrSign();
    }
}

void customerSignup()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                            Sigh Up                            |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    login *temp = first, *newUser;
    newUser = new login;

    gotoxy(15, 6);
    cout << "Signing Up New Customer . . .";
    cin.ignore();

    gotoxy(30, 8);
    cout << "Full Name          : ";
    getline(cin, newUser->lname);
    gotoxy(30, 9);
    cout << "Phone Number       : ";
    cin >> newUser->lphone;
    gotoxy(30, 10);
    cout << "Username (No Space): ";
    cin >> newUser->lusername;
    gotoxy(30, 11);
    cout << "Password (No Space): ";
    cin >> newUser->lpassword;

    saveNewUserToFile(newUser);

    newUser->linker = nullptr;
    if (first == nullptr)
    {
        first = newUser;
    }
    else
    {
        while (temp->linker != nullptr)
        {
            temp = temp->linker;
        }
        temp->linker = newUser;
    }

    gotoxy(30, 14);
    cout << "Sign Up Successful . . .\n";

    gotoxy(30, 20);
    system("pause");
    customerLogin();
}

void loginOrSign()
{
    system("cls");

    char choice;
    do
    {
        gotoxy(15, 2);
        cout << "+---------------------------------------------------------------+";
        gotoxy(15, 3);
        cout << "|                         Please Select                         |";
        gotoxy(15, 4);
        cout << "+---------------------------------------------------------------+";
        gotoxy(21, 7);
        cout << "[Login (Enter)]";
        gotoxy(60, 7);
        cout << "[Sign Up   (+)]";
        gotoxy(41, 8);
        cout << "[ <-- Back ]";
        choice = getch();
        switch (choice)
        {
        case 18:
            customerLogin();
            break;
        case 43:
            customerSignup();
            break;
        case 8:
            system("cls");
            break;
        default:
            gotoxy(30, 10);
            cout << "Please Enter Valid Key";
            customerLogin();
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

        gotoxy(37, 7);
        cout << "1. Add New";
        gotoxy(37, 8);
        cout << "2. Display All";
        gotoxy(37, 9);
        cout << "3. Modify Product";
        gotoxy(37, 10);
        cout << "4. Delete Product";
        gotoxy(37, 11);
        cout << "5. Customer List";
        gotoxy(40, 13);
        cout << "<-- Go Back";
        gotoxy(30, 17);
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

        case 8:
            system("cls");
            break;

        default:
            gotoxy(35, 20);
            cout << "Please, Enter valid input " << endl;
            break;
        }
    } while (choice != 8);
}

void managerLogin()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Manager Login                         |";
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
    if (username == "admin" && password == "123")
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
        gotoxy(30, 20);
        system("pause");
        managerLogin();
    }
}

//===========================================================================
//===============================Main Function===============================
//===========================================================================
int main()
{
    system("cls");
    system("color E4");

    loadUsersFromFile();
    loadProductFromFile();
    loadCustomerFromFile();

    gotoxy(15, 2);
    cout << "+===============================================================+";
    gotoxy(15, 3);
    cout << "|                                                               |";
    gotoxy(15, 4);
    cout << "+===============================================================+";

    char headline[64] = "                         Shoping Mall                          ";
    gotoxy(16, 3);
    for (int i = 0; i < 64; i++)
    {
        Sleep(30);
        cout << headline[i];
    }

    gotoxy(15, 7);
    cout << "                     Data Structure Project";

    gotoxy(15, 10);
    cout << "       By : " << endl;
    gotoxy(15, 11);
    cout << "                   Sajjadul Islam Somon (5749)" << endl;
    gotoxy(15, 12);
    cout << "                   Raduan Ahamed        (4977)" << endl;
    gotoxy(15, 13);
    cout << "                   Akib Mahmud          (4881)" << endl;

    gotoxy(30, 20);
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
        cout << "1. Manager" << endl;
        gotoxy(40, 8);
        cout << "2. Customer" << endl;
        gotoxy(40, 9);
        cout << "3. Cashier" << endl;
        gotoxy(35, 11);
        cout << "Press \"ESC\" to Exit  [->" << endl;
        gotoxy(25, 17);
        cout << "Enter Valid Key . . . ";

        choice = getch();

        switch (choice)
        {
        case '1':
            managerLogin();
            break;

        case '2':
            loginOrSign();
            break;

        case '3':
            cashierLogin();
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

//==============================================================
//=========================File Handeling=======================
//==============================================================
void saveNewUserToFile(login *temp)
{
    ofstream file("l.csv", ios::app); // ios::app (append) to go to the last fo the file.
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else
    {
        file << temp->lname << "," << temp->lphone << "," << temp->lusername << "," << temp->lpassword << endl;
    }
    file.close();
}

void loadUsersFromFile()
{
    deleteList();
    ifstream file("l.csv");
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
            string sname, sphone, susername, spassword;
            if (getline(ss, sname, ',') && getline(ss, sphone, ',') && getline(ss, susername, ',') && getline(ss, spassword))
            {
                login *newUser = new login{sname, sphone, susername, spassword, nullptr};
                if (first == nullptr)
                {
                    first = newUser;
                }
                else
                {
                    login *temp = first;
                    while (temp->linker != nullptr)
                    {
                        temp = temp->linker;
                    }
                    temp->linker = newUser;
                }
            }
        }
    }
    file.close();
}
