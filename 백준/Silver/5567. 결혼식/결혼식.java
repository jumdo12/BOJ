import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.StringTokenizer;

public class Main {
    static Map<Integer, List<Integer>> graph = new HashMap<>();
    static int ans = 0;
    static int N = 0;
    static int M = 0;


    public static void main(String[] args) throws IOException {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String n = br.readLine();
        N = Integer.parseInt(n);

        String m = br.readLine();
        M = Integer.parseInt(m);

        for(int i=0; i<M; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);

            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());

            List<Integer> friends = graph.getOrDefault(left, new ArrayList<>());
            friends.add(right);
            graph.put(left, friends);

            List<Integer> friendFriends = graph.getOrDefault(right, new ArrayList<>());
            friendFriends.add(left);
            graph.put(right, friendFriends);
        }

        List<Integer> sanggeunFriends = graph.getOrDefault(1, new ArrayList<>());

        boolean[] visited = new boolean[N+1];
        for(Integer friend : sanggeunFriends) {
            visited[friend] = true;

            List<Integer> friendFriends = graph.getOrDefault(friend, new ArrayList<>());
            for(Integer friendFriend : friendFriends) {
                visited[friendFriend] = true;
            }
        }

        for(int i=2; i<=N; i++) {
            if(visited[i]) {
               ans++;
            }
        }

        System.out.println(ans);
    }
}
