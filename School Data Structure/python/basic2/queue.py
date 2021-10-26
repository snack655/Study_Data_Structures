from collections import deque
queue = deque()
queue.append(1)
queue.append(2)
queue.append(3)
print(queue)
print(queue.popleft())
print(queue.popleft())
print(queue.popleft())
print(queue)

# 양쪽으로 넣고 뺄 수 있는 덱에서 1 2 3을 넣고
# 왼쪽으로 1 2 3을 팝!
# 그러니 큐의 값은 없다!