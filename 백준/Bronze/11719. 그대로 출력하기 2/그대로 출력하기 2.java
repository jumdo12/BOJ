import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String line;

        try{
            while((line = bf.readLine()) != null){
                System.out.println(line);
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}