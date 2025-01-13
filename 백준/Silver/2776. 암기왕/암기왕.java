import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    public static void solve(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try {
            int tCase = Integer.parseInt(br.readLine());
            Set<Integer> set = new HashSet<>();

            for(int i=0; i<tCase; i++){
                int cnt1 = Integer.parseInt(br.readLine());
                String line = br.readLine();
                String[] parsedLine = line.split(" ");

                for(String token : parsedLine){
                    set.add(Integer.parseInt(token));
                }

                int cnt2 = Integer.parseInt(br.readLine());
                line = br.readLine();
                parsedLine = line.split(" ");

                StringBuilder sb = new StringBuilder();
                for(String token : parsedLine){
                    if(set.contains(Integer.parseInt(token))){
                        sb.append("1\n");
                    } else {
                        sb.append("0\n");
                    }
                }

                bw.write(sb.toString());
                bw.flush();

                set.clear();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}