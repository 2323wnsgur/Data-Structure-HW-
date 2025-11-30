#include <iostream>
#include <string>

using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;
    Node(string data): data(data) , left(nullptr) , right(nullptr){};
};

class Binary_Search_tree{
private:
    Node* root;
    Node* insertNode(Node* node, string data){
        if(node== nullptr){
            return new Node(data);
        }

        if(data<node->data){
            node->left= insertNode(node->left,data);
        }
        else if(data>node->data){
            node->right=insertNode(node->right,data);
        }

        return node;
    }
    Node* deleteNode(Node* node, string data){
        if(node== nullptr) return node;

        if(data<node->data){
            node->left= deleteNode(node->left,data);
        }
        else if(data>node->data){
            node->right= deleteNode(node->right,data);
        }
        else if(node->data==data){
            if(node->left== nullptr and node->right== nullptr){
                delete node;
                return nullptr;
            }
            else if(node->left== nullptr){
                Node* min_node= findMinNode(node->right);
                node->data=min_node->data;
                node->right = deleteNode(node->right,node->data);
            }
            else{
                Node* max_node= findMaxNode(node->left);
                node->data=max_node->data;
                node->left = deleteNode(node->left,node->data);
            }
        }

        return node;
    }
    Node* findMinNode(Node* node){
        Node* current=node;
        while(current->left != nullptr){
            current=current->left;
        }
        return current;
    }
    Node* findMaxNode(Node* node){
        Node* current=node;
        while(current->right != nullptr){
            current=current->right;
        }
        return current;
    }
    void findNodesAtDepth(Node* node, int target_depth, int current_depth,int& cnt){
        if(node== nullptr or current_depth> target_depth){
            return ;
        }
        if(current_depth==target_depth){
            cout<<node->data<<" ";
            cnt++;
            return;
        }
        findNodesAtDepth(node->left,target_depth,current_depth+1,cnt);
        findNodesAtDepth(node->right,target_depth,current_depth+1,cnt);
    }
    void findNodesAtleaf(Node* node){
        if(node->right == nullptr and node->left== nullptr){
            cout<<node->data<<" ";
            return;
        }

        if(node->left != nullptr) findNodesAtleaf(node->left);
        if(node->right != nullptr) findNodesAtleaf(node->right);
    }
public:
    Binary_Search_tree(): root(nullptr){};
    void insert(string name){
        root= insertNode(root,name);
    }
    void pop(string name){
        root= deleteNode(root,name);
    }
    int depth(int k){
        int cnt=0;
        findNodesAtDepth(root,k,1, cnt);
        return cnt;
    }
    void leaf(){
        findNodesAtleaf(root);
    }
};

int main() {
    string input;
    Binary_Search_tree bst;

    while(cin>>input){
        if(input=="quit"){
            break;
        }
        else if(input=="leaf"){
            bst.leaf();
            cout<<endl;
        }
        else if(input=="depth"){

            int dep;
            cin>>dep;
            int cnt;
            cnt=bst.depth(dep);
            cout<<endl;
            if(cnt==0){
                cout<<"NO";
            }

        }
        else if(input=="+" or input=="-"){
            string name;
            cin>>name;
            if(input=="+"){
                bst.insert(name);
            }
            else bst.pop(name);
        }
    }


    return 0;
}
