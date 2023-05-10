import java.util.*;

class Solution {
    int answer = 0;
    
    int[] x_loc = {0, 0, -1, 1};
    int[] y_loc = {1, -1, 0, 0};
    
    
    void bfs(int[][] maps, int x, int y, int[][] visited) {
        visited[y][x] = 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x,y});
        
        while(!queue.isEmpty()) {
            int[] now = queue.remove();
            
            for(int i=0; i<4; i++) {
                int new_x = now[0] + x_loc[i];
                int new_y = now[1] + y_loc[i];
                
                if (new_x<0 || new_x>=maps[0].length || new_y<0 || new_y>=maps.length)
                   continue;

                if (visited[new_y][new_x]==0 && maps[new_y][new_x]==1)
                {
                    visited[new_y][new_x] = visited[now[1]][now[0]]+1;
                    queue.add(new int[]{new_x, new_y});
                }
            }
        }
          
    }
    
    public int solution(int[][] maps) {
        int[][] visited = new int[maps.length][maps[0].length];
        bfs(maps, 0, 0, visited);
        
        if (visited[maps.length-1][maps[0].length-1] == 0)
            return -1;
        return visited[maps.length-1][maps[0].length-1];
    }
}