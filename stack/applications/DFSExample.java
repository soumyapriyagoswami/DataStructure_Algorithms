import java.util.*;

public class DFSExample {
    private List<LinkedList<Integer>> adjList;

    public DFSExample(int vertices) {
        adjList = new ArrayList<>(vertices);
        for (int i = 0; i < vertices; i++) {
            adjList.add(new LinkedList<>());
        }
    }

    public void addEdge(int v, int w) {
        adjList.get(v).add(w);
    }

    public void DFS(int startVertex) {
        boolean[] visited = new boolean[adjList.size()];
        Stack<Integer> stack = new Stack<>();

        stack.push(startVertex);

        while (!stack.isEmpty()) {
            int vertex = stack.pop();

            if (!visited[vertex]) {
                System.out.print(vertex + " ");
                visited[vertex] = true;
            }

            for (int v : adjList.get(vertex)) {
                if (!visited[v]) {
                    stack.push(v);
                }
            }
        }
    }

    public static void main(String[] args) {
        DFSExample graph = new DFSExample(4);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(2, 0);
        graph.addEdge(2, 3);
        graph.addEdge(3, 3);

        System.out.println("Following is Depth First Traversal (starting from vertex 2):");
        graph.DFS(2);
    }
}
