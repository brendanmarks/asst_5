/*
 * main.c
 *
 *  Created on: Oct. 25, 2018
 *      Author: Brendan Marks (260866323)
 */

// import -> include
// <>
// stdio.h (standard input output) -> not studio
// stdlib.h
#include <stdio.h>
#include <stdlib.h>

void revStr(char* str, int length){ //reverse the bits from dec2base so they are in right order
	char* str_rev = (char*)malloc(sizeof(char)*length); //sets pointer to a block of length bytes long
	int i;
	for( i = 0 ; i < length ; i++) // fill array with reverse of str array
		str_rev[i] = str[length-i-1];
	for(i = 0 ; i < length; i++) //print the revstr array
		printf("%c",str_rev[i]);
	// set the point of str -> str_rev
}

void dec2base(int input,int base,char *str){ //translates the input to its base form


	int q = input;
	int i = 0;
	while(q > 0)
	{
		int r = q%base; //find remainder, which will give the next number to the base form
		q = q/base; //divide by base to move along the number to find next remainder
		//store r as a character
		char rChar;
		if(r < 10)
			rChar = '0'+r; //Convert remainder to 0-10 in ACSII
		else
			rChar = 'A'+(r-10); //Convert remainder to A-F in ASCII
		str[i] = rChar;
		i++;
	}

	revStr(str,i); //send str to revstr
}

int main(int argc, char *argv[])
{

	if(argc != 2 && argc != 3){ //check if there was the right number of inputs
		printf("Error: did not enter a valid number of arguments");
		return -1;
	}
	int a; // = (int)*argv[1]; //initialize a and b

	int b; // = (int)*argv[2];
	//int z = (int) b;
	if (argc == 2){
		sscanf(argv[1], "%d", &a); //take the inputed char array from cmd and convert to int
		//a = (int)argv[1];
		b = 2; //uses base 2 by default
	}
	if (argc == 3){
		sscanf(argv[1], "%d", &a); //take the inputed char arrays from cmd and convert to int
		sscanf(argv[2], "%d", &b);
	}
	if (a < 0 || a > 2147483647){
			printf("ERROR: number must be in range [0,2147483647]");
			return -2;
		}
	if (b < 2 || b > 36){
			printf("Error: base must be in range [2,36]");
			return -3;
	}
	int length = 0;

	int q = a;
	do	{ //determine how long the array str will be (for memory purposes)
		int r = q%b;
		q = q/b;
		length++;
	}while(q > 0);

	if (a == 0){ //in case of 0 input
		printf("The Base-%d form of %d is: 0", b, a);
		return 0;
	}
	printf("The Base-%d form of %d is: ", b, a);
	char* str = (char*)(malloc(sizeof(char)*length));
	dec2base(a,b,str); //send str and inputs to dec2base
	return 0;
}
