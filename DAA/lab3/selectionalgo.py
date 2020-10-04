def selectkthrankele(seqlist,k):
    sublistof5s = [seqlist[j:j+5] for j in range(0,len(seqlist),5)]
    allmedianlist = [sorted(sublistof5)[len(sublistof5)//2] for sublistof5 in sublistof5s]
    if len(allmedianlist)<=5:
        appxmedian = sorted(allmedianlist)[len(allmedianlist)//2]
    else:
        appxmedian = selectkthrankele(allmedianlist,len(allmedianlist)//2)

    leftseqlist = [ele for ele in seqlist if ele<appxmedian]
    rightseqlist = [ele for ele in seqlist if ele>appxmedian]
    mid = len(leftseqlist)
    if k==mid :
        return appxmedian
    elif k>mid :
        return selectkthrankele(rightseqlist,k-mid-1)
    else:
        return selectkthrankele(leftseqlist,k)

seqlist = [1,7,2,6,9,16,13,11]
k = 4
print(selectkthrankele(seqlist,k-1))
