class CustomStack {
    vector<int> vec;
    int top = -1;
public:
    CustomStack(int maxSize) {
        vec.resize(maxSize, 0);
    }
    
    void push(int x) {
        if(top == vec.size() - 1) return;
        vec[++top] = x;
        print();
    }
    
    int pop() {
        if(top == -1) return -1;
        return vec[top--];
    }
    
    void increment(int k, int val) {
        if(k > vec.size() || k > top + 1){
            for(int i=0;i<=top;++i){
                vec[i] += val;
            }
        }
        else{
            for(int i=0;i<k;++i){
                vec[i] += val;
            }
        }
        print();
    }
    void print(){
        cout << "Vector : ";
        for(int i=0;i<=top;++i){
            cout << vec[i] << ' ';
        }
        cout << '\n';
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */