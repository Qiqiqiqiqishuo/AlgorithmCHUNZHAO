//-----------------------------------------------------------------------------------------------------------------------------------
// 1. 暴力循环 O(n^2) O(1)
int max(int a, int b) {
    return a>b ? a : b;
}
int min(int a, int b) {
    return a<b ? a : b;
}
int maxArea(int* height, int heightSize){
    int res=0;
    int water=0;
    for (int i=0; i<heightSize-1; i++) {
        for (int j=i+1; j<heightSize; j++) {
            water = (j - i) * min(height[i], height[j]);
            res = max(res, water);
        }
    }

    return res;
}



//---------------------------------------------------------------------------------------------------------------------------------------
// 2. 双指针法 O(n) O(1)
int max(int a, int b) {
    return a>b ? a : b;
}

int min(int a, int b) {
    return a<b ? a : b;
}

int maxArea(int* height, int heightSize){
    int res=0;
    int water=0;
    int i = 0;
    int j = heightSize - 1;
    while (i < j) {
        water = (j - i) * min(height[i], height[j]);
        res = max (water, res);
        if (height[i] > height[j]) {  
            j--;
        } else {
            i++;
        }
    }

    return res;
}