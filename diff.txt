130d129
<
205d203
<
283d280
<
285d281
<
327a324
>
354a352,353
>
>
359,360c358,363
< int chooseSide(bool side, char times){//flip
<       /*if(side){
---
>
>
>
>
> int chooseSide(bool side, char times){
>       if(side){
373c376
<       }*/
---
>       }
394c397
<       //cout<<"++++++"<<side<<endl;
---
>
397,399c400
<       while(1){
<
<               cout << " 對方想要移動第幾列第幾行的棋子 ? 移動到第幾列第幾行 ? " << endl;
---
>       cout << " 你(對方)想要移動我方第幾列第幾行的棋子 ? 移動到第幾列第幾行 ? " << endl;
402,433d402
<               //如果不對就不交換
<       if(side==0){
<               if(buffer[rowOfMe][columnOfMe]=='A'){
<                       if(buffer[rowOfNext][columnOfNext]=='X'||buffer[rowOfNext][columnOfNext]=='Y'||buffer[rowOfNext][columnOfNext]=='+'){
<                               swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
<                               buffer[rowOfMe][columnOfMe]='+';
<                               break;
<                       }
<               }
<               if(buffer[rowOfMe][columnOfMe]=='B'){
<                       if(buffer[rowOfNext][columnOfNext]=='Z'||buffer[rowOfNext][columnOfNext]=='Y'||buffer[rowOfNext][columnOfNext]=='+'){
<                               swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
<                               buffer[rowOfMe][columnOfMe]='+';
<                               break;
<                       }
<               }
<               if(buffer[rowOfMe][columnOfMe]=='C'){
<                       if(buffer[rowOfNext][columnOfNext]=='X'||buffer[rowOfNext][columnOfNext]=='Z'||buffer[rowOfNext][columnOfNext]=='+'){
<                               swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
<                               buffer[rowOfMe][columnOfMe]='+';
<                               break;
<                       }
<               }
<               else {
<                       cout<<"error!!輸入格式錯誤請重新輸入!!"<<endl;
<                       break;
<               }
<               }
<               //**********************************************************************************
<       if(side==1){
<               if(buffer[rowOfMe][columnOfMe]=='X'){
<                       if(buffer[rowOfNext][columnOfNext]=='A'||buffer[rowOfNext][columnOfNext]=='B'||buffer[rowOfNext][columnOfNext]=='+'){
436,460d404
<                               break;
<                       }
<               }
<               if(buffer[rowOfMe][columnOfMe]=='Y'){
<                       if(buffer[rowOfNext][columnOfNext]=='B'||buffer[rowOfNext][columnOfNext]=='C'||buffer[rowOfNext][columnOfNext]=='+'){
<                               swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
<                               buffer[rowOfMe][columnOfMe]='+';
<                               break;
<                       }
<               }
<               if(buffer[rowOfMe][columnOfMe]=='Z'){
<                       if(buffer[rowOfNext][columnOfNext]=='C'||buffer[rowOfNext][columnOfNext]=='A'||buffer[rowOfNext][columnOfNext]=='+'){
<                               swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
<                               buffer[rowOfMe][columnOfMe]='+';
<                               break;
<                       }
<               }
<               else {
<                       cout<<"error!!重新輸入!!"<<endl;
<               }
<       }
<               //swap(buffer[rowOfMe][columnOfMe],buffer[rowOfNext][columnOfNext]);
<               //buffer[rowOfMe][columnOfMe]='+';
<
<       }
463d406
<
