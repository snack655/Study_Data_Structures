arr = ['b', 'c', 'a', 'f', 't', 'e']
arr.sort(reverse=True)  #내림 차순으로 정렬
print(arr)

# 문제 주어진 정수 리스트에서 최고점과 최저점을 출력하시오.
score = [55, 78, 99, 34, 87]

score.sort()
print(score[-1], score[0])