int solution(vector<int>& a) {
    size_t size = a.size();
    int count = 0;
    for (int i = 0; i < size; i++) {
        int left, right;
        left = i - 1 < 0 ? 0 : a[i-1];
        right = i + 1 >= size ? 0 : a[i+1];
        count += (left + right == 2*a[i]);
    }
    return count;
}