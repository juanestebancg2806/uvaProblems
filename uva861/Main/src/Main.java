import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.*;


public class Main {
	public static boolean board[][] = new boolean[10][10];
	public static long mem[][][] = new long[10][82][82];
	
	public static boolean isValid(int r,int c,int n) {
		boolean ans = true;
		int i = r-1, j = c-1;
		while (i >= 0 && j >= 0 && ans) {
			ans = board[i][j] == false;
			i--;
			j--;
		}
		i = r-1; j = c+1;
		while (i >= 0 && j < n && ans) {
			ans = board[i][j] == false;
			i--;
			j++;
		}	
		
		return ans;
	}
	
	
	public static long solve(int n,int k,int r,int c, int N) {
		long ans = 0;
		int nc,nr;
		if(mem[n][k][N] != -1)
			ans = mem[n][k][N];
		
		else if(k == 0)
			ans = 1;
		else if(N == n*n || n*n-N < k)
			ans = 0;
		else {
			nr = c+1 == n ? r+1 : r;
			nc = c+1 < n ? c+1: 0;
			
			if(isValid(r,c,n)) {
				board[r][c] = true;
				ans += solve(n,k-1,nr,nc,N+1);
				board[r][c] = false;
			}
			ans += solve(n,k,nr,nc,N+1);
			
		}
		
		//assert n >= 0 && n < 10;
		//assert k >= 0 && k < 82;
		//assert N >= 0 && N < 82;
		mem[n][k][N] = ans;
		return ans;
	}
	
			
	public static void main(String[] args) throws Throwable{
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		String[] line = stdin.readLine().split(" ");
		int n,k,i,j;
		n = Integer.parseInt(line[0]); k = Integer.parseInt(line[1]);

		for(i = 0; i < 10; i++)
			Arrays.fill(board[i], false);
		
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 82; j++)
				Arrays.fill(mem[i][j],-1);
		}
		
		while(!(n == 0 && k == 0)) {
			
			System.out.println(solve(n,k,0,0,0));
			line = stdin.readLine().split(" ");
			n = Integer.parseInt(line[0]); k = Integer.parseInt(line[1]);
			
			
		}

	}

}
