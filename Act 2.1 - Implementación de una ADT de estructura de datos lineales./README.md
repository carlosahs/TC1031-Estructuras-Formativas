# Complexity analysis
## `insertion`
Since this operation iterates over the `n` nodes of a linked list, the time
complexity of this operation is always `O(n)`.
## `search`
This operation also requires to iterate over the `n` nodes of the linked list.
However, in this case it will do so by an average of `n/2` operations,
nonetheless the time complexity is still `O(n)`.
## `update`
This operation is similar to `search` but it modifies the value that is in the
index searched. Since the modification can be considered to take time `O(1)`,
the time complexity is `O(n)` given that searching must be performed.
## `deleteAt`
This operation is similar to `update` but it deleted the value at the given
index. The same conclusion for the time complexity `O(n)` is made for this
operation since the searching must be performed and this search has time
complexity `O(n)` due to iteration over the nodes of the linked list until the
given index is found.
