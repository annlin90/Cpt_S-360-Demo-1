#include <stdio.h>
#include <math.h>
#include <stdarg.h>

typedef unsigned int u32;

char *ctable = "0123456789ABCDEF"; //uses it with base to convert
int BASE = 10; // for decimal numbers
int INT_BASE= 10; //for int
int OCTAL_BASE = 8;//for octal
int HEX_BASE = 16;//for hex use uint_t

int rpu(u32 x)  
{  
    char c;
    if (x){
       c = ctable[x % BASE]; //unsigned int
       rpu(x / BASE);
       putchar(c);
    }
}

int rpuD(u32 x)  
{  
    char c;
    if (x){
       c = ctable[x % INT_BASE]; //through base of 10 can print in int
       rpu(x / INT_BASE);
       putchar(c);
    }
}
 
int rpuO(u32 x)
{  
    char c;
    if (x){
       c = ctable[x % OCTAL_BASE]; //through base of 8 can print in Octal
       rpu(x / OCTAL_BASE);
       putchar(c);
    }
}


int rpuH(u32 x)
{  
    char c;
    if (x){
       c = ctable[x % HEX_BASE]; //through base of 16 can print in HEX
       rpu(x / HEX_BASE);
       putchar(c);
    }
}


int printu(u32 x)
{
   (x==0)? putchar('0') : rpu(x);
   putchar(' ');
}

int printd(int x) {
 int a = x;  
 if(x<0)
 { 
   putchar('-'); //if int is less than zero add in negative sign as it's a negative
   x =x*-1; //then make the number positive
}
  (x==0)? putchar('0') : rpuD(x);
   putchar(' ');	 
}


void printc(int ip) { //prints in char
 putchar(ip);

} 


void printString(char *ch)
{
	while(*ch) {
	putchar(*ch); //basically goes through the ch and prints through all
	ch++;
	}
}


int printo(u32 x) 
{ 	
	putchar('0');
	(x==0)? putchar('0') : rpuO(x); //prints in octal
   putchar(' ');
}

 int printx(u32 x) 
{ 
	putchar('0');
	putchar('x');
	 (x==0)? putchar('0') : rpuH(x); //prints in hex
   putchar(' ');
}


void Myprintf(char* fmt,...) 
{ 
	char *cp = fmt; //points to format string
	int *ip = (int *)&fmt+1; //points to first item
	 
	
	while (*cp) 
	{ 
		if( *cp != '%' )  //if it doesn't encounters %
		{ 
			putchar(*cp); //spit it out
			if(*cp=='\n') { //if equals \n
			  putchar('\r'); //spit out \r
				}
			cp++;   //keeps looping through the conditional code, if false then it breaks from it
			continue;
		} 
		
		cp++; 
		
		 
		switch(*cp) //for different cases/variables
		{ 
			case 'c' :  		 
					printc(*ip);	
						break; 
			
						
			case 's':  
					printString(*ip);
						break; 

			case 'u' :  
						printu(*ip);	
						break;
			
			case 'd' :  
						printd(*ip);
						break; 
						
			case 'o':  
						printo(*ip);
						break; 
			 
						
			case 'x':  
						printx(*ip);
						break; 
		}	
	cp++; //increment both
	ip++;
	} 
	
	 
} 

 

 
 
 

 
