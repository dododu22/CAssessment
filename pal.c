
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub) {
	//1. We create the output variable with an initial value.
	int res = 0;

	//2. We assign num to a random value in the desired range
	res = (rand() % (ub - lb)) + lb;

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char res = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = ' ';

	while (finish == False) {
		dummy_char = getchar();
		if (dummy_char == '\n')
			finish = True;
	}

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// initialise_array
//--------------------------------------------------
void initialise_array(int a[6], int num) {
for ( int i=(6-1) ; i>=0 ; i-- )
{
	a[i] = num % 10;
	num /= 10;
}
}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {
	boolean b = True;
    for(int i=0;i<3;i++){
        if(a[i]!=a[5-i]){
            b=False;
        }
    }
    if(b==True)
        printf("-------------------------------\n------- SOLVED! ---------\n-------------------------------\n");
	return b;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	char res = ' ';
    res= my_get_char();
	return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c){
    if(c=='a'){
        if(**p_p==0){

        }
        else{
            (**p_p)--;
            *p_nm+=1;
        }
    }
    else if(c=='d'){
        if(**p_p==5){
        }
        else{
            (**p_p)++;
            *p_nm +=1;

        }
    }
    else if(c=='w'){
        if(a[**p_p]==9){
        }
        else{
            a[**p_p]+=1;
            *p_nm+=1;

        }
    }
    else if(c=='x'){
        if(a[**p_p]==0){
        }
        else{
            a[**p_p]-=1;
            *p_nm+=1;

        }
    }
    else{

    }
}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {

    printf("-----Game Status-----\n");
    printf("Number={ ");
    for(int i=0;i<6;i++){
        printf("%d ",a[i]);
    }
    printf("}\n         ");
    for(int i=0;i<6;i++){
        if(i==*p){
            printf("^ ");
            break;
        }
        else{
            printf("  ");
        }
    }
    printf("\nNum mov=%d\n--------------------\n",nm);
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {
    int a[6];
    initialise_array(a, pal_num);
    boolean win = False;
    int k=0;
    int* p=&k;
    int nm=0;
    print_status(a, p, nm);
    boolean endGame=False;
    while(endGame!=True){
        while(win!=True){
            printf("NEW MOVEMENT: Enter a valid command by keyword:\n Valid commands: a d w x\n");
            char c=ask_for_command();
            process_movement(a,&p,&nm,c);
            if(is_pal(a)==True){
                break;
            }
            for(int i=0;i<100;i++)
                printf("\n");
            print_status(a,p, nm);

        }
        boolean resp=False;
        while(resp!=True){
        printf("New game? [Y/n]\n");
        char endG=my_get_char();
            if(endG=='Y' || endG=='y'){
                for(int i=0;i<6;i++)
                    a[i]=gen_num(0,9);
                    k=0;
                    nm=0;
                    print_status(a, p, nm);
                    resp=True;
            }
            else if(endG=='N' || endG=='n'){
                endGame=True;
                resp=True;
            }
            else{
                    int res=rand()%3;
                    if(res==0)
                        printf("Oh! I didn't expected that...\n");
                    else if(res==1)
                        printf("let's try again...\n");
                    else
                        printf("please be more specific!\n");
            }
        }
    }
}

