import java.io.*;
class Main
{
   public static void main(String args[]) throws Exception
   {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      int j=1;
      while(true)
      {
         String str="",s = in.readLine();
	 if(s.length()==0)break;
         int i,count=0;
         char c='1';
         for(i=s.indexOf(c,0);i!=-1;i=s.indexOf(c,i+1))
         {
            count++;
            if(c=='1')
               c = '0';
            else
               c = '1';

         }
         System.out.println("Game #"+j+": "+count);
         j++;
      }
      return 0;
   }
}
