#include <stdio.h>

typedef unsigned long long ull;

ull reduce(ull arr[], ull size, ull (*operation)(ull a, ull b), ull initial) {
    ull result = initial;
    for (ull i = 0; i < size; i++) {
        result = operation(result, arr[i]);
    }
    return result;
}

ull add(ull a, ull b) {
    return a + b;
}

int main(void) {
    ull arr[] = {1, 2, 3, 4, 5};
    ull size = sizeof(arr) / sizeof(arr[0]);
    ull result = reduce(arr, size, add, 0);

    printf("%llu\n", result);

    return 0;
}