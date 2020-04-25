import java.util.*;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.math.BigInteger;
import java.io.InputStreamReader;

public class Main {

	public static long solve(int B,int P,int M) {
		long ans = 1;
		if(P == 0)
			ans = 1;
			
		
		return ans;
	}
	public static void main(String[] args)throws Throwable {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int B,P,M,ans,i;
		String line = stdin.readLine();
		while(line != null) {
			B = Integer.parseInt(line);
			P = Integer.parseInt(stdin.readLine());
			M = Integer.parseInt(stdin.readLine());
			
			System.out.println(solve(B,P,M));
			stdin.readLine();
			line = stdin.readLine();
			
		}

	}

}
