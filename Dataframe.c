#include "Dataframe.h"
#include <stdlib.h>
#include <stdio.h>

Dataframe* create_Dataframe(){
    /*
     * create a cdataframe
     */
    Dataframe* new_dataframe = (Dataframe*)malloc(sizeof(Dataframe));
    new_dataframe ->Data =NULL;
    new_dataframe->PS = 0;
    new_dataframe->LS = 0;
    return new_dataframe;
}

void fill_Dataframe(Dataframe* Dataf){
    /*
     * the function fill a dataframe with column already done
     */
    int data = 0, value = 0;
    printf("Enter the number of data : ");
    scanf("%d", &value);
    for (int j = 0; j < Dataf->LS; j++){
        printf("\n%d\n", j);
        printf("Enter the data of -%d- column : ", j);
        for (int i = 0; i < value; i++){
            fflush(stdin);
            scanf("%d", &data);
            insert_value(Dataf->Data[j], data);
        }
    }
}

void hard_filling(Dataframe* Dataf){
    /*
     * The function hard fill the cdataframe with 0
     */
    int value;
    printf("Enter the number of data : ");
    scanf("%d", &value);
    for (int j = 0; j < Dataf->LS; j++){
        for (int i = 0; i < value; i++) {
            insert_value(Dataf->Data[j], 0);
        }
    }
}

void dis_dataframe(Dataframe **df){
    /*
     * it display the cdataframe int the form of name/ value
     */
    if (df == NULL) return;
    for (int i = 0; i < (*df)->Data[0]->LS; i++) {
        printf("[%d] ", i);
        for (int j = 0; j < (*df)->LS; j++) {
            printf("%10d |", (*df)->Data[j]->data[i]);
        }
        printf("\n");
    }
}

void dis_dataframe_rows(Dataframe *df, int limit) {
    /*
     * display a row in the dataframe
     */
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
    /*
     * display a column.
     */
    if (df == NULL || col_limit <= 0) return;

    printf("Dataframe (first %d columns):\n", col_limit);
    for (int i = 0; i < df->LS; i++) {
        for (int j = 0; j < col_limit && j < df->PS; j++) {
            printf("%d ", df->Data[i]->data[j]);
        }
        printf("\n");
    }
}

void add_row(Dataframe* Dataf) {
    /*
    * add a row to the cdataframe
    */
    if (Dataf->Data == NULL){
        return;
    }
    int value;
    for(int i = 0; i < Dataf->LS; i++){
        printf("Enter the value for the new row of the column %d : ", i);
        scanf("%d", &value);
        Dataf->Data[i]->data[0] = value;
    }
}

void delete_row(Dataframe* Dataf) {
    /*
     * delete a row of the cdataframe
     */
    if (Dataf == NULL || Dataf->LS == 0) return;


    int row;
    printf("Enter the row number to delete: ");
    scanf("%d", &row);


    if (row < 0 || row >= Dataf->LS) return;
    free(Dataf->Data[row]);
    for (int i = row; i < Dataf->LS - 1; i++) {
        Dataf->Data[i] = Dataf->Data[i + 1];
    }
    Dataf->LS--;
    Dataf->Data = realloc(Dataf->Data, Dataf->LS * sizeof(int*));
}

void add_col(Dataframe* Dataf) {
    /*
     * add a column in the cdataframe
     */
    printf("Enter the name of the new col : ");
    char str[32];
    scanf("%s", str);
    if (Dataf->Data == NULL){
        Dataf->Data = (COLUMN**) malloc(sizeof(COLUMN*)*256);
    }
    Dataf->Data[Dataf->LS] = create_column(str);
    Dataf->LS += 1;
}

void delete_col(Dataframe* Dataf) {
    if (Dataf == NULL || Dataf->PS == 0) return;
    int col;
    printf("Enter the column number to delete: ");
    scanf("%d", &col);
    if (col < 0 || col >= Dataf->PS) return;
    for (int i = 0; i < Dataf->LS; i++) {
        for (int j = col; j < Dataf->PS - 1; j++) {
            Dataf->Data[i][j] = Dataf->Data[i][j + 1];
        }
        Dataf->Data[i] = realloc(Dataf->Data[i], (Dataf->PS - 1) * sizeof(int));
    }
    Dataf->PS--;
}

