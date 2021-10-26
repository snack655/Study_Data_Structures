d1 = {}
k = input()
v = input()
d1[k] = v
k = input()
v = input()
d1[k] = v
print(d1)

# k를 key값으로 v를 값으로 이용해서
# map 생성

# 빈칸이 한 번 있는 경우 딕셔너리 생성법
dct1 = {}
for _ in range(2):
    k,v = input().split()
    dct1[k] = v
print(dct1)

#1 kim 2 hong 3 lee
hash = {}
for _ in range(3):
    key, value = input().split()
    hash[int(key)] = value
#hash = dict.fromkeys(key, value)
print(hash)

