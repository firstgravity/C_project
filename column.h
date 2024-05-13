#ifndef C_PROJECT_COLUMN_H
#define C_PROJECT_COLUMN_H

#endif //C_PROJECT_COLUMN_H

typedef struct {
    char *Title;
    int PS;
    int LS;
    int *data;
}COLUMN;

/**
* Create a column
* @param1 : Column title
* @return : the created column
*/
COLUMN *create_column(char *title);

/**
* insert a value in the column
* @param1 : Column pointer
* @return : 0 or 1 if it's a succes or not
*/
int insert_value(COLUMN *col, int value);

/**
* delete a value in the column
* @param1 : Column pointer
*/
void delete_column(COLUMN **col);

/**
* print the cell of the column
* @param1 : Column pointer
*/
void print_col(COLUMN *col);

/**
* the occurency of a value in the column
* @param1 : Column pointer
* @param2 : value (interger)
* @return : the number of occurency
*/
int occ_val(COLUMN *col, int value);

/**
* tell the value at the position = rank
* @param1 : Column pointer
* @param2 : the rank (integer)
* @return : the value at position = rank
*/
int* pos_value(COLUMN *col, int rank);

/**
* tell the number of value greater than value
* @param1 : Column pointer
* @param2 : the value (integer)
* @return : the nb of value > than value
*/
int greater_val(COLUMN *col, int value);

/**
* tell the number of value less than value
* @param1 : Column pointer
* @param2 : the value (integer)
* @return : the nb of value < than value
*/
int less_val(COLUMN *col, int value);

/**
* tell the number of value equal than value
* @param1 : Column pointer
* @param2 : the value (integer)
* @return : the nb of value = to value
*/
int equal_val(COLUMN *col, int value);