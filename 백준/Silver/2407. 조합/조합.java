import java.io.BufferedReader;
import java.io.IOError;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.net.Socket;
import java.net.URL;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	public static BigInteger[][] arr = new BigInteger[1001][1001];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int i, j;
//		for (i = 0; i <= n; i++) {
//			arr[i][0] = new BigInteger("1");
//			arr[i][i] = new BigInteger("1");
//		}
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= i; j++) {
				if(j == 0 || i == j) {
					arr[i][j] = new BigInteger("1");
				}
				else {
					arr[i][j] = arr[i - 1][j - 1].add(arr[i - 1][j]);
				}
				
			}
		}
		
		System.out.println(arr[n][m]);
	}
}