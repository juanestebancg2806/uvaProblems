import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int numbers[] = new int[50];
	static Map<Vector<Long>,Long> mem = new HashMap <Vector<Long>,Long>();
	static long tg;
	
	public static long solve(int N,long acum,String ss) {
		long ans;
		Vector<Long> v = new Vector<Long>();
		v.add((long)N);v.add(acum);
		
		if(mem.get(v) != null) 
			ans = mem.get(v);
		 if((N == 1 && acum+numbers[N-1] == tg)|| (N == 1 && acum == tg)) 
			ans = 1;
		else if(N == 1)
			ans = 0;
		else 
			ans = solve(N-1,acum+numbers[N-1],ss+numbers[N-1]+ " ")+solve(N-1,acum,ss);
		mem.put(v ,ans);
		return ans;
	}
	
	public static void main(String[] args)throws Throwable {
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		int N,i;
		long ans;
		String line = inp.readLine();
		String [] _nums;
		while(line != null) {
			_nums = line.split(" ");
			N = Integer.parseInt(_nums[0]); tg = Integer.parseInt(_nums[1]);
			line = inp.readLine();
			_nums = line.split(" ");
			for(i = 0; i < N;i++)
				numbers[i] = Integer.parseInt(_nums[i]);
			//for(i = 0; i< N;i++)
			//	System.out.print(numbers[i]+ " ");
			ans = solve(N,0,"");
			if(tg == 0)
				System.out.println(ans-1);
			else
				System.out.println(ans);
			//System.out.println(mem);
			
			line = inp.readLine();
		}
	}

}
