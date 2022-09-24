import math
def seadragon(a,b,c):
    if a<=0 or b<=0 or c<=0:
        return -1
    
    
    s=a+b+c
    big=max(a,b,c)
    if s-big<big:
        return -1

    s=s/2
    return math.sqrt(s*(s-a)*(s-b)*(s-c))



print("triangle area calculater")
f=open("py_result.txt",'a')
while True:
    
    a=input('please input first number')
    a=float(a)
    b=input('please input second number')
    b=float(b)
    c=input('please input third number')
    c=float(c)
    if a==-1 and b==-1 and c==-1:
        print("end of program")
        f.write("end of prorram\n")
        f.close()
        break
    print("a =",a)
    st="a ="+ str(a)+'\n'
    f.write(st)
    print("b =",b)
    st="b ="+ str(b)+'\n'
    f.write(st)
    print("c =",c)
    st="c ="+str(c)+'\n'
    f.write(st)
    area=seadragon(a,b,c)
    if area<=0:
        print("invalid input.please try again")
        f.write("invalid input.please try again\n")
    else:
        print("area=",area)
        st="area ="+str(area)+'\n'
        f.write(st)






