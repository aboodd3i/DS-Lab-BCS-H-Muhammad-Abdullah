#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u){
        url=u;
        next=nullptr;
    }
};

class Browser {
    Node* top;
public:
    Browser(){
        top=nullptr;
    }
    void visit(string u){ 
        Node* n=new Node(u);
        n->next=top;
        top=n;
        cout<<"Visited: "<<u<<endl;
    }
    void back() { 
        if(!top){
            cout<<"No prev pages"<<endl;
            return;
        }
        cout<<"Back from: "<<top->url<<endl;
        Node* t=top; top=top->next;
        delete t; 
    }
    void current(){
        if(top) cout<<"Current: "<<top->url<<endl;
        else cout<<"No current page"<<endl;
    }
    void show() { 
        if(!top) { cout<<"History empty"<<endl; return; }
        Node* t=top; cout<<"History:\n"; 
        while(t) { cout<<t->url<<endl; t=t->next; } 
    }
    ~Browser(){
        while(top) back();
    }
};

int main() {
    Browser b;
    b.visit("google.com"); b.visit("wikipedia.org");
    b.visit("github.com"); b.visit("youtube.com");
    b.current(); b.show();
    b.back(); b.current();
    b.back(); b.current();
    b.show();
    return 0;
}

