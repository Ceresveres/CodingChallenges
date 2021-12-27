// time = O(n)
// space = O(1)

int tribonacci(int n) { 
    if (n == 0) return 0;
    int t0 = 0, t1 = 1, t2 = 1;
    
    for (int i=0; i<n-2; i++) {
        int tn = t0 + t1 + t2;
        t0 = t1;
        t1 = t2; 
        t2 = tn;
    }
    return t2;
}
