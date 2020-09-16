def selectkthrankele(seqlist,k):
    sublistof5s = [seqlist[j:j+5] for j in range(0,len(seqlist),5)]
    allmedianlist = [sorted(sublistof5)[len(sublistof5)//2] for sublistof5 in sublistof5s]
    if len(allmedianlist)<=5:
        appmedian = sorted(allmedianlist)[len(allmedianlist)//2]
    else:
        appmedian = selectkthrankele(allmedianlist,len(allmedianlist)//2)

    leftseqlist = [ele for ele in seqlist if ele<appmedian]
    rightseqlist = [ele for ele in seqlist if ele>appmedian]

    mid = len(leftseqlist)

    if k<mid:
        return selectkthrankele(leftseqlist,k)
    elif k>mid:
        return selectkthrankele(rightseqlist,k-mid-1)
    else:
        return appmedian

seqlist = [1,3,4,5,6,67,7,8,88,10,11,12,9]
k = 8
print(selectkthrankele(seqlist,k))
