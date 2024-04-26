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

