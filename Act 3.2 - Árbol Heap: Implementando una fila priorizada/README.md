# Time complexity analysis

## `push`
This method inserts a new element to the heap in `O(1)` time. However, it also
calls the `heapify_up` method to ensure that the structure of the min-heap is
not altered. The cost of this helper method call is `O(lg n)` as it explores
all the levels of the complete binary tree of the heap. Thus the time
complexity of the `push` method is `O(lg n)`.

## `pop`
Similarly to `push`, this method can remove the top element in `O(1)` time but
it also calls the `heapify_down` method to ensure that the structure of the
min-heap is not altered. The cost of `heapify_down` is `O(lg n)` since it also
explores all the levels of the complete binary tree of the heap. Thus the time
complexity of the `pop` method is `O(lg n)`.

## `top`
This method simply returns the element with the highest priority and does so by
returning the element that resides in the root of the binary tree of the heap,
hence its time complexity is `O(1)`.

## `empty`
This method returns `true` if the number of inserted elements in the heap is 0,
otherwise it returns `false`. Due to the fact that the method only requires to
access a variable to perform what it is supposed to, its time complexity is
`O(1)`.

## `full`
In the same way as `empty`, this method accesses to a variable containing the
number of elements inserted, and it returns `true` if the number is equal to
the maximum capacity of the heap. So it follows that its time complexity is
also `O(1)`.
