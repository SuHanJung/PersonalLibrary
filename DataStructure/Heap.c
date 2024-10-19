void Swap(int* a, int* b) {
	int storage = *a;
	*a = *b;
	*b = storage;
	return;
}

int compare(int a, int b) {
	return (a < b) ?  0:1;// LargeHeap
	//return (a > b) ? 0:1;// SmallHeap
}

int HeapPop(int *heap) {
	int storage = heap[1];
	heap[1] = heap[heap[0]--];
	for (int piv = 1; piv * 2 + 1 <= heap[0];) {
		if (compare(heap[piv * 2], heap[piv * 2 + 1])) {
			if (compare(heap[piv], heap[piv * 2])) break;
			Swap(&heap[piv], &heap[piv * 2]);
		}
		else {
			if (compare(heap[piv], heap[piv * 2 + 1])) break;
			else Swap(&heap[piv], &heap[piv * 2 + 1]);
		}
	}
	if (compare(heap[heap[0]], heap[heap[0] / 2])) Swap(&heap[heap[0]], &heap[heap[0] / 2]);
	return storage;
}

void HeapIn(int *heap, int input) {
	heap[++heap[0]] = input;
	for (int piv = heap[0]; compare(heap[piv], heap[piv / 2]) > 0; piv /= 2) Swap(&heap[piv], &heap[piv / 2]);
}

int HeapOut(int *heap) {
	return heap[1];
}

int HeapSize(int *heap) {
	return heap[0];
}

void Heap(int* heap, int data[], int size) {
	heap = malloc(sizeof(int) * (size + 1));
	heap[0] = 0;
	for (int t = 0; t < size; t++) HeapIn(heap, data[t]);
	return;
}
