// PID: 730400003
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	//INITIALIZE BINARY ARRAY OUTPUT
	int binArr[32];
	//SET IT TO THE FIRST ARGUMENT
	for(int i=0; i<32; i++){
		binArr[i] = argv[1][i];
	}
	//CODE TO TURN CHARACTERS IN THE ARRAY INTO 1s AND 0s:
	//WHILE TURNING THE CHARACTERS INTO 1s AND 0s, PRINT THEM OUT WITH THE FIRST PART OF THE OUTPUT
	printf("The negation of the 32-bit two's complement integer ");
	for(int i=0; i<32; i++) {
		if(binArr[i] == 48) {
			printf("0");
			binArr[i] = 1;
		} else {
			printf("1");
			binArr[i] = 0;
		}
	}
	//ADD ONE CODE:
	//MAKE A BOOLEAN TO CHECK FOR 1s UNTIL YOU REACH A 0
	bool is1;
	is1 = true;
	//MAKE A COUNT THAT GOES THROUGH THE ARRAY BACKWARDS (31 to 0)
	int count;
	count = 31;
	//GO THROUGH THE ARRAY BACKWARDS UNTIL YOU REACH A 0
	while(is1) {
		if(binArr[count] == 0) {
			is1 = false;
			binArr[count] = 1;
		}
		count--;
	}
	//PRINT THE REST OF THE OUTPUT INCLUDING BINARY ARRAY
	printf(" is: ");
	for(int i=0; i<32; i++) {
		printf("%d", binArr[i]);
	}
	printf(".\n");
	return 0;
}

