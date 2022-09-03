#include "stack.h"

void reversed_polish_notation (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    /*Terminar*/
    /*Utilizar somente as operações push, pop, empty, ... (interface)*/
    if(c[i]-'0'>=0&&c[i]-'0'<='9')
      printf("%c ", c[i]);
    else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='\\'||c[i]=='^'||c[i]=='%')
      push(s,(int) c[i]);
    else if(c[i]=='}'||c[i]==']'||c[i]==')')
      printf("%c ", (char) pop(s));
    i++;    
  }
  printf("\n");
  destroy(s);
}

int main () {
  char *c = "( 9 + ( ( 0 + 1 ) * ( 2 * 3 ) ) )";
  reversed_polish_notation (c);
  return 0;
}
