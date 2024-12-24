def getDivisor(num: int):
    divisorList = [1]
    i = 2
    while True:
        if i*i > num:
            break
        if num % i == 0:
            divisorList.append(i)
        
        i+=1
    l_len = len(divisorList)
    for i in range(1, l_len):
        divisorList.append(num//divisorList[i])
    return sorted(set(divisorList))


input()
arr = map(int, input().split())


for num in arr:
    if num==1:
        print('Deficient')
        continue
    n_sum = sum(getDivisor(num))
    print('Perfect' if n_sum == num else 'Abundant' if n_sum > num else 'Deficient')
