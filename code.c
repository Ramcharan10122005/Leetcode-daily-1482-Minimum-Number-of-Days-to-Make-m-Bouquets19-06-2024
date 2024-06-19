bool isokay(int mid, int* arr, int s, int m, int k) {
    int consecflow = 0, numofboq = 0;
    for (int i = 0; i < s; i++) {
        if (arr[i] <= mid)
            consecflow++;
        else
            consecflow = 0;
        if (consecflow == k) {
            consecflow = 0;
            numofboq++;
        }
    }
    return numofboq >= m;
}
int minDays(int* b, int s, int m, int k) {
    if ((long)m * k > s)
        return -1;
    int max = INT_MIN;
    for (int i = 0; i < s; i++) {
        max = fmax(max, b[i]);
    }
    int l = 1, r = max, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (isokay(mid, b, s, m, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}
