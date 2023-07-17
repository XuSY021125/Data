import jdk.nashorn.internal.runtime.regexp.joni.ast.StringNode;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        String stones="abnfABJ";
        String jewels="agmAB";
        System.out.println("拥有的石头中有"+jewelsNum(stones,jewels)+"个宝石");
    }
    public static int jewelsNum(String stones,String jewels){
        int nums=0;
        int i,j;
        for (i=0;i<stones.length();i++){
            for (j=0;j<jewels.length();j++){
                if(stones.charAt(i)==jewels.charAt(j)){
                    nums++;
                    break;
                }
            }
        }
        return nums;
    }
}