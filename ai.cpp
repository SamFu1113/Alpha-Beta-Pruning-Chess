#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <fstream>
#include <algorithm>

#define N 6
using namespace std;

int countForWhile = 0;
char buffer[N][N] = {0};
int score[N][N] = {0};

void rule(char arr[][N], char i, char j);
int caculate(char arr[][N], char i, char j, bool side);
void chooseSide(bool side);
void takeAction(bool side, int times);

struct Node { 
    int key; 
    vector<Node *>child; 
}; 
   
 // Utility function to create a new tree node 
Node *newNode(int key) { 
    Node *temp = new Node; 
    temp->key = key; 
    return temp; 
} 

void LevelOrderTraversal(Node * root);

void print_Buffer(){
	for(int i = 0; i < N; i++){
		for(int k = 0; k< N; k++){
			 rule(buffer,i,k);
			 
		}
		
	}
}

void printScore(bool team){
	int z=-1;
	if(team)z=1;
	cout << " --------------------------------- " << endl;
	for(int i = 1; i < N-1; i++){
		for(int k = 1; k < N-1; k++){
			if(buffer[i][k]=='X'||buffer[i][k]=='Y'||buffer[i][k]=='Z'){
				score[i][k]*= -1;
			}		
			cout << setw(3) << score[i][k]*z << " ";
		}
		cout << endl;
	}

	cout << " --------------------------------- " << endl << endl;
}

void initial(){
	
	fstream file;
	file.open("board.txt",ios::in);
	if(!file){
		cout << " can't open file ! " << endl;
	}
	else{
		for(int i = 0; i < N; i++)
  			for(int k = 0; k< N; k++) file >> buffer[i][k];
		file.close();
	}
	print_Buffer();
	
	cout<< endl;
	for(int i = 0; i < N; i++){
		for(int k = 0; k< N; k++){
			 rule(buffer,i,k);
			 
		}
		
	}
}

void createNode(){
	Node *root = newNode(0);
	(root->child).push_back(newNode(0)); 
    (root->child).push_back(newNode(0)); 
    (root->child).push_back(newNode(0)); 
    (root->child[0]->child).push_back(newNode(77)); 
    (root->child[0]->child).push_back(newNode(88)); 
    (root->child[0]->child).push_back(newNode(60));
    (root->child[1]->child).push_back(newNode(40)); 
    (root->child[1]->child).push_back(newNode(32)); 
    (root->child[1]->child).push_back(newNode(56));
    (root->child[2]->child).push_back(newNode(12)); 
    (root->child[2]->child).push_back(newNode(29)); 
    (root->child[2]->child).push_back(newNode(94)); 
}

int chooseTeam(){
	bool team;
	cout << " 選擇哪一方 ? "<< endl << endl;
	cin >> team;
	if(team){
		cout << " 你為ABC ! "<< endl << endl;
		chooseSide(team);
		//takeAction(team)*2;
		
	}
	else{
		cout << " 你為XYZ ! "<< endl << endl;
		chooseSide(team);
		//takeAction();
	}
	return team;
}





int main(){
	initial();
	//cout << buffer[1][-1] << endl;
	createNode();
    //cout << "Level order traversal Before Mirroring\n"; 
    //LevelOrderTraversal(root); 
    
    bool team ;
	team = chooseTeam();
	//eturn scoreteam;
                  
	system("PAUSE");
	return 0;
} 





void chooseSide(bool side){
	char times = 0;
	if(side){
		while(1){
    		if(times %2 ==0){
    			cout << " 現在輪到ABC攻 " << endl << endl;
			}
			else cout << " 現在輪到XYZ攻 " << endl << endl;
			takeAction(side,times);
    		times++;
		}
	}
	else{
		while(1){
    		if(times %2 ==1){
    			cout << " 現在輪到ABC攻 " << endl << endl;
			}
			else cout << " 現在輪到XYZ攻 " << endl << endl;
			takeAction(side,times);
    		times++;
		}
		
	}
}

