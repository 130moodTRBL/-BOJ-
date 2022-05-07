import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	static boolean prime[] = new boolean[4000001];
	static ArrayList<Integer> primeList=new ArrayList<>();
	public static void primeN() {
		
		int n=4000000;
		boolean flag;
		
		prime[0]=true;
		prime[1]=true;
		prime[2]=false;
		
		for(int i=2; i*i<=n; i++) {
			if(!prime[i]) {
				for(int j=i*i; j<=n; j+=i) {
					prime[j]=true;
				}
			}
		}
		
		for(int i=2; i<=n; i++) {
			if(!prime[i]) {
				primeList.add(i);
			}
		}
		
	}
	
	public static void main(String[] args) {

		primeN();
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int start=0;
		int end=0;
		int cnt=0;
		int sum=0;
		
		for(int i=0; i<primeList.size(); i++) {
			while(sum < N && end < primeList.size()) {
				sum+=primeList.get(end);
				end++;
			}
			if(sum==N) {
				cnt++;
			}
			sum-=primeList.get(start);
			start++;
		}
		
		System.out.println(cnt);
	}

}
