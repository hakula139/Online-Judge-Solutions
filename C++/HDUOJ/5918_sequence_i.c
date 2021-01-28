#include <stdio.h>
#include <stdlib.h>

int* GetNext(int* arr, int size) {
  int* next_arr = (int*)calloc(size + 1, sizeof(int));
  int i = 0, j = -1;
  next_arr[0] = -1;
  while (i < size) {
    if (j == -1 || arr[i] == arr[j]) {
      ++i, ++j;
      next_arr[i] = (arr[i] != arr[j] ? j : next_arr[j]);
    } else {
      j = next_arr[j];
    }
  }
  return next_arr;
}

int KmpSearch(int* arr_a, int size_a, int* arr_b, int size_b, int* next_arr,
              int start_pos, int step) {
  int i = start_pos;
  int j = 0;
  int sum = 0;
  while (i < size_a) {
    if (j == -1 || arr_a[i] == arr_b[j])
      i += step, ++j;
    else
      j = next_arr[j];
    if (j == size_b) ++sum, j = next_arr[j];
  }
  return sum;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int case_i = 1; case_i <= t; ++case_i) {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    int* arr_a = (int*)calloc(n + 1, sizeof(int));
    int* arr_b = (int*)calloc(m + 1, sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", arr_a + i);
    for (int i = 0; i < m; ++i) scanf("%d", arr_b + i);

    int sum = 0;
    int* next_arr = GetNext(arr_b, m);
    for (int i = 0; i < p; ++i) {
      if (i + p * (m - 1) >= n) break;
      sum += KmpSearch(arr_a, n, arr_b, m, next_arr, i, p);
    }
    printf_s("Case #%d: %d\n", case_i, sum);

    free(arr_a);
    free(arr_b);
    free(next_arr);
  }
  return 0;
}
