// PID: 730400003
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	//INITIALIZE BINARY ARRAY OUTPUT
	int binArr[16];
	//GET THE NUMBER
	int num = atoi(argv[1]);
	//CHECK FOR THE SIGN
	char sign;
	sign = argv[1][0];
	//IF SIGN IS NEGATIVE, SET THE FIRST INDEX OF BINARY ARRAY TO 1 AND MAKE NUM POSITIVE TO REMOVE SIGN
	//IF SIGN IS POSITIVE, SET THE FIRST INDEX OF BINARY ARRAY TO 0
	if(sign == 45){
		binArr[0] = 1;
		num = num * -1;
	} else {
		binArr[0] = 0;
	}
	//CHECK IF NUMBER IS OUT OF RANGE - PRINT AND RETURN IF SO
	if(num>32767 || num<-32768){
		printf("The two's complement 16-bit representation of %c%d is: not possible.\n", sign, num);
		return 0;
	}
	//HAVE A BACKUP FOR FUTURE PRINTING
	int numCopy = num;
	//INITIALIZE A COUNT VARIABLE FOR THE POWER DURING THE FOR LOOP
	int count;
	count = 1;
	//FOR LOOP GOING FROM 15 to 1 - INDEX OF BINARY ARRAY
	//IF THE INTEGER IS NEGATIVE (FIRST INDEX IS 1):
	if(binArr[0] == 1){
	//MAKE AN INT AND SET IT TO THE 2 TO THE POWER OF 14 (N is 15, We start with N-1)
		int power = 16384;
		//SINCE THE TWOS COMPLIMENT FOR THE DIFFERENCE OF THE MINIMUM AND THE NUM IS IDENTICAL TO THE NUM FOR POSITIVE, WE REUSE THE CODE FOR POSITIVE
		//BUT CHANGE THE NUM TO BE THE DIFFERENCE
		num = 32768-num;
		//THIS CODE IS COPIED FROM THE POSITIVE SECTION
		for(int i=0; i<15; i++) {
			if(num-power>=0){
				binArr[count] = 1;
				num -= power;
			} else {
				binArr[count] = 0;
			}
			count++;
			power = power/2;
		}
	} else {
	//POSITIVE CODE:
	//IF THE INTEGER IS POSITIVE (FIRST INDEX IS 0):
	//MAKE AN INT AND SET IT TO THE 2 TO THE POWER OF 14 (N is 15, We start with N-1)
		int power = 16384;
		//DO THIS FOR EACH BIT WITH A FOR LOOP
		for(int i=0; i<15; i++) {
			//IF THE NUM IS GREATER THAN OR EQUAL TO POWER, SET THE INTEGER IN ARRAY TO 1 AND SUBTRACT THE POWER FROM NUM
			if(num-power>=0){
				binArr[count] = 1;
				num -= power;
			} else {
			//OTHERWISE SET INTEGER IN ARRAY TO 0 AND DO NOTHING
				binArr[count] = 0;
			}
			//INCREASE COUNT (INDEX) AND REDUCE POWER BY DIVIDING BY 2
			count++;
			power = power/2;
		}
	}
	//PRINT THE BINARY ARRAY
	printf("The two's complement 16-bit representation of %c%d is: ", sign, numCopy);
	for(int i=0; i<16; i++) {
		printf("%d", binArr[i]);
	}
	printf(".\n");
	return 0;
}

