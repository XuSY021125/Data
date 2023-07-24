import java.util.Arrays;

//按奇偶排序数组
public class Main {
    public static void main(String[] args) {
        int[] array=new int[]{1,3,4,6,8,7,9};
        System.out.println(Arrays.toString(sortArray(array)));
    }
    public static int[] sortArray(int[] nums){
        int left=0,right=nums.length-1;
        int index1,index2;
        while(left<right){
            while (left<right&&nums[left]%2==0){
                left++;
            }
            while (left<right&&nums[right]%2==1){
                right--;
            }
            if(left<right){
                swap(nums,left,right);
            }
            left++;
            right--;
        }
        return nums;
    }
    public static void swap(int[] nums,int a,int b){
        int temp;
        temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
}