#include <stdio.h>
#include <string.h>
void foo(char * input){
	int a1=11; 
     int a2=22;
     char buf[7]; 
	strcpy(buf, input);   
}   
void main(int argc, char **argv){
   foo(argv[1]);
}

