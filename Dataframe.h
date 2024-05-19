#ifndef C_PROJECT_DATAFRAME_H
#define C_PROJECT_DATAFRAME_H

#endif //C_PROJECT_DATAFRAME_H

typedef struct{
    char* Title;
    int** Data;
    int LS;
    int PS;
}Dataframe;


Dataframe** create_Dataframe();

void fill_Dataframe(Dataframe** Dataf);

void hard_filling(Dataframe** Dataf);

void add_row(Dataframe** Dataf);

void delete_row(Dataframe** Dataf);

void add_col(Dataframe** Dataf);

void delete_col(Dataframe** Dataf);

void rename_col(Dataframe** Dataf);

void search_val(Dataframe** Dataf);

void replace_val(Dataframe** Dataf);

void dis_name_col(Dataframe** Dataf);

void dis_nb_rows(Dataframe** Dataf);

void dis_nb_col(Dataframe** Dataf);

void dis_nb_val(Dataframe** Dataf);

void dis_nb_greater_val(Dataframe** Dataf);

void dis_nb_less_val(Dataframe** Dataf);

void dis_dataframe(Dataframe *df);

void dis_dataframe_rows(Dataframe *df, int limit);

void dis_dataframe_col(Dataframe *df, int col_limit);

