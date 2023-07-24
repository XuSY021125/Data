//单调数列
public class Main {
    public static void main(String[] args) {
        int[] array=new int[]{1,1,0};
        System.out.println(isMonotonic(array));
    }
    public static boolean isMonotonic(int[] nums){
        int i;
        int inc=0,dec=0;
        for (i=1;i<nums.length;i++){
            if(nums[i]>=nums[i-1]){
                inc++;
            }
            if (nums[i]<=nums[i-1]){
                dec++;
            }
        }
        if (inc==nums.length-1||dec==nums.length-1){
            return true;
        }
        return false;
    }
}
