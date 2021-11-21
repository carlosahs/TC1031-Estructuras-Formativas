# Time complexity analysis

## `visit`
This method needs to iterate over every node of the tree to correctly output
the preorder, inorder, postorder, and level y level traversals, thus its time
complexity is `O(n)` where `n` is the number of nodes in the BST.

## `height`
Since the BST is implemented keeping track of the height of the tree every time
an item is added through a data member, the access to the height of the tree is
constant. So the time complexity is `O(1)`.

## `ancestors`
This methods searches for a node in the tree and then outputs all the nodes
visited to reach it. Since finding a node in a BST takes `O(lg n)` in the best
case, and `O(n)` in the worst case, the wrost case will be considered, so the
time complexity of this method is `O(n)`.

## `whatlevelamI`
Similarly to `ancestors`, this method has a time complexity of `O(n)` since it
needs to find the node first and then return the level, which is held by a
variable.
