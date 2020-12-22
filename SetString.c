#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// immutable 




char* Filter(const char* Message){
	int lenMessage;
	lenMessage = strlen(Message);
	char* Message1;
	Message1 = malloc(lenMessage * sizeof(char));
	int l = 0;
	for(int i = 0; i < lenMessage; i++){
	    if (((47 < Message[i]) && (Message[i] < 57)) || ((64 < Message[i]) && (Message[i] < 91)) || ((96 < Message[i]) && (Message[i] < 122)) || (Message[i] == ' ')){
			Message1[l] = Message[i];
   			l += 1;
	    }
	}
	Message1 = realloc(Message1,(1 + l) * sizeof(char));
        Message1[l]='\0';
	return Message1;
        free(Message1);
}



   
char* uplow(const char* Message, int key){
    	int lenstring;
	lenstring = strlen(Message);
	char* Message1;
	Message1 = malloc(lenstring * sizeof(char));
	for(int i = 0; i < lenstring; i++){
		if((Message[i] >= 'a' - (key + 1) * 16) && (Message[i] <= 'z' - (key + 1) * 16)){
			Message1[i] = (char)(Message[i] + key * 32);
		}
                 else{
			Message1[i] = (char)Message[i];
		}
	}
	return Message1;
	free(Message1);
}




char* toUpper(const char* Message){
     return uplow(Message,-1);
}




char* toLower(const char* Message){
         return uplow(Message,1);
}




//mutable




void Mencryptdecryptxor(char* Message, char* key){     
    
    int lenstring;
    lenstring = strlen(Message); 
     
    for (int i = 0; i < lenstring; i++){ 
        Message[i] = Message[i] ^ key[i]; 
        printf("%i",Message[i]); 
    } 
    
} 
  



char* EncryptCaesarCipher(char Message[],  unsigned int Key){
    unsigned int i;
    for( i=0; i < strlen(Message); i++){
       if ((Message[i] >= ' ' && Message[i] <= '@') >=1 ||
          (Message[i] >= '[' && Message[i] <= '`') >=1 ||
          (Message[i] >= '{' && Message[i] <= '~') >=1 ) 
          continue;
        
       else if(isalpha(Message[i] + Key) == 0) 
               Message[i] = (Message[i] - 26) + Key; 
              
       else Message[i] += Key;
    }
    
    return Message;
}




void  MFilter(char* Message){
	char* Message1;
	Message1 = Filter(Message);
	Message=Message1;
}




void MtoUpper(char* Message){
	Message = toUpper(Message);
}




void MtoLower(char* Message){
	Message = toLower(Message);
}




void MremoveSpaces(char* Message){ 
    int Size = 0; 
  
    for (int i = 0; Message[i]; i++) 
        if (Message[i] != ' ') 
            Message[Size++] = Message[i]; 
    Message[Size] = '\0'; 
    
}   




void Mstrip( char* Message){
        int i = 0;
        int lenMessage = strlen(Message) - 1;

        while(Message[i] == ' '){
                i++;
        }

        while(Message[lenMessage] == ' '){
                lenMessage--;
        }

        for(int k = 0; k < lenMessage; k++, i++){
                Message[k] = Message[i];
        }
        Message[lenMessage-1] = '\0';
        
}


