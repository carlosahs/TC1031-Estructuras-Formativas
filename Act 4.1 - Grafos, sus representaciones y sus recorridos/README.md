# Time complexity analysis

## `loadGraphList`
This funcion reads a file with a list of pairs representing an edge. The
reading of this information if performed with a loop that reads each line of
the file, so that means its time complexity is `O(n)`, where `n` is the number
of lines of the file.

## `DFS`
This function searches a path from a start to a goal, exploring a single path
first and then moving to the next possible path. Due to this behaviour, `DFS`
may need to search every node in the graph in order to find a path. Furthermore,
to check if a node was already visited takes `O(log n)` since the visited
nodes are stored in a set that implements an self-balancing tree. Thus the
time complexity is `O(n log n)`. This is backed by the fact that visited nodes are
stored and then ignore if encountered again, hence no extra computation is performed.

## `BFS`
Similarly to `DFS`, this function may need to search every node in the graph in
order to find a possible path, and visited nodes are stored in a set as well,
thus the time complexity is equally `O(n log n)`. Additionally, although the time 
complexity is the same, the space complexity is worse than that of `DFS`, since every
path taken is stored until the goal is found.
