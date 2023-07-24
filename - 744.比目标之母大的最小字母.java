import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        char[] letter=new char[]{'b','d','g','k','x'};
        System.out.println("请输入目标字符：");
        Scanner scan=new Scanner(System.in);
        char target=scan.next().charAt(0);
        char a=find(letter,target);
        System.out.println(a);
    }
    public static char find(char[] letters,char target){
        if(letters[letters.length-1]<=target){
            return letters[0];
        }
        int low=0,high=letters.length-1;
        int mid;
        while (low<high){
            mid=(high-low)/2+low;
            if(target<letters[mid]){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return letters[low];
    }
}
