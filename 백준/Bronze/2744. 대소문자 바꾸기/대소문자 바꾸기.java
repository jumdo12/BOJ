import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static boolean isUpperCase(String str){
        String upperCase = str.toUpperCase();
        return str.equals(upperCase);
    }

    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = bf.readLine();
            String str = "";

            for(int i=0; i<line.length(); i++){
                char ch = line.charAt(i);
                String temp = Character.toString(ch);
                if(isUpperCase(temp)){
                    temp = temp.toLowerCase();
                } else temp = temp.toUpperCase();
                str += temp;
            }

            System.out.println(str);
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}