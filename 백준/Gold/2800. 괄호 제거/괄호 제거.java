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

    public static Set<String> set = new TreeSet<>();

    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try{
            StringBuilder sb = solve(bf);

            bw.write(sb.toString());
            bw.flush();
        }catch (Exception e){
            System.out.println("ERORR");
        }
    }

    public static StringBuilder solve(BufferedReader bf) throws IOException {
        StringBuilder sb = new StringBuilder();

        String line = bf.readLine();
        String[] parsed = line.split("");

        Stack<BlankItem> blankItems = new Stack<>();
        List<Blank> list = new ArrayList<>();

        for(int i=0; i<parsed.length; i++){
            String item = parsed[i];
            if(item.equals("(")) {
                blankItems.push(new BlankItem(i, "("));
            }
            if(item.equals(")")) {
                BlankItem peek = blankItems.peek();

                Blank blank = new Blank(peek.idx, i);
                list.add(blank);

                blankItems.pop();
            }
        }

        boolean[] booleans = new boolean[list.size()];
        addSetRecur(0,parsed,list, booleans);

        set.remove(line);
        set.forEach(item -> sb.append(item).append("\n"));

        return sb;
    }

    public static void addSetRecur(int curr, String[] parsed, List<Blank> list ,boolean[] removedBlank){
        if(curr == list.size()) {
            StringBuilder sb = new StringBuilder();

            boolean[] toRemove = new boolean[parsed.length];

            for(int i=0; i<list.size(); i++) {
                if(removedBlank[i]) {
                    Blank blank = list.get(i);
                    toRemove[blank.leftIdx] = true;
                    toRemove[blank.rightIdx] = true;
                }
            }

            for(int i=0; i<parsed.length; i++) {
                if(!toRemove[i]) {
                    sb.append(parsed[i]);
                }
            }

            set.add(sb.toString());
            return;
        }

        removedBlank[curr] = true;
        addSetRecur(curr+1, parsed, list, removedBlank);

        removedBlank[curr] = false;
        addSetRecur(curr+1, parsed, list, removedBlank);
    }

    public static class BlankItem {
        public int idx;
        public String blank;

        public BlankItem(int idx, String blank) {
            this.idx = idx;
            this.blank = blank;
        }
    }

    public static class Blank {
        private int leftIdx;
        private int rightIdx;

        public Blank(int leftIdx, int rightIdx) {
            this.leftIdx = leftIdx;
            this.rightIdx = rightIdx;
        }

        public int getLeftIdx() {
            return leftIdx;
        }

        public int getRightIdx() {
            return rightIdx;
        }
    }
}