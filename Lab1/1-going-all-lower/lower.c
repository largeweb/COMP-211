// PID: 730400003
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main()
{
    //make a new character variable as int
    int c;
    //set it to the first char of user input
    c = getchar();
    //while character is not at end of file
    while(c!=EOF){
        //if character is between uppercase alphabet ASCII range, add 32 to get to lowercase range and print it
        if(c>=65&&c<=90){
            putchar(c+32);
        } else {
        //otherwise just use whatever character there is and print it
        putchar(c);
        }
        //set character to the next one
        c = getchar();
    }
}
