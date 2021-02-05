double myPow(double x, int n){
    if (n == 0)     return 1;
    if (n == 1)     return x;
    long long N = n;
    if (N <= 0) {
      N = -N;
      x = 1/x;
    }
    double half = myPow(x, N/2);
    if (n % 2 == 0) {
        return half * half;
     } else {
         return half * half * x;
     }
}