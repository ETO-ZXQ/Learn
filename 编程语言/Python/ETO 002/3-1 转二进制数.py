def switch (num):
    num_char = []
    while num != 0:
        num_char.append(str(num%2))
        num = num//2
    for i in num_char[::-1]:
        print(i, end='')


n = int(input('请输入一个十进制整数：'))
switch(n)

