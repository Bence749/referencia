#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//C2L
struct E2
{
    E2* prev;
    E2* next;
    int key;
    E2(): prev(this), next(this){};
};

void precede( E2* q, E2* r )
{
    E2* p = r->prev;
    q->prev = p;
    q->next = r;
    p->next = q;
    r->prev = q;
};

void follow( E2* p, E2* q )
{
    E2* r = p->next;
    q->prev = p;
    q->next = r;
    p->next = q;
    r->prev = q;
};

void out( E2* q )
{
    E2* p = q->prev;
    E2* r = q->next;
    p->next = r;
    r->prev = p;
    q->prev = q;
    q->next = q;
};

E2* toH(E2* x)
{
    int prev = -1;
    for(; x->key >= prev; x = x->next )
        if( x->key == prev )
            out( x->prev );
        else
            prev = x->key;
    return x;
}

//Queue
class Queue
{
    private:
        E2* elem;
        int n;
    public:
        enum Error{ EmptyQueueError };
        Queue() : elem(new E2()),n(0) {}
        E2* getE2() { return elem; }
        void add(E2* x) { if(n > 0) precede(x, elem); else elem = x; n++;}
        E2* rem() { E2* x = elem; elem = elem->next; out(elem->prev); n--; return x; }
        E2* first() { if( n >= 0 ) return elem; else throw EmptyQueueError; }
        int length()
        {
            int l = 0;
            E2* p = elem;
            do
            {
                l++;
                p = p->next;
            }
            while(p != elem);
            return l;
        }
        bool isFull() { return n == this->length();}
        bool isEmpty() { return n == 0; }
        ~Queue() { delete elem; }
        void setEmpty() { elem = new E2(); n = 0; }
};

E2* toH(Queue* x)
{
    E2* tmp = x->first();
    int prev = -1;
    for(; tmp->key >= prev; tmp = tmp->next )
        if( tmp->key == prev )
            out( tmp->prev );
        else
            prev = tmp->key;
    return tmp;
}


int main()
{
    ifstream file("t2.txt");
    string line;
    getline(file, line);
    if(line == "q")
    {
        Queue* q = new Queue();
        while(getline(file, line))
        {
            E2* x = new E2();
            x->key = stoi(line);
            q->add(x);
        }
        E2* l = toH(q);
        E2* p = l;
        do
        {
            cout << p->key << endl;
            p = p->next;
        } while(l != p);
    }
    else
    {
        E2* e = new E2();
        getline(file, line);
        e->key = stoi(line);
        while(getline(file, line))
        {
            E2* x = new E2();
            x->key = stoi(line);
            precede(x, e);
        }
        E2* l = toH(e);
        E2* p = l;
        do
        {
            cout << p->key << endl;
            p = p->next;
        } while(l != p);
    }
    return 0;
}
