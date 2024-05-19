#include "Dataframe.h"
#include <stdlib.h>
#include <stdio.h>

Dataframe* create_Dataframe(){
    Dataframe* new_dataframe = (Dataframe*)malloc(sizeof(Dataframe));
    new_dataframe ->Data =NULL;
    new_dataframe->PS = 0;
    new_dataframe->LS = 0;
    return new_dataframe;
}

void dis_dataframe(Dataframe *df) {
    if (df == NULL) return;

    printf("Dataframe:\n");
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < df->PS; j++) {
            printf("%d ", df->Data[i].data[j]);
        }
        printf("\n");
    }
}

void dis_dataframe_rows(Dataframe *df, int limit) {
    if (df == NULL || limit <= 0) return;

    printf("Dataframe (first %d rows):\n", limit);
    for (int i = 0; i < limit && i < df->LS; i++) {
        for (int j = 0; j < df->PS; j++) {
            printf("%d ", df->Data[i].data[j]);
        }
        printf("\n");
    }
}

void dis_dataframe_col(Dataframe *df, int col_limit) {
    if (df == NULL || col_limit <= 0) return;

    printf("Dataframe (first %d columns):\n", col_limit);
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < col_limit && j < df->PS; j++) {
            printf("%d ", df->Data[i].data[j]);
        }
        printf("\n");
    }
}