
s = input()

if s == "1*1=1":
    for i in range(2, 10):
        for j in range(1, i+1):
            print(str(i) + '*' + str(j) + '=' + str(i*j), end='\t')     # '+' 字符串连接
        print()                                                         # 换行
