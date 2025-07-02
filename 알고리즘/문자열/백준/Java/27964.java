package Main;

import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {

	
	public static void main(String[] args)
	{
		int N = 0;
		int cnt = 0;
		String Cheese = "Cheese";
		String Yummy = "yummy";
		String Sad = "sad";
		Set<String> hset = new HashSet<>();
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		for(int i=0; i<N; i++)
		{
			String s = "";
			
			s = input.next();
			
			if(s.length() >= Cheese.length() && !hset.contains(s))
			{
				if(s.substring(s.length()-Cheese.length(), s.length()).equals(Cheese))
				{
					cnt ++;
					hset.add(s);
				}
			}
		}
		if(cnt >= 4)
			System.out.println(Yummy);
		else
			System.out.println(Sad);
	}
}
