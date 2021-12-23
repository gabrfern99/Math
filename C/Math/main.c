#include <stdio.h>
#include <malloc.h>
#include "matrix.c"

#define ROWS 3
#define COLUMNS 5

/* List with all TESTING_* variables:
 *  TESTING_SWAP
 *  TESTING_PIVOT
 *  TESTING_RAISE_LEFTMOST_PIVOT
 *  TESTING_MULTIPLY_ROW_BY_NONZERO
 */
#define TESTING_MULTIPLY_ROW_BY_NONZERO

int main ()
{
	float array[ROWS][COLUMNS] = {
			{0, 0, 0, 0, 1},
			{0, 0, 3, 1, 3},
			{1, 2, 3, 4, 5} };
	float *array_pointer = &array[0][0];
	
#ifdef TESTING_SWAP
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	swap_rows(ROWS, COLUMNS, array_pointer, 0, 2);

	printf("Swapped Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
#endif /* TESTING_SWAP */

#ifdef TESTING_PIVOT
	printf("Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
	for(size_t i = 0; i < ROWS; ++i)
	{
		int pivot = get_row_pivot_index(ROWS, COLUMNS, array_pointer, i);
		printf("%d\n", pivot);
	}
#endif /* TESTING_PIVOT */

#ifdef TESTING_RAISE_LEFTMOST_PIVOT
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	raise_leftmost_pivot_rows(ROWS, COLUMNS, array_pointer);

	printf("Raised Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);
#endif /* TESTING_RAISE_LEFTMOST_PIVOT */

#ifdef TESTING_MULTIPLY_ROW_BY_NONZERO
	printf("Original Matrix:\n");
	print_matrix(ROWS, COLUMNS, array_pointer);

	float multiplied_row[COLUMNS];
	float *multiplied_pointer;
	multiplied_pointer = &multiplied_row[0];

	printf("Multiplied row: ");
	multiply_row_by_nonzero(ROWS, COLUMNS, array_pointer, 2,\
							3.5, multiplied_pointer);
	for(int i = 0; i < COLUMNS; ++i)
	{
		printf("%.1f ", multiplied_row[i]);
	}
	printf("\n");

#endif /* TESTING_MULTIPLY_ROW_BY_NONZERO */

	return (0);
}
