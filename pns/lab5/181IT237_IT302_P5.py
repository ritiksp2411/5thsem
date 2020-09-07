import xlrd 

loc=("Test-Cases-IT302-Lab-Program-5.xlsx")
wb = xlrd.open_workbook(loc) 
mysheet = wb.sheet_by_index(0) 
r=[]
for i in range(0,mysheet.nrows):
	for j in range(0,mysheet.ncols):
		if mysheet.cell_value(i,j)=="f(x,y)":
			r.append([i,j])
			break
r1=[]
r2=[]
check=0
for c1 in r:
	check=0
	for i in range(c1[1]+2,mysheet.ncols):
		
		if mysheet.cell(c1[0]+1,i).value == xlrd.empty_cell.value:
			r1.append([c1[1]+2,i])
			check=1
			break
	if check==0:
		r1.append([c1[1]+2,i+1])
for c1 in r:
	check=0
	for i in range(c1[0]+2,mysheet.nrows):
		if mysheet.cell(i,c1[1]+1).value == xlrd.empty_cell.value:
			r2.append([c1[0]+2,i])
			check=1
			break
	if check==0:
		r2.append([c1[0]+2,i+1])


l=len(r1)
for t in range(0,l):

	f={}
	output=open(f"181IT237_IT302_P5_Output_TC{t+1}.txt","a")
	for i in range(r1[t][0],r1[t][1]):
		for j in range(r2[t][0],r2[t][1]):
			f[str(int(mysheet.cell_value(r2[t][0]-1, i)))+","+str(int(mysheet.cell_value(j, r1[t][0]-1)))]=mysheet.cell_value(j, i)

	print(f"F(x,y) {t+1}: ",f)
	for i in f:
		if f[i]>1:
			output.write(f"\nF({i}): "+str(round(f[i],2))+" is invalid because it's greater than one")
			break
		output.write(f"\nF({i}): "+str(round(f[i],2)))
	egxy=0
	for i in f:
		xyvalue=i.split(",")
		x=int(xyvalue[0])
		y=int(xyvalue[1])
		egxy+=(2*pow(x,2)+pow(y,2)+2*x*y)*f[i]
	print(f"Value of g(X,Y)=2X^2+Y^2+2XY for f{t+1}: "+str(round(egxy,2)))
	output.write(f"\nValue of g(X,Y)=2X^2+Y^2+2XY for f{t+1}: "+str(round(egxy,2)))
	meanx=0
	for i in f:
		xyvalue=i.split(",")
		x=int(xyvalue[0])
		y=int(xyvalue[1])
		meanx+=x*f[i]
	print("μX : "+ str(round(meanx,2)))
	output.write(f"\nμX : "+str(round(meanx,2)))

	meany=0
	for i in f:
		xyvalue=i.split(",")
		x=int(xyvalue[0])
		y=int(xyvalue[1])
		meany+=y*f[i]
	print("μY : "+str(round(meany,2)))
	output.write(f"\nμY : "+str(round(meany,2)))
	output.close()
