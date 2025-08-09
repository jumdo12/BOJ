import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.stream.Collectors;

//TIP 코드를 <b>실행</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나
// 에디터 여백에 있는 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
public class Main {

    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try{
            StringBuilder sb = solve(bf);

            bw.write(sb.toString());
            bw.flush();
        }catch (Exception e){
            System.out.println(0);
        }
    }

    public static StringBuilder solve(BufferedReader bf) throws IOException {
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(bf.readLine());

        List<Point> points = new ArrayList<>();
        Stack<Point> stack = new Stack<>();

        for(int i=0; i< n; i++) {
            String line = bf.readLine();
            String[] s = line.split(" ");

            int center = Integer.parseInt(s[0]);
            int radius = Integer.parseInt(s[1]);

            Point left = new Point(center - radius, i , Side.LEFT);
            Point right = new Point(center + radius, i , Side.RIGHT);

            points.add(left);
            points.add(right);
        }

        List<Point> sorted = points.stream()
                .sorted()
                .collect(Collectors.toList());
                
        for(int i=0; i<sorted.size(); i++){
            Point point = sorted.get(i);

            if(stack.isEmpty()){

                if(point.side == Side.RIGHT){
                    sb.append("NO");
                    return sb;
                }

                stack.push(point);
            }
            else {
                if(point.side == Side.LEFT) {
                    stack.push(point);
                }
                if(point.side == Side.RIGHT) {
                    if(stack.peek().side == Side.LEFT){
                        if(stack.peek().originIdx != point.originIdx){
                            sb.append("NO");
                            return sb;
                        }
                        stack.pop();
                    }
                }
            }
        }

        if(!stack.isEmpty()){
            sb.append("NO");
        }
        else{
            sb.append("YES");
        }

        return sb;
    }

    public static class Point implements Comparable<Point> {
        public int x;
        public int originIdx;
        public Side side;

        public Point(int x, int originIdx, Side side) {
            this.x = x;
            this.originIdx = originIdx;
            this.side = side;
        }

        public int getX() {
            return x;
        }

        public Side getSide() {
            return side;
        }

        @Override
        public int compareTo(Point o) {
            if(this.x != o.x) {
                return Integer.compare(this.x, o.x);
            }
            if(this.side == Side.LEFT && o.side == Side.RIGHT) {
                return -1;
            }
            if (this.side == Side.RIGHT && o.side == Side.LEFT) {
                return 1;
            }
            return 0;
        }
    }

    public enum Side {
        LEFT,
        RIGHT
    }
}