import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = bf.readLine();
            double score;

            if(line.contains("A")) score = 4.0;
            else if(line.contains("B")) score = 3.0;
            else if(line.contains("C")) score = 2.0;
            else if(line.contains("D")) score = 1.0;
            else score = 0.0;
            
            if(line.contains("+")) score += 0.3;
            else if(line.contains("-")) score -= 0.3;

            System.out.println(score);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}