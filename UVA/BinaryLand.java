import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BinaryLand {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String ln;
		StringTokenizer stk;
		int R, C;
		int rl, cl, rg, cg, rm, cm;
		while((ln=in.readLine())!=null){
			stk = new StringTokenizer(ln);
			R = Integer.parseInt(stk.nextToken());
			C = Integer.parseInt(stk.nextToken());
			char[][] map = new char[R][C];
			stk = new StringTokenizer(in.readLine());
			rl = Integer.parseInt(stk.nextToken());
			cl = Integer.parseInt(stk.nextToken());
			rg = Integer.parseInt(stk.nextToken());
			cg = Integer.parseInt(stk.nextToken());
			rm = Integer.parseInt(stk.nextToken());
			cm = Integer.parseInt(stk.nextToken());
			
			for (int i = 0; i < R; i++) {
				map[i] = in.readLine().toCharArray();
			}
			
			int result =  bfs(map, new Estado(rg-1, cg-1, rm-1, cm-1, 0), new Estado(rl-1, cl-1, rl-1, cl-1, 0), new boolean[R][C][R][C]);
			
			out.write((result > -1? result+"\n":"NO LOVE\n"));
			
			
		}
		out.close();
		in.close();

	}
	public static class Estado{
		int a, b, x, y, t;
		Estado(int a, int b, int x, int y, int t){
			this.a=a;
			this.b=b;
			this.x=x;
			this.y=y;
			this.t = t;
		}
		
		boolean Equal(Estado o){
			return (a==o.a && b==o.b && x==o.x && y==o.y );
		}
	}
	
	public static int bfs(char[][] grafo, Estado eInit, Estado eEsperado, boolean[][][][] visitados){
		
		Queue<Estado> queE = new LinkedList<Estado>();
		queE.add(eInit);
		
		
		Estado actual;
		boolean alcanzado = false;
		int a, b, x, y, t;
		while(!queE.isEmpty()){
			actual = queE.poll();
			a = actual.a;
			b = actual.b;
			x = actual.x;
			y = actual.y;
			t = actual.t;
			if(actual.Equal(eEsperado)){
				return t;
			}		
			
			if(visitados[a][b][x][y]) continue;
			visitados[a][b][x][y] = true;
			
			
			if(verificar(a-1, b, grafo) && verificar(x-1, y, grafo)){
				queE.add(new Estado(a-1, b, x-1, y, t+1));
				//System.out.printf("%d %d %d %d%n", a-1, b, x-1, y);
			}else if(!verificar(a-1, b, grafo) && verificar(x-1, y, grafo)){
				queE.add(new Estado(a, b, x-1, y, t+1));
				//System.out.printf("%d %d %d %d%n", a, b, x-1, y);
			}else if(verificar(a-1, b, grafo) && !verificar(x-1, y, grafo)){
				queE.add(new Estado(a-1, b, x, y, t+1));
				//System.out.printf("%d %d %d %d%n", a-1, b, x, y);
			}
			
			if(verificar(a+1, b, grafo) && verificar(x+1, y, grafo)){
				queE.add(new Estado(a+1, b, x+1, y, t+1));
				//System.out.printf("%d %d %d %d%n", a+1, b, x+1, y);
			}else if(!verificar(a+1, b, grafo) && verificar(x+1, y, grafo)){
				queE.add(new Estado(a, b, x+1, y, t+1));
				//System.out.printf("%d %d %d %d%n", a, b, x+1, y);
			}else if(verificar(a+1, b, grafo) && !verificar(x+1, y, grafo)){
				queE.add(new Estado(a+1, b, x, y, t+1));
				//System.out.printf("%d %d %d %d%n", a+1, b, x, y);
			}
			
			if(verificar(a, b-1, grafo) && verificar(x, y+1, grafo)){
				queE.add(new Estado(a, b-1, x, y+1, t+1));
				//System.out.printf("%d %d %d %d%n", a, b-1, x, y+1);
			}else if(!verificar(a, b-1, grafo) && verificar(x, y+1, grafo)){
				queE.add(new Estado(a, b, x, y+1, t+1));
				//System.out.printf("%d %d %d %d%n", a, b, x, y+1);
			}else if(verificar(a, b-1, grafo) && !verificar(x, y+1, grafo)){
				queE.add(new Estado(a, b-1, x, y, t+1));
				//System.out.printf("%d %d %d %d%n", a, b-1, x, y);
			}
			
			if(verificar(a, b+1, grafo) && verificar(x, y-1, grafo)){
				queE.add(new Estado(a, b+1, x, y-1, t+1));
				//System.out.printf("%d %d %d %d%n", a, b+1, x, y-1);
			}else if(!verificar(a, b+1, grafo) && verificar(x, y-1, grafo)){
				queE.add(new Estado(a, b, x, y-1, t+1));
				//System.out.printf("%d %d %d %d%n", a, b, x, y-1);
			}else if(verificar(a, b+1, grafo) && !verificar(x, y-1, grafo)){
				queE.add(new Estado(a, b+1, x, y, t+1));
				//System.out.printf("%d %d %d %d%n", a, b+1, x, y);
			}		
				
			
		}
		return -1;
	}
	
	static boolean verificar(int x, int y, char[][] grafo){
		if(x < 0) return false;
		if(y < 0) return false;
		if(x >= grafo.length) return false;
		if(y >= grafo[0].length) return false;
		if(grafo[x][y] =='#') return false;
		return true;
		
	}

}
