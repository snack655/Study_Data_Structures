import random

a1 = '오늘도 행복하세요.'
a2 = '폭염 주의하세요'
a3 = '오늘 로또를 사세요'
a4 = '당신은 천제에요'
a5 = '영화 무료 쿠폰을 보내드려요'

print(":::오늘의 운세:::")
input("엔터를 누르면 시작됩니다.")
c = random.randint(1, 5)
if c == 1:
    d = a1
elif c == 2:
    d = a2
elif c == 3:
    d = a3
elif c == 4:
    d = a4
else:
    d = a5

print('-' * 20)
print(d)
print('-' * 20)