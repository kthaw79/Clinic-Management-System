// Header Files
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>

// Function Declaration
void menu();
void pascode();
void cpascode();

using namespace std;

// Class One
class one
{
public:
    virtual void get() = 0;
    virtual void show() = 0;
};

// class information
class info : public one
{
public:
    char name[50], time[50];
    int num, age;
    void get()
    {
        system("cls");
        cin.sync();
        cout << "\n Enter the patient name =";
        cin.getline(name, 50);
        cout << "\n Enter the appointment Time =";
        cin.getline(time, 50);
        cout << "\n Enter Age =";
        cin >> age;
        cout << "\n Enter Appointment No. =";
        cin >> num;
    }
    void show()
    {
        cout << "\n Name =" << name;
        cout << "\n Age =" << age;
        cout << "\n No =" << num;
        cout << "\n Time" << time;
    }
};

// class rana
class rana : public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Rana.txt", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(info));
        out.close();
        cout << "Your Entry has been saved.";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("rana.txt");
        if (in == NULL)
        {
            cout << "\n\n No Data In The File.";
            cout << "\n\n\t\t Press any key to continue: ";
            getch();
            menu();
        }
        else
        {
            while (!in.eof())
            {
                in.read((char *)&a1, sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};

// Class Dr Wagar
class Wagar : public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Wagar.txt", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(info));
        out.close();
        cout << "Your Entry has been saved.";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("wagar.txt");
        if (in == NULL)
        {
            cout << "\n\n No Data In The File.";
            cout << "\n\n\t\t Press any key to continue: ";
            getch();
            menu();
        }
        else
        {
            while (!in.eof())
            {
                in.read((char *)&a1, sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};

// Class Dr Ahmad
class Ahmad : public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Ahmad.txt", ios::app | ios::binary);
        a1.get();
        out.write((char *)&a1, sizeof(info));
        out.close();
        cout << "Your Entry has been saved.";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("ahmad.txt");
        if (in == NULL)
        {
            cout << "\n\n No Data In The File.";
            cout << "\n\n\t\t Press any key to continue: ";
            getch();
            menu();
        }
        else
        {
            while (!in.eof())
            {
                in.read((char *)&a1, sizeof(a1));
                a1.show();
            }
            in.close();
            getch();
            menu();
        }
    }
};

class staf : public one
{
public:
    char all[999];
    char name[50], age[20], sal[30], pos[20];

    void get()
    {
        ofstream out("staff.txt", ios::app);
        {
            system("cls");
            cin.sync();
            cout << "\nEnter Name = ";
            cin.getline(name, 50);
            cout << "\nEnter Age = ";
            cin.getline(age, 20);
            cout << "\nEnter Salary = ";
            cin.getline(sal, 30);
            cout << "\nEnter Working Position = ";
            cin.getline(pos, 20);
        }
        out << "\nName = " << name << "\nAge = " << age
            << "\nSalary = " << sal << "\nWorking Position = "
            << pos;
        out.close();
        cout << "\n\nYour Information has been saved:\n\t\t\tPress any key to continue: ";
        getch();
        menu();
    }
    void show()
    {
        ifstream in("staff.txt");
        if (!in)
        {
            cout << "File open error";
        }
        while (!(in.eof()))
        {
            in.getline(all, 999);
            cout << all << endl;
        }
        in.close();
        cout << "\n\nYour Information has been saved:\n\t\t\tPress any key to continue: ";
        getch();
        menu();
    }
};

// Class Information
class information
{
    void drinfo()
    {
        system("cls");
        system("color F3");
        cout << "\n=================================================================================\n";
        cout << "\n\n\t\t(Three Doctors Available) \n\n \t\t[Information And Time Are Given Below]\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "\t\tDr Available:\n";
        cout << "\t\t\t [[Time]]:\n\n";
        cout << "\tMonday To Friday\t\t9AM TO 5PM\n";
        cout << "\tSaturday        \t\t9AM TO 1PM\n";
        cout << "\tSunday          \t\t OFF\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "\t\tDr. Wagar (Child Specialist)\n\n";
        cout << "\t\t\t [[Time]]:\n\n";
        cout << "\tMonday To Friday\t\t2AM TO 10PM\n";
        cout << "\tSaturday        \t\t8AM TO 1PM\n";
        cout << "\tSunday          \t\t12PM TO 9PM\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "\t\tDr. Ahmad (DVM)\n\n";
        cout << "\t\t\t [[Time]]:\n\n";
        cout << "\tMonday To Friday\t\t8AM TO 5PM\n";
        cout << "\tSaturday        \t\t10AM TO 1PM\n";
        cout << "\tSunday          \t\t OFF\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Press any key to continue: ";
        getch();
        menu();
    }
};

void call_dr()
{
    system("cls");
    int choice;
    cout << "\n\n\n\t\t Press 1 for Dr Rana \n\n\t\t Press 2 for Dr Wagar \n\n\t\t Press 3 for Dr Ahmad ";
    cin >> choice;

    one *ptr;
    rana s3;
    Wagar s4;
    Ahmad s5;
    if (choice == 1)
    {
        ptr = &s3;
        ptr->get();
    }
    else if (choice == 2)
    {
        ptr = &s4;
        ptr->get();
    }
    else if (choice == 3)
    {
        ptr = &s5;
        ptr->get();
    }
    else
    {
        cout << "Sorry Invalid Choice: ";
        getch();
        menu();
    }
}

void manue()
{
}