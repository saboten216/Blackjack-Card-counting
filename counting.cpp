#include "counting.hpp"
#include <iostream>
#include <string>
using namespace std;
/*
報告標題：Blackjack – Counting Cards
科系 : 資管系
年班 : 二甲
學號 : C108134127
姓名 : 黃紫旋
*/
int* counting::card_counting(string* pokers){

    int* counts = new int[312];
    string temp;
    int result = 0;
    for(int i = 0 ; i < 312 ; i ++){
        
        counts[i] = 0;
        temp = pokers[i];

        if (temp[1] =='2'|| temp[1] == '3' || temp[1] == '4' || temp[1] == '5' || temp[1] == '6' ){
            result = result + 1;
        }else if(temp[1] =='7'|| temp[1] == '8' || temp[1] == '9'){
            result = result + 0;
        }else if(temp[1] =='1'|| temp[1] == 'J' || temp[1] == 'Q'|| temp[1] == 'K'|| temp[1] == 'A' ){
            result = result - 1;
        }
        counts[i] = result;
    }
    return counts;


    

}