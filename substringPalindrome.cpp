vector<vector<bool>> buildPalindromeDP(const string& s) {
    int n = s.size();

    vector<vector<bool>> isPalindrome(
        n, vector<bool>(n, false)
    );

   
    for (int len = 1; len <= n; len++) {
        for (int left = 0; left <= n - len; left++) {
            int right = left + len - 1;

            isPalindrome[left][right] =
                s[left] == s[right] &&
                (len <= 2 || isPalindrome[left + 1][right - 1]);
        }
    }

    return isPalindrome;
}