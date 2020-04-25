import java.util.*;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args)throws Throwable{
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		int TC,a,b,i,ans,C = 1;
		TC  = Integer.parseInt(inp.readLine());
		while(TC-- != 0) {
			a = Integer.parseInt(inp.readLine()); b = Integer.parseInt(inp.readLine());
			ans = 0;
			for(i = a; i <= b;i++)
				ans = i%2 != 0 ? ans+i : ans;
			System.out.println("Case "+C+": "+ans);
			C++;
			
		}

	}

}
