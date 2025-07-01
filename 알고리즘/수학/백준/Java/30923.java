// 크냑과 3D프린터
// 밑면의 가로 세로가 1이고 높이가 hi인 직육면체를 빈틈없이 일렬로 세워 붙인 3D 모형의 총 겉넓이를 구하라.


// 내 답안1
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main{
    static int abs(int a)
	{
		return (a >= 0 ? a : -a);
	}
	
    
	public static void main(String args[]){
        int N = 0;
		long answer = 0;
		List<Integer> list = new ArrayList<>();
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		for(int i=0; i<N; i++)
		{
			list.add(input.nextInt());
		}
		
		answer += list.get(0) * 3 + 1 * 2;
		for(int i=1; i<list.size(); i++)
		{
			answer += list.get(i) * 2 + 1 * 2;
			answer += abs(list.get(i)-list.get(i-1));
		}
		answer += list.get(N-1);
		
		System.out.println(answer);
	}
}
