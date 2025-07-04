// 카드1
// 1~N의 숫자 카드를 작은 숫자가 위로 오도록 쌓아놓는다. 이후, 맨 위 카드를 버리고 그 다음 위 카드를 덱 맨 아래에 놔두는 것을 반복한다.
// 버리는 카드를 순서대로 출력하고 마지막에 남게 되는 카드를 출력하라.


// 내 답안1
import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(st.nextToken());
		Queue<Integer> queue = new LinkedList<>();
		
		for(int i=1; i<=N; i++)
		{
			queue.add(i);
		}
		
		while(true)
		{
			int answer = queue.poll();
			
			sb.append(answer);
			sb.append(' ');
			
			if(queue.isEmpty())
				break;
			
			queue.add(queue.poll());
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	}
}