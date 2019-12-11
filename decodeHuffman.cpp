#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
struct Node
{
   char symbol;
   Node *left ;
   Node *right ;
   Node(){
	   this->left = NULL;
	   this->right = NULL;
	   this->symbol = '\0' ;
   }
};
void huffmanTree(Node *root,string str){
	for (int i=4;i<str.length();i++){
		if (str[i]=='0'){
			if (root->left == NULL) root->left =new Node();
			root=root->left;
		}
		else{
			if (root->right == NULL) root->right =new Node();
			root=root->right;
		}
	}
	root->symbol = str[1];
}
void print(Node *root){
	if (root == NULL) return ;
	if (root->left==NULL) cout <<" "<< root->symbol<<endl;
	print(root->left);
	print(root->right);
}
void readFile(Node *root){
	ifstream inFile ;
	inFile.open("Bit_Code.txt");
	string str ;
	while (getline(inFile,str))
	{
		huffmanTree(root,str);
		
	}
	inFile.close();
}
string decode(string str,Node *root){
	Node *tmp = root ;
	string s = "";
	for (int i=0 ; i < str.length();i++){
		if (str[i]=='0') tmp = tmp->left ;
		else tmp = tmp->right;
		if (tmp->left == NULL){
			s += tmp->symbol;
			tmp=root;
		}
	}
	//outFile.close();
	return s ;
}
void decodeFile( Node *root){
	ifstream inFile ;
	inFile.open("encode.txt");
	ofstream outFile ;
	outFile.open("decode.txt");
	string str ;
	while (getline(inFile,str))
	{
		outFile << decode(str,root)<<endl;
		
	}
	inFile.close();
	outFile.close();
}
int main(){
	Node *root = new Node();
	readFile(root);
	decodeFile(root);
	return 0;
}