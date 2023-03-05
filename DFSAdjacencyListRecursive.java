import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DFSAdjacencyListRecursive {

    public static void main(String[] args) {
        System.out.println("Depth First Search - Adjacency List Recursive");

        int numNodes = 5;
        Map<Integer, List<Edge>> graph = new HashMap<>();
        addEdge(graph, 0, 1, 4);
        addEdge(graph, 0, 2, 5);
        addEdge(graph, 1, 2, -2);
        addEdge(graph, 1, 3, 6);
        addEdge(graph, 2, 3, 1);
        addEdge(graph, 2, 2, 10); // Self loop
    
        long nodeCount = dfs(0, new boolean[numNodes], graph);
        System.out.println("DFS node count starting at node 0: " + nodeCount);
        if (nodeCount != 4) System.err.println("Error with DFS");
    
        nodeCount = dfs(4, new boolean[numNodes], graph);
        System.out.println("DFS node count starting at node 4: " + nodeCount);
        if (nodeCount != 1) System.err.println("Error with DFS");
    }

    public static class Edge {
        int from, to, cost;
        
        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    public static void addEdge(Map<Integer, List<Edge>> graph, int from, int to, int cost) {
        List<Edge> list = graph.get(from);
        if (list == null) {
            list = new ArrayList<Edge>();
            graph.put(from, list);
        }
        list.add(new Edge(from, to, cost));
    }

    public static int dfs(int at, boolean[] visited, Map<Integer, List<Edge>> graph) {
        if (visited[at]) return 0;

        visited[at] = true;
        int count = 1;

        List<Edge> edges = graph.get(at);
        if (edges != null) {
            for (Edge edge : edges) {
                count += dfs(edge.to, visited, graph);
            }            
        }
        return count;
    }
}