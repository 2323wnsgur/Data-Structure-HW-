#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>


void Recursive_call_func(std::map<std::string, std::vector<std::string>>& Fuct,std::stack<std::string>& Stack_ConvertedFromFuct,std::string Func_name,
                         std::set<std::string>& visiting,
                         bool& deadlock_flag){

    if (visiting.count(Func_name) == 1) {
        deadlock_flag = true;
        return;
    }
    visiting.insert(Func_name);
    for (auto &it: Fuct[Func_name]) {
        if (Fuct.count(it) == 1) {
            Recursive_call_func(Fuct, Stack_ConvertedFromFuct, it, visiting, deadlock_flag);
            if (deadlock_flag) return;
        } else {
            Stack_ConvertedFromFuct.push(Func_name + "-" + it);
        }
    }

    visiting.erase(Func_name);
}

std::stack<std::string> Convert_to_stack(std::map<std::string, std::vector<std::string>>& Fuct, bool& deadlock_flag){
    std::stack<std::string> Stack_ConvertedFromFuct;
    std::vector<std::string> Main_func=Fuct["M"];
    std::set<std::string> visiting;
    for(std::string& it: Main_func){
        if(Fuct.count(it)==1){
            Recursive_call_func(Fuct, Stack_ConvertedFromFuct, it, visiting, deadlock_flag);
            if (deadlock_flag) return Stack_ConvertedFromFuct;
        }
        else Stack_ConvertedFromFuct.push("M-"+it);
    }


    return Stack_ConvertedFromFuct;
}


int main() {
    int N,K1,K2;
    std::cin>>N>>K1>>K2;

    std::map<std::string, std::vector<std::string>> Fuct;
    for(int i=0;i<N;i=i+1){
        std::string name;
        std::vector<std::string> input_vec;
        std::cin>>name;
        while(1){
            std::string input;
            std::cin>>input;
            if(input == "$") break;
            else input_vec.push_back(input);
        }
        Fuct[name]=input_vec;

    }




        for(int p:{K1,K2}){
            bool deadlock_flag = false;
            std::stack<std::string> ans= Convert_to_stack(Fuct,deadlock_flag);
            int num=ans.size();

            if(deadlock_flag){ std::cout<<"DEADLOCK"<<std::endl; break;}
            else{
                if(abs(p)>ans.size()){
                std::cout<<"NONE"<<std::endl;
                }
                else{
                    if(p<0){
                      for(int g=1;g<-p;g=g+1) {ans.pop();}
                    }
                    else{
                     for(int g=0;g<num-p;g=g+1) {ans.pop();}
                    }
                 std::cout<<ans.top()<<std::endl;
                }
            }
        }








    return 0;
}
