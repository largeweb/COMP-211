// PID: 730400003
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main()
{
    //make new int vars for char, character count, line count, total line count, line count for array index, and count for lines over
    int c, count, l, tLineCt, aLineCt, lineOver;
    //make new array for total lines
    int tLineArr[100];
    //set c to first character of user input
    c = getchar();
    //init values for vars
    count = 1;
    tLineCt = 0;       
    aLineCt = 0;
    lineOver = 0;
    l = 0;
    //while character is not at end of file
    while(c!=EOF){
        //if the character is a new line character, reset the count and lineover values
        if(c==10){
           count = 0;
           lineOver = 0;
           l++;
        } 
        //if character is the 51st:
        if(count==51){
            //if the character is not a new line character
            if(c!=10){
                //print a new line, set the total line array at array index count line count, increase line count, increase line over count
                printf("\n");
                //we dont want to set the total line array to be a line if it has gone over - lineOver>0
                if(lineOver==0){
                    tLineArr[aLineCt] = l;
                    aLineCt++;
                    tLineCt++;
                } else {
                    //we don't want line count to increase here
                }
                lineOver+=1;
            }
            //reset count, increment line count, increment total line count
            count = 1;
        }
        //continue going through characters, printing, incrementing count, and setting char to next one
        putchar(c);
        count++;
        c = getchar();
    }
    //after everything, print out all the line data
    printf("\n");
    printf("Total lines over 50 chars: ");
    printf("%d",tLineCt);
    printf("\n");
    printf("Offending lines: ");
    //for all the valuese in the total line array, print them in the right format
    for(int i=0;i<aLineCt;i++){
        printf("%d,", tLineArr[i]);
        printf(" ");
    }
    printf("\n");
}
