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

void delete_column(COLUMN **col){
    free(col);
    col = NULL;
}

void print_col(COLUMN *col){
    for (int i = 0; i<col->LS; i++){
        printf("[%d]    %d\n", i, col->data[i]);
    }
}

int occ_val(COLUMN *col, int value){
    int count = 0;
    for(int i  = 0; i < col->LS; i++){
        if (value == col->data[i]){
            count++;
        }
    }
    return count;
}

int* pos_value(COLUMN *col, int rank){
    if (rank<=col->LS) {
        return col->data+rank;
    }
    return NULL;
}

int greater_val(COLUMN *col, int value){
    int count = 0;
    for(int i = 0; i<col->LS; i++){
        if (col->data[i]>value){
            count++;
        }
    }
    return count;
}

int less_val(COLUMN *col, int value){
    int count = 0;
    for(int i = 0; i<col->LS; i++){
        if (col->data[i]<value){
            count++;
        }
    }
    return count;
}

int equal_val(COLUMN *col, int value){
    int count = 0;
    for(int i  = 0; i < col->LS; i++){
        if (value == col->data[i]){
            count++;
        }
    }
    return count;
}
