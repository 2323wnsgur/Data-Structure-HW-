#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <fstream>


using namespace std;

int find_index(const vector<int>& data,int t){
    auto it=upper_bound(data.begin(),data.end(),t);
    return int(it-data.begin()-1);
}




struct SegMinMax{
    int n, size;
    vector<double> tmin, tmax;

    explicit SegMinMax(const vector<double>& a){
        n = (int)a.size();
        size = 1; while (size < n) size <<= 1;
        tmin.assign(2*size, numeric_limits<double>::max());
        tmax.assign(2*size, numeric_limits<double>::lowest());

        // 리프 채우기
        for (int i = 0; i < n; ++i){
            tmin[size + i] = a[i];
            tmax[size + i] = a[i];
        }
        // 내부 노드 빌드
        for (int i = size - 1; i > 0; --i){
            tmin[i] = min(tmin[2*i], tmin[2*i+1]);
            tmax[i] = max(tmax[2*i], tmax[2*i+1]);
        }
    }

    pair<double,double> query(int l, int r) const{
        if (l > r) swap(l, r);
        l += size; r += size;
        double mn = numeric_limits<double>::max();
        double mx = numeric_limits<double>::lowest();
        while (l <= r){
            if (l & 1){ mn = min(mn, tmin[l]); mx = max(mx, tmax[l]); ++l; }
            if (!(r & 1)){ mn = min(mn, tmin[r]); mx = max(mx, tmax[r]); --r; }
            l >>= 1; r >>= 1;
        }
        return {mn, mx};
    }
};


int main() {







    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream Myfile("Pitcoin.txt");


    size_t N;
    Myfile>>N;
    string dummy;
    getline(Myfile,dummy);

    vector<int> time;
    time.reserve(N);
    vector<double> price;
    price.reserve(N);

    string line;
    for(size_t i=0;i<N && getline(Myfile, line); ++i){
        istringstream iss(line);
        int t; double f;
        iss>>t>>f;
        time.push_back(t);
        price.push_back(f);
    }


    SegMinMax seg(price);


    int cnt;
    cin>>cnt;

    int time_left,time_right;
    for(int k=0;k<cnt;k=k+1){
        cin>>time_left>>time_right;
        int left_idx= find_index(time,time_left);
        int right_idx= find_index(time,time_right);



        auto [mn,mx]=seg.query(left_idx,right_idx);
        cout << fixed << setprecision(3) << mn << " " << mx << "\n";

    }
    return 0;
}
