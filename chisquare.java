import java.util.Scanner;
public class chisquare{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		System.out.println("Enter number of random numbers to be generated");
		int n=in.nextInt();
		int arr[] = new int[10];
		for(int i=0;i<arr.length;i++)
    			arr[i] = 0;
		for(int i=0;i<n;i++)
		{
			double val=Math.random();
			if(val<0.1)
				arr[0]++;
			else if(val>=0.1 && val<0.2)
				arr[1]++;
			else if(val>=0.2 && val<0.3)
				arr[2]++;
			else if(val>=0.3 && val<0.4)
				arr[3]++;
			else if(val>=0.4 && val<0.5)
				arr[4]++;
			else if(val>=0.5 && val<0.6)
				arr[5]++;
			else if(val>=0.6 && val<0.7)
				arr[6]++;

			else if(val>=0.7 && val<0.8)
				arr[7]++;
			else if(val>=0.8 && val<0.9)
				arr[8]++;
			else if(val>=0.9 && val<1)
				arr[9]++;
		
		}
	       int E=(int)(n/10);
		double sum=0;
		for(int i=0;i<10;i++)
		{
			System.out.println("Observed : "+arr[i]+" Expected value: "+E);
			int r=(int)Math.pow((arr[i]-E),2);
			double o = (double)r/E;			
			sum=sum+o;
			System.out.println("Chi square for "+ (i+1) +" is "+o);
			System.out.println("**************************************");		
		}
		System.out.println("Final chi square sum "+sum);
	}
}
