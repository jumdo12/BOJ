import java.util.*;
import java.util.stream.*;

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = {};
        
        List<String> map1 = convertToList(arr1, n);
        List<String> map2 = convertToList(arr2, n);
        List<String> result = new ArrayList<>();
        
        for(int i=0; i<map1.size(); i++){
            String str1 = map1.get(i);
            String str2 = map2.get(i);
            
            String temp = "";
            for(int l = 0; l < str1.length(); l++){
                if(str1.charAt(l) == '0' && str2.charAt(l) == '0'){
                    temp += " ";
                } else {
                    temp += "#";
                }
            }
            
            result.add(temp);
        }
        
        return result.toArray(new String[0]);
    }
    
    private List<String> convertToList(int[] arr, int n){
        return Arrays.stream(arr)
            .mapToObj(num -> convertDToB(num,n))
            .collect(Collectors.toList());
    }
    
    private String convertDToB(int num, int bSize){
        StringBuilder sb = new StringBuilder();
        while(num != 0){
            sb.append(num % 2);
            num /= 2;
        }
        
        while(sb.length() < bSize){
            sb.append(0);
        }
        
        return sb.reverse().toString();
    }
}