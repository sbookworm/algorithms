#!/bin/env python
# -*- coding: utf-8 -*-

def calc_similar(u, v):
    count = 0
    for i in u:
        if i in v:
            count += 1
    return count


# recommon u by v
def recommend(u, v):
    rec_lst = []
    u_lst = user_dict[u]
    v_lst = user_dict[v]
    for i in v_lst:
        if i not in u_lst:
            rec_lst.append(i)

    return rec_lst

#item_category = {}
"""
with open("../tianchi_fresh_comp_train_item.csv", 'r') as item:
    title = item.readline()
    while 1:
        l = item.readline()
        if not l:
            break
        l = l.strip()
        d = l.split(",")
        item_category[d[0]] = d[2]
"""

user_dict = {}
with open("../tianchi_fresh_comp_train_user.csv", 'r') as user:
    title = user.readline()
    while 1:
        l = user.readline()
        if not l:
            break
        l = l.strip()
        d = l.split(",")
        uid = d[0]
        iid = d[1]
        bhvr = d[2]
        if bhvr > 1:
            user_dict.setdefault(uid, [])
            user_dict[uid].append(iid)


user_similar = {}
for u in user_dict.keys():
    user_similar.setdefault(u, {})
    for v in user_dict.keys():
        if u == v:
            continue
        user_similar[u].setdefault(v, 0)
        user_similar[u][v] = calc_similar(user_dict[u], user_dict[v])

for u in user_similar.keys():
    max_u = 0
    sim_u = u
    for v in user_similar[u].keys():
        if u == v:
            continue
        if user_similar[u][v] > max_u:
            max_u = user_similar[u][v]
            sim_u = v
    if max_u == 0:
        continue
    
    lst = recommend(u, max_u)
    for  i in lst:
        print "%s,%s" % (u, lst[i])
