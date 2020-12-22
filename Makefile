ecSOURCES =  SetString.c TestString.c Coder.c Main.c
dcSOURCES =  SetString.c TestString.c Coder.c Main1.c
ecTARGET = encoder
dcTARGET = decoder

all: $(ecTARGET)
    
$(ecTARGET): $(ecSOURCES:.c=.o) 
	gcc $(ecSOURCES:.c=.o) -o $@ -std=c99

%.o: %.c
	gcc $< -c -o $@ -std=c99

clean:
	rm *.o *.d $(ecTARGET)
