import java.util.Scanner;
public class RN_KSmirnov{

  public static void main(String args[]){
  
  int n=5;
  double R[]={0.05, 0.14, 0.44, 0.81, 0.93};//or generate random numbers and sort in ascending order
  double iBYn[]=new double[5];
  double v1[]=new double[5];
  double v2[]=new double[5];
  for(int i=0;i<n; i++){
    iBYn[i]=(i+1)/5.0;
    v1[i]=iBYn[i]-R[i];
    v2[i]=R[i]-((i)/5.0);
  }
  System.out.print("i	|	1	2	3	4	5\n");
  System.out.print("R(i)	|\t");
  for(int i=0;i<n;i++){
	System.out.print(R[i]+"\t");	
  }
  System.out.print("\ni/n	|\t");
  for(int i=0;i<n;i++){
	System.out.print(iBYn[i]+"\t");	
  }
  System.out.print("\ni/N-R(i)|\t");
  for(int i=0;i<n;i++){
	System.out.print(v1[i]+"\t");	
  }
  System.out.print("\nR(i)-(i-1)/N|\t"); 
  for(int i=0;i<n;i++){
	System.out.print(v2[i]+"\t");	
  }
  double Dplus=max(v1);
  double Dminus=max(v2);
  double D,Dalpha;
  if(Dplus>Dminus)
	D=Dplus;
  else
	D=Dminus;

System.out.print("\nD="+D);
 
	Dalpha=0.565;
System.out.print("\nD alpha="+Dalpha);
  if(Dalpha>D)
	System.out.println("\nH0 is not rejected");
}

public static double max(double v1[])
{
	double max=v1[0];
	for(int i=1;i<5;i++)
		if(v1[i]>max)
			max=v1[i];
	return max;

} 
public static double min(double v2[])
{
	double min=v2[0];
	for(int i=1;i<5;i++)
		if(v2[i]<min)
			min=v2[i];

	return min;
} 
}
