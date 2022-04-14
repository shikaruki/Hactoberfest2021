# -*- coding: utf-8 -*-
"""
Created on Mon Jul  5 15:26:30 2021

@author: lucid
"""

def ordenacao_selecao(seq):
    for i in range(0,len(seq)):
        j=i
        while j<len(seq):
            if seq[j]<seq[i]:
                t=seq[i]
                seq[i],seq[j]=seq[j],t
            j+=1
            
    return seq
print(ordenacao_selecao(seq))