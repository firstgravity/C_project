#include <stdio.h>
#include <stdlib.h>
#include "Dataframe.h"
#include "column.h"

int main()
{
    COLUMN *mycol = create_column("My column");
    int value;
    for(int i=0; i<5; i++){
        scanf("%d", &value);
        fflush(stdin);
        if (insert_value(mycol, value)){
            printf("    ok\n");
        }
        else {
            printf("error");
        }
    }
    print_col(mycol);
    printf("%d", occ_val(mycol, 3));
}