# Time complexity analysis

## `put`
This method has a time complexity of `O(k)`, where `k` refers to the complexity
of the hash function, if there are no collisions in the hash table. However, if
there are collisions, then the helper method `quadratic_probing` will need to
iterate over all the indices of the hash table, thus making the time complexity
`O(n+k)` in the worst case.

## `get`
Since this method also uses the helper method `quadratic_probing`, which in
turn also calls the hash function, it also shares the same time complexity of
`O(n+k)`.
