	int **transformedArr = deleteRow(r, c, arr, 1);
	delete[] arr;
	logTwoDimensionalArray(r, c, transformedArr);
	delete[] transformedArr;