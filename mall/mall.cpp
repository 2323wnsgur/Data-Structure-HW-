#include <iostream>
#include <vector>
#include <queue>

int main() {
    int N,k;
    std::cin>>N>>k;
    if(N < k) k=N;
    std::vector<std::queue<std::pair<int,int>>> Mall_Line(k);



    ///////////// input
    int ID, cnt;
    for(int i=0;i<k;i=i+1){
        std::cin>>ID>>cnt;
        Mall_Line[i].emplace(ID,cnt);
    }


    for(int i=0;i<N-k;i=i+1){
        std::cin>>ID>>cnt;
        int line_number;
        int min_time=9999;
        for(int j=k-1;j>=0;j=j-1){
            if(Mall_Line[j].empty()) continue;
            if(min_time>=Mall_Line[j].back().second){
                min_time=Mall_Line[j].back().second;
                line_number=j;
            }
        }
        Mall_Line[line_number].emplace(ID,min_time+cnt);
    }

    /////////////////// printing
    for(int i=0;i<N;i=i+1){
        int line_number;
        int min_time=9999;
        for(int j=0;j<k;j=j+1){
            if(Mall_Line[j].empty()){
                continue;
            }
            else{
                if(min_time>=Mall_Line[j].front().second){
                    min_time=Mall_Line[j].front().second;
                    line_number=j;
                }
            }
        }
        std::cout<<Mall_Line[line_number].front().first<<std::endl;
        Mall_Line[line_number].pop();
    }
    return 0;
}
