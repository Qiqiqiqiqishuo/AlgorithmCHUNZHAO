//------------------------------------------------------------------------
// 1. 模拟
//  优先处理待执行任务最多的任务种类
int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < tasksSize; ++i) {
        ++freq[tasks[i] - 'A'];
    }

    int m = 0;
    int nextValid[26], rest[26];
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            nextValid[m] = 1;
            rest[m++] = freq[i];
        }
    }

    int time = 0;
    for (int i = 0; i < tasksSize; ++i) {
        ++time;
        int minNextValid = INT_MAX;
        for (int j = 0; j < m; ++j) {
            if (rest[j]) {
                minNextValid = fmin(minNextValid, nextValid[j]);
            }
        }
        time = fmax(time, minNextValid);
        int best = -1;
        for (int j = 0; j < m; ++j) {
            if (rest[j] && nextValid[j] <= time) {
                if (best == -1 || rest[j] > rest[best]) {
                    best = j;
                }
            }
        }
        nextValid[best] = time + n + 1;
        --rest[best];
    }

    return time;
}



//----------------------------------------------------------------------------------
// 2. 桶子
//  -___-
//  待补充
int cmp(const void*a, const void*b){
    return *(int*)a > *(int*)b ? -1 : 1;
}

int leastInterval(char* tasks, int tasksSize, int n){
    if(n==0) return tasksSize;
    
    int map[26] = {0};
    for(int i = 0; i < tasksSize; i++){
        map[tasks[i]-'A']++;
    }
    qsort(map,26,sizeof(int),cmp);
    
    int max = map[0];
    int time = 0, count;
    for (int i = 0; i < 26; i++) {
        while (map[i] > 0) {
            time += n + 1;
            int j = 0;
            count = 0;
            while (count < n + 1 && i + j < 26) {
                if (map[i + j] > 0) {
                    map[i + j]--;
                    count++;
                }
                j++;
            }
        }
    }
    return (max-1)*(n+1)+count > tasksSize ? (max-1)*(n+1)+count : tasksSize;
}