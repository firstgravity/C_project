#ifndef C_PROJECT_COLUMN_H
#define C_PROJECT_COLUMN_H

#endif //C_PROJECT_COLUMN_H

typedef struct {
    char *Title;
    int PS;
    int LS;
    int *data;
}COLUMN;

COLUMN create_column(char *title);

int insert_value(COLUMN *col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN *col);

int occ_val(COLUMN *col, int value);

int pos_value(COLUMN *col, int rank);

int greater_val(COLUMN *col, int value);

int less_val(COLUMN *col, int value);

int equal_val(COLUMN *col, int value);