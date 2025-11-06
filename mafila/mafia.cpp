#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
std::vector<std::pair<std::string,std::vector<std::string>>> mafia_tree;
int cnt_subtree(std::string& name){
    int cnt=0;
    for(auto& it: mafia_tree){
        if(name==it.first){
            for(auto k:it.second){
                cnt=cnt+1+ cnt_subtree(k);
            }
        }
    }
    return cnt;
}

int find_depth(std::string & name){
    int depth=0;
    for(auto& it: mafia_tree){
        for(auto k:it.second){
            if(k==name){
                depth=depth+1+ find_depth(it.first);
            }
        }
    }
    return depth;
}
bool cmp(std::string& a, std::string& b){
    int cnt_a = cnt_subtree(a);
    int cnt_b = cnt_subtree(b);
    if (cnt_a != cnt_b) {
        return cnt_a > cnt_b;
    }
    int depth_a = find_depth(a);
    int depth_b = find_depth(b);
    if (depth_a != depth_b) {
        return depth_a < depth_b;
    }
    return a < b;
}
int main() {



    int N;
    std::cin>>N;

    std::string PERSON;
    std::string BOSS;
    std::set<std::string> temp_set;

    for(int i=0;i<N-1;i=i+1){
        std::cin>>PERSON>>BOSS;
        temp_set.insert(PERSON);
        temp_set.insert(BOSS);
        bool found = false;
        for(auto& it : mafia_tree){
            if(it.first==BOSS){
                it.second.push_back(PERSON);
                found= true;
            }
        }
        if(!found){
           mafia_tree.emplace_back(BOSS,std::vector<std::string>{PERSON});
        }
    }


    std::vector<std::string> all_people(temp_set.begin(), temp_set.end());
    std::sort(all_people.begin(), all_people.end(), cmp);
    for ( auto& name : all_people) {
        std::cout << name << std::endl;
    }
    return 0;
}
