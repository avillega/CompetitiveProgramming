import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.LinkedList;

public class LeoPrimeFactors {
	

	static long[] busqueda = { 1,2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230L, 200560490130L,
			7420738134810L, 304250263527210L, 13082761331670030L, 614889782588491410L, 1000000000000000005L };

	

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		int N = Integer.parseInt(in.readLine());
		
		for (int casos = 0; casos < N; casos++) {
			
			long num = Long.parseLong(in.readLine());
			int i = 0;

			while(busqueda[i] < num){
				i++;
			}
			
			out.write((busqueda[i]>num? i-1:i)+"\n");
		}

		out.close();
		in.close();

	}

}
