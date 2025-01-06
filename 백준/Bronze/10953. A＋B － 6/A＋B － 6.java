import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
           int n = Integer.parseInt(bf.readLine());
           for(int i=0; i<n; i++){
               String line = bf.readLine();
               String[] parsedLine = line.split(",");
               int a = Integer.parseInt(parsedLine[0]);
               int b = Integer.parseInt(parsedLine[1]);
               System.out.println(a+b);
           }
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}