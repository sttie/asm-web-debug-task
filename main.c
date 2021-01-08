#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/* Размер типа char не стандартизирован, а поэтому он может
   различаться на разных системах. По этой причине было принято
   решение использовать просто однобайтовые числа */
int count_lines(int8_t** matrix, int rows, int cols);


int main() {
    int rows, cols;

    do {
        printf("Введите количество строк двумерного массива: ");
        scanf("%d", &rows);
        if (rows <= 0) {
            printf("Количество строк должно быть положительным!\n");
        }
    } while (rows <= 0);

    do {
        printf("Введите количество столбцов двумерного массива: ");
        scanf("%d", &cols);
        if (cols <= 0) {
            printf("Количество столбцов должно быть положительным!\n");
        }
    } while (cols <= 0);


    int8_t** matrix = (int8_t**) malloc(sizeof(int8_t*) * rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int8_t*) malloc(sizeof(int8_t) * cols);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Пропускаем оставшийся в потоке символ новой строки 
            getchar();
            printf("matrix[%d][%d] = ", i, j);
            scanf("%hhd", &matrix[i][j]);
        }
    }

    printf("\nВходная матрица:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%-5d", matrix[i][j]);
        }
        printf("\n");
    }

    int length = count_lines(matrix, rows, cols);
    if (length > 0) {
        printf("Длина наибольшей вертикальной нулевой линии: %d\n", length);
    } else {
        printf("В заданном двумерном массиве нет нулевых элементов!\n");
    }

    return 0;
}