import java.util.*;

class Solution {
    
    static class Song implements Comparable<Song> {
        public String genre;
        public int play;
        public int idx;
        
        public Song(String genre, int play, int idx){
            this.genre = genre;
            this.play = play;
            this.idx = idx;
        }
        
        @Override
        public int compareTo(Song other) {
            if(this.play != other.play) {
                return other.play - this.play;
            }
            
            return this.idx - other.idx;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> map = new HashMap<>();
        Map<String, PriorityQueue<Song>> countMap = new HashMap<>();
        
        for(int i=0; i<genres.length; i++) {
            if(!map.containsKey(genres[i])) {
                map.put(genres[i], plays[i]);
            }
            else {
                map.put(genres[i], map.get(genres[i]) + plays[i]);    
            }
            
            if(!countMap.containsKey(genres[i])) {
                countMap.put(genres[i], new PriorityQueue<>());
            }
            Song song = new Song(genres[i], plays[i], i);
            countMap.get(genres[i]).add(song);
        }
        
        List<Song> ans = new ArrayList<>();
        map.entrySet()
            .stream()
            .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
            .forEach(e -> {
                String genre = e.getKey();
                PriorityQueue<Song> pq = countMap.get(genre);
                
                if(!pq.isEmpty()) {
                    ans.add(pq.poll());
                }
                
                if(!pq.isEmpty()) {
                    ans.add(pq.poll());
                }
            });
    
        return ans.stream().mapToInt(i -> i.idx).toArray();
    }
}