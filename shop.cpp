// IN THE NAME OF GOD
#include <iostream>
#include <string.h>
using namespace std;
struct storage
{
    char gname[30];
    char gnum[15];
    long long int amount;
    long long int price;
    struct storage *fl, *bl;
};
class store
{
public:
    store();
    void sinsert(char[], long long int);
    void sreport();
    void sdeletee(char[], long long int);
    long long int ssearch(char[], long long int &);

private:
    struct storage *start, *cur, *p;
};
store::store()
{
    start = new struct storage;
    start->fl = NULL;
    start->fl = NULL;
    cur = start;
}
void store::sinsert(char gm[], long long int am)
{
    int sw = 0;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->gnum, gm) == 0)
        {
            sw = 1;
            p->amount += am;
            cout << "\n this is amount inserted :";
        }
    if (!sw)
    {
        p = new struct storage;
        cur->fl = p;
        p->fl = NULL;
        p->bl = cur;
        cur = p;
        strcpy(p->gnum, gm);
        p->amount = am;
        cout << "\n please enter goods name: ";
        cin >> (p->gname);
        cout << "\n enter price: ";
        cin >> p->price;
    }
}
void store::sreport()
{
    cout << "\n the list of all goods in storage :";
    for (p = start->fl; p != NULL; p = p->fl)
        cout << "\n"
             << p->gname << " " << p->gnum << " " << p->amount << " " << p->price;
}
void store::sdeletee(char gm[], long long int am)
{
    struct storage *bp, *ap;
    int sw = 0;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->gnum, gm) == 0)
        {
            sw = 1;
            p->amount -= am;
            cout << "\n this amount deleted";
            if (p->amount == 0)
            {
                bp = p->bl;
                ap = p->fl;
                ap->bl = bp;
                bp->fl = ap;
                p->fl = NULL;
                p->bl = NULL;
                cout << "\n"
                     << p->gname << " " << p->gnum << "deleted";
                delete p;
            }
        }
    if (!sw)
        cout << "\n not found and not deleted";
}
long long int store ::ssearch(char gm[], long long int &pr)
{
    int sw = 0;
    long long int m;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->gnum, gm) == 0)
        {
            sw = 1;
            m = p->amount;
            pr = p->price;
            return m;
        }
    if (!sw)
    {
        pr = 0;
        m = 0;
        return m;
    }
}
struct factor
{
    char fno[15];
    char mnum[15];
    long long int totalprice;
    long long int famount;
    long long int mprice;
    struct factor *fl, *bl;
};
class sale : public store
{
public:
    sale();
    void sfactor();
    void rfactor();
    void reportfactor();

private:
    struct factor *start, *cur, *p;
};
sale::sale()
{
    start = new struct factor;
    start->fl = NULL;
    start->bl = NULL;
    cur = start;
}
void sale::sfactor()
{
    long long int m;
    char mn[15];
    long long int pr;
    cout << "\n please enter goods number for sale:";
    cin >> mn;
    cout << "\n please enter amount for sale:";
    cin >> m;
    if (ssearch(mn, pr) >= m)
    {
        p = new struct factor;
        p->fl = NULL;
        p->bl = NULL;
        cur->fl = p;
        cur = p;
        strcpy(p->mnum, mn);
        p->mprice = pr;
        p->famount = m;
        p->totalprice = p->mprice * m;
        cout << "\n please enter factor number:";
        cin >> p->fno;
        sdeletee(mn, m);
        cout << "\n this amount of this goods salled";
    }
    else
        cout << "\n not enough and not salled";
}
void sale::rfactor()
{
    char fn[15];
    int sw = 0;
    struct factor *bp, *ap;
    cout << "\n please enter factor number for returning:";
    cin >> fn;
    for (p = start->fl; p != NULL && !sw; p = p->fl)
        if (strcmp(p->fno, fn) == 0)
        {
            sw = 1;
            bp = p->bl;
            ap = p->fl;
            bp->fl = ap;
            ap->bl = bp;
            p->fl = NULL;
            p->bl = NULL;
            sinsert(p->mnum, p->famount);
            delete p;
            cout << "\n this factor deleted";
        }
    if (!sw)
        cout << "\n not found and not deleted";
}
void sale::reportfactor()
{
    cout << "\n the list of all factors:";
    for (p = start->fl; p != NULL; p = p->fl)
        cout << "\n"
             << p->fno << " " << p->mnum << " " << p->famount << " " << p->mprice << " " << p->totalprice;
}
int main()
{
    sale X;
    char ch;
    long long int m;
    char mn[15];
    do
    {
        cout << " \n please enter i for insert storage, r for report storage, s for salling , u for returning,f for report factor and x for exit:";
        cin >> ch;
        switch (ch)
        {
        case 'i':
        case 'I':
            cout << "\n please enter goods number for insert:";
            cin >> mn;
            cout << "\n please enter amount for inseert";
            cin >> m;
            X.sinsert(mn, m);
            break;
        case 'u':
        case 'U':
            X.rfactor();
            break;
        case 'r':
        case 'R':
            X.sreport();
            break;
        case 's':
        case 'S':
            X.sfactor();
            break;
        case 'f':
        case 'F':
            X.reportfactor();
            break;
        }
    } while (ch != 'x' && ch != 'X');
}
// Ali Barzegari