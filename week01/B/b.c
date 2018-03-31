#include <stdio.h>

int main() {
    int num_testes;
    int n, m;
    char matrix[20][20];
    int completed = 0;
    int num_flags = 0;

    scanf("%d", &num_testes);
    // PRUUUUUUUUUUUUUUUUU
    for (int k = 0; k < num_testes; k++) {
        completed = 0;

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                matrix[i][j] = -1;
            }
        }
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" ");
                scanf("%c", &matrix[i][j]);
                //printf("%c\n", matrix[i][j]);
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                num_flags = 0;

                if (matrix[i][j] != 'F') {
                    if ((matrix[i - 1][j - 1] == 'F') && i > 0 && j > 0) {
                        num_flags++;
                    }

                    if ((matrix[i][j - 1] == 'F') && i >= 0 && j > 0) {
                        num_flags++;
                    }

                    if ((matrix[i - 1][j] == 'F') && i > 0 && j >= 0) {
                        num_flags++;
                    }

                    if ((matrix[i + 1][j + 1] == 'F') && i < n-1 && j < m-1) {
                        num_flags++;
                    }

                    if ((matrix[i + 1][j] == 'F') && i < n-1 && j >= 0) {
                        num_flags++;
                    }

                    if ((matrix[i][j + 1] == 'F') && i >= 0 && j < m-1) {
                        num_flags++;
                    }

                    if ((matrix[i + 1][j - 1] == 'F') && i < n-1 && j > 0) {
                        num_flags++;
                    }

                    if ((matrix[i - 1][j + 1] == 'F') && i > 0 && j < m-1) {
                        num_flags++;
                    }

                    if ((matrix[i][j] - '0' != num_flags) && matrix[i][j] != 'F') {
                        // printf("%d, %d\n", i, j);1
                        // printf("%d\n", num_flags);
                        // printf("%d\n", matrix[i][j]);
                        completed = 1;
                        break;
                    }
                }
                else {
                    int all_fs = 0;
                    if ((matrix[i - 1][j - 1] != 'F') && (i - 1 >= 0) && j - 1 >= 0) {
                        all_fs = 1;
                    }

                    if ((matrix[i][j - 1] != 'F') && (i >= 0) && j - 1 >= 0) {
                        all_fs = 1;
                    }

                    if ((matrix[i - 1][j] != 'F') && (i - 1 >= 0) && j >= 0) {
                        all_fs = 1;
                    }

                    if ((matrix[i + 1][j + 1] != 'F') && (i + 1 <= n-1) && j + 1 <= m-1) {
                        all_fs = 1;
                    }

                    if ((matrix[i + 1][j] != 'F') && i + 1 <= n-1 && j >= 0) {
                        all_fs = 1;
                    }

                    if ((matrix[i][j + 1] != 'F') && i >= 0 && j + 1 <= m-1) {
                        all_fs = 1;
                    }

                    if ((matrix[i + 1][j - 1] != 'F') && i + 1 <= n-1 && j - 1 >= 0) {
                        all_fs = 1;
                    }

                    if ((matrix[i - 1][j + 1] != 'F') && i - 1 >= 0 && j + 1 <= m-1) {
                        all_fs = 1;
                    }

                    if (all_fs == 0) {
                        // printf("%d, %d\n", i, j);
                        // printf("%d\n", num_flags);
                        // printf("%d\n", matrix[i][j]);
                        completed = 1;
                        break;
                    }
                }
            }
        }
        if (completed == 1) {
            printf("Please sweep the mine again!\n");
        }
        else {
            printf("Well done Clark!\n");
        }
    }

    return 0;
}