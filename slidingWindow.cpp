
class Solution {
public:
    int slidingWindow(vector<char> vec) {
        int n = vec.size();

        if(!n)
            return 0;

        vector<int> cnt(26,0);
        int i=0; int ans=1;
        int j=0;
        cnt[vec[0]-'a']=1;
        while(j != n-1) {
            if(!cnt[vec[j+1]-'a']) {
                j+=1;
                cnt[vec[j]-'a']+=1;
                ans=max(ans, j-i+1);
            } else {
                cnt[vec[i]-'a']-=1;
                i+=1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<char> vec {'a', 'b', 'r', 'e', 'x', 'r', 'z', 'x'} ;
    cout << sol.slidingWindow(vec);
}
