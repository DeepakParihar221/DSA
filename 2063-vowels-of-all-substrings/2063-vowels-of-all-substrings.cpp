class Solution {
public:
    long long countVowels(string word) {
        //can't generate all substrings so we will count 
        //the contribution of a vowel in the sum/
        //the generated formula is (len-i)*(i+1) where i is position of vowel
        
        int n = word.length();
        long long sum = 0;
        long long int p1 , p2;
        for(int i=0;i<n;++i){
            if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
                p1 = n-i;
                p2 = i+1;
                sum += p1*p2;
            }
        }
        return sum;
    }
};