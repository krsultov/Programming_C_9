#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 11

int main(void) {

#ifdef ARRAY_SIZE
#if ( ARRAY_SIZE > 11 ) && ( ARRAY_SIZE < 1 )
    printf("Array size is not withing the range of supported numbers by the program. Use a number between 0 and 11\n");
#else
    int arr[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = pow(2,i);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\n%d", arr[i]);
    }

#endif

#else
    printf("No array size is present");
#endif

    return 0;
}