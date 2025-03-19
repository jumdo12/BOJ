import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static final int ROW_SIZE = 9;
    private static final int COL_SIZE = 9;
    private static final int board[][] = new int[ROW_SIZE][COL_SIZE];
    private static final int ans [][] = new int[ROW_SIZE][COL_SIZE];

    public static void main(String[] args) {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        solve(bufferedReader);
    }

    private static void solve(BufferedReader br){
        try{
            for(int i=0; i<ROW_SIZE; i++){
                String line = br.readLine();
                String[] parseLine = line.split(" ");
                for(int j=0; j<COL_SIZE; j++){
                    board[i][j] = Integer.parseInt(parseLine[j]);
                }
            }
        } catch (Exception e){}

        backtracking(0);

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<ROW_SIZE; i++){
            for(int j=0; j<COL_SIZE; j++){
                sb.append(ans[i][j] + " ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }

    private static void backtracking(int curr){
        if(curr == 81){
            for(int i=0; i<ROW_SIZE; i++){
                for(int j=0; j<COL_SIZE; j++){
                    ans[i][j] = board[i][j];
                }
            }
            return;
        }

        int row = curr / ROW_SIZE;
        int col = curr % ROW_SIZE;

        if(board[row][col] != 0){
            backtracking(curr+1);
            return;
        }

        for(int i=1; i<=9; i++){
            if(isHorizontal(row,col,i) && isVertical(row,col,i) && isSquare(row,col,i)){
                board[row][col] = i;
                backtracking(curr+1);
                board[row][col] = 0;
            }
        }
    }

    private static boolean isHorizontal(int row, int col, int num){
        for(int i=0; i<ROW_SIZE; i++){
            if(num == board[i][col]){
                return false;
            }
        }
        return true;
    }

    private static boolean isVertical(int row, int col, int num){
        for(int i=0; i<COL_SIZE; i++){
            if(num == board[row][i]){
                return false;
            }
        }
        return true;
    }

    private static boolean isSquare(int row, int col, int num){
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[startRow + i][startCol + j] == num) return false;
            }
        }
        return true;
    }
}































