#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {



    string line;
    vector<char> brace_vector;

    while(getline(cin,line)){
        for (auto it : line) {
            if (it == '{' or it == '}') brace_vector.push_back(it);
        }
    }

    int cnt=0;
    int ans=0;
    for(auto it: brace_vector){
        if(it=='{'){
            cnt=cnt+1;
            ans=ans+cnt;
        }
        else{
            cnt=cnt-1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
