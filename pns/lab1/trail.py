import math
def main():
    count=0
    r = input("Enter value of r\n")
    with open("output.txt", "w") as f:
        try:
            r = int(r)
            if(75<=r<=85):
                for x in range(0, -r-1, -1):
                    a = int(math.sqrt(r*r - x*x))
                    for y in range(a+1):
                        print("("+str(x)+","+str(y)+") ", end = " ")
                        f.write("("+str(x)+","+str(y)+") ")
                        count+=1
            else:
                print("Invalid Input")
                f.write("Invalid Input\n")
        except ValueError:
            try:
                r=float(r)
                r=int(r)
                if(75<=r<=85):
                    for x in range(0, -r-1, -1):
                        a = int(math.sqrt(r*r - x*x))
                        for y in range(a+1):
                            print("("+str(x)+","+str(y)+") ", end = " ")
                            f.write("("+str(x)+","+str(y)+") ")
                            count+=1
                else:
                    print("Invalid Input")
                    f.write("Invalid Input\n")
            except ValueError:
                print("Invalid Input\n")
                f.write("Invaid Input\n")
    print(count)
    f.close()
if __name__ == "__main__":
    main()