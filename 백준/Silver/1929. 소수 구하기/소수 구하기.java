import java.util.Scanner;

public class Main {

	public static int prime[];
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		int m=sc.nextInt();		
		int n=sc.nextInt();		
		
		prime=new int[n+1];
		get_prime();
		
		for(int i=m; i<=n; i++)
		{
			if(prime[i]!=1)
			{
				System.out.println(i);
			}
		}
		
	}
	
	public static void get_prime() {
		
		prime[0]=1;
		prime[1]=1;
		
		for(int i=2; i<Math.sqrt(prime.length); i++)
		{
			for(int j=2*i; j<prime.length; j=j+i)
			{
				prime[j]=1;
			}
		}
		
	}
		
	
}
