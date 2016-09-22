import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class UVA11631 {
	public static Comparator<Edge> edgeComparator = new Comparator<Edge>() {
		@Override
		public int compare(Edge o1, Edge o2) {
			return o1.weight - o2.weight;
		}
	};

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer stk;
		PriorityQueue<Edge> listaEdges;
		while (true) {
			stk = new StringTokenizer(in.readLine());
			int numV = Integer.parseInt(stk.nextToken());
			int numE = Integer.parseInt(stk.nextToken());
			if (numV == 0)
				break;
			listaEdges = new PriorityQueue<Edge>(edgeComparator);
			int totalPeso = 0;
			Vertex[] vertices = new Vertex[numV];
			for (int i = 0; i < vertices.length; i++) {
				vertices[i] = new Vertex(i);
			}

			for (int i = 0; i < numE; i++) {
				stk = new StringTokenizer(in.readLine());
				int v1 = Integer.parseInt(stk.nextToken());
				int v2 = Integer.parseInt(stk.nextToken());
				int we = Integer.parseInt(stk.nextToken());
				vertices[v1].colaEdges.add(new Edge(v1, v2, we));
				vertices[v2].colaEdges.add(new Edge(v2, v1, we));
				totalPeso += we;

			}

			int MST = 0;
			TreeSet<Integer> vertexAdded = new TreeSet<>();
			vertexAdded.add(0);
			listaEdges.addAll(vertices[0].colaEdges);
			while (vertexAdded.size() < numV && !listaEdges.isEmpty()) {
				Edge temp = listaEdges.poll();

				if (!vertexAdded.contains((temp.vertex2))) {
					// System.err.println(temp.vertex1+" "+temp.vertex2+"
					// "+temp.weight);
					vertexAdded.add(temp.vertex2);
					MST += temp.weight;
					listaEdges.addAll(vertices[temp.vertex2].colaEdges);
				}
			}

			out.write(totalPeso - MST + "\n");

		}

		out.close();
		in.close();

	}

	static class Edge {
		int vertex1;
		int vertex2;
		int weight;

		public Edge(int v1, int v2, int we) {
			this.vertex1 = v1;
			this.vertex2 = v2;
			this.weight = we;
		}

	}

	static class Vertex {
		public int id;

		public Vertex(int id) {
			this.id = id;
		}

		PriorityQueue<Edge> colaEdges = new PriorityQueue<>(edgeComparator);

	}

}
