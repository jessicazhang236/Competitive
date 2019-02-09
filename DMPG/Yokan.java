import java.io.*;
import java.util.*;

public class Yokan {
	 static ArrayList<Integer> countList[];
	 public static int indexOf(int a, int k, boolean upperbound)
     {
            int l = 0;
            int u = countList[a].size() - 1;
            while (l <= u)
            {
                int m = l + (u - l) / 2;
                if (k < countList[a].get(m))
                    u = m - 1;
                else if (k > countList[a].get(m))
                    l = m + 1;
                else
                    if(upperbound)
                        return m + 1;
                    else
                        return m;
            }
            return l;
        }
       
	 public static void main(String[] args) throws IOException
	    {
	        // TODO Auto-generated method stub
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
     String[] line = in.readLine().split(" ");
     int N=Integer.parseInt(line[0]);
     int M=Integer.parseInt(line[1]);
	        int total[] = new int[N];
	        countList=new ArrayList[M];
	        for (int m=0; m<M; m++)
	        {
	            countList[m] = new ArrayList<Integer>(200);
	        }
	        String[] line2 = in.readLine().split(" ");
	        for (int n=0; n<N; n++)
	        {
	        	total[n] = Integer.parseInt(line2[n]);
	            countList[total[n]-1].add(n+1);
	        }
	        int Q=Integer.parseInt(in.readLine());
	        for (int q=1; q<=Q; q++)
	        {
	        	String[] line3 = in.readLine().split(" ");
	            int l=Integer.parseInt(line3[0]);
	            int r=Integer.parseInt(line3[1]);
	            if (r-l<=2)
	                System.out.println ("YES");
	            else
	            {
	            double L=(r-l+1)/3.0;
	            boolean check=false;
	            int x=-1;
	            someloop:
	            for (int c=0; c<11; c++)
	            {
	                int test=(int)(l+(r-l+1)*Math.random());
	                int flavour=total[test-1];
	                int res = indexOf(flavour-1, r, true)-indexOf(flavour-1, l, false);
	            if (res>=2*L)
	                {System.out.println ("YES");
	                check=true;
	            break someloop;
	                }
	            else if (res>=L&&x==-1)
	                x=flavour;
	            else if (res>=L&&x!=-1)
	            {
			for (int C=0; C<7; C++)
			{
				int test2=(int)(l+(r-l+1)*Math.random());
				int flavour2=total[test2-1];
				if (flavour2!=flavour&&test2!=test&&indexOf(flavour2-1, r, true)-indexOf(flavour2-1, l, false)>=L)
					{
					System.out.println("YES");
					check=true;
				break someloop;
					}
		}
		}
		}
		if (check==false)
			System.out.println ("NO");
	}
	}
	}
}
