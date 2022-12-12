def shortest_path(graph, node1, node2):
    path_list = [[node1]]
    path_index = 0
    # To keep track of previously visited nodes
    previous_nodes = {node1}
    if node1 == node2:
        return path_list[0]
        
    while path_index < len(path_list):
        current_path = path_list[path_index]
        last_node = current_path[-1]
        next_nodes = graph[last_node]
        # Search goal node
        if node2 in next_nodes:
            current_path.append(node2)
            return current_path
        # Add new paths
        for next_node in next_nodes:
            if not next_node in previous_nodes:
                new_path = current_path[:]
                new_path.append(next_node)
                path_list.append(new_path)
                # To avoid backtracking
                previous_nodes.add(next_node)
        # Continue to next path in list
        path_index += 1
    # No path is found
    return []

f = open("day12.txt", "r")
letters = f.read()
letters = ''.join(letters.splitlines())

width = 161
height = 41

graph = {}
graph_l = []

start = letters.find('S')
end = letters.find('E')

letters = letters[0:start] + 'a' + letters[start+1: ]
letters = letters[0:end] + 'z' + letters[end+1: ]

for i in range(width*height):
    graph[i] = []
    if i > width:
        if ord(letters[i]) + 1 >= ord(letters[i-width]):
            graph_l.append((i, i-width))
            graph[i].append(i-width)
    if i < width*height - width:
        if ord(letters[i]) + 1 >= ord(letters[i+width]):
            graph_l.append((i, i+width))
            graph[i].append(i+width)   
    if i % width != 0:
        if ord(letters[i]) + 1 >= ord(letters[i-1]):
            graph_l.append((i, i-1))
            graph[i].append(i-1)
    if i % width != width - 1:
        if ord(letters[i]) + 1 >= ord(letters[i+1]):
            graph_l.append((i, i+1))
            graph[i].append(i+1)               
    

visited = [] # List for visited nodes.
queue = []     #Initialize a queu
print(len(shortest_path(graph, start, end))-1)