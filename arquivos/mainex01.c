#include"stack.h"
#include<time.h>
#include<stdio.h>
int main ()
{   srand(time(NULL));

    Stack* s1= create(6);
    Stack* s2= create(6);
    Stack* s3= create(6);
  
    int i;


    for (i=0;i<6;i++)
    {
        push(s1,rand()%10);
    }
    int x;
    for(i=0;i<6;i++)
    {   
        x=pop(s1);
        if(x%2==0)
            push(s2,x);
        else
            push(s3,x);
    }

    while(!empty(s2))
    {
        push(s1,pop(s2));
    }
    while(!empty(s3))
    {
        push(s2,pop(s3));
    }

    print(s1);
    print(s2);


}