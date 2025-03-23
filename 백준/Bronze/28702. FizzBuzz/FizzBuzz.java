import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solve(br);
    }

    private static void solve(BufferedReader br){
        List<String> list = new ArrayList<>();
        try{
            for(int i=0; i<3; i++){
                list.add(br.readLine());
            }
        }catch (Exception e){
            e.printStackTrace();
        }

        int numIdx = 0;
        for(int i=0; i < 3; i++){
            try {
                numIdx = Integer.parseInt(list.get(2-i)) + i;
            } catch (NumberFormatException e){
                continue;
            }
        }

        int next = numIdx + 1;
        if(next% 15 == 0){
            System.out.println("FizzBuzz");
        } else if( next % 3 == 0){
            System.out.println("Fizz");
        } else if(next % 5 == 0){
            System.out.println("Buzz");
        } else{
            System.out.println(next);
        }
    }
}

