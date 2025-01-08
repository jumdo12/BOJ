import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve(){
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Map<String, String> passwords = new HashMap<>();

        try {
            String line = bf.readLine();
            int tCount = Integer.parseInt(line.split(" ")[0]);
            int caseCount = Integer.parseInt(line.split(" ")[1]);

            for(int i=0; i<tCount; i++){
                line = bf.readLine();
                String name = line.split(" ")[0];
                String password = line.split(" ")[1];

                passwords.put(name,password);
            }

            StringBuilder ans = new StringBuilder();
            for(int i=0; i<caseCount; i++){
                line = bf.readLine();
                ans.append(passwords.get(line)).append("\n");
            }
            System.out.println(ans);
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}