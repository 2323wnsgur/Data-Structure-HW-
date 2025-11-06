#include <iostream>
#include <vector>
#include <cstdlib> // abs() 함수를 위해 추가

int main() {
    int cnt;
    std::cin >> cnt;


    std::vector<std::vector<int>> arr(cnt, std::vector<int>(2));

    for (int i = 0; i < cnt; i = i + 1) {
        std::cin>>arr[i][0]>>arr[i][1];
    }

    int all_distance=0;
    int dist_bet;
    std::vector<int> dist_between(cnt);
    for (int i = 0; i < cnt; i = i + 1) {
        if(i==cnt-1){
            dist_bet = abs(arr[i][0]-arr[0][0])+abs(arr[i][1]-arr[0][1]);
        }else {
            dist_bet = abs(arr[i][0] - arr[i + 1][0]) + abs(arr[i][1] - arr[i + 1][1]);
        }
        all_distance=all_distance+dist_bet;
        dist_between[i]=dist_bet;
    }




    int input_time;
    int input_time_modded;
    for(int i=0;i<5;i=i+1){
        std::cin>>input_time;
        input_time_modded=input_time%all_distance;
        int sum=0;
        for(int j=0;j<cnt;j=j+1){
            sum=sum+dist_between[j];
            if(sum>=input_time_modded){
                int dist_forward=input_time_modded-(sum-dist_between[j]);
                int z = (j + 1 == cnt) ? 0 : j + 1;

                int x_move=0,y_move=0;
                if (arr[z][0]>arr[j][0]){
                        x_move=1;
                }
                else if(arr[z][0]<arr[j][0]){
                        x_move=-1;
                }
                if (arr[z][1]>arr[j][1]){
                        y_move=1;
                }
                else if(arr[z][1]<arr[j][1]){
                        y_move=-1;
                }
                std::cout<<arr[j][0]+x_move*dist_forward<<" "<<arr[j][1]+y_move*dist_forward<<std::endl;
                break;
                }

            }
    }


    return 0;
}
