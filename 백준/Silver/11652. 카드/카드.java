import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve(){
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            int tCase = Integer.parseInt(bf.readLine());
            Map<Long,Integer> map = new HashMap<>();

            for(int i=0; i<tCase; i++){
                Long num = Long.parseLong(bf.readLine());
                map.put(num,map.getOrDefault(num,0) + 1);
            }

            int maxVal = Integer.MIN_VALUE;
            Long minKey = 0L;
            for(Map.Entry<Long,Integer> entry : map.entrySet()){
                if(maxVal < entry.getValue()){
                    minKey = entry.getKey();
                    maxVal = entry.getValue();
                }
            }

            for(Map.Entry<Long,Integer> entry : map.entrySet()){
                if(maxVal == entry.getValue() && minKey > entry.getKey()){
                    minKey = entry.getKey();
                }
            }

            System.out.println(minKey);
        }catch (Exception e){

        }
    }
}