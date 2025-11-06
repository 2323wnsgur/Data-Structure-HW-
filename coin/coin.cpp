#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int find_index(const vector<int>& data,int t){
    auto it=upper_bound(data.begin(),data.end(),t);
    return int(it-data.begin()-1);
}
int main() {



    FILE* inputFile = fopen("Pitcoin_sample.txt", "rb");

    fseek(inputFile, 0, SEEK_END); // move to end of the file
    long fileSize = ftell(inputFile); // set file size
    fseek(inputFile, 0, SEEK_SET); // move to starting point of the file

    vector<char> buffer(fileSize);
    fread(buffer.data(),1,fileSize,inputFile);
    fclose(inputFile);

    char* ptr = buffer.data();
    ptr++;

    size_t N = 0;

    while (*ptr >= '0' && *ptr <= '9') {
        N = N * 10 + (*ptr - '0');
        ptr++;
    }
    ptr++;
    ptr++;

    vector<int> time;
    time.reserve(N);
    vector<double> price;
    price.reserve(N);

    for (size_t i = 0; i < N; ++i) {
        int t = 0;
        double f = 0.0;
        double decimal_place = 0.1;
        bool is_decimal = false;
        bool is_negetive_f=false;

        while (*ptr == ' ') {
            ptr++;
        }

        while (*ptr >= '0' && *ptr <= '9') {
            t = t * 10 + (*ptr - '0');
            ptr++;
        }

        while (*ptr == ' ') {
            ptr++;
        }

        if(*ptr=='-'){
            is_negetive_f=true;
            ptr++;
        }
        while (*ptr != '\n' && ptr < buffer.data() + fileSize ) {
            if (*ptr == '.') {
                is_decimal = true;
                ptr++;
                continue;
            }
            if (!is_decimal) {
                f = f * 10 + (*ptr - '0');
            } else {
                f =f+ (*ptr - '0') * decimal_place;
                decimal_place /= 10.0;
            }
            ptr++;
        }
        f=f+0.002; // for '/r'
        if(is_negetive_f){
            f=-f;
        }

        ptr++;
        time.push_back(t);
        price.push_back(f);
    }




    std::cout << std::fixed << std::setprecision(3)<<price[N-1]<<std::endl;


    int cnt;
    cin>>cnt;

    int time_left,time_right;
    for(int k=0;k<cnt;k=k+1){
        cin>>time_left>>time_right;
        int left_idx= find_index(time,time_left);
        int right_idx= find_index(time,time_right);


        auto [itmin,itmax]= minmax_element(price.begin()+left_idx,price.begin()+right_idx);
        std::cout << std::fixed << std::setprecision(3)<< *itmin << " " << *itmax << std::endl;

    }
    return 0;
}
