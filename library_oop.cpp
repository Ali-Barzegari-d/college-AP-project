// IN THE NAME OF GOD
#include <iostream>
#include <string.h>
using namespace std;
struct library
{
    char b_name[15];
    char b_isbn[15];
    char b_writer[15];
    char b_translator[15];
    char b_subject[15];
    int b_amount;
    struct library *bl, *fl;
};
class lib
{
public:
    lib();
    void insert();
    void sort();
    void report();
    void deletee();
    void search();
    void lending();
    void unrent();

private:
    struct library *start, *cur, *p;
};
lib::lib()
{
    start = new struct library;
    start->fl = NULL;
    start->bl = NULL;
    cur = start;
}
void lib::insert()
{
    int sw = 0, am;
    char is[15];
    cout << "\n please enter isbn for insert";
    cin >> is;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->b_isbn, is) == 0)
        {
            sw = 1;
            cout << "\n please enter amount for isbn";
            cin >> am;
            p->b_amount += am;
            cout << "\n this amount inserted successfully";
        }
    if (!sw)
    {
        p = new struct library;
        p->fl = NULL;
        p->bl = cur;
        cur->fl = p;
        cur = p;
        strcpy(p->b_isbn, is);
        cout << "\n enter book name:";
        cin >> p->b_name;
        cout << "\n enter writer:";
        cin >> p->b_writer;
        cout << "\n enter translator:";
        cin >> p->b_translator;
        cout << "\n enter subject:";
        cin >> p->b_subject;
        cout << "\n enter amount:";
        cin >> p->b_amount;
    }
}
void lib::sort()
{
    struct library *q, *bp, *ap, *aq, *bq;
    for (p = start->fl; p->fl != NULL; p = p->fl)
    {
        bp = p->bl;
        ap = p->fl;
        for (q = p->fl; q != NULL; q = q->fl)
        {
            bq = q->bl;
            aq = q->fl;
            if (strcmp(p->b_name, q->b_name) > 0)
                if (p->fl == q)
                {
                    bp->fl = q;
                    q->bl = bp;
                    aq->bl = p;
                    p->fl = aq;
                    q->fl = p;
                    p->bl = q;
                }
                else
                {
                    bp->fl = q;
                    q->bl = bp;
                    aq->bl = p;
                    p->fl = aq;
                    ap->bl = q;
                    q->fl = ap;
                    bq->fl = p;
                    p->bl = bq;
                }
        }
    }
}
void lib::report()
{
    sort();
    for (p = start->fl; p != NULL; p = p->fl)
        cout << "\n"
             << p->b_name << " " << p->b_writer << " " << p->b_translator << " " << p->b_isbn << " " << p->b_subject << " " << p->b_amount;
}
void lib::deletee()
{
    char is[15];
    struct library *bp, *ap;
    int sw = 0;
    cout << "\n please enter isbn for search and delete:";
    cin >> is;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->b_isbn, is) == 0)
        {
            sw = 1;
            bp = p->bl;
            ap = p->fl;
            bp->fl = ap;
            ap->bl = bp;
            p->fl = NULL;
            p->bl = NULL;
            cout << "\n"
                 << p->b_name << " " << p->b_isbn << "found and deletes";
            delete p;
        }
    if (!sw)
        cout << "\n not found and not deleted";
}
void lib::search()
{
    char sub[30];
    cout << "\n please enter subject for search and report";
    cin >> sub;
    for (p = start->fl; p != NULL; p = p->fl)
        if (strcmp(p->b_subject, sub) == 0)
            cout << "\n"
                 << p->b_name << " " << p->b_isbn << " " << p->b_writer << " " << p->b_translator << " " << p->b_subject << " " << p->b_amount;
}
void lib::unrent()
{
    char is[15];
    int sw = 0;
    cout << "\n please enter isbn of book for returning:";
    cin >> is;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if ((strcmp(p->b_isbn, is)) == 0)
        {
            sw = 1;
            p->b_amount++;
            cout << "\n this book returned to library";
            if (!sw)
                cout << "\n this book not found and returned to library";
        }
}
void lib::lending()
{
    int sw = 0;
    char is[15];
    cout << "\n please enter isbn for search and lending:";
    cin >> is;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->b_isbn, is) == 0)
        {
            sw = 1;
            if (p->b_amount > 0)
            {
                p->b_amount--;
                cout << "\n this book found and lended";
            }
            else
            {
                cout << "\n this book found and not exist in library and not lended";
            }
            if (!sw)
                cout << "\n this book not found in library and not lended";
        }
}
int main()
{
    lib x;
    char s;
    while (true)
    {
        cout << "please enter a character:";
        cout << "i:insert  r:report  d:delete  b:lending  u:unrent  s:search \n";
        cin >> s;
        switch (s)
        {
        case 'I':
        case 'i':
            x.insert();
            break;
        case 'R':
        case 'r':
            x.report();
            break;
        case 'D':
        case 'd':
            x.deletee();
            break;
        case 'S':
        case 's':
            x.search();
            break;
        case 'B':
        case 'b':
            x.lending();
            break;
        case 'U':
        case 'u':
            x.unrent();
            break;
        default:
            break;
        }
    }
}
// Ali Barzegari