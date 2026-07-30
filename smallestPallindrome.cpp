class Solution {
public:
    long long nCr(int n, int r,long long limit){
        if(r>n)return 0;
        r= min(r,n-r);
        long long ans = 1;
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
            if (ans >= limit)
            return limit;
        }
    return ans;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        char mid =' ';
        if(n%2==1)mid=s[n/2];
        vector<int>count(26,0);
        for(int i=0;i<n;i++){
            if(n%2==1 && i==n/2)continue;
            count[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)count[i]/=2;
        string halfResult = "";
        int half = n/2;
        for(int i=0;i<half;i++){
            bool placeHolder = false;
            for(int j=0;j<26;j++){
                if(count[j]>0){
                    count[j]-=1;
                    long long ways = 1;
                    int letters = 0;
                    for(int ch=0;ch<26;ch++)letters+=count[ch];
                    for(int ch=0;ch<26;ch++){
                        if(count[ch]>0){
                            ways*=nCr(letters,count[ch],k);
                            letters-=count[ch];
                        }
                        if(ways>=k)break;
                    }
                    if(ways>=k){
                        halfResult.push_back(j+'a');
                        placeHolder = true;
                        break;
                    }
                    k-=ways;
                    count[j]+=1;
                }

            }
            if(placeHolder==false)return "";
        
        }
    string rev = halfResult;
    reverse(begin(rev),end(rev));
    if(mid!=' ')halfResult.push_back(mid);
    return halfResult+rev;
    }
};