class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        int n = target.length();
        int startx = 0, starty = 0;
        int r = 0, c = 4;
        string ans = "";
        for(int i=0;i<n;i++){
            string temp = "";
            if(target[i]=='z'){
                while(starty>0){
                    temp += 'L';
                    starty--;
                }
                while(startx<5){
                    temp += 'D';
                    startx++;
                }
                temp += '!';
                ans += temp;
                continue;
            }
            r = 0, c = 4;
            while(board[r][c]!=target[i]){
                if(board[r][c]>target[i]) c--;
                else r++;
            }
            if(r>startx){
                while(r-startx>0){
                    temp += 'D';
                    startx++;
                }   
            }
            else{
                while(startx-r>0){
                    temp += 'U';
                    startx--;
                }
            }
            if(c>starty){
                    while(c-starty>0){
                        temp += 'R';
                        starty++;
                    }
                }else{
                    while(starty-c>0){
                        temp += 'L';
                        starty--;
                    }
                }
            
            
            
            temp += '!';
            
            ans += temp;
        }
        return ans;
    }
};