from operator import eq


# https://www.geeksforgeeks.org/printing-longest-common-subsequence/
def longets_common_subsequence(seq0, seq1, cmp_fn=eq):
    return _longets_common_subsequence(seq0, seq1, len(seq0), len(seq1), cmp_fn=cmp_fn) 


def _longets_common_subsequence(seq0, seq1, i0, i1, cmp_fn):
    # Dynamic programming implementation of LCS problem 
    L = [[0 for _ in range(i1 + 1)]
         for _ in range(i0 + 1)] 
  
    # Following steps build L[i0+1][i1+1] in bottom up fashion. Note 
    # that L[i][j] contains length of LCS of seq0[0..i-1] and seq1[0..j-1]  
    for i in range(i0 + 1): 
        for j in range(i1 + 1): 
            if i == 0 or j == 0: 
                L[i][j] = 0
            elif cmp_fn(seq0[i - 1], seq1[j - 1]): 
                L[i][j] = L[i - 1][j - 1] + 1
            else: 
                L[i][j] = max(L[i - 1][j],
                              L[i][j - 1]) 
  
    # Following code is used to collect LCS 
    index = L[i0][i1] 
  
    # Create a character array to store the lcs sequence 
    lcs = [None] * (index + 1) 
    lcs[index] = None 
  
    # Start from the right-most-bottom-most corner and 
    # one by one store characters in lcs[] 
    i = i0 
    j = i1 
    while i > 0 and j > 0: 
        # If current item in seq0[] and seq1 are same, then 
        # current character is part of LCS 
        if cmp_fn(seq0[i - 1], seq1[j - 1]): 
            lcs[index - 1] = (seq0[i - 1], seq1[j - 1])
            i -= 1
            j -= 1
            index -= 1
  
        # If not same, then find the larger of two and 
        # go in the direction of larger value 
        elif L[i - 1][j] > L[i][j - 1]: 
            i -= 1
        else: 
            j -= 1
  
    return [x for x in lcs if x is not None]
 
