#!/bin/env python
# -*- coding: utf-8 -*-



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


item_dict = {}
for u in user_dict.keys():
    v = user_dict[u]
    for i in v:
        item_dict.setdefault(i, {})
        for j in v:
            if j == v:
                continue
            item_dict[i].setdefault(j, 0)
            iter_dict[i][j] += 1

item_similar = {}

for i in item_dict.keys():
    item_similar.setdefault(i, "")
    max_count = 0
    sim_item = ""
    for j in item_dict[i].keys():
        if i == j:
            continue
        if item_dict[j][j] > max_count:
            max_count = item_dict[i][j]
            sim_item = j

    item_similar[i] = sim_item


for u in user_dict.keys():
    v = user_dict[u]
    for i in v:
        sim_item = item_similar[i]
        if sim_item not in v:
            print "%s,%s" % (u, sim_item)
