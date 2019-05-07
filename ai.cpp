//test
#include <iostream>
#include <iomanip>
#include <fstream>

#define N 6
using namespace std;

int countForWhile = 0;
float score[N][N] = {0};
void rule(char arr[][N], char i, char j);

struct Node 
{ 
    int key; 
    vector<Node *>child; 
}; 
   
 // Utility function to create a new tree node 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    return temp; 
} 

int main(){
	fstream file;
	char buffer[N][N];
	file.open("board.txt",ios::in);
	if(!file){
		cout << " can't open file ! " << endl;
	}
	else{
		for(int i = 0; i < N; i++)
  			for(int k = 0; k< N; k++) file >> buffer[i][k];
		file.close();
	}
	
	for(int i = 1; i < N-1; i++){
		for(int k = 1; k< N-1; k++){
			cout << buffer[i][k] << " ";
		}
		cout << endl;
	}
	

	
	cout<< endl;
	for(int i = 0; i < N; i++){
		for(int k = 0; k< N; k++){
			 rule(buffer,i,k);
			 
		}
		
	}

	for(int i = 1; i < N-1; i++){
		for(int k = 1; k < N-1; k++){
			if(buffer[i][k]=='X'||buffer[i][k]=='Y'||buffer[i][k]=='Z'){
				score[i][k]*= -1;
			}
			cout << setw(3) << score[i][k] << " ";
		}
		cout << endl;
	}
	
	//cout << buffer[1][-1] << endl;
	int row, column = 0;
	int count = 0;
	/*while(count < 20){
		cin >> row >> column;
		if(!((row >=0 && row <N) && (column >=0 && column <N ))){
			count -- ;
			continue;
		}
		else{
			count++;
		}
		
	}*/
	
  			
	system("PAUSE");
	return 0;
} 

void rule(char arr[][N], char i, char j){
	

		switch(arr[i][j]){
			case 'A': //A>>XY ZX>>A 
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
			default: break;
				
		
	}
	
}
/*void moveOrEat(char **arr, char i, char j, char c){
	switch(arr[i][j]){
				case 'X':
					if()
					if(arr[i-1][j] == 'A'){
						arr[i][j] = 'A';
						arr[i-1][j] = '+'	
					}
					arr[i+1][j] == 'A' arr[i][j-1] == 'A' arr[i][j+1] == 'A'
	}	
}*/
