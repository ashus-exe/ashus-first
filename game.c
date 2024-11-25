#include <stdio.h>
#include<stdlib.h>

#define nl printf("\n");
#define sbo printf("[");
#define sbc printf("]");
#define Row 3
#define Col 3

int moves[10]={0};

void printbox(char mat[][3]);
void printsamplebox();
void printsamplebox2();
void updatebox1( char mat[][3], int r, int c);
void updatebox2( char mat[][3], int r, int c);
int checkwin(char mat[][3]);
int ifinvalid(int n);
int ifinvalid2(int n);
int checkDraw(char mat[][3]);
int checkstep(char mat[][3], int aa);
int checkstep2(char mat[][3], int r, int c);



int main() {

int ans, x =0, aa, step ;
int r=3, c=3;
int r1, c1, r2, c2;
int moves[10]={0};

char box[3][3] = {'.','.','.','.','.','.','.','.','.'};
char p1[20], p2[20];

puts("Enter Name of Player 1 : ");
fgets(p1, 20, stdin );
puts("Enter Name of Player 2 : ");
fgets(p2, 20, stdin );

nl;
printsamplebox2();
nl;
printbox(box);


for(int m=1; m<=5; m++){
    
    again1 :
    nl;
    printf("-> %s",p1);
    
    printf("Enter step : ");
    scanf("%d", &step);

     r1 = (step-1)/3+1;
     c1 = (step-1)%3+1;

    if(ifinvalid2(step) == 1){
        printf("Slected position is out of range !!\nChoose again");
        goto again1;
    }
    
    
    //  printf("enter row : ");
    // scanf("%d",&r1);
    // if(ifinvalid(r1) == 1){
    //     break;
    // }
    //  printf("enter col : ");
    // scanf("%d",&c1);
    // if(ifinvalid(c1) == 1){
    //     break;
    // }

    if(checkstep2(box, r1, c1)== 1){
        printf("Chossed option already occupied. \nChoose again\n");
        goto again1;
    }

    aa = ((r1-1)*3)+(c1);
    moves[x] = aa; 
    x++;

    updatebox1(box, r1, c1);
    printbox(box);

    ans = checkwin(box);
    if(ans == 1){
        nl;
        printf("🔹Player 1 win !!!\n");
        nl;
        goto end;
    }

    if(m==5){
        if(checkDraw(box) == 1){
            printf("\n🔹GAME DRAW !!!\n\n");
            break;
        }
    }

    again2 :
    nl;
    printf("-> %s",p2);

    printf("Enter step : ");
    scanf("%d", &step);

     r2 = (step-1)/3+1;
     c2 = (step-1)%3+1;

    if(ifinvalid2(step) == 1){
        printf("Slected position is out of range !!\nChoose again");
        goto again2;
    }

    //  printf("enter row : ");
    // scanf("%d",&r2);
    // if(ifinvalid(r2) == 1){
    //     break;
    // }
    //  printf("enter col : ");
    // scanf("%d",&c2);
    // if(ifinvalid(c2) == 1){
    //     break;
    // }

    if(checkstep2(box, r2, c2)== 1){
        printf("Chossed option already occupied. \nChoose again\n");
        goto again2;
    }
    
    aa = ((r2-1)*3)+(c2);
    moves[x] = aa; 
    x++;

    updatebox2(box, r2, c2);
    printbox(box);

    ans = checkwin(box);
    if(ans == 2){
        nl;
        printf("🔹Player 2 win !!!\n");
        nl;
        goto end;
    }
}

    end :

    return 0;
}



void printbox(char mat[][3]){

    for(int i=0; i<3; i++){
        for(int j =0; j<3; j++){
            sbo;
            printf(" %c ",mat[i][j]);
            sbc;
        }
        printf("\n");
    }
}


void printsamplebox(){
    int mat[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sbo;
            printf("%d,%d",i+1, j+1);
            sbc;
        }
        nl;
    }
}

void printsamplebox2(){
    int mat[3][3], a=1;
    printf("Choose position as follow : - \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sbo;
            printf(" %d ",a++);
            sbc;
        }
        nl;
    }
}


void updatebox1( char mat[][3], int r, int c){
    mat[r-1][c-1] = 'X';
}

void updatebox2( char mat[][3], int r, int c){
    mat[r-1][c-1] = 'O';
}



int checkwin(char arr[][3]){
    int j = 0;

    for(int i =0; i<3; i++){

            //condition 1 : row
        if(arr[i][j]+arr[i][j+1]+arr[i][j+2] == 264)
            return 1;
        if(arr[i][j]+arr[i][j+1]+arr[i][j+2] == 237)
            return 2;
        
            //condition 2 : col
        if(arr[j][i]+arr[j+1][i]+arr[j+2][i] == 264)
            return 1;
        if(arr[j][i]+arr[j+1][i]+arr[j+2][i] == 237)
            return 2;
    }

        //condition 3 : diagonal 1
    if(arr[j][j]+arr[j+1][j+1]+arr[j+2][j+2] == 264)
        return 1;
    if(arr[j][j]+arr[j+1][j+1]+arr[j+2][j+2] == 264)
        return 2;

        //condition 4 : diagonal 2
    if(arr[j][j+2]+arr[j+1][j+1]+arr[j+2][j] == 264)
        return 1;
    if(arr[j][j+2]+arr[j+1][j+1]+arr[j+2][j] == 237)
        return 2;

    return 0;

}



int ifinvalid(int n){
    if(n>3 || n<1){
        printf("Invalid choice, ");
        printf("Choose correct row/col\n");
        return 1; 
    }
    return 0;
}


int ifinvalid2(int n){
    if(n>9 || n<1){
        printf("Invalid choice, ");
        printf("Choose correct row/col\n");
        return 1; 
    }
    return 0;
}



int checkDraw(char mat[][3]) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == '.') {
                return 0; 
            }
        }
    }
    return 1; 
}


int checkstep2(char mat[][3], int r, int c){
    if(mat[r-1][c-1] == 'X' || mat[r-1][c-1] == 'O'){
        return 1;
    }
    return 0;
}


int checkstep(char mat[][3], int aa){
    for(int i=0; i<10; i++){
        if(moves[i] == aa)
        return 1;
    }
    return 0;
}
