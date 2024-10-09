#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // This pointer will hold the
    // base address of the block created
    int *ptr1, *ptr2;
    int n;

    // Get the number of elements for the array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr1 = (int*) malloc(n * sizeof(int));

    // Dynamically allocate memory using calloc()
    ptr2 = (int*) calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr1 == NULL || ptr2 == NULL)
    {
        printf("New memory NOT allocated!!!\n");
        exit(0);
    }

    // Memory has been successfully allocated
    printf("Memory successfully allocated.\n");

    // Get the elements of the array
    for (size_t i = 0; i < n; i++)
    {
        ptr1[i] = i + 1;
        ptr2[i] = i + 1;
    }

    // Print the elements of the array
    printf("The elements of the ptr1 array are: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d, ", ptr1[i]);
    }

    printf("\n");

    // Print the elements of the array
    printf("The elements of the ptr2 array are: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d, ", ptr2[i]);
    }

    printf("\n");

    // Free the memory of ptr2
    free(ptr2);
    ptr2 = NULL;
    printf("ptr2 memory successfully freed.\n");

    // Get the number of elements for the array
    printf("Enter new number of elements: ");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    int *new_ptr = (int*) realloc(ptr1, n * sizeof(int));

    if (new_ptr == NULL)
    {
        printf("New memory NOT allocated!!!\n");
        exit(0);
    }

    printf("Memory successfully re-allocated using realloc.\n");

    // DO NOT Free the memory ptr1 (old pointer) is pointing to
    // But you should set it to NULL
    ptr1 = NULL;

    // Get the new elements of the array
    for (size_t i = 0; i < n; i++)
    {
        new_ptr[i] = i + 1;
    }

    // Print the elements of the array
    printf("The elements of the new array are: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d, ", new_ptr[i]);
    }

    printf("\n");

    // Free the memory
    free(new_ptr);
    new_ptr = NULL;
    printf("new_ptr memory successfully freed.\n");

    return 0;
}
