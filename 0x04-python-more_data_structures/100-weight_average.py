#!/usr/bin/python3
def weight_average(my_list=[]):
    if not my_list:
        return 0
    sum_scores = sum(weight * score for score, weight in my_list)
    sum_weights = sum(weight for _, weight in my_list)
    return sum_scores / sum_weights if sum_weights else 0
