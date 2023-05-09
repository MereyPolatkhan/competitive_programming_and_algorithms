num = "030" # 1210

flag = True

for i, n in enumerate(num):
    if num.count(str(i)) != int(n):
        # print(i, n, num.count(str(i)))
        flag = False
        break



print(flag)