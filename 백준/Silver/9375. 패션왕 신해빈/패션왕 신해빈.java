import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        solve();
    }
    private static void solve(){
        Map<String, Integer> clothes = new HashMap<>();

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            int t = Integer.parseInt(bf.readLine());
            for(int i=0; i<t; i++){
                int cnt = Integer.parseInt(bf.readLine());
                for(int j=0; j<cnt; j++){
                    String line = bf.readLine();
                    String type = line.split(" ")[1];

                    int curr = clothes.getOrDefault(type,0);
                    clothes.put(type,curr+1);
                }

                int ans = 1;
                for(String key : clothes.keySet()){
                    ans *= (clothes.get(key) + 1);
                }
                System.out.println(ans - 1);
                clothes.clear();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}