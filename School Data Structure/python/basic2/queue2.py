from collections import deque
queue = deque()
queue.append(1)
queue.append(2)
queue.append(3)
print(queue)
print(queue.popleft())
print(queue.popleft())
print(queue)
queue.append(11)
queue.append(22)
queue.append(33)
print(queue)
#print(queue.reverse())
# 이건 절대로 안됨!
queue.reverse()
print(queue)

# reverse() 함수로 큐과 뒤집힌다.
# 반전 함수