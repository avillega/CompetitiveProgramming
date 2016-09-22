import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Map;
import java.util.TreeMap;

public class UVA417 {
	static char[] abc = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
			't', 'u', 'v', 'w', 'x', 'y', 'z' };

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		Comparator<String> customComp = new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				if (o1.length() != o2.length())
					return o1.length() - o2.length();
				return o1.compareTo(o2);
			}
		};
		TreeMap<String, Integer> map = new TreeMap<>(customComp);
		generate(map, 1);

		String linea;
		while ((linea = in.readLine()) != null) {
			if (!map.containsKey(linea)) {
				out.write("0\n");
			} else {
				out.write((map.get(linea)) + "\n");
			}
		}
		out.flush();
		out.close();
		in.close();

	}

	public static void generate(TreeMap<String, Integer> map, int numeroActual) {

		if (map.isEmpty()) {
			for (char c : abc) {
				map.put(c + "", numeroActual);
				numeroActual++;
			}
			generate(map, numeroActual);
		}
		TreeMap<String, Integer> temp = new TreeMap<>();

		for (Map.Entry<String, Integer> entry : map.entrySet()) {
			if (numeroActual > 83682)
				return;
			String key = entry.getKey();
			int i = (int) (key.charAt(key.length() - 1) - 'a' + 1);
			for (; i < abc.length; i++) {
				temp.put(key + abc[i], numeroActual);
				numeroActual++;
			}
		}

		map.putAll(temp);
		generate(map, numeroActual);

	}

}
