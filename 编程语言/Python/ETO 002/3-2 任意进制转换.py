def switch(num, r):
    char = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    num_char = []

    while num!= 0:
        num_char.append(char[num%r])
        num = num//r

    # 打印输出
    for i in num_char[::-1]:
        print(i, end='')


n1 = int(input('请输入要转换的数字：'))
n2 = int(input('请输入要转换的进制：'))
switch(n1, n2)
