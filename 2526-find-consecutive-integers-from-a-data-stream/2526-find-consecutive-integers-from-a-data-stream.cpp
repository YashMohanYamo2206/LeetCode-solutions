class DataStream {
    int notValue, val, k;
    deque<int> dq;
public:
    DataStream(int value, int K) {
        val = value;
        k = K;
        notValue = 0;
    }
    
    bool consec(int num) {
        if(k == 1){
            return num == val;
        }
        if(dq.size() < k - 1){
            dq.push_back(num);
            notValue += (num != val);
            // cout <<"1 "<< notValue << endl;
            return false;
        }
        if(dq.size() == k - 1){
            dq.push_back(num);
            notValue += (num != val);
            // cout <<"1 "<< notValue << endl;
            return notValue == 0;
        }
        notValue -= (dq.front() != val);
        dq.pop_front();
        // deque<int> d = dq;
         // cout << endl;
        notValue += (num != val);
        dq.push_back(num);
        // cout << "2 "<< notValue << endl;
        return notValue == 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */