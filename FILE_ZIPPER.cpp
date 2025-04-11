#include<bits/stdc++.h>
using namespace std;
//input:->
//first line give the string to compress str
//then give a string of 0's and 1's to decode it s

//structure of node
struct node{
    //character value
    char data;
    //frequency of that character
    int fre;
    //it's left and right child
    node* right,* left;
    //constructor
    node(char data,int fre){
        this->data=data;
        this->fre=fre;
        this->right=NULL;
        this->left=NULL;
    }
};

//functor for making priority queue minimum
struct compare{
    bool operator()(node* a,node* b){
        return a->fre>b->fre;
    }
};

//printing the prefixfree code of all the characters
void print_code(node* root,string str){
    //base case
    //if a character print the code
    if(root->data != '$'){
        cout<<root->data<<"-->"<<str<<endl;
        return;
    }
    //on left str+0
    print_code(root->left,str+"0");
    //on right str+1
    print_code(root->right,str+"1");
    return;
}

//decode string of 0's and 1's into actual stirng of character
void decode_string(node* root,string str){
    node*temp=root;
    for(int i=0;i<str.length();i++){
        //if it is 1 goto right
        if(str[i]=='1'){
            temp=temp->right;
            //if character is not $ print character
            if(temp->data != '$'){
                cout<<temp->data;
                temp=root;
            }
        }
        //else go to the left for 0
        else{
            temp=temp->left;
            //print data if not equal to $
            if(temp->data != '$'){
                cout<<temp->data;
                temp=root;
            }
        }
    }
    return;
}

//huffman code to make the tree
void HuffmanCoding(vector<pair<char,int> >&freq,string str){
    //making priority queue
    priority_queue<node*,vector<node*>,compare> p_q;
    //inserting all the values
    for(int i=0;i<freq.size();i++){
        p_q.push(new node(freq[i].first,freq[i].second));
    }
    //if size is one the only node is the root node
    while(p_q.size()!=1){
        //pop the top 2 least frequency character
        node* n1=p_q.top();
        p_q.pop();
        node* n2=p_q.top();
        p_q.pop();
        //make a newnode with this two nodes as child of it and freq=freq1+freq2
        node* newnode=new node('$',n1->fre+n2->fre);
        newnode->left=n1;
        newnode->right=n2;
        //push the newnode with new freq into priority queue
        p_q.push(newnode);
    }
    //the only node is root node
    node* root=p_q.top();
    //print code for each character
    print_code(root,"");
    //decode the given string in actual characters
    decode_string(root,str);
}

//decode the string into characters and there frequency
vector<pair<char, int> > decode(string str,unordered_map<char,int>& freq){
    int length=str.length();
    vector<pair<char ,int> >ans;
    //increasing the freq of each character present in it using map
    for(int i=0;i<length;i++){
       freq[str[i]]++;
    }
    //store this value in an array
    unordered_map<char,int>::iterator it;
    for(it=freq.begin();it!=freq.end();it++){
        ans.push_back(make_pair(it->first,it->second));
    }
    //return array
    return ans;
}

int main(){
    string str;
    cin>>str;
    string to_decode;
    cin>>to_decode;
    //map
    unordered_map<char,int>freq;
    //array 
    vector<pair<char,int> >frequency;
    frequency=decode(str,freq);
    //calling huffman codeing function
    HuffmanCoding(frequency,to_decode);
    return 0;
}