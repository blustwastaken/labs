import random

def sort(A):
    if len(A)<=1: 
        return A
    else:
        q = random.choice(A)
        leftA = [n for n in A if n < q]
        middleA = [q] * A.count(q)
        rightA = [n for n in A if n > q]
        return sort(leftA) + middleA + sort(rightA)