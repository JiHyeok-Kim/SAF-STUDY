#include <string>
#include <vector>

using namespace std;

string getMap(int num,int len){
    string ans;
    int idx=len-1;
    for(int i=0;i<len;i++){
        if(num%2 == 0) ans= ' ' + ans;
        else ans = '#' + ans;
        num /= 2;
    } 
    return ans;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        int result = arr1[i] | arr2[i];
        string temp = getMap(result,n);
        answer.push_back(temp);
    } 
    return answer;
}