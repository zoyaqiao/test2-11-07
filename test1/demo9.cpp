#include <iostream>
#include <stack>

using namespace std;

struct demo1 {
    int val;
    demo1* next;
};

void test1() {
    demo1* _root = new demo1;

    demo1* node = _root;
    node->val = 0;
    ++node->val;
    ++node->val;
    // cout << "node->val " << node->val << endl;
}

class StackOfPlates {
public:
    struct stack_node {
        stack<int> node;
        stack_node* next;
        int node_size;
        int capacity;
        bool is_full;
    };
    StackOfPlates(int cap) {
        // cout << "StackOfPlates" << endl;
        _root = new stack_node();
        _root->capacity = cap;
        _root->node_size = 0;
        _root->next = nullptr;
        _root->is_full = false;
        _cap = cap;
    }
    
    void push(int val) {
        // cout << "push";
        stack_node* Nnode = _root;
        // find node
        while (Nnode->is_full && Nnode->next != nullptr) {
            Nnode = Nnode->next;
        }
        if (Nnode->node_size < Nnode->capacity) {
            Nnode->node.push(val);
            Nnode->node_size = Nnode->node_size + 1;
            // cout << "_root -> node_size"<<_root -> node_size <<endl;
            // cout << "Nnode->node_size " << Nnode->node_size << endl;
        }
        if (Nnode->node_size == Nnode->capacity) {
            Nnode->next = new stack_node();
            Nnode->is_full = true;

            Nnode = Nnode->next;
            Nnode->capacity = _cap;
            Nnode->node_size = 0;
            Nnode->next = nullptr;
            Nnode->is_full = false;
        }
        
        
    }
    
    int pop() {
        // cout << "_root -> node_size"<<_root -> node_size <<endl;
        stack_node* Nnode = _root;
        if(Nnode != nullptr && Nnode->node_size == 0) {
            return -1;
        }
        // find node
        while (Nnode->is_full && Nnode->next != nullptr) {
            // cout << "while";
            if (Nnode->next->node_size != 0) {
                Nnode = Nnode->next;
            } else {
                break;
            }
        }
        int res;
        // cout << "pop1";
        if (Nnode->node_size != 0) {
            res = (Nnode->node).top();
            Nnode->node.pop();
            -- Nnode->node_size;
        }
        if (Nnode->node_size == 0) {
            if (Nnode->next != nullptr) {
                delete Nnode->next;
            }
            delete Nnode;
        }
        // cout << "pop12";
        return res;
    }
    
    int popAt(int index) {
        // cout << "_root -> node_size"<<_root -> node_size <<endl;
        stack_node* Nnode = _root;
        for (int i = 1; i < index; ++i) {
            if (Nnode) {
                Nnode = Nnode->next;
            } else {
                return -1;
            }
        }
        int res;
        if (Nnode->node_size != 0) {
            res = Nnode->node.top();
            Nnode->node.pop();
            --Nnode->node_size;
        } else {
            return -1;
        }
         if (Nnode->node_size == 0 && Nnode != _root) {
            if (Nnode->next != nullptr) {
                delete Nnode->next;
            }
            delete Nnode;
        }
        // cout << "popat";
        return res;

    }
private:
    stack_node* _root;
    int _cap;
};

void test2() {
    StackOfPlates obj(5);
    obj.push(1);
    obj.push(2);
    cout << obj.popAt(1);
    cout << obj.pop();
    
    cout << obj.pop();
    

}

int main() {
    test2();
    return 0;
}