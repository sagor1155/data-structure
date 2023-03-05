import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * ConnectedComponentDfsAdjacencyList
 */
public class ConnectedComponentDfsAdjacencyList {

    private int numNodes = 0;
    private Map<Integer, List<Edge>> graph;
    private int componentCount = 0;
    private boolean[] visited;
    private int[] components;
    public class Edge {
        int from, to;
        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    public static void main(String[] args) {
        System.out.println("Find Connected Components Using DFS-Adjacency List");  
        ConnectedComponentDfsAdjacencyList cc = new ConnectedComponentDfsAdjacencyList();
        cc.createGraph();
        cc.findComponents();
    }

    public void findComponents() {
        visited = new boolean[numNodes];
        components = new int[numNodes];

        for (int i=0; i<numNodes; i++) {
            if (!visited[i]) {
                componentCount++;
                dfs(i);
            }
        }

        System.out.println("Total connected components: " + componentCount);
        printArray("Components", components);
    }

    public void dfs(int at) {
        visited[at] = true;
        components[at] = componentCount;

        List<Edge> neighbours = graph.get(at);
        if (neighbours != null) {
            for (Edge edge : neighbours) {
                if (!visited[edge.to]) {
                    dfs(edge.to);
                }
            }
        }
    }

    public void createGraph() {
        graph = new HashMap<>();
        // Setup a graph with five connected components:
        // {0,1,7}, {2,5}, {4,8}, {3,6,9}, {10}
        numNodes = 11;
        addEdge(0, 1);
        addEdge(1, 7);
        addEdge(7, 0);
        addEdge(2, 5);
        addEdge(4, 8);
        addEdge(3, 6);
        addEdge(6, 9);
    }

    public void addEdge(int from, int to) {
        List<Edge> list = graph.get(from);
        if (list == null) {
            list = new ArrayList<Edge>();
            graph.put(from, list);
        }
        list.add(new Edge(from, to));
    }

    private void printArray(String heads, int[] arr) {
        System.out.print("[" + heads + "] ");
        for (int elem : arr) {
            System.out.print(elem + " ");
        }
        System.out.println("");
    }

    
}