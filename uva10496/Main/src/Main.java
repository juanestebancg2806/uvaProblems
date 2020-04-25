import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.*;


public class Main {
	public static int G[][] = new int[12][12];
	public static int tup[] = new int[24];
	public static int n;
	public static int mem[][] = new int[11][(1<<12)-1];
	
	public static int solve(int v,int A,int vs) {
		int ans = 99999999,i;
		if(mem[v][A] != -1)
			ans = mem[v][A];
		else if(A == (1<<n)-1)
			ans = G[v][vs];
		else {
			for(i = 0; i < n;i++) {
				if(i != v && (A&1<<i) == 0)
					ans = Math.min(ans,G[v][i]+solve(i,A|(1<<i),vs));
			}
		}
		return mem[v][A] = ans;
		
		
		
	}
	public static void main(String[] args)throws Throwable {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int TC = Integer.parseInt(stdin.readLine()),i,j,u,v,x,y,N;
		String [] line;
		while(TC-- != 0) {
			stdin.readLine();
			line = stdin.readLine().split(" ");
			x = Integer.parseInt(line[0]); y = Integer.parseInt(line[1]);
			tup[0] = x;tup[1] = y;
			N = Integer.parseInt(stdin.readLine());n = N+1;
			for(i = 0;i < 11;i++) {
				Arrays.fill(mem[i], -1);
			}
			for(j = 0,i = 2;j < N;j++,i += 2) {
				line = stdin.readLine().split(" ");
				tup[i] = Integer.parseInt(line[0]);tup[i+1] = Integer.parseInt(line[1]);
			}
			N = 2*(N+1);
			for(i = 0,u = 0; i < N;i += 2,u++) {
				G[u][u] = 0;
				x = tup[i];
				y = tup[i+1];
				for(j = i+2,v = u+1; j < N; j += 2,v++) 
					G[u][v] = G[v][u] = Math.abs(x-tup[j]) + Math.abs(y-tup[j+1]);
					
			}
			System.out.println("The shortest path has length "+solve(0,1,0));
			
		}

	}

}
