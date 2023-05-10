class Solution {
    int answer = 0;
    int visited[];
    int arr[] = {1, -1};
    
    void dfs (int[] numbers, int target, int index, int result) {

        if (index == numbers.length) {
            if (result == target)
                answer++;
            return;
        }
        
        for (int i=0; i<2; i++) {
            if (visited[index] == 1)
                break;
            result += (numbers[index] * arr[i]);
            dfs(numbers, target, index+1, result);
        }
        visited[index] = 1;
        // dfs(numbers, target, index+1, result - numbers[index]);
        // dfs(numbers, target, index+1, result + numbers[index]);
    }
    
    
    public int solution(int[] numbers, int target) {
        visited = new int[numbers.length];
        
        for (int i=0; i<numbers.length; i++)
            visited[i] = 0;
        
        dfs(numbers, target, 0, 0); 
        System.out.println(answer);
        return answer;
    }
}