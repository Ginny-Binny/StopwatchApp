int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0, j = 0;
    while (i < n) {
        int cnt = 1;
        while (i < n - 1 && chars[i] == chars[i + 1]) {
            ++cnt;
            ++i;
        }
        chars[j++] = chars[i];
        if (cnt > 1) {
            string s = to_string(cnt);
            for (char c : s) {
                chars[j++] = c;
            }
        }
        ++i;
    }
    return j;
}
