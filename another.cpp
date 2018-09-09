class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=s.length();
        vector<string> vec;
        set<string> strset;
        if(l<11){
            return vec;
        }
        for(int i=0;i<=l-10;i++){
            if(check(strset,i,s)){
                vec.push_back(s.substr(i,10));
            }
            strset.insert(s.substr(i,10));
        }
        set<string> strset2;
        for(int i=0;i<vec.size();i++){
            strset2.insert(vec[i]);
        }
        vec.clear();
        for(set<string>::iterator it=strset2.begin();it!=strset2.end();it++){
            vec.push_back(*it);
        }

        return vec;

    }
    bool check(set<string> strset,int t,string s){
        string tmp=s.substr(t,10);
        return strset.count(tmp)==1;
    }
};
