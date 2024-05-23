#include <stdio.h>
#include <stdlib.h>
#include "Dataframe.h"

void showMenu() {
    printf("--------------------------");
    printf("Choose an option:\n");
    printf("1. Create Dataframe\n");
    printf("2. Fill Dataframe\n");
    printf("3. Hard Fill Dataframe\n");
    printf("4. Add Row\n");
    printf("5. Delete Row\n");
    printf("6. Add Column\n");
    printf("7. Delete Column\n");
    printf("8. Rename Column\n");
    printf("9. Search Value\n");
    printf("10. Replace Value\n");
    printf("11. Display Column Name\n");
    printf("12. Display Number of Rows\n");
    printf("13. Display Number of Columns\n");
    printf("14. Display Number of Values\n");
    printf("15. Display Number of Equal Values\n");
    printf("16. Display Number of Greater Values\n");
    printf("17. Display Number of Lesser Values\n");
    printf("18. Display Dataframe\n");
    printf("19. Display Dataframe Rows\n");
    printf("20. Display Dataframe Columns\n");
    printf("21. Free Dataframe\n");
    printf("22. Exit\n");
    printf("--------------------------");
}

int main() {
    int choice;
    int running = 1;
    Dataframe *df = NULL;

    while (running) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (df != NULL) {
                    printf("Dataframe already exists. Free it first.\n");
                } else {
                    df = create_Dataframe();
                    printf("Dataframe created.\n");
                }
                break;
            case 2:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    fill_Dataframe(df);
                    printf("Dataframe filled.\n");
                }
                break;
            case 3:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    hard_filling(df);
                    printf("Dataframe hard filled.\n");
                }
                break;
            case 4:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    add_row(df);
                    printf("Row added.\n");
                }
                break;
            case 5:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    delete_row(df);
                    printf("Row deleted.\n");
                }
                break;
            case 6:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    add_col(df);
                    printf("Column added.\n");
                }
                break;
            case 7:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int col_index;
                    printf("Enter column index to delete: ");
                    scanf("%d", &col_index);
                    if (col_index < df->LS) {
                        delete_column(&(df->Data[col_index]));  // Corrected here
                        printf("Column deleted.\n");
                    } else {
                        printf("Invalid column index.\n");
                    }
                }
                break;
            case 8:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    rename_col(df);
                    printf("Column renamed.\n");
                }
                break;
            case 9:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    search_val(df);
                }
                break;
            case 10:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    replace_val(df);
                }
                break;
            case 11:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int col_index;
                    printf("Enter column index to display name: ");
                    scanf("%d", &col_index);
                    dis_name_col(df, col_index);
                }
                break;
            case 12:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    dis_nb_rows(df);
                }
                break;
            case 13:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    dis_nb_col(df);
                }
                break;
            case 14:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    dis_nb_val(df);
                }
                break;
            case 15:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int value;
                    printf("Enter value to count occurrences: ");
                    scanf("%d", &value);
                    dis_nb_equal_val(df, value);
                }
                break;
            case 16:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int value;
                    printf("Enter value to count greater occurrences: ");
                    scanf("%d", &value);
                    dis_nb_greater_val(df, value);
                }
                break;
            case 17:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int value;
                    printf("Enter value to count lesser occurrences: ");
                    scanf("%d", &value);
                    dis_nb_less_val(df, value);
                }
                break;
            case 18:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    dis_dataframe(&df);
                }
                break;
            case 19:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int limit;
                    printf("Enter number of rows to display: ");
                    scanf("%d", &limit);
                    dis_dataframe_rows(df, limit);
                }
                break;
            case 20:
                if (df == NULL) {
                    printf("Create a Dataframe first.\n");
                } else {
                    int col_limit;
                    printf("Enter number of columns to display: ");
                    scanf("%d", &col_limit);
                    dis_dataframe_col(df, col_limit);
                }
                break;
            case 21:
                if (df == NULL) {
                    printf("No Dataframe to free.\n");
                } else {
                    for (int i = 0; i < df->LS; i++) {
                        delete_column(&(df->Data[i]));  // Corrected here
                    }
                    free(df->Data);
                    free(df);
                    df = NULL;
                    printf("Dataframe freed.\n");
                }
                break;
            case 22:
                if (df != NULL) {
                    for (int i = 0; i < df->LS; i++) {
                        delete_column(&(df->Data[i]));  // Corrected here
                    }
                    free(df->Data);
                    free(df);
                }
                printf("Exiting...\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
