#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>

#define N 6
using namespace std;

int countForWhile = 0;
char buffer[N][N] = {0};
int score[N][N] = {0};
int n=rand()%4;

void rule(char arr[][N]);
int caculate(char arr[][N], bool side);
int chooseSide(bool side, char times);
void takeAction(bool side, int times);
void printBuffer();


/*struct Node { 
    int key; 
    vector<Node *>child; 
};*/
   
 // Utility function to create a new tree node 
/*Node *newNode(int key) { 
    Node *temp = new Node; 
    temp->key = key; 
    return temp; 
}*/

//void LevelOrderTraversal(Node * root);

void print_Buffer(){
	rule(buffer);
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
	//rule(buffer);
}

/*void createNode(){
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
}*/

int chooseTeam(){
	bool team;
	cout << " 選擇哪一方 ? "<< endl << endl;
	cin >> team;
	if(team){
		cout << " 你為ABC ! "<< endl << endl;
		//takeAction(team)*2;
		
	}
	else{
		cout << " 你為XYZ ! "<< endl << endl;
		//takeAction();
	}
	return team;
}



int values[10] = {0};
int otherSideRow[10] = {0}; 
int otherSideColumn[10] = {0};
int m = 0;
int countForMe = 0, countForOther = 0;
const int MAX = 1000; 
const int MIN = -1000; 
  
