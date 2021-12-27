// PID: 730400003
// I pledge the COMP 211 honor code.

#include "bit_utils.h"

char* itob(int argnum, int size) {
	//INITIALIZE BINARY ARRAY OUTPUT
	int binArr[size];
	//GET THE NUMBER
	int num = argnum;
	//MAKE THE SPACE MALLOC AVAILABLE
	char *spaceInMem;
	spaceInMem = (char *) malloc((size) * sizeof(char));
	//CHECK FOR THE SIGN
	char sign;
	if(num<0) {
		sign = 1;
	} else {
		sign = 0;
	}
	//IF SIGN IS NEGATIVE, SET THE FIRST INDEX OF BINARY ARRAY TO 1 AND MAKE NUM POSITIVE TO REMOVE SIGN
	//IF SIGN IS POSITIVE, SET THE FIRST INDEX OF BINARY ARRAY TO 0
	if(sign == 1){
		binArr[0] = 1;
		num = num * -1;
	} else {
		binArr[0] = 0;
	}
	//INITIALIZE A COUNT VARIABLE FOR THE POWER DURING THE FOR LOOP
	int count;
	count = 1;
	//FOR LOOP GOING FROM 15 to 1 - INDEX OF BINARY ARRAY
	//IF THE INTEGER IS NEGATIVE (FIRST INDEX IS 1):
	if(binArr[0] == 1){
	//MAKE AN INT AND SET IT TO THE 2 TO THE POWER OF size-2 
		int power = 2;
		for(int i=0; i<size-2;i++){
			power = power * 2;
		}
		//SINCE THE TWOS COMPLIMENT FOR THE DIFFERENCE OF THE MINIMUM AND THE NUM IS IDENTICAL TO THE NUM FOR POSITIVE, WE REUSE THE CODE FOR POSITIVE
		//BUT CHANGE THE NUM TO BE THE DIFFERENCE
		num = power-num;
		//THIS CODE IS COPIED FROM THE POSITIVE SECTION
		for(int i=size-1; i>0; i--) {
			//IF NUM IS DIVISIBLE BY 2, SET ARRAY AT END (GOING TO BEGINNING) TO BE 0)
			if(num % 2 == 0){
				binArr[i] = 0;
			//OTHERWISE SET IT TO 1 AND SUBTRACT 1 TO ALLOW DIVISION BY 2
			} else {
				binArr[i] = 1;
				num -= 1;
			}
			//INCREASE COUNT AND DIVIDE NUM BY 2
			count++;
			num = num/2;
		}

	} else {
	//POSITIVE CODE:
	//IF THE INTEGER IS POSITIVE (FIRST INDEX IS 0):
	//MAKE AN INT AND SET IT TO THE 2 TO THE POWER OF size-2 
		int power = 2;
		for(int i=0; i<size-2;i++){
			power = power * 2;
		}
		//DO THIS FOR EACH BIT WITH A FOR LOOP
		for(int i=size-1; i>0; i--) {
			//IF NUM IS DIVISIBLE BY 2, SET ARRAY AT END (GOING TO BEGINNING) TO BE 0)
			if(num % 2 == 0){
				binArr[i] = 0;
			//OTHERWISE SET IT TO 1 AND SUBTRACT 1 TO ALLOW DIVISION BY 2
			} else {
				binArr[i] = 1;
				num -= 1;
			}
			//INCREASE COUNT AND DIVIDE NUM BY 2
			count++;
			num = num/2;
		}
	}
	//SET THE SPACE IN MEM AND RETURN
	for(int i=0; i<size; i++) {
		if(binArr[i] == 1){
			spaceInMem[i] = '1';
		}
		if(binArr[i] == 0){
			spaceInMem[i] = '0';
		}
	}
	spaceInMem[size] = '\0';
	return spaceInMem;
}

// Returns num after mask has been applied.
int mask_bits(int num, int mask) {
	int maskedbits;
        maskedbits = num & mask;
	return maskedbits;
}

// Returns num after bits have been set.
int set_bits(int num, int bits) {
	int setbits;
	setbits = num | bits;
	return setbits;
}

// Returns num after bits have been inversed.
int inverse_bits(int num, int bits) {
	int inversedbits;
	inversedbits = num ^ bits;
	return inversedbits;
}

// returns the bits in the number from startbit to
// end bit (including startbit and endbit);
int bit_select(int num, int startbit, int endbit) {
	//MAKE VARIABLE TO SUBMIT
	unsigned int selected = num;
	//THE FIRST SHIFT WILL BE A LOGICAL LEFT SHIFT TO RID OF THE BITS TO THE LEFT BIT OF INTEREST
	//THE SECOND SHIFT WILL BE A LOGICAL RIGHT SHIFT OF THE SAME AMOUNT AND THEN IT WILL SHIFT AGAIN THE AMOUNT OF THE END BIT INDEX OF INTEREST
	int lshift = 31 - startbit;
	selected = selected << lshift;
	selected = selected >> lshift;
	selected = selected >> endbit;
	return selected;
}

