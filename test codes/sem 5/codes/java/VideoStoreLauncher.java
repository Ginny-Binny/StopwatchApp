package java;

import java.util.Scanner;
import java.util.*;

public class VideoStoreLauncher
{
    public static void main(String[] args)
    {
        String ma[] = new String [4];
        ma[0]="The Matrix";
        ma[1]="Godfather II";
        ma[2]="Star war Episode IV";
        ma[3]="A new Hope";
        Video ob=new Video();
        for(int i=0;i<4;i++)
        {
            System.out.println("Enter the rating of movie"+ma[i]);
            ob.rating();
        }
        for(int i=0;i<4;i++)
        {
            System.out.println("Enter the weather returned or not::"+ma[i]);
            ob.checked();
        }
        VideoStore t=new VideoStore();


    }
}
class VideoStore
{
    Video w=new Video();
    String T=new String();
    String Y=new String();
    VideoStore Q=new VideoStore();
    String U=new String();
    int u;
    void addVideo(String T)
    {
        T=w.tittle();

    }
    void CheckOut(String Y)
    {
        Y=w.checked();
    }
    void Rating(int u)
    {
        for(int i=0;i<4;i++)
        {
            u=w.rating();
        }
    }

}
class Video
{
    Scanner y=new Scanner(System.in);
    String  tittle()
    {
        System.out.println("Enter the tittle::");
        String a=y.next();
        return a;
    }
    String checked()
    {
        System.out.println("Enter the flag is checked or not::");
        String w=y.next();
        return w;
    }
    int rating()
    {
        System.out.println("Enter the rating of the movie::");
        int s=y.nextInt();
        return s;
    }



}