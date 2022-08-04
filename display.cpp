#include "display.hpp"
#include <string>
#include <iostream>
#include <windows.h>
#include <stdio.h>
/*
報告標題：Blackjack – Counting Cards
科系 : 資管系
年班 : 二甲
學號 : C108134127
姓名 : 黃紫旋
*/


/*
將要輸出的資料先預存起來
每次抓取90字元輸出 >> 清空 >> 再往下1字元後的90字元輸出 >> 以此類推
*/

// Poker  Points  Counts  Category 1  Category 2  Category 3

string padding(string str, int length, int option) { //填充空白 補齊長度
    int padding_length = length - str.size();
    string ret = "";

    for(int i = 0; i < padding_length; i++)
        ret = ret + " ";
    
    if(option == 0) // option0 塞前面  option1 塞後面
        return ret + str;
    else 
        return str + ret;
}

void display::display_info(string* pokers , int* counts){

    int point=0 ,Category1=0, Category2=0 ,Category3=0;
    char tmp1[100000] = "";
    char tmp2[100000] = "";

    for(int i = 0 ; i < 312 ; i ++){
        if(i == 0){
            point = counts[i] - 0;
        }else{
            point = counts[i] - counts[i-1];
        }

        if(point == 1){
            Category1 ++;
        }else if(point ==0){
            Category2 ++;
        }else if(point == -1){
            Category3 ++;
        }
        
        sprintf(tmp1, "%s%-15s%-15s%-15s%-15s%-15s%-15s", tmp1, "Poker", "Points", "Counts", "Category 1", "Category 2", "Category 3");
        sprintf(tmp2, "%s%-15s%-15d%-15d%-15d%-15d%-15d", tmp2, pokers[i].c_str(), point, counts[i], Category1, Category2, Category3);

    }
    string msg1(tmp1); //char* to string
    string msg2(tmp2);

    int run_length = 90;
    for(int i = 0; i < run_length; i++) { //初始90字元
        string run1 = padding(msg1.substr(0, i), run_length, 0); //padding(要輸出的字串, 要跑馬的範圍 , option0 = 插入空白到字串前方)
        string run2 = padding(msg2.substr(0, i), run_length, 0);
        cout << run1 << endl << run2;
        Sleep(100);
        system("cls"); //清空
    }

    for(int i = 1; i + run_length < msg1.size(); i++) { //往下
        string run1 = msg1.substr(i, run_length);
        string run2 = msg2.substr(i, run_length);
        cout << run1 << endl << run2;
        Sleep(100);
        system("cls");
    }

    for(int i = msg1.size() - run_length; i < msg1.size(); i++) { //最後結尾
        string run1 = padding(msg1.substr(i, msg1.size()-i), run_length, 1);
        string run2 = padding(msg2.substr(i, msg1.size()-i), run_length, 1);
        cout << run1 << endl << run2 ;
        Sleep(1);
        system("cls");
    }
}