#include "stack.h"
#include<math.h>

char* reversed_polish_notation (char *c) {
  Stack *s = create(strlen(c));
  char *c1 = (char*) malloc((strlen(c)+1)*sizeof(char));

  c1[strlen(c)]='\0';

  int i = 0;

  int j=0;

  char x;

  while (c[i] != '\0') {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/
    if(c[i]-'0'>=0&&c[i]-'0'<='9')
    {
      printf("%c ", c[i]);
      c1[j]=c[i];
      j++;
    }
    else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='\\'||c[i]=='^'||c[i]=='%'||c[i]=='/')
      push(s,(int) c[i]);
    else if(c[i]=='}'||c[i]==']'||c[i]==')')
    {
        x=(char) pop(s);
        c1[j]=x;
        j++;
        printf("%c ", x);
    }
    i++;    
  }
  printf("\n");
  c1[j]='\0';

  destroy(s);
  return(c1);
}

int compute_polish_expression (char *c)
{
    int i=0;
    int x1;
    int x2;
    Stack* s=create(strlen(c));
    while(c[i]!='\0')
    {   
        if(c[i]>='0'&&c[i]<='9')
        {
            push(s, (int) c[i]-'0');
        }
        else if(c[i]!=' '&&c[i]!='\n')
        //if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'||c[i]=='^'||c[i]=='%'||c[i]=='\\')
        {
            x1=pop(s);
            x2=pop(s);
            if(c[i]=='+')
            push(s,x1+x2);
            else if(c[i]=='-')
            push(s,x1-x2);
            else if(c[i]=='*')
            push(s, (x1)*(x2));
            else if(c[i]=='\\'||c[i]=='/')
            push(s,x1/x2);
            else if(c[i]=='%')
            push(s,x1%x2);
            else if(c[i]=='^')
            push(s,pow(x1,x2));
        }
        i++;
    }
    return(pop(s));
}


int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  char* c1 =reversed_polish_notation (c);
  int i=0;
  printf("\n");

  /*
  while(c1[i]!='\0')
  {
    printf(" %c", c1[i]);
    i++;
  }
  */

  printf("\n %d \n",compute_polish_expression (c1));
  
  return 0;
}

