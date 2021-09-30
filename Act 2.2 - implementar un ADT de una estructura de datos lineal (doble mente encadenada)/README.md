# Complexity analysis
## `insertion`
This operation is always `O(1)` since the tail of the doubly linked list
can always be accessed in time `O(1)` and insertion always adds an item
to the tails of the list.

## `search`
This operation requires to iterate over the `n` nodes of the doubly linked list
regardless of having a head and tail. This is due to the fact that `search`
must search for the first node that matches the searched value, which could be
closer to the head or closer to the tail. As such, it is required to iterate
over all the nodes because of that uncertainty, having time complexity `O(n)`.

## `update`
This operation can take advantage of the head an tail of the doubly linked
list, as such the searching can be performed in time `O(n/2)` since it can
start from either the head or tail. However the time complexity still remains
`O(n)`.

## `deleteAt`
This operation is very similar to `update`, since it only differs on the
deleteion of the item, and thus it shares the same time complexity `O(n)`.
