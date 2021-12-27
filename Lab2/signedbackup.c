// PID: 730400003
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main() {
	//initialize maximum num of digits given problem
	//initialize the return array and input as array - input can have up to 5 digits for 16 bits
	int binArr[16];
	char input[5];
	//make new int variables for the getchar, a generic count, and the number for the problem input
	int c, count, num;
	//set these variables
	c = getchar();
	count = 0;
	num = 0;
	//make booleans to determine if number is positive and if it is a working number. set workingnum to true by default
	bool isPositive;
	bool workingNum;
	workingNum = true;
	//check if the first character is a plus sign to determine isPositive
	if(c==43){
		isPositive = true;
	} else {
		isPositive = false;
	}
	//while we aren't at the end of the input:
	while(c!=EOF){
		//check if count exceed max digits of range
		if(count == 6){
			printf("this is invalid");
			return 0;
		}
		//go through the input and add the characters in order, increase count
		c = getchar();
		input[count] = c;
		count++;
	}
	//build the number with the array
	num = atoi(input);
	//check if number is valid
	if(num>32767 || num< -32767){
		printf("not valid");
		return 0;
	}
	//convert to binary
	//check first bit (sign)
	if(isPositive){
		binArr[0] = 0;
	} else {
		binArr[0] = 1;
	}
	int testNum;
	testNum = num;
	printf("%d\n", testNum);
	for(int i=15;i>0;i++){


		if(testNum%2 == 1) {
			binArr[i] = 1;
			testNum = (testNum - 1) / 2;
		} else {
			binArr[i] = 0;
			testNum = testNum / 2;
		}

		/*
		int divide;
		divide = 2;
		for(int j=0; j<i; j++){
			divide = divide*2;
		}
		if(testNum%divide==1){
			binString[16-i] = 0;
			testNum = testNum / 2;
		} else {
			binString[16-i] = 1;
			testNum = (testNum-1)/2;
		}
		*/
	}
	//printf("%d\n",num);
	for(int i=0;i<16;i++){
		printf("print num stuff now: %d\n",binArr[i]);
	}
	//printf("%s\n",binArr);
}
