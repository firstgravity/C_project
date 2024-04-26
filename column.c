#include "column.h"
#include <stdlib.h>
#define REALOC_SIZE 256
#include <stdio.h>

COLUMN *create_column(char *title){
    COLUMN *column = (COLUMN*)malloc(sizeof(COLUMN));
    column->Title = title;
    column->PS = 0;
    column->LS = 0;
    column->data = NULL;
    return column;
}

int insert_value(COLUMN *col, int value){
    if (col->data == NULL){
        col->data = (int*)malloc(REALOC_SIZE*sizeof(int));
        if (col->data == NULL){
            return 0;
        }
        else{
            col->PS = 256;
        }
    }
    else if(col->LS >= col->PS ){
        int* ptr = col->data;
        col->data = (int*)realloc(col->data, REALOC_SIZE*sizeof(int) + col->PS);
        if (col->data == NULL){
            col->data = ptr;
            return 0;
        }
        else{
            col->PS += 256;
        }
    }
    col->data[col->LS] = value;
    col->LS += 1;
    return 1;
}

