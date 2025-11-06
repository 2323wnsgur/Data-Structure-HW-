#include <iostream>
#include <vector>

void print_position(int dist,int cnt,std::vector<std::vector<int>> arr,std::vector<int> dist_between){
    int sum=0;
    for(int j=0;j<cnt;j=j+1){
        sum=sum+dist_between[j];
        if(sum>=dist){
            int dist_forward=dist-(sum-dist_between[j]);
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








int main() {
    int cnt;
    std::cin >> cnt;
    std::vector<std::vector<int>> arr(cnt, std::vector<int>(2));
    for (int i = 0; i < cnt; i = i + 1) {
        std::cin>>arr[i][0]>>arr[i][1];
    }


    int input_time;
    std::cin>>input_time;


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



    //////////////////////////////

    double dist_p1=0;
    for(int i=0;i<cnt/2-1;i=i+1){
        dist_p1=dist_p1+dist_between[i];
    }
    dist_p1=dist_p1/2.0;
    double dist_p2=dist_p1+all_distance/2.0;


    double dist_to_c2=2*dist_p1;
    int to_move=-1;
    for(int i=0;i<input_time;i=i+1){
        dist_to_c2=dist_to_c2+to_move;
        if(dist_to_c2==dist_p1 or dist_to_c2==dist_p2){
            to_move=to_move*-1;
        }
        else if(dist_to_c2<dist_p1 or dist_to_c2>dist_p2){
            to_move=to_move*-1;
            dist_to_c2=dist_to_c2+to_move;
        }
    }
    double dist_to_c1=2*dist_p1-dist_to_c2;
    if(dist_to_c1<0){
        dist_to_c1=all_distance+dist_to_c1;
    }
    /////////

    print_position(dist_to_c1,cnt,arr,dist_between);
    print_position(dist_to_c2,cnt,arr,dist_between);



    return 0;
}
