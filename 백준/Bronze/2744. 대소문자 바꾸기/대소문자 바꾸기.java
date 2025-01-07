import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try{
            String line = bf.readLine();
            StringBuilder ans = new StringBuilder();

            for(int i=0; i<line.length(); i++){
                char ch = line.charAt(i);
                if(Character.isUpperCase(ch)){
                    ans.append(Character.toLowerCase(ch));
                } else if(Character.isLowerCase(ch)){
                    ans.append(Character.toUpperCase(ch));
                } else {
                    ans.append(ch);
                }
            }
            System.out.println(ans);
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}