#include "cards.hpp"
#include "counting.hpp"
#include "display.hpp"
#include <iostream>
#include <string>
/*
報告標題：Blackjack – Counting Cards
科系 : 資管系
年班 : 二甲
學號 : C108134127
姓名 : 黃紫旋
*/

int main(){
    cards t;
    string * pokers;
    pokers = t.get_cards(); //生成6副牌

    counting k;
    int* counts;
    counts = k.card_counting(pokers);

    display d;
    d.display_info(pokers,counts);

}