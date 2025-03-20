import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int board[][] = new int[20][20];
    static int minDst = Integer.MAX_VALUE;
    private static int n = 0;

    public static void main(String[] args) {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        solve(bufferedReader);
    }

    private static void solve(BufferedReader br){
        try {
            n = Integer.parseInt(br.readLine());
            for(int i=0; i<n; i++){
                String[] parsedLine = br.readLine().split(" ");
                for(int j=0; j<parsedLine.length; j++){
                    board[i][j] = Integer.parseInt(parsedLine[j]);
                }
            }
        } catch (Exception e){}

        boolean visited[] = new boolean[n];
        dfs(0,visited,0);
        System.out.println(minDst);
    }

    private static void dfs(int curr, boolean[] visited,int size){
        if(size == n / 2){
            diff(visited);
            return;
        }

        for(int i=curr; i<n; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(i+1, visited, size + 1);
                visited[i] = false;
            }
        }
    }

    private static void diff(boolean[] visited){
        int leftSum = 0;
        int rightSum = 0;

        for(int i=0; i<n; i++){
            if(visited[i]){
                for(int j=0; j<n; j++){
                    if(visited[j]){
                        leftSum += board[i][j];
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                for(int j=0; j<n; j++){
                    if(!visited[j]){
                        rightSum += board[i][j];
                    }
                }
            }
        }

        int min = Math.abs(leftSum - rightSum);
        minDst = Math.min(min,minDst);
    }
}































