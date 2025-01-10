import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve(){
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Map<String,Integer> map = new HashMap<>();

        try {
            int tCase = Integer.parseInt(bf.readLine());
            for(int i=0; i<tCase; i++){
                String line = bf.readLine();
                map.put(line,map.getOrDefault(line,0) + 1);
            }

            int maxVal = Integer.MIN_VALUE;
            String minName = null;

            for(Map.Entry<String,Integer> entry : map.entrySet()){
                String name = entry.getKey();
                int val = entry.getValue();

                if(val > maxVal || val == maxVal && name.compareTo(minName) < 0){
                    minName = name;
                    maxVal = val;
                }
            }
            System.out.println(minName);
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}