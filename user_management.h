
#ifndef USER_MANAGEMENT_GUARD__H
#define USER_MANAGEMENT_GUARD__H

#include<stdio.h>

void register1();         // the user register
int facelogin();          //the user login
int adlogin();           //the administrator login 
int match(int account_user,char password_user[100]);   //ensure account
int admatch(int account_user,char password_user[100]);	//ensure account
void coremain();    //the function of mainmenu
void mainmenu();    //the interface of mainmenu

#endif
