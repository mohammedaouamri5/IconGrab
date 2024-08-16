#pragma once





#define CHEAT_SHEET_CSV "./cheat-sheet.csv"
#define CHEAT_SHEET_BIN "./cheat-sheet.bin"



#define MAX_LEN_DISC 49
#define MAX_LEN_CODE 4
#define NUMBER_OF_ROWS 12536



typedef struct row{
    char disc[MAX_LEN_DISC+1];
    char code[MAX_LEN_CODE+1];
} row;


/* the redding mode 

    `CODE` is when we reed the code
    `DISC` is when we reed the disc
*/
enum RMODE {
    CODE, 
    DISC
};

row* read(void); 



#ifdef  CSV 

void store(row*); 

#endif // CSV


