# 0으로 채우는 zfill
# Fill the string with zeros
n = 20
print(hex(n))
# 0x14

n = str(hex(n))
print(n.zfill(10))
# 10은 글자수를 나타낸다고 생각했고 그 남은 수를 전부 0으로 채워준다.
# 그것이 zfill

n1 = str(30)
print(n1.zfill(10))

n2 = 'hello'
print(n2.zfill(10))