void takeAction(bool side, int times){
	cout << " 目前棋況為 : " << endl;
	for(int i = 1; i < N-1; i++){
		for(int k = 1; k< N-1; k++){
			cout << buffer[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl << endl << " 目前整體評分為 : ";
    cout << caculate(buffer, 6, 6 , side) << endl;
	int u=6;
	while(u--){int k=6;while(k--)score[u][k]=0;}
		for(int i = 0; i < N; i++){
			for(int k = 0; k< N; k++){
			 	rule(buffer,i,k);
			 
			}
		}
	
	printScore(side*(times%2)); //判斷每一次主動方的分數 
	int rowOfMe,columnOfMe,rowOfNext,columnOfNext;
	cout << " 你(對方)想要移動我方第幾列第幾行的棋子 ? 移動到第幾列第幾行 ? " << endl;
	cin >> rowOfMe >> columnOfMe >> rowOfNext >> columnOfNext;
	cout << endl;
	swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
	buffer[rowOfMe][columnOfMe]='+';
} 
//A>>XY, B>>YZ, C>>ZX; X>>AB, Y>>BC, Z>>CA
void rule(char arr[][N], char i, char j){  
		switch(arr[i][j]){
			case 'A': 
//				do{
					if(arr[i-1][j] == 'X' || arr[i-1][j] == 'Z')score[i][j] --;
					if(arr[i+1][j] == 'X' || arr[i+1][j] == 'Z')score[i][j] --;
					if(arr[i][j+1] == 'X' || arr[i][j+1] == 'Z')score[i][j] --;
					if(arr[i][j-1] == 'X' || arr[i][j-1] == 'Z')score[i][j] --; 
					
					if(arr[i-1][j] == 'Y')score[i][j] ++;
					if(arr[i+1][j] == 'Y')score[i][j] ++;
					if(arr[i][j+1] == 'Y')score[i][j] ++;
					if(arr[i][j-1] == 'Y')score[i][j] ++; 
					
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}while(countForWhile < N);
				countForWhile = 0;
				break;
			case 'B':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'X' || arr[i-1][j] == 'Y')score[i][j] --;
					if(arr[i+1][j] == 'X' || arr[i+1][j] == 'Y')score[i][j] --;
					if(arr[i][j+1] == 'X' || arr[i][j+1] == 'Y')score[i][j] --;
					if(arr[i][j-1] == 'X' || arr[i][j-1] == 'Y')score[i][j] --; 
					
					if(arr[i-1][j] == 'Z')score[i][j] ++;
					if(arr[i+1][j] == 'Z')score[i][j] ++;
					if(arr[i][j+1] == 'Z')score[i][j] ++;
					if(arr[i][j-1] == 'Z')score[i][j] ++; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				countForWhile = 0;
				break;
			case 'C':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'Y' || arr[i-1][j] == 'Z')score[i][j] --;
					if(arr[i+1][j] == 'Y' || arr[i+1][j] == 'Z')score[i][j] --;
					if(arr[i][j+1] == 'Y' || arr[i][j+1] == 'Z')score[i][j] --;
					if(arr[i][j-1] == 'Y' || arr[i][j-1] == 'Z')score[i][j] --; 
					
					if(arr[i-1][j] == 'X')score[i][j] ++;
					if(arr[i+1][j] == 'X')score[i][j] ++;
					if(arr[i][j+1] == 'X')score[i][j] ++;
					if(arr[i][j-1] == 'X')score[i][j] ++; 
					
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				countForWhile = 0;
				break;
			case 'X':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'A' || arr[i-1][j] == 'C')score[i][j] --;
					if(arr[i+1][j] == 'A' || arr[i+1][j] == 'C')score[i][j] --;
					if(arr[i][j+1] == 'A' || arr[i][j+1] == 'C')score[i][j] --;
					if(arr[i][j-1] == 'A' || arr[i][j-1] == 'C')score[i][j] --; 
					
					if(arr[i-1][j] == 'B')score[i][j] ++;
					if(arr[i+1][j] == 'B')score[i][j] ++;
					if(arr[i][j+1] == 'B')score[i][j] ++;
					if(arr[i][j-1] == 'B')score[i][j] ++; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				countForWhile = 0;
				break;
			case 'Y':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'A' || arr[i-1][j] == 'B')score[i][j] --;
					if(arr[i+1][j] == 'A' || arr[i+1][j] == 'B')score[i][j] --;
					if(arr[i][j+1] == 'A' || arr[i][j+1] == 'B')score[i][j] --;
					if(arr[i][j-1] == 'A' || arr[i][j-1] == 'B')score[i][j] --; 
					
					if(arr[i-1][j] == 'C')score[i][j] ++;
					if(arr[i+1][j] == 'C')score[i][j] ++;
					if(arr[i][j+1] == 'C')score[i][j] ++;
					if(arr[i][j-1] == 'C')score[i][j] ++; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				countForWhile = 0;
				break;
			case 'Z':
				//while(countForWhile < N){
					if(arr[i-1][j] == 'C' || arr[i-1][j] == 'B')score[i][j] --;
					if(arr[i+1][j] == 'C' || arr[i+1][j] == 'B')score[i][j] --;
					if(arr[i][j+1] == 'C' || arr[i][j+1] == 'B')score[i][j] --;
					if(arr[i][j-1] == 'C' || arr[i][j-1] == 'B')score[i][j] --; 
					
					if(arr[i-1][j] == 'A')score[i][j] ++;
					if(arr[i+1][j] == 'A')score[i][j] ++;
					if(arr[i][j+1] == 'A')score[i][j] ++;
					if(arr[i][j-1] == 'A')score[i][j] ++; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				countForWhile = 0;
				break;
		}
	
}

