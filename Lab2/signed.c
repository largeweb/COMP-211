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
	if(num>32767 || num<-32767){
		printf("The signed 16-bit representation of %c%d is: not possible.\n", sign, num);
		return 0;
	}
	//HAVE A BACKUP FOR FUTURE PRINTING
	int numCopy = num;
	//FOR LOOP GOING FROM 15 to 1 - INDEX OF BINARY ARRAY
	for(int i=15; i>0; i--){
		//IF THE NUMBER IS 0, THEN DON'T COMPUTE ANYTHING AND SET THE INTEGER IN THE ARRAY TO 0
		if(num == 0){
			binArr[i] = 0;
		} else {
			//OTHERWISE CHECK IF IT IS DIVISIBLE BY TWO OR NOT
			if(num%2==0){
				//IF IT IS, SET INTEGER IN ARRAY TO 0 AND SET THE NUMBER TO THE NEW QUOTIENT
				binArr[i] = 0;
				num = num/2;
			} else {
				//IF IT IS NOT, SET INTEGER IN ARRAY TO 1 AND SET THE NUMBER (MINUS 1) TO NEW QUOTIENT
				binArr[i] = 1;
				num = num - 1;
				num = num / 2;
			}
		}
	}	
	//PRINT THE BINARY ARRAY
	printf("The signed 16-bit representation of %c%d is: ", sign, numCopy);
	for(int i=0; i<16; i++) {
		printf("%d", binArr[i]);
	}
	printf(".\n");
	return 0;
}

