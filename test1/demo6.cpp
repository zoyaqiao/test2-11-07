#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class SearchTree {
private:
    TreeNode* _root;
    bool first_flag = false;
public:
    // insert node
    TreeNode* Insert_node(TreeNode* node, int& val) {
        if (nullptr == node) {
            node = new TreeNode(val);
        }
        if (!first_flag) {
            _root = node;
            first_flag = true; 
            return node;
        }
        if (val < _root -> val) {
            find_insert_node() ;
        }
    }

    TreeNode* find_insert_node(int& val) {
        if (_root -> left == nullptr && _root->right == nullptr) {

        }
        TreeNode* fast = _root;
        TreeNode* slow = _root;
        while (nullptr == fast) {
            if (val < fast -> val) {
                fast = fast -> left;
            } else if (val > fast -> val) {
                fast = fast -> right;
            } else {
                break;
            }
        }


    }


};