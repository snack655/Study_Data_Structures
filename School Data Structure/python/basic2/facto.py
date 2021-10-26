def f_iter(n):
    r = 1
    for i in range(1, n + 1):
        r *= i
    return r

def f_rec(n):
    if n <= 1:
        return 1
    else:
        return n * f_rec(n-1)

print(f_iter(5))
print(f_rec(5))

# iter 1에서 올리며 팩토리얼
# rec 재귀적인 표현 팩토리얼
# 줄이고 줄이고
