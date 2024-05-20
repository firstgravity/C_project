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

void fill_Dataframe(Dataframe* Dataf){
    int data = 0, value = 0;
    printf("Enter the number of data : ");
    scanf("%d", &value);
    for (int j = 0; j < Dataf->LS; j++){
        fflush(stdout);
        printf("Enter the data of -%s-", Dataf->Data[j]->Title);
        for (int i = 0; i < value; i++){
            fflush(stdin);
            scanf("%d", &data);
            insert_value(Dataf->Data[j], data);
        }
    }
}

void hard_filling(Dataframe* Dataf){
    for (int j = 0; j < Dataf->PS; j++){
        for (int i = 0; i < Dataf->Data[j]->PS; i++) {
            Dataf->Data[j]->data[i] = 0;
        }
    }
}

void dis_dataframe(Dataframe *df) {
    if (df == NULL) return;

    printf("Dataframe:\n");
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < df->PS; j++) {
            printf("%d ", df->Data[i]->data[j]);
        }
        printf("\n");
    }
}

void dis_dataframe_rows(Dataframe *df, int limit) {
    if (df == NULL || limit <= 0) return;

    printf("Dataframe (first %d rows):\n", limit);
    for (int i = 0; i < limit && i < df->LS; i++) {
        for (int j = 0; j < df->PS; j++) {
            printf("%d ", df->Data[i]->data[j]);
        }
        printf("\n");
    }
}

void dis_dataframe_col(Dataframe *df, int col_limit) {
    if (df == NULL || col_limit <= 0) return;

    printf("Dataframe (first %d columns):\n", col_limit);
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < col_limit && j < df->PS; j++) {
            printf("%d ", df->Data[i]->data[j]);
        }
        printf("\n");
    }
}

void dis_nb_less_val(Dataframe* Dataf, int  x){
    int count = 0;
    for (int i = 0; i < Dataf->LS; i++){
        for (int j = 0; j< Dataf->Data[i]->LS; j++){
            if (Dataf->Data[i]->data[j] < x) {
                count++;
            }
        }
    }
    printf("The number of value less than %d is : %d\n", x, count);
}

void dis_nb_greater_val(Dataframe* Dataf, int  x){
    int count = 0;
    for (int i = 0; i < Dataf->LS; i++){
        for (int j = 0; j< Dataf->Data[i]->LS; j++){
            if (Dataf->Data[i]->data[j] > x) {
                count++;
            }
        }
    }
    printf("The number of value greater than %d is : %d", x, count);
}