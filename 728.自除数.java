import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("范围");
        Scanner in=new Scanner(System.in);
        int left=in.nextInt();
        Scanner input=new Scanner(System.in);
        int right=input.nextInt();
        int[] array=returnList(left,right);
        System.out.println("范围里的自除数有："+ Arrays.toString(array));
    }
    public static int[] returnList(int left,int right){
        int i=0,j=0;
        int[] array=new int[100];
        for(i=left;i<=right;i++){
            if(selfDividing(i)){
                array[j]=i;
                j++;
            }
        }
        return array;
    }
    public static boolean selfDividing(int num) {
        int x = num;
        while (x > 0) {
            int temp = x % 10;
            if (temp == 0 || num % temp != 0) {
                return false;
            }
            x=x/10;
        }
        return true;
    }
}
