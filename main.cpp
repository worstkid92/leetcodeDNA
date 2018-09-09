#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=s.length();
        vector<string> vec;
        if(l<11){
            return vec;
        }
        vector<bool> visited(l,false);
        for(int i=0;i<=l-11;i++){
            if(!visited[i]){
                for(int j=i+1;j<=l-10;j++){
                    if(check(s,i,j)){
                        visited[j]=true;
                        vec.push_back(s.substr(i,10));
                    }
                }
            }

        }
        set<string> strset;
        for(int i=0;i<vec.size();i++){
            strset.insert(vec[i]);
        }
        vec.clear();
        for(set<string>::iterator it=strset.begin();it!=strset.end();it++){
            vec.push_back(*it);
        }
        return vec;

    }
    bool check(string s,int t,int j){
        for(int i=0;i<10;i++){
            if(s[t+i]!=s[j+i]){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution so;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> vec;
    vec=so.findRepeatedDnaSequences(s);
    cout<<vec[0]<<endl;
}
