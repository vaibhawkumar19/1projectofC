#include<stdio.h>
#include<string.h>
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
void setMatrix(int A[][4]);
void showMatrix(int A[][4]);
int checkWin(int a[][4]);
int readKey();
int shiftLeft(int A[][4]);
int shiftRight(int A[][4]);
int shiftUp(int A[][4]);
int shiftDown(int A[][4]);
void red();
void yellow();
void blue();
void reset();
int main(){
char str[30];
int a[4][4],count=1,i,j,move=20,p;
printf("\n\n\n");
printf("enter your name:- ");
fgets(str,30,stdin);
p=strlen(str);
str[p-1]='\0';
system("cls");
red();
printf("    Game Name:-           Number Shifting Game\n\n");
blue();
printf("                          RULE OF THIS GAME\n\n");
printf("1.You can move only 1 step at a time with the arrow key\n");
printf("Move Up   : by Up arrow Key\n");

printf("Move Down : by Up arrow Key\n");
printf("Move Left : by Up arrow Key\n");
printf("Move Right: by Up arrow Key\n");
printf("2.You can move numbers at an empty position only\n\n");
printf("3.For each valid move : your total number of moves will decrease by 1.\n");
printf("Winning Situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
red();
printf("           Winning Situation:");

for(i=0;i<4;i++){
    for(j=0;j<4;j++){
            if(count!=16)
        a[i][j]=count++;
    else
        a[3][3]=0;
    }
}
showMatrix(a);   // show matrix winning situation
printf("\n\n");
yellow();
printf("5.You can exit the game at any time by pressing 'E' or e\n");
printf("So Try to win in minimum no of move\n\n");
printf("               Happy gaming , Good Luck\n\n");
printf("Enter any key to start.....   ");
reset();
getch();
system("cls");
setMatrix(a);
while(move){
        printf("\n\n\n");
        printf("  Hello ");
        blue();
        printf("%s , ",str);
        reset();
        printf("Move Remaining: :%d\n",move);
       showMatrix(a);
        if(checkWin(a)){
            printf("\nCongratulation you win in %d moves",5-move);
            printf("\nPress any key to exit...");
            getch();
            exit(0);
        }
        switch(readKey(a))
        {
        case ESC:
            exit(0);
        case UP:
            if(!shiftUp(a))
                move++;
            break;
        case DOWN:
            if(!shiftDown(a))
                move++;
            break;
        case LEFT:
            if(!shiftLeft(a))
                move++;
            break;
       case RIGHT:
            if(!shiftRight(a))
                move++;
            break;
       default:
            move++;
        }
        system("cls");
        move--;
    }
    if(move==0){
            red();
        printf("\n\n  you are lose try again press any e or E and for exit press any key");
        char ch1=getch();
        if(ch1=='e'|| ch1=='E'){
                system("cls");
                reset();
            main();
        }

        getch();
}
}
int checkWin(int a[][4])
{
    int i,j,k=0;
     for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
                k<15?k++:(k=0);
            if(a[i][j]!=k)
                return(0);
        }
     }
     return(1);

}

void setMatrix(int A[][4]){
    int pool[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int maxIndex=14,index,i,j;
    srand(time(NULL));

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(maxIndex>=0){
                index=rand()%(maxIndex+1);
                A[i][j]=pool[index];
                pool[index]=pool[maxIndex];
                maxIndex--;
            }
            else
                A[i][j]=0;

        }
    }
}
void showMatrix(int A[][4]){
 int i,j;
 printf("\n------------------------\n|");
 for(i=0;i<=3;i++){
    for(j=0;j<=3;j++){
        if(A[i][j]!=0)
            printf(" %-2d | ",A[i][j]);
        else
            printf("    | ");
    }
    printf("\n");
    if(i!=3)
        printf("|");

 }
  printf("------------------------\n");
}
int readKey(){
    int ch;
    ch=getch();
    switch(ch)
    {
    case 27:
        return(ESC);
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return(5);

    }
}
int shiftLeft(int A[][4]){
  int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==3)
        return(0);
    else{
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
    }

}
int shiftRight(int A[][4]){
    int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==0)
        return(0);
    else{
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
    }

}
int shiftUp(int A[][4]){
      int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==3)
        return(0);
    else{
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
    }

}
int shiftDown(int A[][4]){
          int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==0)
        return(0);
    else{
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
    }

}
void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

void blue(){
printf("\033[034m");
}
