graph = {
    'A': set(['B','C']),
    'B': set(['A', 'D', 'E']),
    'C': set(['A', 'F']),
    'D': set(['B']), 
    'E': set(['B','F']), 
    'F': set(['C','E'])
}
def Iterative_dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    return visited

def recursive_dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for next in graph[start] - visited:
        recursive_dfs(graph, next, visited)
    return visited

print recursive_dfs(graph, 'C')
print Iterative_dfs(graph, 'C')
