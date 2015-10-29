import java.util.Scanner;
public class p7{
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
			double val=(Math.random()*10);
			if(val<1)
				arr[0]++;
			else if(val>=1 && val<2)
				arr[1]++;
			else if(val>2 && val<3)
				arr[2]++;
			else if(val>=3 && val<4)
				arr[3]++;
			else if(val>=4 && val<5)
				arr[4]++;
			else if(val>=5 && val<6)
				arr[5]++;
			else if(val>=6 && val<7)
				arr[6]++;
			else if(val>=7 && val<8)
				arr[7]++;
			else if(val>=8 && val<9)
				arr[8]++;
			else if(val>=9 && val<=10)
				arr[9]++;		
		}
		Draw(arr);
	       int E=(int)(n/9);
		double sum=0;
		for(int i=0;i<10;i++)
		{
			System.out.println("Observed : "+arr[i]+" Expected value: "+E);
			int r=(int)Math.pow((arr[i]-E),2);
			double o = (double)r/E;			
			sum=sum+o;
			System.out.println("Chi square for "+ (i+1) +" is "+o);
			System.out.println("------------------------------");		
		}
		System.out.println("Final chi square sum "+sum);
		double alpha=0.05;
		double H0=16.910;
		if(sum>H0)
			System.out.println("Rejected as sum "+sum+" is greater than H0 "+H0+" ");
		else
			System.out.println("\nAccepted.Sum "+sum+" is less than H0 "+H0+" ");
	}
		public static void Draw(int arr[])
		{
			int max=0;
			int arr1[]=new int[arr.length];
			for(int i=0;i<arr.length;i++)
			{
				arr1[i]=arr[i];
				if(arr[i]>max)
					{max=arr[i];}
			}
			System.out.println("Graph with frequency on y axis from 0 to "+max+" and classes on x axis");
			System.out.println("---------------------------------------------------------------------");
			for(int i=max;i>0;i--)
			{
				//System.out.print(max);
				for(int j=0;j<arr1.length;j++)
				{	
					if(arr1[j]==max)
					 {
						arr1[j]--;
						System.out.print(" I  ");
					}
					else{
						System.out.print("    ");
					}
				}
				System.out.println("");
				max--;
			}
			System.out.println("0-1 1-2 2-3 3-4 4-5 5-6 6-7 7-8 8-9 9-10");
		}
		
}

