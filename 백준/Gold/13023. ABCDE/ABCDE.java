import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solver(br);
    }

    private static int t = 0;
    private static boolean visited[];
    private static int ans = 0;
    private static List<Integer>[] g;

    public static void solver(BufferedReader br){
        try {
            String input = br.readLine();
            String[] parsedInput = input.split(" ");

            t = Integer.parseInt(parsedInput[0]);
            int n = Integer.parseInt(parsedInput[1]);
            visited = new boolean[t];
            g = new ArrayList[t];
            for(int i=0; i<t; i++){
                g[i] = new ArrayList<>();
            }


            for(int i=0; i<n; i++){
                input = br.readLine();
                parsedInput = input.split(" ");
                int start = Integer.parseInt(parsedInput[0]);
                int end = Integer.parseInt(parsedInput[1]);

                g[start].add(end);
                g[end].add(start);
            }

            for(int i=0; i<t; i++){
                dfs(i, 0);
            }
            System.out.println(ans);
        }catch (IOException e){
            System.out.println(e.getMessage());
        }
    }

    public static void dfs(int curr, int cnt){
        if(cnt == 4){
            ans = 1;
            return;
        }

        visited[curr] = true;
        for(int vertex : g[curr]){
            if(!visited[vertex]){
                dfs(vertex,cnt+1);
                if(ans == 1) return;
            }
        }
        visited[curr] = false;
    }
}

