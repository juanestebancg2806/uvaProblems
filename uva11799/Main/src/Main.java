import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {
	public static void main(String[] args)throws Throwable {
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		Solve s = new Solve();
		int N,i,TC,C = 1;
		TC = Integer.parseInt(inp.readLine());
		String line;
		int a[] = new int[102];
		while(TC-- != 0) {
			line = inp.readLine();
			String ss[] = line.split(" ");N = Integer.parseInt(ss[0]);
			for(i = 1; i < ss.length;i++) 
				a[i-1] = Integer.parseInt(ss[i]);
			System.out.println("Case "+C+": "+s.solve(a, N));
			C++;
		}

	}

}


class Solve{
	public int solve(int [] a,int N) {
		int ans = a[0],i;
		for(i = 0; i < N;i++)
			ans = Math.max(ans, a[i]);
		return ans;
	}
}