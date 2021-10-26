Group = {}
print("### K-Pop 그룹 관리 프로그램 ###")

while True:
    menu = int(input("[1:등록/2:삭제/3:조회/4:조회]:"))
    if menu == 4:
        break
    elif menu == 1:
        name = input("그룹 이름이 무엇인가?")
        member = input("그룹 인원이 몇명인가?")
        Group[name] = member
    elif menu == 2:
        delete = input("삭제할 그룹 이름이 무엇인가?")
        del(Group[delete])
    elif menu == 3:
        print(Group)

    print("### K-Pop 관리 프로그램 종료 ###")