num = []
num_char = []
file = open('Number.txt', 'r')

for i in range(10):
    s = file.readline()
    num_char = s.split()
    for j in range(10):
        num.append(int(num_char[j]))

file.close()

num_char.clear()

num.sort()

for i in range(100):
    num_char.append(str(num[i]))
    if (i+1)%10 == 0:
        num_char.append('\n')
    else:
        num_char.append(' ')
file2 = open('Number_sorted.txt', 'w')

# 将数据写入
for i in num_char:
    file2.write(i)


file2.close()
# print(num)
# print(num_char)