void rename_col(Dataframe* Dataf) {
    /*
     * rename a colum of the cdataframe
     */
    int col;
    char new_title[100];
    int new_title_length = 0;
    int i;
    if (Dataf == NULL) {
        printf("Dataframe is NULL.\n");
        return;
    }
    printf("Enter the column number to rename: ");
    scanf("%d", &col);
    if (col < 0 || col >= Dataf->PS) {
        printf("Invalid column number.\n");
        return;
    }
    printf("Enter the new title for column %d: ", col);
    scanf("%99s", new_title);
    while (new_title[new_title_length] != '\0' && new_title_length < 100) {
        new_title_length++;
    }
    Dataf->Data[col]->Title = (char*)realloc(Dataf->Data[col]->Title, (new_title_length + 1) * sizeof(char));
    for (i = 0; i < new_title_length; i++) {
        Dataf->Data[col]->Title[i] = new_title[i];
    }
    Dataf->Data[col]->Title[i] = '\0';
    printf("Column %d renamed to %s\n", col, Dataf->Data[col]->Title);
}

void search_val(Dataframe* Dataf) {
    /*
     * search a value in the cdataframe
     */
    int value;
    int found = 0;
    if (Dataf == NULL) {
        printf("Dataframe is NULL.\n");
        return;
    }
    printf("Enter the value to search for: ");
    scanf("%d", &value);
    for (int i = 0; i < Dataf->LS; i++) {
        for (int j = 0; j < Dataf->Data[0]->LS; j++) {
            if (Dataf->Data[i]->data[j] == value) {
                printf("Value %d found at column %d, row %d\n", value, i + 1, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Value %d not found in the dataframe.\n", value);
    }
}

void replace_val(Dataframe* Dataf) {
    /*
     * replace a cell of the cdataframe
     */
    int old_value, new_value;
    int replaced = 0;
    if (Dataf == NULL) {
        printf("Dataframe is NULL.\n");
        return;
    }
    printf("Enter the value to replace: ");
    scanf("%d", &old_value);
    printf("Enter the new value: ");
    scanf("%d", &new_value);
    for (int i = 0; i < Dataf->LS; i++) {
        for (int j = 0; j < Dataf->Data[0]->LS; j++) {
            if (Dataf->Data[i]->data[j] == old_value) {
                Dataf->Data[i]->data[j] = new_value;
                printf("Replaced value %d with %d at row %d, column %d\n", old_value, new_value, i + 1, j + 1);
                replaced = 1;
            }
        }
    }
    if (!replaced) {
        printf("Value %d not found in the dataframe.\n", old_value);
    }
}

void dis_nb_less_val(Dataframe* Dataf, int  x){
    /*
     * display the number of value less than the input
     */
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
    /*
     * number of value greater than the input in the cdataframe
     */
    int count = 0;
    for (int i = 0; i < Dataf->LS; i++){
        for (int j = 0; j< Dataf->Data[i]->LS; j++){
            if (Dataf->Data[i]->data[j] > x) {
                count++;
            }
        }
    }
    printf("The number of value greater than %d is : %d\n", x, count);
}

void dis_nb_equal_val(Dataframe* Dataf, int  x){
    int count = 0;
    for (int i = 0; i < Dataf->LS; i++){
        for (int j = 0; j< Dataf->Data[i]->LS; j++){
            if (Dataf->Data[i]->data[j] == x) {
                count++;
            }
        }
    }
    printf("The number of value equal than %d is : %d\n", x, count);
}

void dis_nb_val(Dataframe* Dataf){
    printf("The number of value is : %d \n", Dataf->LS * Dataf->Data[0]->LS);
}

void dis_nb_rows(Dataframe* Dataf){
    printf("The number of rows is : %d\n", Dataf->Data[0]->LS);
}

void dis_nb_col(Dataframe* Dataf){
    printf("The number of column is : %d\n", Dataf->LS);
}

void dis_name_col(Dataframe* Dataf, int x){
    if (x==-1){
        for (int i = 0; i < Dataf->LS; i++){
            printf("[%d]: %s\t", i, Dataf->Data[i]->Title);
        }
        printf("\n");
    }
    else if( x <= Dataf->LS){
        printf("The name of the column %d is : %s\n", x, Dataf->Data[x]->Title);
    }
    else{
        printf("The column %d is not yet define !\n");
    }
}
