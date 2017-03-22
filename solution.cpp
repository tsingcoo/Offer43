//
// Created by 王青龙 on 2017/3/21.
//

#include <vector>
#include <iostream>
#include <cmath>
#include "solution.h"

const int maxValue = 6;

void Solution::PrintProbability(int number) {
    if (number < 1) {
        return;
    }
    std::vector<std::vector<int>> pProbabilities(2, std::vector<int>(1 + maxValue * number, 0));

    int flag = 0;
    for (int i = 0; i <= maxValue; ++i) {
        pProbabilities[flag][i] = 1;
    }

    for (int j = 2; j <= number; ++j) {
        flag = 1 - flag;

        for (int i = j * 1; i <= j * maxValue; ++i) {
            pProbabilities[flag][i] = 0;//这里应该已经为了把上上轮残留的数据清除
            for (int k = i - 1; (k >= i - 6) && (k >= j - 1); --k) {
                pProbabilities[flag][i] += pProbabilities[1 - flag][k];
            }
        }
    }

    int total = std::pow(maxValue, number);
    for (int i = number * 1; i <= number * maxValue; ++i) {
        std::cout<<i<<": "<<(double)pProbabilities[flag][i]/total<<std::endl;
    }

}
