// IN THE NAME OF GOD
#include <iostream>
#include <string.h>
using namespace std;
struct personel
{
    char name[20];
    char family[30];
    string personalcode;
    string natcode;
    string Side;
    float Salaryamount;
    int status;
    int childen;
} a[40], b;
void Blue(string str);
void Red(string str);
void Green(string str);
void read();
void montakhab();
void sort();
void write();
int main()
{
    read();
    montakhab();
    sort();
    write();
}
void Blue(string str) { cout << "\033[1;34m" << str << "\033[0m"; }
void Red(string str) { cout << "\033[1;31m" << str << "\033[0m\n"; }
void Green(string str) { cout << "\033[1;32m" << str << "\033[0m"; }
void read()
{
    for (int i = 0; i < 40; i++)
    {
        Blue("Enter the name of personnel");
        cout << i + 1 << "\n";
        cin >> a[i].name;
        Blue("Enter the last name of personnel");
        cout << i + 1 << "\n";
        cin >> a[i].family;
        Blue("Enter the personnel code of personnel");
        cout << i + 1 << "\n";
        cin >> a[i].personalcode;
        Blue("Enter the national code of personnel");
        cout << i + 1 << "\n";
        cin >> a[i].natcode;
        Blue("Enter the side of personnel");
        cout << i + 1 << "\n";
        cin >> a[i].Side;
        Blue("Enter the salary amount of personnel(toman)");
        cout << i + 1 << "\n";
        cin >> a[i].Salaryamount;
        Blue("Enter the marital status of personnel");
        cout << i + 1;
        Green("    single=1  ,  married=2");
        cout << "\n";
        cin >> a[i].status;
        Blue("Enter the number of children of personnel");
        cout << i + 1 << "\n";
        cin >> a[i].childen;
    }
}
void montakhab()
{
    Red("Personnel who have more than 2 children and their salary is less than 8 million Tomans:");
    cout << "\n";
    for (int i = 0; i < 40; i++)
        if (a[i].childen >= 2 && a[i].Salaryamount < 8000000)
            cout << a[i].name << " " << a[i].family << "\n";
}
void write()
{
    for (int i = 0; i < 40; i++)
        cout << a[i].name << " " << a[i].family << "\n";
}
void sort()
{
    for (int i = 1; i < 40; i++)
        for (int j = 0; j < 40 - i; j++)
        {
            if (strcmp(a[j].family, a[j + 1].family) > 0)
            {
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
            else if (strcmp(a[j].family, a[j + 1].family) == 0)
            {
                if (strcmp(a[j].name, a[j + 1].name) > 0)
                {
                    b = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = b;
                }
            }
        }
}
// Ali Barzegari