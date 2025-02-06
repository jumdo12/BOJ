import java.util.*;

class Solution {
    public String[] solution(String[] picture, int k) {
        List<String> list = new ArrayList<>();
        
        for(int i=0; i<picture.length; i++){
            String str = picture[i];
            
            
            for(int j=0; j<k; j++){
                String temp = "";
                
                for(String ch : str.split("")){
                    for(int l = 0; l<k; l++){
                        temp += ch;
                    }
                }
                
                list.add(temp);
            }
        }
        
        return list.toArray(new String[0]);
    }
}