// Returns optimal value for 
// current player(Initially called 
// for root and maximizer) 
int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta) { 
    // Terminating condition. i.e  
    // leaf node is reached 
    if (depth == 3) 
        return values[nodeIndex]; 
  
    if (maximizingPlayer) { 
        int best = MIN; 
  
        // Recur for left and  
        // right children 
        for (int i = 0; i < 2; i++) { 
              
            int val = minimax(depth + 1, nodeIndex * 2 + i,  
                              false, values, alpha, beta); 
            best = max(best, val); 
            alpha = max(alpha, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        
        return best; 
    } 
    else{ 
        int best = MAX; 
        // Recur for left and 
        // right children 
        for (int i = 0; i < 2; i++) 
        { 
            int val = minimax(depth + 1, nodeIndex * 2 + i, 
                              true, values, alpha, beta); 
            best = min(best, val); 
            beta = min(beta, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        
        return best; 
    } 
} 

int me = 0, other = 0;
void check(bool side){
	if(side){
		for(int i = 1; i < N-1; i++){
			for(int k = 1; k< N-1; k++){
				if(buffer[i][k]=='X'||buffer[i][k]=='Y'||buffer[i][k]=='Z')
					other++;
				if(buffer[i][k]=='A'||buffer[i][k]=='B'||buffer[i][k]=='C')
					me++;
			}
		}
		
	}
	else{
		for(int i = 1; i < N-1; i++){
			for(int k = 1; k< N-1; k++){
				if(buffer[i][k]=='X'||buffer[i][k]=='Y'||buffer[i][k]=='Z')
					me++;
				if(buffer[i][k]=='A'||buffer[i][k]=='B'||buffer[i][k]=='C')
					other++;
			}
		}
		
	}
} 


bool legal(bool side, int rowOfMe, int columnOfMe, int rowOfNext,int columnOfNext){
		if(side == 1){
			if(buffer[rowOfMe][columnOfMe]=='A'){
				if(buffer[rowOfNext][columnOfNext]=='X'||buffer[rowOfNext][columnOfNext]=='Y'||buffer[rowOfNext][columnOfNext]=='+'){
					return true;
				}
				else {
					return false;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='B'){
				if(buffer[rowOfNext][columnOfNext]=='Z'||buffer[rowOfNext][columnOfNext]=='Y'||buffer[rowOfNext][columnOfNext]=='+'){
					return true;
				}
				else {
					return false;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='C'){
				if(buffer[rowOfNext][columnOfNext]=='X'||buffer[rowOfNext][columnOfNext]=='Z'||buffer[rowOfNext][columnOfNext]=='+'){
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		//**********************************************************************************
		else if (side == 0){
			if(buffer[rowOfMe][columnOfMe]=='X'){
				if(buffer[rowOfNext][columnOfNext]=='A'||buffer[rowOfNext][columnOfNext]=='B'||buffer[rowOfNext][columnOfNext]=='+'){
					return true;
				}
				else {
					return false;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='Y'){
				if(buffer[rowOfNext][columnOfNext]=='B'||buffer[rowOfNext][columnOfNext]=='C'||buffer[rowOfNext][columnOfNext]=='+'){
					return true;
				}	
				else {
					return false;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='Z'){
				if(buffer[rowOfNext][columnOfNext]=='C'||buffer[rowOfNext][columnOfNext]=='A'||buffer[rowOfNext][columnOfNext]=='+'){
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		
		}
}
void autoplay(bool side, int times){
	//cout<<" 我方有 : " << me << " 個 "<< endl;
	//cout<<" 敵方有 : " << other << " 個 "<< endl;
	cout << endl << endl << " 目前整體評分為 : ";
    cout << caculate(buffer, side) << endl;
	int u=6;
	while(u--){int k=6;while(k--)score[u][k]=0;}
	
	rule(buffer);
	printScore(side*(-1)); //判斷每一次主動方的分數 
	int rowOfMe,columnOfMe,rowOfNext,columnOfNext;
	cout << " Autoplay..... " << endl;
	int changed=0;
	
	int i = 0, j = 0, k = 0, tmpI = 0, tmpJ = 0;
	int maximum = -10;//min取最小值 , countForMe是計算對我方有多少子 countForOther是計算對方有多少子 
	 
	for(i = 1; i < N-1; i++){
		//if(changed==1)break;
		for(j = 1; j < N-1; j++){
			//if(changed==1)break;
			if(side){
				for(i = 1; i < N-1; i++){
					//if(changed==1)break;
					for(j = 1; j < N-1; j++){
						if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C'){
							countForMe++;
						}
					}
				}
				for(i = 1; i < N-1; i++){
					for(j = 1; j < N-1; j++){
						if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C'){
							if(maximum < score[i][j]){
								maximum = score[i][j];	
								
								tmpI = i;
								tmpJ = j;
								                  	
							}
						}
					}
				}
					//changed = 1 ;
				k = 0;//k歸零,因為要計算對方有幾子 
				for(i = 1; i < N-1; i++){
					//if(changed==1)break;
					for(j = 1; j < N-1; j++){
						
						if(buffer[i][j]=='X'||buffer[i][j]=='Y'||buffer[i][j]=='Z' || buffer[i][j]=='+'){
					 		countForOther++;
						}
					
						if(buffer[i][j]=='X'||buffer[i][j]=='Y'||buffer[i][j]=='Z' || buffer[i][j]=='+'){	
							while(k < countForOther){
								values[k] = score[i][j];
								otherSideRow[m]= i;
								otherSideColumn[m]= j;
								k++;
								m++;
							}
							
						}
					
					}
				}	
			
				int max = -10;
				//sort(values, values + countForOther);
				int ti[4]={tmpI, tmpI+1, tmpI-1, tmpI};
				int tj[4]={tmpJ+1, tmpJ, tmpJ, tmpJ-1};
				int otherSideRow = 0;
				int otherSideColumn = 0;
				
				for(k=0;k<4;k++){
					if(buffer[ti[k]][tj[k]] != '0'){
						if(max < score[ti[k]][tj[k]]){
							max = score[ti[k]][tj[k]];
							otherSideRow = ti[k];
							otherSideColumn = tj[k];
						}
					}
					
									
				}
		
				
			
					int changed=0;
					for(int i = 1; i < N-1; i++){
					if(changed==1)break;
						for(int j=1; j<N-1; j++){
							if(side){
								if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C'){
									int ti[4]={i+1, i, i-1, i};
									int tj[4]={j, j+1, j, j-1};
									for(int k=0;k<4;k++){
										if(changed==1)break; 
										if(buffer[ti[k]][tj[k]]!=0){
						//A>>XY, B>>YZ, C>>ZX; X>>AB, Y>>BC, Z>>CA
											switch(buffer[i][j]){
												case 'A': 
													for(int l=0;l<4;l++){
														if(buffer[ti[l]][tj[l]] == 'X' || buffer[ti[l]][tj[l]] == 'Y'){
															swap(buffer[ti[l]][tj[l]],buffer[i][j]);
															buffer[i][j]='+'; 
															changed=1;
															cout << i << "," << j << "->" << ti[l] << "," << tj[l] << endl;
															break;
														}
													}
												break;
												case 'B':
													for(int l=0;l<4;l++){
														if(buffer[ti[l]][tj[l]] == 'Z' || buffer[ti[l]][tj[l]] == 'Y'){
															swap(buffer[ti[l]][tj[l]],buffer[i][j]);
															buffer[i][j]='+'; 
															changed=1;
															cout << i << "," << j << "->" << ti[l] << "," << tj[l] << endl;
															break;
														}
													}
												break;
												case 'C':
													for(int l=0;l<4;l++){
														if(buffer[ti[l]][tj[l]] == 'X' || buffer[ti[l]][tj[l]] == 'Z'){
															swap(buffer[ti[l]][tj[l]],buffer[i][j]);
															buffer[i][j]='+'; 
															changed=1;
															cout << i << "," << j << "->" << ti[l] << "," << tj[l] << endl;
															break;
														}
													}
												break;
											}
									
										}
									}
								}
							}
						}	
					}
					if(changed==0){
						for(int i=1;i<5;i++){
							if(changed==1)break;
								for(int j=1;j<5;j++){
									if(changed==1)break;
										if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C'){
											int ti[4]={i+1, i, i, i-1};
											int tj[4]={j, j+1, j-1, j};
											for(int k=0;k<4;k++){
												k=k+n;
												k=k%4;
												if(buffer[ti[k]][tj[k]]=='+'){
													swap(buffer[ti[k]][tj[k]], buffer[i][j]);
													cout << i << "," << j << "->" << ti[k] << "," << tj[k] << endl;
													changed=1;
													n++;
													break;
												}
											}
										}
								}
						}
					}
				
			}
			
			else{
				for(i = 1; i < N-1; i++){
					for(j = 1; j < N-1; j++){
						score[i][j] *= -1; 
					}
				} 
				for(i = 1; i < N-1; i++){
					//if(changed==1)break;
					for(j = 1; j < N-1; j++){
						if(buffer[i][j]=='X'||buffer[i][j]=='Y'||buffer[i][j]=='Z'){
							countForMe++;
						}
					}
				}
				for(i = 1; i < N-1; i++){
					for(j = 1; j < N-1; j++){
						if(buffer[i][j]=='X'||buffer[i][j]=='Y'||buffer[i][j]=='Z'){
							if(maximum < score[i][j]){
								maximum = score[i][j];	
								
								tmpI = i;
								tmpJ = j;
								                  	
							}
						}
					}
				}
							
					
					

					//changed = 1 ;
				k = 0;//k歸零,因為要計算對方有幾子 
				for(i = 1; i < N-1; i++){
					//if(changed==1)break;
					for(j = 1; j < N-1; j++){
						
						if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C' || buffer[i][j]=='+'){
					 		countForOther++;
						}
					
						if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C' || buffer[i][j]=='+'){	
							while(k < countForOther){
								values[k] = score[i][j];
								otherSideRow[m]= i;
								otherSideColumn[m]= j;
								k++;
								m++;
							}
							
						}	
					}
				}
				
			
				int max = -10;
				//sort(values, values + countForOther);
				int ti[4]={tmpI, tmpI, tmpI+1, tmpI-1};
				int tj[4]={tmpJ-1, tmpJ+1, tmpJ, tmpJ};
				int otherSideRow = 0;
				int otherSideColumn = 0;
				bool tmp;
				for(k=0;k<4;k++){
					if(buffer[ti[k]][tj[k]] != '0'){
						if(max < score[ti[k]][tj[k]]){
							max = score[ti[k]][tj[k]];
							otherSideRow = ti[k];
							otherSideColumn = tj[k];
						}
					}
					tmp =true;				
				}
				//cout << oth0erSideRow << " " << otherSideColumn <<endl;
					if(tmp){
						swap(buffer[otherSideRow][otherSideColumn],buffer[tmpI][tmpJ]);
						buffer[tmpI][tmpJ]='+'; 	
						cout << tmpI << "," << tmpJ << "->" << otherSideRow << "," << otherSideColumn << endl;
					
						
					}
					else{
						int changed = 0 ;
					if(changed==0){
						for(int i=1;i<5;i++){
							if(changed==1)break;
								for(int j=1;j<5;j++){
									if(changed==1)break;
										if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C'){
											int ti[4]={i+1, i, i, i-1};
											int tj[4]={j, j+1, j-1, j};
											for(int k=0;k<4;k++){  //change
												k=k+n;
												k=k%4;
													if(buffer[ti[k]][tj[k]]=='+'){
													swap(buffer[ti[k]][tj[k]], buffer[i][j]);
													cout << i << "," << j << "->" << ti[k] << "," << tj[k] << endl;
													changed=1;
													n++;
													break;
												}
											}
										}
								}
						}
					}
					
						
					}
					
				
				
				
			}
		}
	}
		
	
	/*if(changed==0){
		for(int i=1;i<5;i++){
			if(changed==1)break;
			for(int j=1;j<5;j++){
				if(changed==1)break;
		if(side){
			if(buffer[i][j]=='A'||buffer[i][j]=='B'||buffer[i][j]=='C'){
			
					int ti[4]={i, i, i+1, i-1};
					int tj[4]={j+1, j-1, j, j};
					for(int k=0;k<4;k++){
					if(buffer[ti[k]][tj[k]]=='+'){
						swap(buffer[ti[k]][tj[k]], buffer[i][j]);
							cout << i << "," << j << "->" << ti[k] << "," << tj[k] << endl;
							changed=1;
							break;
					}
					}
				}
			}
		else{
			if(buffer[i][j]=='X'||buffer[i][j]=='Y'||buffer[i][j]=='Z'){
			
					int ti[4]={i, i, i+1, i-1};
					int tj[4]={j+1, j-1, j, j};
					for(int k=0;k<4;k++){
					if(buffer[ti[k]][tj[k]]=='+'){
						swap(buffer[ti[k]][tj[k]], buffer[i][j]);
							cout << i << "," << j << "->" << ti[k] << "," << tj[k] << endl;
							changed=1;
							break;
					}
					}
				}
				}
			}
		}
	}*/
	

	/*for(int k = 0; k < countForOther ; k++){
		cout << values[k] << " ";
	}*/
	cout <<"The optimal value is : "<< minimax(0, 0, true, values, MIN, MAX);

			
	m = 0;
	countForOther = 0;
	countForMe = 0;
}



void result(bool side, int me, int other){
	cout<<" The result : "<< endl;
	if(side){
		if(me > other){
			cout<<" Winner is ABC ! \n";
		}
		else
			cout<<" Winner is XYZ ! \n";
		
	}
	else{
		if(me > other){
			cout<<" Winner is ABC ! \n";
		}
		else
			cout<<" Winner is XYZ ! \n";
	}

}



int main(){
	initial();
	//cout << buffer[1][-1] << endl;
	//createNode();
    //cout << "Level order traversal Before Mirroring\n"; 
    //LevelOrderTraversal(root); 
    printBuffer();
    bool team ;
	team = chooseTeam();
	//eturn scoreteam;

	
	bool side;
	int times = 0;
	side = chooseSide(team, times);
	check(side);
	cout<<" 我方有 : " << me << " 個 "<< endl;
	cout<<" 敵方有 : " << other << " 個 "<< endl;
	while(1){
		cout<<endl;
		//cout<<" 我方有 : " << me << " 個 "<< endl;
		//cout<<" 敵方有 : " << other << " 個 "<< endl;
		
		if(me == 0 || other == 0){
		   break;
		}
		
		else{
			cout<<" times : "<< times + 1 <<endl;
			if(team){
				autoplay(side, times);
				me = 0;
				other = 0;
				check(side);	
				printBuffer();
				cout<<" 我方有 : " << me << " 個 "<< endl;
				cout<<" 敵方有 : " << other << " 個 "<< endl;
				
				takeAction(side,times);
				printBuffer();
				me = 0;
				other = 0;
				check(side);
				cout<<" 我方有 : " << me << " 個 "<< endl;
				cout<<" 敵方有 : " << other << " 個 "<< endl;
			}
			else{
				takeAction(side,times);
				printBuffer();
				me = 0;
				other = 0;
				check(side);
				cout<<" 我方有 : " << me << " 個 "<< endl;
				cout<<" 敵方有 : " << other << " 個 "<< endl;
				autoplay(side, times);
				me = 0;
				other = 0;
				check(side);
				printBuffer();
				cout<<" 我方有 : " << me << " 個 "<< endl;
				cout<<" 敵方有 : " << other << " 個 "<< endl;
			}  	
		
				
			
		}
		
		times += 2;
		if(times == 20){
			cout<<" 已到達規定10步 ! "<< endl;
		}
	}
	result(side, me, other); 
	system("PAUSE");
	return 0;
} 

int chooseSide(bool side, char times){//flip
	/*if(side){
    		if(times %2 ==0){
    			cout << " 現在輪到ABC攻 " << endl << endl;
			}
			else cout << " 現在輪到XYZ攻 " << endl << endl;
		}
	
	else{
    		if(times %2 ==1){
    			cout << " 現在輪到ABC攻 " << endl << endl;
			}
			else cout << " 現在輪到XYZ攻 " << endl << endl;
		
	}*/ 
	return side;
}

void printBuffer(){
	cout << " 目前棋況為 : " << endl;
	for(int i = 1; i < N-1; i++){
		for(int k = 1; k< N-1; k++){
			cout << buffer[i][k] << " ";
		}
		cout << endl;
	}
}



void takeAction(bool side, int times){
	cout << endl << endl << " 目前整體評分為 : ";
    cout << caculate(buffer, side) << endl;
	int u=6;
	while(u--){int k=6;while(k--)score[u][k]=0;}
	
	rule(buffer);
	//cout<<"++++++"<<side<<endl;
	printScore(side*1); //判斷每一次主動方的分數 
	int rowOfMe,columnOfMe,rowOfNext,columnOfNext;
	
	
	while(1){
		cout << " 對方想要移動第幾列第幾行的棋子 ? 移動到第幾列第幾行 ? " << endl;
		cin >> rowOfMe >> columnOfMe >> rowOfNext >> columnOfNext;
		cout << endl;
		//如果不對就不交換 
		if(side==0){
			if(buffer[rowOfMe][columnOfMe]=='A'){
				if(buffer[rowOfNext][columnOfNext]=='X'||buffer[rowOfNext][columnOfNext]=='Y'||buffer[rowOfNext][columnOfNext]=='+'){
					swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
					buffer[rowOfMe][columnOfMe]='+';
					break;	
				}
				else {
					cout<<" error 重新輸入! "<<endl;
					continue;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='B'){
				if(buffer[rowOfNext][columnOfNext]=='Z'||buffer[rowOfNext][columnOfNext]=='Y'||buffer[rowOfNext][columnOfNext]=='+'){
					swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
					buffer[rowOfMe][columnOfMe]='+';
					break;
				}
				else {
					cout<<" error 重新輸入! "<<endl;
					continue;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='C'){
				if(buffer[rowOfNext][columnOfNext]=='X'||buffer[rowOfNext][columnOfNext]=='Z'||buffer[rowOfNext][columnOfNext]=='+'){
					swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
					buffer[rowOfMe][columnOfMe]='+';
					break;
				}
				else {
					cout<<" error 重新輸入! "<<endl;
					continue;
				}
			}
			else {
				cout<<" 選到我方(空白)棋子! "<<endl;
				continue;
			}
		}
		//**********************************************************************************
		if(side==1){
			if(buffer[rowOfMe][columnOfMe]=='X'){
				if(buffer[rowOfNext][columnOfNext]=='A'||buffer[rowOfNext][columnOfNext]=='B'||buffer[rowOfNext][columnOfNext]=='+'){
					swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
					buffer[rowOfMe][columnOfMe]='+';
					break;
				}
				else {
					cout<<" error 重新輸入! "<<endl;
					continue;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='Y'){
				if(buffer[rowOfNext][columnOfNext]=='B'||buffer[rowOfNext][columnOfNext]=='C'||buffer[rowOfNext][columnOfNext]=='+'){
					swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
					buffer[rowOfMe][columnOfMe]='+';
					break;
				}	
				else {
					cout<<" error 重新輸入! "<<endl;
					continue;
				}
			}
			if(buffer[rowOfMe][columnOfMe]=='Z'){
				if(buffer[rowOfNext][columnOfNext]=='C'||buffer[rowOfNext][columnOfNext]=='A'||buffer[rowOfNext][columnOfNext]=='+'){
					swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
					buffer[rowOfMe][columnOfMe]='+';
					break;
				}
				else {
					cout<<" error 重新輸入! "<<endl;
					continue;
				}
			}
			else {
				cout<<" 選到我方(空白)棋子! "<<endl;
				continue;
			}
		
		}
		
	}
	
		//swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
		//buffer[rowOfMe][column1OfMe]='+';
} 
//A>>XY, B>>YZ, C>>ZX; X>>AB, Y>>BC, Z>>CA

void rule(char arr[][N]){  
	for(int i = 0; i < N; i++){
		for(int j = 0; j< N; j++){
		switch(arr[i][j]){
			case 'A': 
//				do{
					if(arr[i-1][j] == 'X' || arr[i-1][j] == 'Z')score[i][j] --;
					if(arr[i+1][j] == 'X' || arr[i+1][j] == 'Z')score[i][j] --;
					if(arr[i][j+1] == 'X' || arr[i][j+1] == 'Z')score[i][j] --;
					if(arr[i][j-1] == 'X' || arr[i][j-1] == 'Z')score[i][j] --; 
					
					if(arr[i-1][j] == 'Y')score[i][j] +=2;
					if(arr[i+1][j] == 'Y')score[i][j] +=2;
					if(arr[i][j+1] == 'Y')score[i][j] +=2;
					if(arr[i][j-1] == 'Y')score[i][j] +=2; 
					
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}while(countForWhile < N);
				//countForWhile = 0;
				break;
			case 'B':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'X' || arr[i-1][j] == 'Y')score[i][j] --;
					if(arr[i+1][j] == 'X' || arr[i+1][j] == 'Y')score[i][j] --;
					if(arr[i][j+1] == 'X' || arr[i][j+1] == 'Y')score[i][j] --;
					if(arr[i][j-1] == 'X' || arr[i][j-1] == 'Y')score[i][j] --; 
					
					if(arr[i-1][j] == 'Z')score[i][j] +=2;
					if(arr[i+1][j] == 'Z')score[i][j] +=2;
					if(arr[i][j+1] == 'Z')score[i][j] +=2;
					if(arr[i][j-1] == 'Z')score[i][j] +=2; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				//countForWhile = 0;
				break;
			case 'C':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'Y' || arr[i-1][j] == 'Z')score[i][j] --;
					if(arr[i+1][j] == 'Y' || arr[i+1][j] == 'Z')score[i][j] --;
					if(arr[i][j+1] == 'Y' || arr[i][j+1] == 'Z')score[i][j] --;
					if(arr[i][j-1] == 'Y' || arr[i][j-1] == 'Z')score[i][j] --; 
					
					if(arr[i-1][j] == 'X')score[i][j] +=2;
					if(arr[i+1][j] == 'X')score[i][j] +=2;
					if(arr[i][j+1] == 'X')score[i][j] +=2;
					if(arr[i][j-1] == 'X')score[i][j] +=2; 
					
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				//countForWhile = 0;
				break;
			case 'X':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'A' || arr[i-1][j] == 'C')score[i][j] --;
					if(arr[i+1][j] == 'A' || arr[i+1][j] == 'C')score[i][j] --;
					if(arr[i][j+1] == 'A' || arr[i][j+1] == 'C')score[i][j] --;
					if(arr[i][j-1] == 'A' || arr[i][j-1] == 'C')score[i][j] --; 
					
					if(arr[i-1][j] == 'B')score[i][j] +=2;
					if(arr[i+1][j] == 'B')score[i][j] +=2;
					if(arr[i][j+1] == 'B')score[i][j] +=2;
					if(arr[i][j-1] == 'B')score[i][j] +=2; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				//countForWhile = 0;
				break;
			case 'Y':
//				while(countForWhile < N){
					if(arr[i-1][j] == 'A' || arr[i-1][j] == 'B')score[i][j] --;
					if(arr[i+1][j] == 'A' || arr[i+1][j] == 'B')score[i][j] --;
					if(arr[i][j+1] == 'A' || arr[i][j+1] == 'B')score[i][j] --;
					if(arr[i][j-1] == 'A' || arr[i][j-1] == 'B')score[i][j] --; 
					
					if(arr[i-1][j] == 'C')score[i][j] +=2;
					if(arr[i+1][j] == 'C')score[i][j] +=2;
					if(arr[i][j+1] == 'C')score[i][j] +=2;
					if(arr[i][j-1] == 'C')score[i][j] +=2; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				//countForWhile = 0;
				break;
			case 'Z':
				//while(countForWhile < N){
					if(arr[i-1][j] == 'C' || arr[i-1][j] == 'B')score[i][j] --;
					if(arr[i+1][j] == 'C' || arr[i+1][j] == 'B')score[i][j] --;
					if(arr[i][j+1] == 'C' || arr[i][j+1] == 'B')score[i][j] --;
					if(arr[i][j-1] == 'C' || arr[i][j-1] == 'B')score[i][j] --; 
					
					if(arr[i-1][j] == 'A')score[i][j] +=2;
					if(arr[i+1][j] == 'A')score[i][j] +=2;
					if(arr[i][j+1] == 'A')score[i][j] +=2;
					if(arr[i][j-1] == 'A')score[i][j] +=2; 
//					else if(arr[i-1][j] == '+' || arr[i][j-1] == '+' || arr[i+1][j] == '+' || arr[i][j+1] == '+'){
//						score[i][j] += 0.5;
//				
//					}
//					else continue;
//					countForWhile++;
//				}
				//countForWhile = 0;
				break;
		}
		}
	}
	
	

	
}



/*void LevelOrderTraversal(Node * root) { 
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
} */

//map score
int caculate(char arr[][N], bool side){
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

