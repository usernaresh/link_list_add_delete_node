#include <iostream>


#define Debug 0
using namespace std;

class node{
    int data;
    node *next_node;
    public:
    node(int value): data(value){this->next_node = nullptr;} 
    node(): data(0){this->next_node = nullptr;} 
    //node(node& node): data(node.data), next_node(node->next_node()){}  
    int get_nodedata() { return this->data;}
    void set_nodedata(int vl) {this->data =vl;}
    node* get_nextnode(){return this->next_node;}
    void set_nextnode(node* nd) {this->next_node = nd;}
};

class link_list{
    node* head_node;
    node* end_node;
    int total_nodes;
    public:
        link_list(): total_nodes(0), head_node(nullptr), end_node(nullptr){}
        void add_node_end(int);
        void delete_node(int index);
        int get_totalnode() { return total_nodes; }
        node* get_headnode(){ return head_node;}
        void set_headnode(node* nd) {head_node = nd;}
        node* get_endnode() { return end_node;}
        void set_endnode(node* nd) {end_node = nd;}
        
        void print_linklist(){
            cout << "total nodes: " << total_nodes << endl; 
            if(total_nodes >=1){
                node* tnd = get_headnode();
                int i=1;
                do{
                    cout << " value of " << i << " node is: " << tnd->get_nodedata() << endl;
                    i++;
                    tnd = tnd->get_nextnode();
                }while(i<= total_nodes);
            }
        } 
};

void link_list::add_node_end(int value){
    
    node* nd = new node(value);
    #if Debug
        cout << " new node address: " << nd  << endl;
    #endif
    if (get_totalnode() >= 1){
        node* tnd = end_node;
        tnd->set_nextnode(nd);
        //end_node->set_nextnode(nd);
        nd->set_nextnode(nullptr);
        total_nodes++;
        set_endnode(nd);        
        #if Debug
            cout << " head node address: " << head_node  << endl;
            cout << " end node address: " << end_node  << endl;
        #endif     
        
    }
    else{
        set_headnode(nd);
        set_endnode(nd);
        #if Debug
            cout << " new head node address: " << head_node  << endl;
            cout << " new end node address: " << end_node  << endl;
        #endif
        nd->set_nextnode(nullptr);
        nd->set_nodedata(value);
        #if Debug
            cout << " new nodes next node: " << nd->get_nextnode()  << endl;
        #endif
        
        total_nodes=1;
    }
}

void link_list :: delete_node(int index){
    node* tnd = head_node;
    node* prv_node;
    node* nxt_node; 
    
    for (int i = 0; i< index; i++){
        prv_node = tnd;
        tnd = tnd->get_nextnode();
        nxt_node = tnd->get_nextnode();
    }
    prv_node->set_nextnode(nxt_node);
    total_nodes--;
    delete tnd;
}

int main()
{
    cout<<"Link List " << endl;

    link_list l1;
    l1.add_node_end(1);
    l1.add_node_end(2);
    l1.add_node_end(7);
    l1.add_node_end(9);
    l1.add_node_end(11);
    l1.add_node_end(13);
    l1.print_linklist();
    l1.delete_node(3);
    l1.delete_node(4);
    l1.print_linklist();
    return 0;
}
