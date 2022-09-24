import java.io.*;
import java.util.Scanner;
import java.lang.Math;

public class hw1
{

    public static double seadragon(double a,double b,double c)
    {
        if(a<=0||b<=0||c<=0) return -1;
        double s=a+b+c;
        s/=2;
        return Math.sqrt(s*(s-a)*(s-b)*(s-c));
    }

    public static void main(String argc[]) throws IOException
    {
        System.out.println("triangle area calculater");
        Scanner sc = new Scanner(System.in);
        
        FileWriter fw = new FileWriter("java_result.txt",true);
        while(true)
        {

        
        
        double a,b,c,area;
        
        System.out.println("please input first number");
        a=sc.nextDouble();
        System.out.println("please input second number");
        b=sc.nextDouble();
        System.out.println("please input third number");
        c=sc.nextDouble();
        if(a==-1&&b==-1&&c==-1)
        {
            System.out.println("end of program");
            fw.write("end of program\n");
            fw.close();
            
            break;
        }
        System.out.println("a="+a);
        fw.write("a="+a+"\n");
        
        System.out.println("b="+b);
        fw.write("b="+b+"\n");
        
        System.out.println("c="+c);
        fw.write("c="+c+"\n");
        
        area=seadragon(a,b,c);
        if(!(area>0))
        { 
            System.out.println("Invalid input.Please try again");
            fw.write("Invalid input.Please try again\n");
            
        }
        else 
        {
            System.out.println("area="+area);
            fw.write("area="+area+"\n");
            
        }


    }

    }
}