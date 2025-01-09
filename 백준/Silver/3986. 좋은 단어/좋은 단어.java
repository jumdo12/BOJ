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
            int N = Integer.parseInt(bf.readLine());
            int cnt = 0;

            for(int i=0; i<N; i++){
                String line = bf.readLine();
                Stack<Character> stack = new Stack<>();

                for(int j = 0; j < line.length(); j++){
                    char ch = line.charAt(j);
                    if(stack.isEmpty() || stack.peek() != ch){
                        stack.push(ch);
                    } else {
                        stack.pop();
                    }
                }

                if(stack.isEmpty()) cnt++;
            }

            System.out.println(cnt);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}