void LevelOrderTraversal(Node * root) { 
    if (root==NULL) 
        return; 
   
    // Standard level order traversal code 
    // using queue 
    queue<Node *> q;  // Create a queue 
    q.push(root); // Enqueue root  
    while (!q.empty()) { 
        int n = q.size(); 
  
        // If this node has children 
        while (n > 0) { 
            // Dequeue an item from queue and print it 
            Node * p = q.front(); 
            q.pop(); 
            cout << p->key << " "; 
   
            // Enqueue all children of the dequeued item 
            for (int i=0; i<p->child.size(); i++) 
                q.push(p->child[i]); 
            n--; 
        } 
   
        cout << endl; // Print new line between two levels 
    } 
} 

//map score
int caculate(char arr[][N], char i, char j, bool side){
	int a = 0, b = 0, c = 0, x = 0, y = 0, z = 0;
	for(int i = 1; i < N -1 ;i++){
		for(int j = 1; j < N -1 ;j++){
			switch(arr[i][j]){
				case'A':
					a++;
					break;
				case'B':
					b++;
					break;
				case'C':
					c++;
					break;
				case'X':
					x++;
					break;
				case'Y':
					y++;
					break;
				case'Z':
					z++;
					break;
			}
			
		}
	}
	 
	//cout << a << " " << b << " " << c << " " << x << " " << y << " " << z << " " << endl;
	if(side){
		int scoreA = (a - x)*1 + (a - y)*2;
		int scoreB = (b - y)*1 + (b - z)*2;
		int scoreC = (c - z)*1 + (c - x)*2;
		int score = scoreA + scoreB + scoreC;
		return score;
	}
	else{
		int scoreX = (x - a)*1 + (x - b)*2;
		int scoreY = (y - b)*1 + (y - c)*2;
		int scoreZ = (z - c)*1 + (z - a)*2;
		int score = scoreX + scoreY + scoreZ;
		return score;
		
	} 
}
