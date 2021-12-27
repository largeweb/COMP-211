// PID: 730400003
// I pledge the COMP 211 honor code.
#include <stdint.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instructions.h"

// ------------------------------------
// Function implementation that determines whether you are
// working with an R type or I type instruction
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      instruction_type: R_TYPE or I_TYPE (see instructions.h)
//

instruction_type get_type_of_instruction(uint32_t instruct){
    // TODO
    // MAKE A NEW NUM SET TO THE OPCODE SECTION OF THE INPUT INTEGER
	int num = bit_select(instruct, 31, 26);
	//IF IT IS EQUAL TO 000000 RETURN R_TYPE, OTHERWISE RETURN I_TYPE
	if(num == 0) {
		return R_TYPE;
	} else {
		return I_TYPE;
	}
} // end get_type_of_instruction() function

// ------------------------------------
// Function implementation that creates an R-type instruction
// based on the integer given (see instructions.h)
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      a pointer to an r_instruction (see instructions.h).
//              This consists of the following structure members
//              you will have to set: rs, rt, rd, shamt, func
//
r_instruction *create_r_instruction(uint32_t instruct){
    // TODO
    // MAKE A NEW r_instruction POINTER EQUAL TO 4 BYTES OF MALLOC'ed SPACE
    r_instruction *rtypePtr = (r_instruction *) malloc(4);
    //MAKE NUM INT VARIABLES SET TO THE SECTIONS OF THE INPUT INTEGER
    int numRS = bit_select(instruct, 25, 21);
    int numRT = bit_select(instruct, 20, 16);
    int numRD = bit_select(instruct, 15, 11);
    int numSHAMT = bit_select(instruct, 10, 6);
    int numFUNC = bit_select(instruct, 5, 0);
    //SET THE POINTER's STRUCT VALUES EQUAL TO THE INT VARIABLES AND RETURN
    rtypePtr -> rs = numRS;
    rtypePtr -> rt = numRT;
    rtypePtr -> rd = numRD;
    rtypePtr -> shamt = numSHAMT;
    rtypePtr -> func = numFUNC;
    return rtypePtr;
} // end create_r_instruction() function

// ------------------------------------
// Function implementation that creates an I-type instruction
// based on the integer given (see instructions.h)
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      a pointer to an i_instruction (see instructions.h).
//              This consists of the following structure members
//              you will have to set: opcode, rs, rt, immediate
//
i_instruction *create_i_instruction(uint32_t instruct){
	//TODO
    // MAKE A NEW i_instruction POINTER EQUAL TO 4 BYTES OF MALLOC'ed SPACE
    i_instruction *itypePtr = (i_instruction *) malloc(4);
    //MAKE NUM INT VARIABLES SET TO THE SECTIONS OF THE INPUT INTEGER
    int numOP = bit_select(instruct, 31, 26);
    int numRS = bit_select(instruct, 25, 21);
    int numRT = bit_select(instruct, 20, 16);
    int numIM = bit_select(instruct, 15, 0);
    //SET THE POINTER's STRUCT VALUES EQUAL TO THE INT VARIABLES AND RETURN
    itypePtr -> opcode = numOP;
    itypePtr -> rs = numRS;
    itypePtr -> rt = numRT;
    itypePtr -> immediate = numIM;
    return itypePtr;
} // end create_i_instruction() function
