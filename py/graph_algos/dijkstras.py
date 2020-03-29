# dijkstra's algorithm

graph = {"start":{"A":6, "B":2}, "A":{"FIN":1}, "B":{"A":3, "FIN":5}, "FIN": {}};
costs = {"A":6, "B":2, "FIN":float("inf")};
parents = {"A":"start", "B":"start", "FIN":None};
processed = [];

def find_lowest_cost_node(costs, processed):
    ret_node = None;
    min_cost = float("inf");
    for n, c in costs.items():
        if c < min_cost and n not in processed:
            ret_node = n;
    print(ret_node);            
    return (ret_node);

        

def dijkstras(graph, costs, parents, processed):
    node = find_lowest_cost_node(costs, processed);
    while node is not None:
        cost = costs[node];
        neighbours = graph[node];
        for n in neighbours.keys():
            new_cost = cost + neighbours[n];
            if new_cost < costs[n]:
                costs[n] = new_cost;
                parents[n] = node;
        processed.append(node);
        node = find_lowest_cost_node(costs, processed);

dijkstras(graph, costs, parents, processed);
print(graph);
print(costs);
print(parents);
print(processed);    

