import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            String str = bf.readLine();
            while(str.length() > 10){
                System.out.println(str.substring(0,10));
                str = str.substring(10);
            }
            System.out.println(str);
        } catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}