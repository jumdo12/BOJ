import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // 학년(1~6), 성별(0=여,1=남)
        int[][] count = new int[7][2];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken()); // 성별
            int Y = Integer.parseInt(st.nextToken()); // 학년
            count[Y][S]++;
        }

        int rooms = 0;
        for (int grade = 1; grade <= 6; grade++) {
            for (int gender = 0; gender <= 1; gender++) {
                if (count[grade][gender] > 0) {
                    rooms += (count[grade][gender] + K - 1) / K; // 올림 나눗셈
                }
            }
        }

        System.out.println(rooms);
    }
}
