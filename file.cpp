#include <bits/stdc++.h>
using namespace std;

struct node
{
    string data;
    int num;
    node *next;
} *head;

void addName();
void loadFromFile();
void saveToFile(string);
void clearList();

void saveToFile(node *temp)
{
    ofstream file("f.csv", ios::app); //ios::app (append) to go to the last fo the file.
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else 
    {
        file << temp->data << "," << temp->num << endl;
    }
    file.close();
}

void loadFromFile()
{
    ifstream file("f.csv");
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
                int i1;
                istringstream(s2) >> i1;    //Convert s2 to an integer

                node *newNode = new node{s1, i1, nullptr};
                if (!head)
                {
                    head = newNode;
                }
                else 
                {
                    node *temp = head;
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

void addName()
{
    node *newNode = new node;
    cin.ignore();
    cout << "Name: ";
    getline(cin, newNode->data);
    cout << "ID: ";
    cin >> newNode->num;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
    }
    else 
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    saveToFile(newNode);
    cout<<"successfull\n";
}

void clearList()
{
    //Clear List
    node *temp = head;
    while (temp != nullptr)
    {
        node *deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
    head = nullptr;     //indicate an empty list
}

void display()
{
    node *temp = head;
    if (!head) 
    {
        cout << "Empty!!!\n";
    }
    else 
    {
        while (temp)
        {
            cout<<temp->data<<endl<<temp->num<<endl<<endl;
            temp = temp->next;
        }
    }
}

int main()
{
    loadFromFile();
    int c=0;
    while (c != 3)
    {
        cout<<"\t\t1. add\n";
        cout<<"\t\t2. show\n";
        cout<<"\t\t3. exit\n";
        cin >> c;
        switch (c)
        {
        case 1:
            addName();
            break;
        case 2:
            display();
            break;
        case 3:
            break;
        default:
            break;
        }
    }
    return 0;
}