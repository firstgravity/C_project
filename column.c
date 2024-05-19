#include "column.h"
#include "Dataframe.h"
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

void dis_dataframe(Dataframe *df) {
    if (df == NULL) return;

    printf("Dataframe:\n");
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < df->PS; j++) {
            printf("%d ", df->Data[i][j]);
        }
        printf("\n");
    }
}

void dis_dataframe_rows(Dataframe *df, int limit) {
    if (df == NULL || limit <= 0) return;

    printf("Dataframe (first %d rows):\n", limit);
    for (int i = 0; i < limit && i < df->LS; i++) {
        for (int j = 0; j < df->PS; j++) {
            printf("%d ", df->Data[i][j]);
        }
        printf("\n");
    }
}

void dis_dataframe_col(Dataframe *df, int col_limit) {
    if (df == NULL || col_limit <= 0) return;

    printf("Dataframe (first %d columns):\n", col_limit);
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < col_limit && j < df->PS; j++) {
            printf("%d ", df->Data[i][j]);
        }
        printf("\n");
    }
}