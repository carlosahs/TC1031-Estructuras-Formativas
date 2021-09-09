# Asymptotic analysis
## Bubble sort
Since the algorithm operates using two loops (one
while-loop and one for-loop as implemented here) over
an array of size N , for the worst case (an array that
is sorted backwards) the algorithm needs to perform N
computations, while for the second loop it always
performs N computations because it has to cycle to the
whole array. Therefore the time complexity is O(N^2).

## Selection sort
The algorithm requires two arrays to sort an array, the
first array always performs N computations for an array
of size N, while the second performs N-k computations
for every kth iteration. As such the time complexity
may be expressed as ∑ (N-k) for k = 0 to N, which is
the same as (N^2 + N) / 2, therefore the time
complexity is O(N^2).

## Merge sort
The algorithm divides the array into smaller subarrays
until the size of the subarrays is 1. Since the
division of the array is by 2, the number of performed
operations is log_2(N) for an array of size N.

Furthermore, merge sort also performs a merge operation
that requires two loops, one to copy the contents of
the array to an auxiliar one, and another to perform
the merging. Both of these loops perform N computations
for a subarray of size N. Thus, the time complexity of
merge sort is O(Nlog(N)).

## Sequential search
Since the algorithm requires to look for every element
of an array of size N in the worst case, the time
complexity is O(N).

## Binary search
Since the algorithm splits the array into two parts for
every failed search, binary search performs log_2(N)
computations for an array of size N. Thus the time
complexity is O(log(N)).
