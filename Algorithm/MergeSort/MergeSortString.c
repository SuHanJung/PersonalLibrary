
compare(char *a, char* b){
	for (int t = 0; a[t] != 0 || b[t] != 0; t++) {
		if (a[t] < b[t]) return -1;
		else if (a[t] > b[t]) return 1;
	}
	return 0;
}
int MergeSorting(char arr[][51], int* ans, int n, int cell) {
	int* storage = (int*)malloc(sizeof(int) * n);
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if (compare(arr[ans[start + left]], arr[ans[start + cell + right]]) == 1) {
				storage[start + left + right] = ans[start + cell + right];
				right++;
			}
			else {
				storage[start + left + right] = ans[start + left];
				left++;
			}
			if (right >= end) {
				for (; left < cell; left++) storage[start + left + right] = ans[start + left];
				break;
			}
			else if (left >= cell) {
				for (; right < end; right++) storage[start + left + right] = ans[start + cell + right];
				break;
			}
		}
	}
	if (n % (cell * 2) <= cell) for (int t = 0, end = (n / (cell * 2)) * cell * 2; t < end; t++) ans[t] = storage[t];
	else for (int t = 0; t < n; t++) ans[t] = storage[t];
	free(storage);
	return 0;
}

void MergeSort(char arr[][51], int* ans, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, ans, n, cell);
	}
	return;
}
