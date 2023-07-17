import java.util.Scanner;
// 二进制间距
public class Main {
    public static void main(String[] args) {
        System.out.println("请输入目标正整数：");
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        System.out.println(binaryGap(n));
    }
    public static int binaryGap(int n){
        int prior=n%2;
        int gap=1,maxgap=gap;
        String str1="";
        int flag=0;
        while (n>=1){
            int val=n%2;
            str1=str1+val;
            if (n==1){
                System.out.println(contraryString(str1));
            }
            if (val==1){
                flag++;
            }
            if(val==0&&prior==1){
                gap++;
                maxgap=Math.max(maxgap, gap);
            }
            else {
                prior=val;
                gap=1;
            }
            n=n/2;
        }
        if (flag<=1){
            return 0;
        }
        else{
            return maxgap;
        }
    }
    public static String contraryString(String str1){
        String str2="";
        for (int i = str1.length()-1; i >= 0; i--) {
            str2=str2+str1.charAt(i);
        }
        return str2;
    }
}