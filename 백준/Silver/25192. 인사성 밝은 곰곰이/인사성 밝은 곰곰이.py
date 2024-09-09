N = int(input())

nameList:set = set()
num = 0

for i in range(N):
	s = input()
	if s == "ENTER":
		num += len(nameList)
		nameList = set()
		continue

	nameList.add(s)

print(num + len(nameList))