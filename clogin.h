// #include <bits/stdc++.h>
// #include <conio.h>
// #include "animation.h"

// #ifndef clogin
// #define clogin

// // using namespace std;
// // #define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

// struct login
// {
//     string lname;
//     string lphone;
//     string lusername;
//     string lpassword;
//     login *linker;
// } *first = nullptr;

// void loginOrSign();
// void signup();
// bool customerLogin();
// void saveNewUserToFile(login *temp);
// void loadUsersFromFile();

// //===========================================================================
// //========================== Customer Function ==============================
// //===========================================================================
// void loginOrSign()
// {
//     system("cls");

//     char choice;
//     do
//     {
//         gotoxy(15, 2);
//         cout << "+---------------------------------------------------------------+";
//         gotoxy(15, 3);
//         cout << "|                         Please Select                         |";
//         gotoxy(15, 4);
//         cout << "+---------------------------------------------------------------+";
//         gotoxy(30, 7);
//         cout << "[Login (Enter)]";
//         gotoxy(65, 7);
//         cout << "[Sign Up   (+)]";
//         gotoxy(40, 8);
//         cout << "[ <-- Back ]";
//         choice = getch();
//         switch (choice)
//         {
//         case 18:
//             customerlogin();
//             break;
//         case 43:
//             signup();
//             break;
//         case 8:
//             break;
//         default:
//             gotoxy(30, 10);
//             cout << "Please Enter Valid Key";
//             customerLogin();
//             break;
//         }
//         while (choice != 8)
//             ;
//     }
// }

// void signup()
// {
//     system("cls");

//     gotoxy(15, 2);
//     cout << "+---------------------------------------------------------------+";
//     gotoxy(15, 3);
//     cout << "|                            Sigh Up                            |";
//     gotoxy(15, 4);
//     cout << "+---------------------------------------------------------------+";

//     login *newUser = new login;

//     gotoxy(30, 7);
//     cout << "Full Name          : ";
//     cin.ignore();
//     getline(cin, newUser->lname);

//     gotoxy(30, 8);
//     cout << "Phone Number       : ";
//     cin >> newUser->lphone;

//     gotoxy(30, 9);
//     cout << "Username (No Space): ";
//     cin >> newUser->lusername;

//     gotoxy(30, 10);
//     cout << "Password (No Space): ";
//     cin >> newUser->lpassword;

//     saveNewUserToFile(newUser);

//     newUser->linker = nullptr;
//     if (first == nullptr)
//     {
//         first == newUser;
//     }
//     else
//     {
//         login *temp = first;
//         while (temp->linker != nullptr)
//         {
//             temp = temp->linker;
//         }
//         temp->linker = newUser;
//     }

//     gotoxy(30, 14);
//     cout << "Sign Up Successful . . .\n";

//     gotoxy(30, 20);
//     system("pause");
//     customerLogin();
// }

// bool customerLogin()
// {
//     system("cls");

//     gotoxy(15, 2);
//     cout << "+---------------------------------------------------------------+";
//     gotoxy(15, 3);
//     cout << "|                        Customer Login                         |";
//     gotoxy(15, 4);
//     cout << "+---------------------------------------------------------------+";

//     gotoxy(32, 7);
//     cout << "Login . . . . . . . . . . . . . .";
//     gotoxy(32, 8);
//     cout << "`````````````````````````````````";
//     string username, password;
//     gotoxy(30, 10);
//     cout << "Customer-Username : ";
//     cin >> username;
//     gotoxy(30, 11);
//     cout << "Password          : ";
//     char ch;
//     while (1)
//     {
//         ch = getch();
//         if (ch == 43)
//         {
//             signup();
//         }
//         else if (ch == 13)
//         {
//             break;
//         }
//         else if (ch == 8)
//         {
//             if (!password.empty())
//             {
//                 password.pop_back();
//                 cout << "\b \b";
//             }
//         }
//         else
//         {
//             password.push_back(ch);
//             cout << "*";
//         }
//     }
//     login *temp = first;
//     while (temp != nullptr)
//     {
//         if (username == temp->lusername && password == temp->lpassword)
//         {
//             gotoxy(30, 14);
//             cout << "Login Susscessfull . . .\n";
//             loadingBar();
//             // Customer();
//             break;
//             ;
//         }
//         temp = temp->linker;
//     }
//     if (temp == nullptr)
//     {
//         gotoxy(30, 14);
//         cout << "Wrong Username or Password . . .\n\n";
//         gotoxy(30, 15);
//         cout << "Your entered Password :  " << password << endl;
//         gotoxy(30, 20);
//         system("pause");
//         customerLogin();
//     }
//     return true;
// }

// //==============================================================
// //=========================File Handeling=======================
// //==============================================================
// void saveNewUserToFile(login *temp)
// {
//     ofstream file("l.csv", ios::app); // ios::app (append) to go to the last fo the file.
//     if (!file.is_open())
//     {
//         cout << "File is unable to open.\n";
//     }
//     else
//     {
//         file << temp->lname << "," << temp->lphone << "," << temp->lusername << "," << temp->lpassword << endl;
//     }
//     file.close();
// }

// void loadUsersFromFile()
// {
//     deleteList();
//     ifstream file("l.csv");
//     if (!file.is_open())
//     {
//         cout << "Unable to open File.\n";
//     }
//     else
//     {
//         string line;
//         bool headerskipped = false;
//         while (getline(file, line))
//         {
//             if (!headerskipped)
//             {
//                 headerskipped = true;
//                 continue;
//             }
//             istringstream ss(line);
//             string sname, sphone, susername, spassword;
//             if (getline(ss, sname, ',') && getline(ss, sphone, ',') && getline(ss, susername, ',') && getline(ss, spassword))
//             {
//                 login *newUser = new login{sname, sphone, susername, spassword, nullptr};
//                 if (first == nullptr)
//                 {
//                     first = newUser;
//                 }
//                 else
//                 {
//                     login *temp = first;
//                     while (temp->linker != nullptr)
//                     {
//                         temp = temp->linker;
//                     }
//                     temp->linker = newUser;
//                 }
//             }
//         }
//     }
//     file.close();
// }

// #endif