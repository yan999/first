#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elmStack *address;
struct elmStack{
    infotype info;
    address next;
};
struct stack{
    address top;
};
void createStack(stack *s);
address alokasi(infotype x);
void push(stack *s, address p);
address pop(stack *s);
void printInfo(stack *s);
void createHanoi(stack *s, int n);
bool Move(stack *a, stack *b);
bool isComplete(stack *s, int n);


#endif // HEAD_H_INCLUDED
