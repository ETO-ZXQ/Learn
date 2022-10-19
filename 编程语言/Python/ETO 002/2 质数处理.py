def pp(n):
    prime = []

    # 生成质数序列

    for i in range(2,n+1):
        for j in range(2,i):
            if i%j == 0:
                break
        else:
            prime.append(i)

    # 将不是逆序数的数生成

    prime2 = []

    for i in prime:
        j = i
        ii = 0
        while i!=0:
            ii = ii*10
            ii = ii + i%10
            i = i//10

        if ii in prime:
            prime2.append(j)
    # 统计数字

    n1 = 0
    n2 = 0
    n3 = 0

    for i in prime2:
        flag = 0
        while i!=0:
            flag = flag + 1
            i = i//10

        if flag == 1:
            n1 += 1
        elif flag ==2:
            n2 += 1
        else:
            n3 += 1

    # 输出字典
    dic = {'一位数':n1, '两位数':n2, '三位数':n3}

    print(dic)

    # print(prime)
    # print(prime2)


num = int(input("请输入查找范围："))
pp(num)

