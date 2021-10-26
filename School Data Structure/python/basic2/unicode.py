#ord : 유니코드 문자 -> 정수
#chr : 유니코드 정수 -> 문자

print(ord('a'))
# 결과 : 97
# ord는 문자를 아스키의 정수로 바꾸어주고

print(ord('A'))
# 결과 : 65

print(chr(99))
# c
# chr은 아스키에 대입되는 이 정수값을 일치하는 문자로 바꾸어준다.

# 소문자 출력
for i in range(97, 123):
    print(chr(i), end='')
print()
for i in range(0, 26):
    print(chr(ord('a') + i), end='')