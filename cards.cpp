#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include "cards.hpp"
using namespace std;
/*
報告標題：Blackjack – Counting Cards
科系 : 資管系
年班 : 二甲
學號 : C108134127
姓名 : 黃紫旋
*/
string* cards::get_cards()
{
    // 建立4*13陣列 每生成一張卡 就在對應位置 +1 當卡數量等於6時 重新生成
    int card[4][13];
    int suit, num;
    // string pokers[312];
    string* pokers = new string[312];

    for (int i = 0; i < 4; i++){ // init card
        for (int j = 0; j < 13; j++){
            card[i][j] = 0;
        }
    }

    srand((unsigned)time(NULL));

    for (int k = 0; k <= 311; k++){

        bool flag = true ;
        suit = rand() % 4 ;
        num = rand() % 13;
        while(flag){
            if(card[suit][num] != 6){
                card[suit][num] = card[suit][num] + 1;
                flag = false;
            }else{
                suit = rand() % 4 ;
                num = rand() % 13 ;
            }
        }


        switch (suit){ // S黑桃 H愛心 D方塊 C梅花
        case 0:
            pokers[k] = "S" ;
            break;
        case 1:
            pokers[k] = "H";
            break;
        case 2:
            pokers[k] = "D"; 
            break;
        case 3:
            pokers[k] = "C"; 
            break;
        }
        switch (num){ 
        case 0:
            pokers[k] = pokers[k] + "A"; 
            break;
        case 1:
            pokers[k] = pokers[k] + "2"; 
            break;
        case 2:
            pokers[k] = pokers[k] + "3"; 
            break;
        case 3:
            pokers[k] = pokers[k] + "4"; 
            break;
        case 4:
            pokers[k] = pokers[k] + "5"; 
            break;
        case 5:
            pokers[k] = pokers[k] + "6"; 
            break;
        case 6:
            pokers[k] = pokers[k] + "7"; 
            break;
        case 7:
            pokers[k] = pokers[k] + "8"; 
            break;
        case 8:
            pokers[k] = pokers[k] + "9"; 
            break;
        case 9:
            pokers[k] = pokers[k] + "10"; 
            break;
        case 10:
            pokers[k] = pokers[k] + "J"; 
            break;
        case 11:
            pokers[k] = pokers[k] + "Q"; 
            break;
        case 12:
            pokers[k] = pokers[k] + "K"; 
            break;
        }
    }
    return pokers;
}
