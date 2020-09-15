def create_data(filename):
    with open(filename) as x:
        # map which storex the number for each woman == mapw
        # map which storex the number for each man == mapm
        global mlist,wlist,iwplist,implist,mapw,mapm   
        fir = False
        sec = False
        mapm = {}
        mapw = {}
        list_ = []
        for lines in x.read().splitlines():
            if not fir:
                c = 0
                for name in lines.split(" "):
                    mapm[name] =c
                    c += 1
                fir= True
                countm = len(mapm)        # countm is total number of man
                mlist = [[None]*countm for i in range(countm)]
                implist = [[None]*countm for i in range(countm)]

            elif not sec:
                c = 0
                for name in lines.split(" "):
                    mapw[name] = c
                    c += 1
                sec = True
                countw = len(mapw)        # countm is total number of woman
                wlist = [[None]*countw for i in range(countw)]
                iwplist = [[None]*countm for i in range(countm)]
            
            elif countm>0 :
                fir = False
                list_ = []
                curperson = ''
                c = 0
                for name in lines.split(" "):
                    list_.append(name)
                    if not fir:
                        curperson = name
                        fir = True
                        continue
                    mlist[mapm[curperson]][c] = (mapw[name])
                    implist[mapm[curperson]][mapw[name]] = len(mapm)-c
                    c = c+1
                countm = countm-1
                
            elif countw>0 :
                fir = False
                list_ = []
                curperson = ''
                c = 0
                for name in lines.split(" "):
                    list_.append(name)
                    if not fir:
                        curperson = name
                        fir = True
                        continue
                    wlist[mapw[curperson]][c] = (mapm[name])
                    iwplist[mapw[curperson]][mapm[name]] = len(mapm)-c
                    c = c+1
                countw = countw-1

def gale_shapley():
    husband = [-1 for _ in range(len(mapm))]
    count = [0 for _ in range(len(mapm))]    # upto what woman did the man proposed
    fmen = list(mapm.values())
    mname = list(mapm.keys())
    wname = list(mapw.keys())
    while(len(fmen)!=0):
        m = fmen.pop()
        women = mlist[m][count[m]]
        count[m] += 1
        if husband[women] == -1:
            husband[women] = m
        elif iwplist[women][m]>iwplist[women][husband[women]]:
            fmen.append(husband[women])
            husband[women] = m
        else:
            fmen.append(m)
    for i in range(len(husband)):
        print(mname[husband[i]]+" - "+wname[i])
        
create_data("input.txt")
gale_shapley()
