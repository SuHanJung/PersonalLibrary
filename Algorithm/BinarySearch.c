void searching(int list[],int n,int val) {
	int piv = 0, maxi = n, mini = 0;
	for (; maxi - mini >= 1;) {
		piv = (maxi + mini) / 2;
		if (list[piv] == val) return 1;
		else if (list[piv] > val) maxi = piv;
		else mini = piv;
	}
}
