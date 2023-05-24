// IN THE NAME OF GOD
#include <iostream>
#include <string.h>
using namespace std;
struct storage
{
    char gname[30];
    char gnum[15];
    char gtype[30];
    long long int amount;
    long long int price;
    struct storage *fl;
} *start, *cur, *p;
void insert()
{
    char gn[15];
    long long int am;
    int sw = 0;
    cout << "\n please enter goods number for insert :";
    cin >> gn;
    cout << "\n enter amount : ";
    cin >> am;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->gnum, gn) == 0)
        {
            sw = 1;
            p->amount = am;
            cout << "\n this is amount inserted :";
        }
    if (!sw)
    {
        p = new struct storage;
        cur->fl = p;
        p->fl = NULL;
        cur = p;
        strcpy(p->gnum, gn);
        p->amount = am;
        cout << "\n please enter goods name: ";
        cin >> (p->gname);
        cout << "\n enter goods type:";
        cin >> (p->gtype);
        cout << "\n enter price: ";
        cin >> p->price;
    }
}
void report()
{
    cout << "\n the list of all goods in storage :";
    for (p = start->fl; p != NULL; p = p->fl)
        cout << "\n"
             << p->gname << " " << p->gnum << " " << p->gtype << " " << p->amount << " " << p->price;
}
void deletee()
{
    char gn[15];
    long long int am;
    struct storage *bp, *p;
    int sw = 0;
    cout << "\n please enter goods number ";
    cin >> (gn);
    cout << "\n please enter amount:";
    cin >> am;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->gnum, gn) == 0)
        {
            sw = 1;
            if (p->amount > am)
            {
                p->amount -= am;
                cout << "\n this amount deleted";
            }
            else if (p->amount == am)
            {
                for (bp = start; bp->fl != p; bp = bp->fl)
                    ;
                bp = p->fl;
                bp->fl = bp;
                p->fl = NULL;
                cout << "\n the amount is zero and record deleted:";
                delete p;
            }
            else
            {
                cout << "\n not enough and not deleted";
            }
            if (!sw)
                cout << "\n not found and not deleted";
        }
}
void search()
{
    char gt[30];
    cout << "\n please enter goods for search :";
    cin >> gt;
    for (p = start->fl; p != NULL; p = p->fl)
        if (strcmp(p->gtype, gt) == 0)
            cout << "\n"
                 << p->gname << " " << p->gnum << " " << p->gtype << " " << p->amount << " " << p->price;
}
int main()
{
    char ch;
    do
    {
        cout << " \n please enter i for insert, r for report, d for delete , s for search and x for exit:";
        cin >> ch;
        switch (ch)
        {
        case 'i':
        case 'I':
            insert();
            break;
        case 'd':
        case 'D':
            deletee();
            break;
        case 'r':
        case 'R':
            report();
            break;
        case 's':
        case 'S':
            search();
            break;
        }
    } while (ch != 'x' && ch != 'X');
}
// Ali Barzegari