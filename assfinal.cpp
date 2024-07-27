#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MA_Staff = 45;

int i, Num_Staff, op, Op_update, Id_update, ID_delete;
bool isfound;
string username, password;
void login()
{

    cout << "\t********** Login MENU **********" << endl;
    cout << "\tEnter Username: ";
    cin >> username;
    cout << "\tEnter Password: ";
    cin >> password;
    if (username == "Ad" && password == "123")
    {
        cout << "\tPlease wait";
        for (int j = 1; j <= 5; j++)
        {
            Sleep(200);
            cout << "...";
        }
        cout << "\n\tLogin Successful" << endl;
        Sleep(1000);
    }

    else
    {
        cout << "\tWrong Option, Please Try Again" << endl;
        Sleep(1000);
    }
}

struct Staff
{
    string Name, position;
    int Age, salary, Dob, Id;
    char Gender;
};

struct Custommer
{

    string Name, Service;
    int Age;
    char Gender;
    double price, price_perday, total_price;
};

Staff staffshow[MA_Staff];
int staff_Startfrom = 0;
/*----------------------------------Add staff section----------------------------------*/
void addstaff()
{
Input:
    cout << "\t--------------- Add New Staff ---------------" << endl;
    cout << "\tHow many Staff do you want to input:";
    cin >> Num_Staff;
    for (i = 0; i < Num_Staff; i++)
    {
        if (Num_Staff > MA_Staff)
        {
            cout << "\tPlease wait";
            for (int j = 1; j <= 5; j++)
            {
                Sleep(200);
                cout << "...";
            }
            cout << "\n";
            cout << "\t-----------------------------\n";
            cout << "\tSorry !!! Staff is limit 45! " << endl;
            cout << "\tPress Any key To Input Again " << endl;
            cout << "\t-----------------------------\n";
            getch();
            system("cls");
            goto Input;
        }

        else if (staff_Startfrom < MA_Staff)
        {

            system("cls");
            cout << "\t-------- New Staff Form ----------" << endl;
            cout << " \t Enter ID           :";
            cin >> staffshow[staff_Startfrom].Id;
            cout << " \t Enter Name         :";
            cin.ignore();
            getline(cin, staffshow[staff_Startfrom].Name);
            cout << "\t Enter Gender        :";
            cin >> staffshow[staff_Startfrom].Gender;
            cout << " \t Enter Date Of birth :";
            cin >> staffshow[staff_Startfrom].Dob;
            cout << "\t Enter Age           :";
            cin >> staffshow[staff_Startfrom].Age;
            cout << "\t Enter Position      :";
            cin >> staffshow[staff_Startfrom].position;
            cout << "\t Enter Salary        :";
            cin >> staffshow[staff_Startfrom].salary;
            staff_Startfrom++;

            cout << "\t successfull Staffing  \n\n";
            Sleep(1000);
        }
        else
        {
            cout << "\t Sorry !!! Staff is Full" << endl;
            Sleep(1000);
        }
    }
}
/*----------------------------------Screen staff section----------------------------------*/
void ScreenStaff()
{
    cout << fixed << showpoint << setprecision(2);
    system("cls");
    if (staff_Startfrom == 0)
    {
        cout << "\tNo Staff Information Available" << endl;
    }
    else
    {

        for (i = 0; i < staff_Startfrom; i++)
        {
            cout << "-------------------------------------------" << endl;
            cout << "\tStaff " << i + 1 << " Information:" << endl;
            cout << " Staff ID                  :" << staffshow[i].Id << endl;
            cout << " Staff Name                :" << staffshow[i].Name << endl;
            cout << " Staff Gender              :" << staffshow[i].Gender << endl;
            cout << " Staff Date Of birth       :" << staffshow[i].Dob << endl;
            cout << " Staff Age                 :" << staffshow[i].Age << endl;
            cout << " Staff Position            :" << staffshow[i].position << endl;
            cout << " Staff Salary              :" << staffshow[i].salary << "$ Per Month " << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    system("pause");
}
/*----------------------------------Update staff section----------------------------------*/
void updatestaff()
{
update1:
    system("cls");

    cout << " \t 1 Update ID                :" << endl;
    cout << " \t 2 Update Name              :" << endl;
    cout << " \t 3 Update All               :" << endl;
    cout << "-------------------------------------------" << endl;
    cout << " \t Please Enter an Option     :" << endl;
    cin >> Op_update;
    switch (Op_update)
    {
    case 1:
    id_update:
        cout << " Enter ID to Update             :";
        isfound = 0;
        cin >> Id_update;
        for (i = 0; i < staff_Startfrom; i++)
        {
            if (Id_update == staffshow[i].Id)
            {
                cout << "-------------------------------------------" << endl;
                cout << "Staff Update           :" << staffshow[i].Id << endl;
                cout << "Enter New Staff ID     :";
                cin >> staffshow[staff_Startfrom].Id;
                isfound = 1;
                cout << "-------------------------------------------" << endl;
            }
        }
        if (isfound == 0)
        {
            cout << "\tID " << Id_update << " Not found in the list\n";
            goto id_update;
        }
        break;
    case 2:
    name_update:
        cout << " Enter ID to Update             :";
        isfound = 0;
        cin >> Id_update;
        for (i = 0; i < staff_Startfrom; i++)
        {
            if (Id_update == staffshow[i].Id)
            {
                cout << "-------------------------------------------" << endl;
                cout << "Staff Name        :" << staffshow[i].Name << endl;
                cout << "Enter New Staff ID     :";
                cin >> staffshow[staff_Startfrom].Name;
                isfound = 1;
                cout << "-------------------------------------------" << endl;
            }
        }
        if (isfound == 0)
        {
            cout << "\tID " << Id_update << " Not found in the list\n";
            goto name_update;
        }
        break;
    case 3:
    all_update:
        cout << "\tEnter Id to Update All:";
        isfound = 0;
        cin >> Id_update;
        for (i = 0; i < staff_Startfrom; i++)
        {
            if (Id_update == staffshow[i].Id)
            {
                cout << "-------------------------------------------" << endl;
                cout << "\tStaff " << i + 1 << " Information:" << endl;
                cout << " Staff ID                  :" << staffshow[i].Id << endl;
                cout << " Staff Name                :" << staffshow[i].Name << endl;
                cout << " Staff Gender              :" << staffshow[i].Gender << endl;
                cout << " Staff Date Of birth       :" << staffshow[i].Dob << endl;
                cout << " Staff Age                 :" << staffshow[i].Age << endl;
                cout << " Staff Position            :" << staffshow[i].position << endl;
                cout << " Staff Salary              :" << staffshow[i].salary << "$ Per Month " << endl;
                cout << "-------------------------------------------" << endl;
                cout << " \t Enter ID           :";
                cin >> staffshow[staff_Startfrom].Id;
                cout << " \t Enter Name         :";
                cin.ignore();
                getline(cin, staffshow[staff_Startfrom].Name);
                cout << "\t Enter Gender        :";
                cin >> staffshow[staff_Startfrom].Gender;
                cout << " \t Enter Date Of birth :";
                cin >> staffshow[staff_Startfrom].Dob;
                cout << "\t Enter Age           :";
                cin >> staffshow[staff_Startfrom].Age;
                cout << "\t Enter Position      :";
                cin >> staffshow[staff_Startfrom].position;
                cout << "\t Enter Salary        :";
                cin >> staffshow[staff_Startfrom].salary;
                cout << "-------------------------------------------" << endl;
                isfound = 1;
                break;
            }
        }
        if (isfound == 0)
        {
            cout << "\tId " << Id_update << "not found in the list\n";
            goto all_update;
        }

        break;

        cout << "\tWrong Option Please try again\n";
        goto update1;
    }
}
/*----------------------------------Delete staff section----------------------------------*/
void DeleteStaff()
{
delete2:
    cout << "\t-------- Delete Staff Form ----------" << endl;
    cout << "\t Enter ID to Delete        :";
    isfound = 0;
    cin >> ID_delete;
    for (i = 0; i < staff_Startfrom; i++)
    {

        if (ID_delete == staffshow[i].Id)
        {

            for (int j = i; j < staff_Startfrom; j++)
            {
                staffshow[i] = staffshow[i + 1];
            }
            staff_Startfrom--;
            cout << "\tStaff Deleted Successfully" << endl;
            Sleep(200);
        }
    }
    if (isfound == 0)
    {
        cout << "-------------------------------------------" << endl;
        cout << "\tDelete is not complete!!!\n";
        cout << "-------------------------------------------" << endl;
        goto delete2;
    }
    else
    {
        cout << "-------------------------------------------" << endl;
        cout << "\tDelete is completed!!\n";
        cout << "-------------------------------------------" << endl;
    }
}
/*----------------------------------Service list section---------------------------------*/
void service()
{
    cout << "\t--------==>  Petien Care  <==----------" << endl;
    cout << "-----EMERGENCY AND ICU-----\n - Emergency\n - General ICU \n - Neuro - ICU \n";
    cout << "-----OUTPATIENT SERVICES-----\n - ENT(Ear, Nose and Throat) \n - Eye Care - Dental Service\n - Dermatology & Venereology \n ";
    cout << "-----GYNECO-MATER-NEO-----\n - Gynecology \n - Maternity \n - Neonate Care \n ";
    cout << "-----SERVICES & FACILITIES-----\n - Cancer \n - Heart Diseases \n - Diabetes-Endocrine Disorder\n - Gastroenterology and Liver \n  - Kidneys and Hemodialysis Services \n- Procedures and Tests \n ";
    cout << "-----SURGERY-----\n - General, Digestive and Oncological Surgery \n - Neurosurgery \n  - Trauma-Orthopaedic Surgery";
}
void about()
{
    cout << "\t--------==>  About Us   <==----------" << endl;
    cout << "\t " << endl;
    cout << "-------------------------------------------" << endl;
}
/*----------------------------------staff Menu section----------------------------------*/
/*
void staffmenu()
{
Cin:
    system("cls");
    cout << "\t--------  Staff Menu ----------" << endl;
    cout << "\t1. Add Staff" << endl;
    cout << "\t2. View Staff" << endl;
    cout << "\t3. Update Staff" << endl;
    cout << "\t4. Delete Staff" << endl;
    cout << "\t5. Back To Main Menu" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "\tPlease Enter an Option : ";
    cin >> op;
    switch (op)
    {
    case 1:
        addstaff();
        break;
    case 2:
        ScreenStaff();
        break;
    case 3:
        updatestaff();
        break;
    case 4:
        DeleteStaff();
        break;
    case 5:
        screenMainmenu();
        break;
    default:
        cout << "nvalid Option !!! " << endl;
        goto Cin;
        break;
    }
}
* /
    /*----------------------------------Main Menu section----------------------------------*/
/*
void Mainmenu()
{
    system("cls");
    cout << "\t********** Main Menu **********" << endl;
    cout << "\t1. Staff Info" << endl;
    cout << "\t2. Customer Info" << endl;
    cout << "\t3. View Services" << endl;
    cout << "\t4. View Customers" << endl;
    cout << "\t5. View Staffs" << endl;
    cout << "\t6. Exit" << endl;
    cout << "\tPlease Enter an Option : ";
    cin >> op;
    /*
        switch (op)
        {
        case 1:
            staffMenu();
            break;
        case 2:
            customerMenu();
            break;
        case 3:
            displayServices();
            break;
        case 4:
            viewCustomerServices();
            break;
        case 5:
            viewStaff();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\tWrong Option, Please Try Again" << endl;
            Sleep(1000);
            break;
        }
}
*/
int main()
{

    service();

    return 0;
}
