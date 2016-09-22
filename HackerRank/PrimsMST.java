import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class PrimsMST {
	
	

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer stk = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(stk.nextToken());
		int M = Integer.parseInt(stk.nextToken());
		ArrayList<Edge>[] graph = new ArrayList[N];
		
		for (int i = 0; i < N; i++) {
			graph[i] = new ArrayList<Edge>();
		}
		boolean[] inMST = new boolean[N];
		int from, to, we, MSTwe = 0, countInMST =0;
		for (int i = 0; i < M; i++) {
			stk = new StringTokenizer(in.readLine());
			from = Integer.parseInt(stk.nextToken());
			to = Integer.parseInt(stk.nextToken());
			we = Integer.parseInt(stk.nextToken());
			graph[from-1].add(new Edge(from-1, to-1, we));
			graph[to-1].add(new Edge(to-1, from-1, we));
		}
		
		PriorityQueue<Edge> edgesQ = new PriorityQueue<Edge>();
		int start = Integer.parseInt(in.readLine());
		inMST[start-1] = true;
		edgesQ.addAll(graph[start-1]);
		countInMST++;
		Edge actual;
		while(countInMST < N){
			actual = edgesQ.poll();
			if(!inMST[actual.to]){
				edgesQ.addAll(graph[actual.to]);
				countInMST++;
				inMST[actual.to] = true;
				MSTwe+=actual.we;
			}
			
		}
		
		out.write(MSTwe+"\n");
		out.close();
		in.close();	

	}	
	static class Edge implements Comparable<Edge>{
		int from, to, we;
		Edge(int _from, int _to, int _we){
			from=_from;
			to=_to;
			we=_we;
		}
		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return this.we-o.we;
		}
		
	}

}
