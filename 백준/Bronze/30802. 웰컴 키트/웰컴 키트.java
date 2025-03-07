import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
public class Main {
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try{
            int studentNumber = Integer.parseInt(bf.readLine());
            int count = 0;

            String[] parsedData = bf.readLine().split(" ");

            String[] parsedData2 = bf.readLine().split(" ");
            int t = Integer.parseInt(parsedData2[0]);
            int p = Integer.parseInt(parsedData2[1]);

            int[] arr = new int[6];
            for(int i=0; i<6; i++){
                arr[i] = Integer.parseInt(parsedData[i]);
                if(arr[i] % t == 0) count += arr[i] / t ;
                else count += arr[i] / t + 1;
            }

            System.out.println(count);
            System.out.println(studentNumber / p + " " + studentNumber % p);
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}