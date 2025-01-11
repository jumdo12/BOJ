import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        solve();
    }

    private static void solve() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        try {
            while ((line = br.readLine()) != null) { // EOF 처리
                String[] parsedLine = line.split(" ");
                int nCnt = Integer.parseInt(parsedLine[0]);
                int mCnt = Integer.parseInt(parsedLine[1]);

                if (nCnt == 0 && mCnt == 0) { // 종료 조건
                    break;
                }

                Set<Integer> nSet = new HashSet<>();
                for (int i = 0; i < nCnt; i++) {
                    nSet.add(Integer.parseInt(br.readLine()));
                }

                int cnt = 0;
                for (int i = 0; i < mCnt; i++) {
                    if (nSet.contains(Integer.parseInt(br.readLine()))) {
                        cnt++;
                    }
                }

                System.out.println(cnt);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
