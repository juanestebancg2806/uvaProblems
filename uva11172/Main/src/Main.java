import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args)throws Throwable {
		Solve s = new Solve();
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		String line = inp.readLine();
		int N = Integer.parseInt(line);
		while(N != 0) {
			line = inp.readLine(); 
			String [] ints = line.split(" ");
			long a = Integer.parseInt(ints[0]), b = Integer.parseInt(ints[1]);
			System.out.println(s.solve(a, b));
			N--;
		}
		
	}

}

 class Solve{
	public String solve(long  a,long  b) {
		String ans;
		if(a > b)
			ans = ">";
		else if(a < b)
			ans = "<";
		else
			ans = "=";
		
		return ans;
	}
}