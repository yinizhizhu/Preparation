# X+2*X=3*X+1
s=input()
eq=s.replace('=','-(') +')'
print(eq)
r=eval(eq , {'X':1j})
print(r)
ans=0
flag=True
try:
    ans = -r.real/r.imag
except:
    print('-1')
    flag=False
if flag:
    if ans%1==0 and int(ans)>0:
        print(int(ans))
    else:
        print('-1')