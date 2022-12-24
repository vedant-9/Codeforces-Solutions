t=int(input())
for _ in range(t):
	p,a,b,c=map(int,input().split())
	ans=(-p)%a
	ans=min(ans,(-p)%b)
	ans=min(ans,(-p)%c)
	print(ans)