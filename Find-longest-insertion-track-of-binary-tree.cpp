//~~~~~~~~~~~~~~~~~~
#include <iostream>    
using namespace std;
//~~~~~~~~~~~~~~~~~~
struct Node{
  int _id,
    _data;
  Node *_left, *_right;
};
//==============================================
void insert_into_bst(int,Node* &, int&);
Node* build_bst();
Node* get_p2_long_track(Node*);
void set_pointer(Node*, Node* &, int&, int&, int&);
void print_track(Node*);
void print_tree (Node*);
//==============================================
int main(){//input: 17 2 28 1 4 14 10 29/ press controll D to end input
 
 Node *p2_long = NULL, *root = NULL;
 
 root = build_bst();

 p2_long = get_p2_long_track(root);
 
 cout << "the actual tree (in order):" <<endl; 
 print_tree(root);
 
 print_track(p2_long);
 
 
  return 0;
}
//==========================================================
void print_tree(Node* root){

if(root){
	print_tree( root ->_left);
	cout << "insertion number: "<< root -> _id << " ";
	cout<< " data: "<< root-> _data <<endl;
	print_tree( root ->_right);
  }
}
//==========================================================
void print_track(Node* root){

cout <<endl << "this is the first longest track found: "<<endl;

while(root){
	
	cout<< "insertion number: "<< root ->_id <<" "
	    << " data: "<< root-> _data <<endl;
   
   if( root -> _left && root -> _left -> _id - root -> _id ==1)
   
     root = root ->_left; 
	
	else
	  root = root ->_right; 
   }
    cout<<endl;
}	
//==========================================================
Node *build_bst() {
 
 struct Node *root = NULL; 
 int num ,counter = 0;

 cin >> num;
 
 while (!cin.eof()) {
    
    counter++;
	insert_into_bst(num, root, counter);
	cin >> num ;
	
}
 return root ;
}
//==========================================================
void insert_into_bst(int num,  Node *&root, int &counter) {
 
 if (root == NULL) { 
	root = new Node ;
 
	root -> _data = num ;
	
	root -> _id = counter; 
	
	root -> _left = root -> _right = NULL ;
 }
 
 else if (num <= root -> _data)
	 
	insert_into_bst(num, root->_left, counter);
 
	else
	    insert_into_bst(num, root->_right, counter); 
}
//==========================================================
Node* get_p2_long_track(Node* root){

Node *p2_long_track = NULL;

int length = -1, curr_length = 1, son_id = 0;

set_pointer(root, p2_long_track, son_id, curr_length, length);

  return p2_long_track;
}
//==========================================================
void set_pointer(Node* root, Node* &p2_long_track, int& son_id, int& curr_length, int& length){

  int L_length, R_length;
  
  if(!root) 
    {
	 curr_length=0;
	 return;
    }
 
  set_pointer( root-> _left, p2_long_track, son_id, L_length, length);
    
  set_pointer( root-> _right,p2_long_track, son_id, R_length, length);
  
  curr_length = max(L_length, R_length);
    
  if(son_id - root -> _id == 1)
     curr_length ++;
    
    else
      curr_length = 0;
  
  if(curr_length > length)
    {
     length = curr_length;
     p2_long_track = root;
    }
  
  son_id = root -> _id;
}
//==========================================================
