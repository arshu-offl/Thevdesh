
// Poo Poo O(q * q)
vector<int> solution(vector<int> queries){
    
    unordered_map<int, int> hashMap;
    int mx = 0;
    vector<int> ans;
    for(int q: queries){
       
        hashMap[q] = 1;
        
        int curr = 1;
        int temp = q;
        
        // Find contigous
        while(hashMap.count(temp - 1)){
            curr++;
            temp--;
        }
        
        temp = q;
        while(hashMap.count(temp + 1)){
            curr++;
            temp++;
        }
        
        mx = max(mx, curr);
        ans.push_back(mx);
    }
    
    return ans;
}
