import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n;
        String line;
        try {
            n = Integer.parseInt(bf.readLine());
            for(int i=0; i<n; i++){
                line = bf.readLine();
                String[] parsedLine = line.split(",");
                System.out.println(Integer.parseInt(parsedLine[0]) + Integer.parseInt(parsedLine[1]));
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}