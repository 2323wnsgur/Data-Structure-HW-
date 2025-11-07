#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool is_uniform(const vector<vector<bool>>& IMG_vector){
    bool first=IMG_vector[0][0];
    for(auto& row: IMG_vector){
        for(bool val:row){
            if(val != first) return false;
        }
    }
    return true;
}

vector<vector<bool>> extract_quarter(const vector<vector<bool>> &img, int start_row, int end_row, int start_col, int end_col) {
    vector<vector<bool>> quad;
    for (int i = start_row; i < end_row; i++) {
        vector<bool> row_slice(img[i].begin() + start_col, img[i].begin() + end_col);
        quad.push_back(row_slice);
    }
    return quad;
}

string return_QTSstring(const vector<vector<bool>>& IMG_vector){
    int vec_length=IMG_vector.size();
    int half=vec_length/2;
    string result="(";
    if(is_uniform(IMG_vector) or vec_length==1){
        return IMG_vector[0][0]? "1" : "0";
    }

    result += return_QTSstring(extract_quarter(IMG_vector, 0, half, half, vec_length)); // q1
    result += return_QTSstring(extract_quarter(IMG_vector, 0, half, 0, half));   // q2
    result += return_QTSstring(extract_quarter(IMG_vector, half, vec_length, 0, half));   // q3
    result += return_QTSstring(extract_quarter(IMG_vector, half, vec_length, half, vec_length));   // q4


    result += ")";
    return result;

}


int main() {
    int k;
    string token;
    cin>>k>>token;
    int powerK2=1<<k;
    vector<vector<bool>> IMG_vector(powerK2,vector<bool>(powerK2,false));

    if(token=="QTS"){ // case of QTS
        string QuadTreeString;
        cin>>QuadTreeString;

        if(QuadTreeString.length()==1){
            if(QuadTreeString=="1"){
            for(auto & row: IMG_vector){
                fill(row.begin(),row.end(), true);
                }
            }
        }
        else {

            int now_depth = 0;
            vector<int> quarter_table;
            for (auto it: QuadTreeString) {
                if (it == '(') {
                    now_depth ++;
                    quarter_table.push_back(1);
                } else if (it == ')') {
                    now_depth --;
                    quarter_table.pop_back();   
                    if (!quarter_table.empty()) ++quarter_table.back();
                } else { // case of number, input to the IMG_vector by using depth
                    int length = 1 << (k - now_depth);
                    int row = powerK2, col = powerK2;
                    int power_num = k - 1;

                    for (auto qt: quarter_table) {
                        if (qt == 1) row = row - (1 << power_num);
                        else if (qt == 2) {
                            row = row - (1 << power_num);
                            col = col - (1 << power_num);
                        } else if (qt == 3) col = col - (1 << power_num);
                        else {};
                        --power_num;
                    }


                    for (int i = 0; i < length; i = i + 1) {
                        for (int j = 0; j < length; j = j + 1) {
                            if (it == '1') {
                                IMG_vector[row - 1 - i][col - 1 - j] = true;
                            }
                        }
                    }
                    ++quarter_table.back();
                }
            }
        }


        for(auto& row: IMG_vector){
            for(auto val: row){
                std::cout<<val;
            }
            std::cout<<std::endl;
        }


    }


    else if (token=="IMG"){ // case of IMG
        char pl;
        for(auto& row: IMG_vector){
            for(auto val: row){
                cin>>pl;
                if(pl=='1') val=true;
            }
        }

        string al= return_QTSstring(IMG_vector);
        cout<<al<<endl;

    }
    return 0;
}
