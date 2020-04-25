import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String[] args)throws Throwable {
		BufferedReader inp = new BufferedReader(new InputStreamReader(System.in));
		Solve s = new Solve();
		String line = inp.readLine();
		Vector<Integer> v = new Vector<>();
		while(line != null) {
			String [] numbers = line.split(" ");
			for(String n: numbers)
				v.add(Integer.parseInt(n));
			v.remove(0);
			if(s.solve(v))
				System.out.println("Jolly");
			else
				System.out.println("Not jolly");
			v.clear();
			line = inp.readLine();
			
		}
	}

}

class Solve{
	public boolean solve(Vector<Integer> v) {
		boolean ans = true;
		int i;
		Vector<Integer> nums = new Vector<>();
		for(i = 1; i < v.size();i++)
			nums.add(Math.abs(v.get(i)-v.get(i-1)));
		Collections.sort(nums);
		for(i = 0; i < nums.size() && ans;i++)
			ans = nums.get(i) ==i+1;
		return ans;
	}
}
