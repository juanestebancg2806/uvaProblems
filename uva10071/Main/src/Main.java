import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args)throws Throwable {
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		String line = inp.readLine();
		while(line != null) {
			String [] ints = line.split(" ");
			int a = Integer.parseInt(ints[0]), b = Integer.parseInt(ints[1]);
			System.out.println((b*2)*a);
			line = inp.readLine();
		}
		
	}

}
