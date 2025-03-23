import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solve(br);
    }

    static class MySet{
        private static Set<Integer> myset = new HashSet<>();

        public void add(int x){
            myset.add(x);
        }

        public void remove(int x){
            myset.remove(x);
        }

        public int check(int x){
            if(myset.contains(x)) return 1;
            return 0;
        }

        public void toggle(int x){
            if(myset.contains(x)){
                myset.remove(x);
            }
            else{
                myset.add(x);
            }
        }

        public void all(){
            for(int i=1; i<=20; i++){
                myset.add(i);
            }
        }

        public void empty(){
            myset.clear();
        }
    }

    public static void solve(BufferedReader br){
        MySet mySet = new MySet();

        try{
            String input = br.readLine();
            int num = Integer.parseInt(input);
            StringBuilder sb = new StringBuilder();
            for(int i=0; i<num; i++){
                input = br.readLine();;
                String[] parsedInput = input.split(" ");

                String command = parsedInput[0];
                if(command.equals("add")){
                    int number = Integer.parseInt(parsedInput[1]);
                    mySet.add(number);
                }
                else if(command.equals("check")){
                    int number = Integer.parseInt(parsedInput[1]);
                    sb.append(mySet.check(number));
                    sb.append('\n');
                }
                else if(command.equals("remove")){
                    int number = Integer.parseInt(parsedInput[1]);
                    mySet.remove(number);
                }
                else if(command.equals("toggle")){
                    int number = Integer.parseInt(parsedInput[1]);
                    mySet.toggle(number);
                }
                else if(command.equals("all")){
                    mySet.all();
                }
                else{
                    mySet.empty();
                }
            }
            System.out.println(sb);
        }catch (Exception e){
            e.printStackTrace();
        }

    }
}

