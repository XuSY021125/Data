import com.sun.org.apache.bcel.internal.generic.SWAP;

//747.至少是其他数字两倍的最大数
public class Main {
    public static void main(String[] args) {
        int[] array = new int[]{2, 5, 4, 1, 3,10};
        System.out.println(doubleMax(array));
    }
    public static int doubleMax(int[] array){
        int i,m1=0,m2=0,index=0;
        for (i = 0; i < array.length; i++) {
            if (array[i] > m1) {
                index=i;
                m2 = m1;
                m1 = array[i];
            }
            else if(array[i]>m2){
                m2=array[i];
            }
        }
        if(m1>=m2*2){
            return index;
        }
        else{
            return -1;
        }
    }
}
