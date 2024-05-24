import sys
lines = sys.stdin.readlines()

for n in lines:
	n = int(n)
	answer = 1
	sum = 1
	
	while True:
		if sum % n == 0:
			print(answer)
			break

		sum *= 10
		sum+=1
		answer+=1
