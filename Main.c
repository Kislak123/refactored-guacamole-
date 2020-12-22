#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "SetString.h"
#include "TestString.h"
#include "Coder.h"




#define MaxMessageSize 256




int main(){
 char Message[MaxMessageSize];
 scanf("%s",Message);
 printf("%s\n", Filter(Message));
 
 MFilter(Message);
 encryptdecryptxor(Message);

 return 0;
}
