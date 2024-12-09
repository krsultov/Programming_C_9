#include <stdio.h>
#include <limits.h>

#define PRINT_TYPE_INFO(TYPE, FORMAT, SIGNED_MIN, SIGNED_MAX, UNSIGNED_MAX) \
printf("%-15s %-10s %-15zu %-20lld %-20lld %-18s %-20llu\n", \
#TYPE, FORMAT, sizeof(TYPE), (long long)SIGNED_MIN, (long long)SIGNED_MAX, \
FORMAT, (unsigned long long)UNSIGNED_MAX)

int main() {
    printf("%-15s %-10s %-15s %-20s %-20s %-18s %-20s\n",
           "Type", "Format", "Size (bytes)", "Signed Min", "Signed Max", "Unsigned Format", "Unsigned Max");

    PRINT_TYPE_INFO(char, "%d", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
    PRINT_TYPE_INFO(short, "%d", SHRT_MIN, SHRT_MAX, USHRT_MAX);
    PRINT_TYPE_INFO(int, "%d", INT_MIN, INT_MAX, UINT_MAX);
    PRINT_TYPE_INFO(long, "%ld", LONG_MIN, LONG_MAX, ULONG_MAX);
    PRINT_TYPE_INFO(long long, "%lld", LLONG_MIN, LLONG_MAX, ULLONG_MAX);

    return 0;
}