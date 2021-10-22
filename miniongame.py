def vowel(s):
    w=s[0:1]
    if(w=='A' or w=='E' or w=='I' or w=='O' or w=='U'):
        return True        
def minion_game(string):
    s_s,s_k=0,0
    for i in range(len(string)):
        if(vowel(s[i])==True):
            s_k+=len(string)-i
        else:
            s_s+=len(string)-i
    if(s_k>s_s):
            print("Kevin %d"%(s_k))
    elif(s_s>s_k):
            print("Stuart %d"%(s_s))
    elif(s_s==s_k):
            print("Draw")

    

if __name__ == '__main__':
    s = input()
    minion_game(s)