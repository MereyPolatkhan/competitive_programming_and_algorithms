n = int(input()) 
a = []
for i in range(n):
    s = input() 
    a.append(s)

k = int(input()) 
new_string = ""
for i in range(n):
    new_string += a[i][k-1]

print(new_string)