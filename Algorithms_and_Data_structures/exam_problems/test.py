def task1():
    # n = int(input("please input size <= 1 liter containers: ")) 
    # m = int(input("please input size > 1 liter containers: ")) 
    n, m = 12, 122
    res = n * 0.1 + m * 0.25

    print("%.2f" % round(res, 2))

def task2():
    # interest_rate = float(input("interest rate : ")) # (for example: 1.1, 1.3)
    # balance = float(input("balance: "))
    interest_rate, balance = 1.1, 10000
    for year in range(1, 4):
        balance *= interest_rate
        
        print(f"year: {year} balance:", "%.2f" % round(balance, 2))


def task3():
    def age_prices(age):
        if (age <= 2): 
            return 0.00
        elif (age >= 3 and age <= 12): 
            return 14.00
        elif (age >= 65):
            return 18.00 
        else:
            return 23.00 
    

    group_cost = 0
    while (True):
        s = input()
        if (len(s.strip()) == 0 ):
            break
        
        age = int(s)
        group_cost += age_prices(age)
    
    print("final cost: ", "%.2f" % round(group_cost, 2))
    
# print("task1: ")
# task1()
# print("task2: ")
# task2()
print("task3: ")
task3()
