#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
struct Node
{
   char symbol;
   int freq;
   Node *next;
   Node *left ;
   Node *right ;
   Node(char symbol, int freq){
	   this->next = NULL;
	   this->left = NULL;
	   this->right = NULL;
	   this->symbol = symbol ;
	   this->freq = freq ;
   }
};
void addNode(char symbol, Node **root){
	Node *node = new Node (symbol,1);
	node->next = *root;
	*root = node ;
}

void calculateFreq(char symbol,Node **root){
	bool check =false;
	Node *head = *root;
	while (head!=NULL)
	{
		if (head->symbol==symbol){
			head->freq++;
			check = true ;
			break ;
		}
		head=head->next;
	}
	if (!check){
		addNode(symbol,root);
	}
}
void readFreq(string fileName,Node **root){
	ifstream inFile ;
	inFile.open(fileName);
	string str ;
	while (getline(inFile,str))
	{
		for (int i= 0 ; i <str.length();i++){
			calculateFreq(str[i],root);
		}
		
	}
	inFile.close();
	
}
void sort(Node **root){
	Node *head ;
	bool check = false;
	while (!check){
		head = *root ;
		bool b =true;
		while(head!=NULL){
			if (head->next !=NULL && head->freq > (head->next)->freq){
				swap(head->freq,head->next->freq);
				swap(head->symbol,head->next->symbol);
				swap(head->left,head->next->left);
				swap(head->right,head->next->right);
				b=false;
			}

			head=head->next;
		}
		check = b ;
	}
}
Node *huffmanTree(Node *root){
	Node *head = new Node (root->symbol,root->freq);
	Node *node =head;
	while (root->next!=NULL)
	{	
		node->next = new Node(root->next->symbol,root->next->freq);
		root=root->next;
		node =node->next;
	}
	
	while (head->next!=NULL){
		Node *tmp = new Node('\0',0) ;
		tmp->freq = head->freq + head->next->freq ;
		tmp->left = head ;
		tmp->right = head->next;
		tmp->next = head->next->next;
		head=tmp;
		sort(&head);
	}
	return head ;

}
void print(Node *root){
	if (root == NULL) return ;
	cout << root->freq; 
	if (root->left==NULL) cout <<" "<< root->symbol;
	cout <<endl;
	print(root->left);
	print(root->right);
}
string encode(string str ,char symbol,Node *root){
	if (root->left == NULL ){
		if (root->symbol==symbol) return str;
		else return "";
	}
	string left = str + "0";
	string right = str + "1";
	return encode(left,symbol,root->left)+ encode(right,symbol,root->right);
	
}
void output(string fileIn,Node *root){
	ifstream inFile ;
	ofstream outFile ;
	outFile.open("encode.txt");
	inFile.open(fileIn);
	string str ;
	while (getline(inFile,str))
	{
		for (int i= 0 ; i <str.length();i++){
			outFile << encode("",str[i],root);
		}
		outFile << endl ;
		
	}
	inFile.close();
	outFile.close();
}
void HuffmanTable(Node *root,Node *huffman){
	ofstream out ;
	out.open("Bit_Code.txt");
	while (root!=NULL){
		out << "/"<< root->symbol<<"/ "<<encode("",root->symbol,huffman) <<endl;
		root = root->next;
	}
	out.close();
}
void run(){
	Node *root = NULL;
	readFreq("test.txt",&root);
	sort(&root);
	Node *huffman = huffmanTree(root);
	HuffmanTable(root,huffman);
	output("test.txt",huffman);
}

int main(){
	run();
	return 0;
}


