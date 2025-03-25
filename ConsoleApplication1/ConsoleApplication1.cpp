#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#pragma warning(disable : 4996)
using namespace std;

const int MAX_NUMBER_LENGTH = 11;
const int MAX_OPERATOR_LENGTH = 20;
struct Phone {
    char number[MAX_NUMBER_LENGTH];     //номер телефону
    char operatorName[MAX_OPERATOR_LENGTH]; //оператор
    float debt;          //заборгованість по оплаті
};
struct Subscriber {
    char surname[20];    //прізвище
    char address[20];    //адреса
    struct Phone phone; //номер телефону
};



FILE* fp; // покажчик на файл

//------------------введення даних-----------------------
void input()
{
    Subscriber subscriber;
    
    char answer;

    fp = fopen("fp.dat", "ab"); // відкриття файлу для допису
    if (fp == NULL) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    do
    {
        cout << "Enter subscriber's surname: ";
        cin >> subscriber.surname;
        cout << "Enter subscriber's address: ";
        cin >> subscriber.address;
        cout << "Enter phone number: ";
        cin >> subscriber.phone.number;
        cout << "Enter phone operator: ";
        cin >> subscriber.phone.operatorName;
        cout << "Enter phone debt: ";
        cin >> subscriber.phone.debt;

        fwrite(&subscriber, sizeof(Subscriber), 1, fp);
       

        cout << "Continue input? (y/n): ";
        answer = getch();
    } while (answer != 'n');

    fclose(fp); // закриття файлу
    getch(); // чекати натискання клавіші
}

//------------читання даних з файлу----------------------
void read_from_file() {
    Subscriber subscriber;
  

    // Відкриття файлу для читання
    fp = fopen("fp.dat", "rb");
    if (fp == NULL) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    // Виведення заголовку
    cout << "Subscribers list:\n";
    cout << left << setw(20) << "Surname" << setw(20) << "Address" << setw(15) << "Number" << setw(15) << "Operator" << setw(8) << "Debt" << endl;

    // Читання даних абонентів
    while (fread(&subscriber, sizeof(Subscriber), 1, fp)) {
        cout << left << setw(20) << subscriber.surname << setw(20) << subscriber.address
        << setw(15) << subscriber.phone.number << setw(15) << subscriber.phone.operatorName <<
            setw(8) << subscriber.phone.debt << endl;
    }

    fclose(fp);
    getch();
}

//-------------заміна даних в файлі----------------
void replace_in_file()
{
    Subscriber subscriber;

    char number[MAX_NUMBER_LENGTH];

    cout << "Enter the phone number to replace: ";
    cin >> number;

    fp = fopen("fp.dat", "r+b");
    if (fp == NULL) {
        cerr << "File does not exist!";
        getch();
        return;
    }

    while (fread(&subscriber, sizeof(Subscriber), 1, fp) ) {
        if (strcmp(subscriber.phone.number, number) == 0) {
            cout << "Enter new subscriber's surname: ";
            cin >> subscriber.surname;
            cout << "Enter new subscriber's address: ";
            cin >> subscriber.address;
            cout << "Enter new phone operator: ";
            cin >> subscriber.phone.operatorName;
            cout << "Enter new phone debt: ";
            cin >> subscriber.phone.debt;

            fseek(fp,ftell(fp) -sizeof(Subscriber), SEEK_SET);
            fwrite(&subscriber, sizeof(Subscriber), 1, fp);

            fclose(fp);
            cout << "Data replaced successfully!";
            getch();
            return;
        }
    }
    fclose(fp);
    cout << "Phone number not found!";
    getch();
}

//-------------видалення даних з файлу---------------
void delete_from_file()
{
    Subscriber subscriber;
    Phone phone;
    char number[MAX_NUMBER_LENGTH];

    cout << "Enter the phone number to delete: ";
    cin >> number;

    FILE* tempFile = fopen("temp.dat", "wb");
    if (!(fp = fopen("fp.dat", "rb"))) {
        cerr << "File does not exist!";
        getch();
        return;
    }

    bool found = false;
    while (fread(&subscriber, sizeof(Subscriber), 1, fp)) {
        if (strcmp(subscriber.phone.number, number) != 0) {
            fwrite(&subscriber, sizeof(Subscriber), 1, tempFile);
           
        }
        else {
            found = true;
        }
    }
    fclose(fp);
    fclose(tempFile);

    remove("fp.dat");
    rename("temp.dat", "fp.dat");

    if (found)
        cout << "Data deleted successfully!";
    else
        cout << "Phone number not found!";

    getch();
}

//-----------запит на прізвища заборгованістю-------------
void search_debt(float debtThreshold)
{
    Subscriber subscriber;
    
    bool found = false;
    if (!(fp = fopen("fp.dat", "rb"))) {
        cerr << "File does not exist!";
        getch();
        return;
    }

    cout << "Subscribers with debt exceeding " << debtThreshold << ":\n";
    cout << "Surname\t\tAddress\t\tNumber\t\tOperator\tDebt\n";

    while (fread(&subscriber, sizeof(Subscriber), 1, fp)) {
        if (subscriber.phone.debt > debtThreshold) {
            found = true;
            cout << subscriber.surname << "\t\t" << subscriber.address << "\t\t"
                << subscriber.phone.number << "\t\t" << subscriber.phone.operatorName << "\t\t"
                << subscriber.phone.debt << endl;
        }
    }

    fclose(fp);

    if (!found)
        cout << "No subscribers found with debt exceeding " << debtThreshold << endl;

    getch();
}

//-------------пошук абонента за номером телефону---------------
void search_by_number(const char* phoneNumber)
{
    Subscriber subscriber;

    bool found = false;

    if (!(fp = fopen("fp.dat", "rb"))) {
        cerr << "File does not exist!";
        getch();
        return;
    }

    while (fread(&subscriber, sizeof(Subscriber), 1, fp)) {
        if (strcmp(subscriber.phone.number, phoneNumber) == 0) {
            found = true;
            cout << "Subscriber found:\n";
            cout << "Surname: " << subscriber.surname << endl;
            cout << "Address: " << subscriber.address << endl;
            cout << "Number: " << subscriber.phone.number << endl;
            cout << "Operator: " << subscriber.phone.operatorName << endl;
            cout << "Debt: " << subscriber.phone.debt << endl;
            break;
        }
    }

    fclose(fp);

    if (!found)
        cout << "Subscriber not found with number " << phoneNumber << endl;

    getch();
}

//-------------------головна програма--------------------
int main()
{
    while (true)
    {
        system("cls");
        cout << "          MENU  \n\n";
        cout << "1. Input data\n";
        cout << "2. Read data from file\n";
        cout << "3. Replace data in file\n";
        cout << "4. Delete data from file\n";
        cout << "5. Search subscribers by debt\n";
        cout << "6. Search subscriber by phone number\n";
        cout << "7. Exit\n\n";
        cout << "Choose menu item: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:  input(); break;
        case 2:  read_from_file(); break;
        case 3:  replace_in_file(); break;
        case 4:  delete_from_file(); break;
        case 5: {
            float threshold;
            cout << "Enter debt threshold: ";
            cin >> threshold;
            search_debt(threshold);
            break;
        }
        case 6: {
            char phoneNumber[MAX_NUMBER_LENGTH];
            cout << "Enter phone number to search: ";
            cin >> phoneNumber;
            search_by_number(phoneNumber);
            break;
        }
        case 7:  exit(0); break;
        default: cout << "Invalid choice. Try again.\n"; break;
        }
    }
    return 0;
}
