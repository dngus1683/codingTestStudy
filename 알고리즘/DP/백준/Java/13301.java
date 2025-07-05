// 타일 장식물
// 1x1 크기의 정사각형 1개로부터 시작해서, 직사각형의 가장 긴 변 길이만큼의 정사각형을 이어붙여 나가는 방식으로 나선 모양처럼 점점 큰 타일을 붙인 형태로 이어나간다.
// 타일의 개수 N이 주어졌을 때, N개의 타일로 구성된 직사각형의 둘레를 구하는 프로그램을 작성하시오.

import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(st.nextToken());
		List<Long> arr = new ArrayList<>();
		 
		arr.add((long)0);
		arr.add((long)1);
		for(int i=2; i<=N; i++)
		{
			arr.add(arr.get(i-1) + arr.get(i-2));
		}
		
		sb.append((arr.get(N) + arr.get(N-1))*2 + arr.get(N) * 2 );
		
		bw.write(sb.toString());
		bw.flush();
		bw.close();
		br.close();
	
	}
}