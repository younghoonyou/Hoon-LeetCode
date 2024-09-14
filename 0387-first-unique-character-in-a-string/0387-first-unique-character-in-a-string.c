int firstUniqChar(char* s) {
    int arr[26] = {0, };
    for(int i=0;i<strlen(s);++i){
        arr[s[i] - 'a']++;
    }
    for(int i=0;i<strlen(s);++i){
        if(arr[s[i] - 'a'] == 1) return i;
    }
    return -1;
}