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

    public static class MyDeque {
        public Deque<Integer> deque = new ArrayDeque<>();
        public boolean reverse = false;

        public MyDeque(String line) {
            String parseLineBlank = parseLineBlank(line);
            insertParsedBlank(parseLineBlank);
        }

        public void convertPrint(){
            reverse = !reverse;
        }

        public String getPrint() {
            Deque<Integer> temp = new ArrayDeque<>(deque);
            StringBuilder sb = new StringBuilder();

            if(deque.isEmpty()){
                sb.append("[]");
                return sb.toString();
            }

            if(!reverse){
                sb.append("[");

                while (temp.size() != 1) {
                    sb.append(temp.removeFirst());
                    sb.append(",");
                }

                if(temp.size() == 1) {
                    sb.append(temp.removeFirst());
                }

                sb.append("]");
            } else {
                sb.append("[");

                while (temp.size() != 1) {
                    sb.append(temp.removeLast());
                    sb.append(",");
                }

                if(temp.size() == 1) {
                    sb.append(temp.removeFirst());
                }

                sb.append("]");
            }

            return sb.toString();
        }

        public void deleteItem(){
            if(!reverse) {
                deque.removeFirst();
            }
            else {
                deque.removeLast();
            }
        }

        private String parseLineBlank (String line) {
            String replace = line.replace("[", "");

            return replace.replace("]", "");
        }

        private void insertParsedBlank(String parseLineBlank) {
            if(parseLineBlank.isBlank()) {
                 return;
            }

            String[] split = parseLineBlank.split(",");

            for (String s : split) {
                deque.addLast(Integer.parseInt(s));
            }
        }
    }

    public static StringBuilder solve(BufferedReader bf) throws IOException {
        StringBuilder sb = new StringBuilder();

        String cntString = bf.readLine();

        for(int i=0; i<Integer.parseInt(cntString); i++){
            String commandLine = bf.readLine();
            String length = bf.readLine();
            String items = bf.readLine();

            MyDeque myDeque = new MyDeque(items);
            String[] parsedCommand = commandLine.split("");

            long count = Arrays.stream(parsedCommand)
                    .filter(s -> s.equals("D"))
                    .count();

            if(Long.parseLong(length) < count) {
                sb.append("error").append("\n");
                continue;
            }

            for(String command : parsedCommand){
                if(command.equals("R")) {
                    myDeque.convertPrint();
                }

                if(command.equals("D")) {
                    myDeque.deleteItem();
                }
            }

            sb.append(myDeque.getPrint()).append("\n");
        }

        return sb;
    }



    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        try{
            StringBuilder sb = solve(bf);

            bw.write(sb.toString());
            bw.flush();
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}