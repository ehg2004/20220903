#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;

  while (c[i] != '\0') {
    int x;
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/	 
    if(c[i]!=' '&&c[i]!='\n')
    {

      if(c[i]=='{'||c[i]=='['||c[i]=='(')
        push(s,(int) c[i]);

      else if(!empty(s))
      {
        x = pop(s);
        if((x=='{'&&c[i]!='}')|| (x == '[' && c[i]!=']')||(x=='('&&c[i]!=')'))
          return(0);
      }
      else
          return(0);
    }
    i++;    
  }
  return(empty(s));

}

int main () {
  int i;
  char* c[5];
  c [0]= "( ( ) [ ( ) ] )";
  c[1] = "( [ ) ]";
  c[2] = "( ) [ ]";
  c[3] = "( [ ]";
  c[4] = ") (";
  for(i=0;i<5;i++){
  if (parser(c[i])) 
    printf("true  (bem formada) %d \n",i);
  else  
    printf("false (mal formada) %d \n",i);
  }
  return 0;
}
