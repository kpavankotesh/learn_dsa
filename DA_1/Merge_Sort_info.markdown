Merge Sort Analysis
===================

> Main part is the merge method (m is number of elements in the array)
	It exactly takes 4m+2 operations for each merge call. Taking the upper bound as 6m. 
	Number of merge calls happens can be analyzed by making a recursive tree. 
	In the recursive tree there are (logn + 1) levels. and at each level there are 6n operations taking place. 
	Number of operations at each level is 2^j * (6n/2^j) = 6n. 
	Here 2^j are number of arrays at each level and (6n/2^j) is number of operations on each array at level j
	so effectively the running time of merge sort is 6n(logn + 1)