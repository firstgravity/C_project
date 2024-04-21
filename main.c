#include <stdio.h>
#include <stdlib.h>
#include "Dataframe.h"
#include "column.h"

int main()
{
    COLUMN mycol = create_column("My column");
    insert_value(&mycol, 5);
    print_col(&mycol);
    int occ = occ_val(&mycol, 5);
    int position = pos_value(&mycol, 0);
    int nb_sup = greater_val(&mycol, 4);
    int nb_inf = less_val(&mycol, 6);
    int equal = equal_val(&mycol, 5);
    delete_column(&mycol);

    Dataframe** Dataf = create_Dataframe();

    fill_Dataframe(Dataf);

    hard_filling(Dataf);

    print_Dataframe(Dataf);

    print_row_Dataframe(Dataf);

    print_col_Dataframe(Dataf);

    add_row(Dataf);

    delete_row(Dataf);

    add_col(Dataf);

    delete_col(Dataf);

    rename_col(Dataf);

    search_val(Dataf);

    replace_val(Dataf);

    dis_name_col( Dataf);

    dis_nb_rows(Dataf);

    dis_nb_col(Dataf);

    dis_nb_val(Dataf);

    dis_nb_greater_val( Dataf);

    dis_nb_less_val( Dataf);
    return 0;
}