#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

void bfs(std::map<char,vector<char>>& graph, char start1,char start2,char start3){
    map<char,int> cnt_table;
    for(auto& i:graph){
        cnt_table[i.first]=0;
    }

    for(auto start:{start1,start2,start3}){
        map<char,int> level_table;
        for(auto& i:graph){
            level_table[i.first]=999;
        }

        queue<pair<char,int>> q;
        q.push({start,0});
        level_table[start]=0;

        while(!q.empty()){
            auto [cur,level] = q.front();
            q.pop();

            for(char next:graph[cur]){
                if(level_table[next]>level+1){
                    level_table[next]=level+1;
                    q.push({next,level+1});
                }
            }
        }

        for(auto& k:cnt_table){
            k.second=max(k.second,level_table[k.first]);
        }

    }

    auto min_it=cnt_table.begin();
    for(auto it=cnt_table.begin();it!=cnt_table.end();it++){
        if(it->second<min_it->second){
            min_it=it;
        }
        else if(it->second==min_it->second and it->first<min_it->first){
            min_it=it;
        }

    }

    if(min_it->second==999){
        std::cout<<"@"<<std::endl;
        std::cout<<-1<<std::endl;
    }
    else {
        std::cout << min_it->first << std::endl;
        std::cout << min_it->second + 2 * (min_it->second - 1) << std::endl;
    }

}


int main() {
    int N;
    std::cin>>N;

    char friend_1,friend_2,friend_3;
    std::cin>>friend_1>>friend_2>>friend_3;


    std::map<char,vector<char>> graph;
    for(int i=0;i<N;i++){
        char input;
        std::cin>>input;
        graph[input];

        while(1){
            char vertex;
            std::cin>>vertex;
            if(vertex=='$') break;
            graph[input].push_back(vertex);
        }
    }

    bfs(graph,friend_1,friend_2,friend_3);

    return 0;
}
