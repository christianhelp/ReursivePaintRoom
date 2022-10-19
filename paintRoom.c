#include "paintRoom.h"
#include <stdio.h>
void recPaintRoom( RoomData room, int row, int col, int distanceFromA);
/* declare any other helper functions here*/

/* printName
 * input: none
 * output: none
 *
 * Prints name the student who worked on this solution
 */
void printName( )
{
    /* TODO : Fill in your name*/
    printf("\nThis solution was completed by:\n");
    printf("Christian Walker\n");
}

/* TODO
 * paintRoom
 * input: the room to process
 * output: N/A
 *
 * This non-recursive function is called by the driver and it makes the initial call to recursive function recPaintRoom.
 */
void paintRoom( RoomData r ){
    
    int i, j;
    for(i=0;i < r.numrows-1;i++){
        for(j=0; j < r.numcols-1; j++) if(r.roomArray[i][j] == 'A') break;
        if(r.roomArray[i][j] == 'A') break;
    }
    
    recPaintRoom(r,i,j,0);
    
    
    
}

/*
 
 Best case : O(1)
 Worst Case : O(4^n)
 
 */


/* TODO
 * recPaintRoom
 * input: the room to process, the row and column of the current location being explored, the distance traveled from 'A'
 * output: N/A
 */
void recPaintRoom( RoomData room, int row, int col, int distanceFromA ){
    
    if(room.roomArray[row][col] == '*' || (room.roomArray[row][col] != ' ' && room.roomArray[row][col] < 'A' + distanceFromA-1) ) return;
    
    /*Assignment condition*/
    room.roomArray[row][col] = (distanceFromA<=25) ?  'A' + distanceFromA : 'Z';
    
    /*LEFT*/
    recPaintRoom(room ,row ,col-1, distanceFromA+1  );
    
    
    /*RIGHT*/
    recPaintRoom(room, row, col+1 ,distanceFromA+1 );
    
    
    /*DOWN*/
    recPaintRoom(room ,row+1 ,col ,distanceFromA+1  );
    
    
    /* UP*/
    recPaintRoom(room , row-1, col, distanceFromA+1 );
    
    
}
 
