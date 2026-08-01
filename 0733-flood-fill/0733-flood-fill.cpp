class Solution {
public:

    void fill(vector<vector<int>>& image, int sr, int sc, int color, int cur){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        if(image[sr][sc] != cur) return;
        image[sr][sc] = color;
        fill(image, sr + 1, sc, color, cur);
        fill(image, sr - 1, sc, color, cur);
        fill(image, sr, sc + 1, color, cur);
        fill(image, sr, sc - 1, color, cur);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
