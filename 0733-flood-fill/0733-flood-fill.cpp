class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int oriColor = image[sr][sc];
        if(oriColor == color){
            return image;
        }
        image[sr][sc] = color;
        q.push({sr,sc});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] =  {0, 1, 0, -1};
      
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int curRow = row + drow[i];
                int curCol = col + dcol[i];
                if(curRow >= 0 && curCol >= 0 && curRow < n && curCol < m && image[curRow][curCol] == oriColor){
                    image[curRow][curCol] = color;
                    q.push({curRow, curCol});
                }
            }
        }
    return image;
    }
};