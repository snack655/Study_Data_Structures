# 이름은 스택이지만 사실상 리스트

stack = []
stack.append(5)
stack.append(3)
stack.append(8)
stack.append(6)
stack.append(4)
stack.pop()
stack.append(1)
stack.pop()
print(stack)
print(stack[0])
print(stack[::-1]) # 리스트에서 값을 뒤집은 값을 출력
print('stack pop', stack.pop())
print('stack pop', stack.pop())
print('stack pop', stack.pop())
print('stack pop', stack.pop())
# 값 빼기

