import java.util.*;

class Words_Splitter
{
  public static void main(String args[])
   {
      System.out.println("\nEnter the Paragraph to Split:\n");

       //Variable Declaration and Initialization
       Scanner getstring = new Scanner(System.in);
       String input = getstring.nextLine();
       int msglength=140;
       String[] words=input.split(" ");
       String[] smallmsg=new String[input.length()/msglength+1];
       int smallmsgcount=0;
       smallmsg[0]="";
       int posiblemsg=input.length()/msglength+1;
       String[] handles = new String[20];
       int handlecount=0;
       String[] emailids = new String[20];
       int emailidcount=0;
       int i;

       //Email Pattern
       String emailPattern = "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$";

       //Operation in Words
       for(i=0;i<words.length;++i)
        {

           //For Smaller Messages
           if((smallmsg[smallmsgcount].length()+words[i].length()+1)>msglength)
            {
               smallmsg[++smallmsgcount]="";
            }  
           smallmsg[smallmsgcount]=smallmsg[smallmsgcount]+words[i]+" ";

           //For Handles
           if (words[i].indexOf("@") == 0 )
               handles[handlecount++] = words[i];

           //For Emailids
           if (words[i].matches(emailPattern))
               emailids[emailidcount++] = words[i];
        }

       //Printing the List of Smaller Messages
       System.out.println("\n\nList of messages:");
       for(i=0;i<smallmsg.length;++i)
        {
           System.out.print("\n"+smallmsg[i]);
           System.out.println(i+1 +"/" + posiblemsg);
        }

       //Printing the List of Emailids
       System.out.println("\n\nList of Email id:\n");
       for(i=0;i<emailidcount;++i)
        {
           System.out.println(emailids[i]);
        }

       //Printing the List of Handles
       System.out.println("\n\nList of handles:\n");
       for(i=0;i<handlecount;++i)
        {
           System.out.println(handles[i]);
        }
    }
}