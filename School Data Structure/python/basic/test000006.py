# 매개변수로 넘긴 문자열 3개를 출력하는 것
def info(name, address, phone):  # 이름 주소 전화번호
    print(f'{name}, {address}, {phone}')


info('경태', '안경집', '01069746974')


# 김씨 출력하기 문제
def Hello(name, age):
    print(f'Hi, {name}, You are {age} years old.')


Hello('minjae', '17')


# 문제 - 자신이 좋아하는 가수 이름을 3개 입력 받고, 출력하는 함수 만들기
def singer():
    a = input("좋아하는 가수 1 : ")
    b = input("좋아하는 가수 2 : ")
    c = input("좋아하는 가수 3 : ")
    print(f'좋아하는 가수는 : {a, b, c}')

singer()

# 2번쨰 코드
def singer2(a, b, c):
    print(f'좋아하는 가수는 : {a, b, c}')

a = input("1 : ")
b = input("2 : ")
c = input("3 : ")
singer2(a, b, c)