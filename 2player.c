#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
char board[3][3];
void resetboard();
void printboard();
int checkfreespace();
void player1move();
void player2move();
char checkwinner();
void printwinner(char win);
const char player1 = 'X';
const char player2 = 'O';
int main(){
    char winner = ' ';
    resetboard();
    //printboard();
    while(winner == ' ' && checkfreespace() != 0){
        printboard();
        player1move();
        winner = checkwinner();
        if(winner != ' ' || checkfreespace() == 0 )
        {
            break;
        }
        printboard();
        player2move();
        winner = checkwinner();
        if(winner != ' ' || checkfreespace() == 0 )
        {
            break;
        }
    }
    printboard();   // Print the final board state
    printwinner(winner);  // Announce the winner

    return 0;
}
void printboard(){
    printf("  %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("-------------\n");
    printf("  %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("-------------\n");
    printf("  %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}
void resetboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ' ';
        }
    }
}
int checkfreespace(){
    int free = 9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != ' '){
                free--;
            }
        }
    }
    return free;
}
void player1move(){
    int x;
    int y;
    printf("\nPlayer1 move:");
    do{
     printf("\nEnter the row(1-3):");
     scanf("%d",&x);
     printf("\nEnter column(1-3):");
     scanf("%d",&y);
     x--;
     y--;
     if(board[x][y] != ' '){
        printf("\nWrong move");
     }
     else{
        board[x][y] = player1;
        break;
     }
    }while(board[x][y] != ' ');
}
void player2move(){
    int x;
    int y;
    printf("\nPlayer2 move:");
    do{
     printf("\nEnter the row(1-3):");
     scanf("%d",&x);
     printf("\nEnter column(1-3):");
     scanf("%d",&y);
     x--;
     y--;
     if(board[x][y] != ' '){
        printf("\nWrong move");
     }
     else{
        board[x][y] = player2;
        break;
     }
    }while(board[x][y] != ' ');
}
char checkwinner(){
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
        if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }
    //row
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //column
        for(int i=0;i<3;i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    return ' ';
}
void printwinner(char win){
     if(win == ' '){
        printf("\nIt is a draw.");
     }
     else if(win == player2){
        printf("\nPlayer2 win!");
     }
     else{
        printf("\nPlayer1 win");
     }
}
