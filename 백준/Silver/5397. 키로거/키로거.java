import javax.security.auth.callback.CallbackHandler;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve(){
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try{
            int tCase = Integer.parseInt(bf.readLine());

            for(int i=0; i<tCase; i++){
                String line = bf.readLine();
                StringBuilder left = new StringBuilder();
                StringBuilder right = new StringBuilder();

                for(Character ch : line.toCharArray()){
                    if(ch == '<'){
                        if(left.length() > 0){
                            right.append(left.charAt(left.length() - 1));
                            left.deleteCharAt(left.length()-1);
                        }
                    } else if(ch == '>'){
                        if(right.length() > 0){
                            left.append(right.charAt(right.length()-1));
                            right.deleteCharAt(right.length()-1);
                        }
                    } else if(ch == '-'){
                        if(left.length() > 0){
                            left.deleteCharAt(left.length()-1);
                        }
                    } else {
                        left.append(ch);
                    }
                }

                bw.write(left.toString());
                bw.write(right.reverse().toString());
                bw.newLine();
                bw.flush();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}