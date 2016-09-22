import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class BankRobbery {

	public static void main(String[] args) throws IOException {		
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String ln;
		StringTokenizer stk;
		int N, M, B, P, origen, dest, we;
		ArrayList<NodoDist>[] graph;
		int[] banks, polices, distancias;
		Comparator<NodoDist> maxComp = new Comparator<NodoDist>() {
			@Override
			public int compare(NodoDist o1, NodoDist o2) {				
				if(o1.dist!=o2.dist)
					return o2.dist - o1.dist;
				else
					return o1.s - o2.s;
			}
		};
		while((ln=in.readLine())!=null){
			stk = new StringTokenizer(ln);
			N = Integer.parseInt(stk.nextToken());
			M = Integer.parseInt(stk.nextToken());
			B = Integer.parseInt(stk.nextToken());
			P = Integer.parseInt(stk.nextToken());			
			graph = new ArrayList[N];
			for (int i = 0; i < N; i++) {
				graph[i] = new ArrayList<NodoDist>();
			}
			for (int i = 0; i < M; i++) {
				stk = new StringTokenizer(in.readLine());
				origen = Integer.parseInt(stk.nextToken());
				dest =  Integer.parseInt(stk.nextToken());
				we =  Integer.parseInt(stk.nextToken());
				graph[origen].add(new NodoDist(dest, we));
				graph[dest].add(new NodoDist(origen, we));
			}
			if(P==0){
				out.printf("%d *%n", B);
				banks = new int[B];
				stk = new StringTokenizer(in.readLine());
				for (int i = 0; i < B; i++) {
					banks[i] = Integer.parseInt(stk.nextToken());
				}
				Arrays.sort(banks);
				out.write(banks[0]+"");
				for (int i = 1; i < B; i++) {
					out.write(" "+banks[i]);
				}
				out.println();
				continue;
			}
			banks = new int[B];
			stk = new StringTokenizer(in.readLine());
			for (int i = 0; i < B; i++) {
				banks[i] = Integer.parseInt(stk.nextToken());
			}		
			
			stk = new StringTokenizer(in.readLine());
			polices = new int[P];
			for (int i = 0; i < polices.length; i++) {
				polices[i] = Integer.parseInt(stk.nextToken());
			}
			PriorityQueue<NodoDist> allBanks = new PriorityQueue<NodoDist>(maxComp);
			distancias = dijkstra(graph, polices, N);
			
			for (int i = 0; i < B; i++) {
				allBanks.add(new NodoDist(banks[i], distancias[banks[i]]));
			}
			ArrayList<Integer> finalfinalNoVaMas = new ArrayList<Integer>();
			int max = 0;
			int count =0;
			NodoDist actual;
			while(!allBanks.isEmpty()){
				actual = allBanks.poll();
				if(count == 0){
					max = actual.dist;
					finalfinalNoVaMas.add(actual.s);
					count++;
				}else{
					if(actual.dist >= max){
						finalfinalNoVaMas.add(actual.s);
						count++;
					}else{
						break;
					}
				}
					
			}
			if(max == Integer.MAX_VALUE){
				out.printf("%d *%n", count);
			}else{
				out.printf("%d %d%n", count, max);
			}
			Collections.sort(finalfinalNoVaMas);
			out.write(finalfinalNoVaMas.get(0)+"");
			
			for (int i = 1; i < finalfinalNoVaMas.size(); i++) {
				out.write(" "+finalfinalNoVaMas.get(i));
			}
			out.println();
			
			
		}
		out.close();
		in.close();
		

	}
	
	
	public static int[] dijkstra(ArrayList<NodoDist>[] graph, int[] tombos, int N){
		
		int[] distances = new int[N];
		boolean[] visitado = new boolean[N];
		Arrays.fill(distances, Integer.MAX_VALUE);
		PriorityQueue<NodoDist> pq = new PriorityQueue<NodoDist>();
		for(int t: tombos){
			
			distances[t] = 0;
			pq.add(new NodoDist(t, distances[t]));
		}
		NodoDist actual;
		while(!pq.isEmpty()){
			actual = pq.poll();
			visitado[actual.s] = true;
			for(NodoDist v: graph[actual.s]){
				if(!visitado[v.s] && distances[v.s] > distances[actual.s]+v.dist){
					
					distances[v.s] = distances[actual.s]+v.dist;
					pq.add(new NodoDist(v.s, distances[v.s]));
				}
			}
			
		}
	
		return distances;
	}
	
	static class NodoDist implements Comparable<NodoDist>{
		int s;
		int dist;
		NodoDist(int num, int dist){
			this.s = num;
			this.dist = dist;
		}
		
		public int compareTo(NodoDist o) {
			if(this.dist!=o.dist)
				return this.dist - o.dist;
			else
				return this.s - o.s;
		}
	}

}
