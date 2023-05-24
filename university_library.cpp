// IN THE NAME OF GOD
#include <iostream>
#include <string.h>
using namespace std;
struct library
{
    char bname[30];
    char writer[30];
    char translator[30];
    char isbn[15];
    int amount;
    struct library *fl, *bl;
};
class callib
{
public:
    callib();
    void insert(char[], int);
    void del(char[]);
    void report();
    void borrowing(char[]);
    void returning(char[]);
    int searchbook(char[]);

private:
    struct library *start, *cur, *p;
};
callib::callib()
{
    start = new struct library;
    start->fl = NULL;
    start->bl = NULL;
    cur = start;
}
void callib::insert(char is[], int m)
{
    int sw = 0;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
    {
        if (strcmp(p->isbn, is) == 0)
        {
            sw = 1;
            p->amount += m;
            cout << "\n this amount inserted";
        }
        if (!sw)
        {
            p = new struct library;
            p->fl = NULL;
            p->bl = cur;
            cur->fl = p;
        }
        cur = p;
        strcpy(p->isbn, is);
        p->amount = m;
        cout << "\n please enter book name:";
        cin >> p->bname;
        cout << "\n please enter writer:";
        cin >> p->writer;
        cout << "\n please enter translator:";
        cin >> p->translator;
    }
}
void callib::del(char is[])
{
    int sw = 0;
    struct library *bp, *ap;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
    {
        if (strcmp(p->isbn, is) == 0)
        {
            sw = 1;
            bp = p->bl;
            ap = p->fl;
            bp->fl = ap;
            ap->bl = bp;
            p->fl = NULL;
            p->bl = NULL;
            cout << "\n"
                 << p->bname << "deleted";
            delete p;
        }
        if (!sw)
            cout << "\n this book not found and not deleted";
    }
}
void callib::report()
{
    cout << "\n the list of all books";
    for (p = start->fl; p != NULL; p = p->fl)
    {
        cout << "\n"
             << p->bname << p->writer << p->translator << p->isbn << " " << p->amount;
    }
}
void callib::borrowing(char is[])
{
    int sw = 0;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
    {
        if (strcmp(p->bname, is) == 0)
        {
            sw = 1;
            p->amount--;
            cout << "\n this book borrowed";
        }
    }
}
void callib::returning(char is[])
{
    int sw = 0;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->bname, is) == 0)
        {
            sw = 1;
            p->amount++;
            cout << "\n this book returned to this colledge library ";
        }
}
int callib::searchbook(char is[])
{
    int am = 0;
    int sw = 0;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->bname, is) == 0)
        {
            sw = 1;
            am = p->amount;
        }
    return am;
}
class centerallib
{
public:
    centerallib();
    void cinsert();
    void cdel();
    void cborrow();
    void creport();
    void creturning();

private:
    struct library *start, *cur, *p;
    callib X[4];
};
centerallib::centerallib()
{
    start = new struct library;
    start->fl = NULL;
    start->bl = NULL;
    cur = start;
}
void centerallib::cinsert()
{
    int libno;
    int sw = 0;
    char is[15];
    int am;
    cout << "\n please enter isbn of book for insert";
    cin >> is;
    cout << "\n please enter library number of book for insert";
    cin >> libno;
    cout << "\n please enter amount of book for insert";
    cin >> am;
    if (libno >= 0 && libno < 4)
    {
        X[libno].insert(is, am);
    }
    else if (libno == 4)
    {
        for (p = start->fl; p != NULL && !sw; p = p->fl)
            if (strcmp(p->isbn, is) == 0)
            {
                sw = 1;
                p->amount += am;
                cout << "\n this amount of this book inserted to central library";
            }
            else
            {
                p = new struct library;
                p->fl = NULL;
                p->bl = cur;
                cur->fl = p;
                cur = p;
                strcpy(p->isbn, is);
                p->amount = am;
                cout << "\n please enter book name:";
                cin >> p->bname;
                cout << "\n please enter writer:";
                cin >> p->writer;
                cout << "\n please enter translator:";
                cin >> p->translator;
            }
    }
    else
    {
        cout << "the library number is incorrect  and the book not insert";
    }
}
void centerallib::cdel()
{
    int sw = 0;
    char is[15];
    struct library *bp, *ap;
    cout << "\n please enter isbn of book for delete";
    cin >> is;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->isbn, is) == 0)
        {
            sw = 1;
            bp = p->bl;
            ap = p->fl;
            bp->fl = ap;
            ap->bl = bp;
            p->fl = NULL;
            p->bl = NULL;
            cout << "\n"
                 << p->bname << " " << p->isbn << " " << p->writer << " " << p->translator << "deleted";
            delete p;
        }
    if (!sw)
    {
        cout << "\n this book not found in central library and not deleted";
    }
    for (int i = 0; i < 4; i++)
        X[i].del(is);
}
void centerallib::creport()
{
    cout << "the list of all book in central library";
    for (p = start->fl; p != NULL; p = p->fl)
        cout << "\n"
             << p->bname << " " << p->isbn << " " << p->writer << " " << p->translator << " " << p->amount;
    for (int i = 0; i < 4; i++)
    {
        cout << "\n college library number(" << i << "):";
        X[i].report();
    }
}
void centerallib::cborrow()
{
    char is[15];
    int sw = 0;
    cout << "\n please enter isbn of book for boroow";
    cin >> is;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->isbn, is) == 0)
        {
            sw = 1;
            p->amount--;
            cout << "\n this book borrowed from central library";
        }
    if (!sw)
        for (int i = 0; i < 4 && !sw; i++)
            if (X[i].searchbook(is) > 0)
            {
                sw = 1;
                X[i].borrowing(is);
            }
    if (!sw)
        cout << "\n this book not found in all libraries and not borrowed";
}
void centerallib::creturning()
{
    char is[15];
    int sw = 0;
    int libno;
    cout << "\n please enter isbn of book for returning:";
    cin >> is;
    cout << "\n please enter library number for returning:";
    cin >> libno;
    if (libno >= 0 && libno < 4)
        X[libno].returning(is);
    else if (libno == 4)
    {
        for (p = start->fl; p != NULL && !sw; p = p->fl)
            if (strcmp(p->isbn, is) == 0)
            {
                sw = 1;
                p->amount++;
                cout << "\n this book returned to centeral library";
            }
        if (!sw)
            cout << "\n this book not found in central library and not returned";
    }
    else
        cout << "\n the library number is incorrect and this book not returned";
}
int main()
{
    char ch;
    centerallib y;
    do
    {
        cout << " \n please enter i for insert, r for report, d for delete,u for return , b for borrowing and x for exit:";
        cin >> ch;
        switch (ch)
        {
        case 'i':
        case 'I':
            y.cinsert();
            break;
        case 'd':
        case 'D':
            y.cdel();
            break;
        case 'r':
        case 'R':
            y.creport();
            break;
        case 'b':
        case 'B':
            y.cborrow();
            break;
        case 'u':
        case 'U':
            y.creturning();
            break;
        }
    } while (ch != 'x' && ch != 'X');
    return 0;
}
// Ali Barzegari