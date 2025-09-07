import java.io.*;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void solve(BufferedReader bf) throws IOException {
        int n = Integer.parseInt(bf.readLine());

        // 위쪽
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) sb.append(" ");
            for (int j = 0; j < 2 * (n - i) - 1; j++) sb.append("*");
            sb.append("\n");
        }

        // 아래쪽
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i; j++) sb.append(" ");
            for (int j = 0; j < 2 * (n - i) - 1; j++) sb.append("*");
            sb.append("\n");
        }
    }

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {

            solve(br);
            bw.write(sb.toString());
            bw.flush();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
