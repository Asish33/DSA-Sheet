//recursive solution.
class Solution {
public:
    int fun(int row,int col){
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
        int up = fun(row-1,col);
        int left = fun(row,col-1);
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return fun(m-1,n-1);
    }
};
