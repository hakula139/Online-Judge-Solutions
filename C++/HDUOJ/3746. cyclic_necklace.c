#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* GetNext(char* str, int size) {
    int* next_arr = (int*)calloc(size + 1, sizeof(int));
    int  i = 0, j = -1;
    next_arr[0] = -1;
    while (i < size) {
        if (j == -1 || str[i] == str[j])
            next_arr[++i] = ++j;
        else
            j = next_arr[j];
    }
    return next_arr;
}

int main() {
    const int kMaxSize = 100233;
    int       t;
    scanf_s("%d", &t);
    while (t--) {
        char pearls[kMaxSize];
        scanf_s("%s", pearls, kMaxSize);
        int  size     = strlen(pearls);
        int* next_arr = GetNext(pearls, size);
        int  length   = size - next_arr[size];
        int  remain   = size % length;
        if (!next_arr[size])
            printf_s("%d\n", size);
        else if (!remain)
            printf_s("0\n");
        else
            printf_s("%d\n", length - remain);
        free(next_arr);
    }
    return 0;
}
