#include <iostream>
#include <stdlib.h>
//#include <windows.h>
#include "list.h"
using namespace std;

void createStack(stack *s)
{
    s->top = Nil;
}
address alokasi(infotype x)
{
    address p = new elmStack();
    p->info = x;
    p->next = Nil;
    return p;
}
void push(stack *s, address p)
{
    p->next = s->top;
    s->top = p;
}
address pop(stack *s)
{
    address p = s->top;
    s->top = p->next;
    p->next = Nil;
    return p;
}
void printInfo(stack *s)
{
    address p = s->top;
    while (p != Nil){
        cout << p->info << endl;
        p = p->next;
    }
}
void createHanoi(stack *s, int n)
{
    while (n > 0){
        address p = alokasi(n);
        push(s,p);
        n--;
    }
}
bool Move(stack *a, stack *b)
{
    if (a->top != Nil){
        if ((b->top == Nil) || ((a->top)->info < (b->top)->info)){
            address p = pop(a);
            push(b,p);
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
bool isComplete(stack *s, int n)
{
    bool urut = true; address p = s->top; int i = 1;
    if (s->top != Nil){
        while (p->next != Nil){
            if (p->info > (p->next)->info){
                urut = false;
            }
            p = p->next; i++;
        }
        if (urut && (i == n))
            return urut;//true;
        else
            return false;
    }
    else
        return false;
}
