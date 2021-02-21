bool palindrome(char * s, int left, int right){
    while (left <right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
int countSubstrings(char * s){
    int slen = strlen(s);
    int count = 0;
    for (int i=0; i<slen; i++) {
        for (int length = 0; i+length<slen; length++) {
            if (palindrome(s,i,i+length)) count++;
        }
    }
    return count;
}
