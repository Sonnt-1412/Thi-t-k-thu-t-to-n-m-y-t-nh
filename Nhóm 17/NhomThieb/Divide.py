import sys

input = sys.stdin.readline

MAXN = int(5e5 + 5)


class Student:
    def __init__(self, x, r):
        self.x = x
        self.r = r
        self.dis = r - x


def comp(a: Student):
    return (a.x, a.r)


n = int(input())
st = []

for _ in range(n):
    x, r = map(int, input().split())
    st.append(Student(x, r))

# sắp xếp
st.sort(key=comp)

MAX = st[-1].r - st[-1].x
ans = 1
stack = [st[-1].r + st[-1].x]

for i in range(n - 2, -1, -1):
    if st[i].r - st[i].x > MAX:
        ans += 1
        while stack:
            u = stack[-1]
            if u <= st[i].r + st[i].x:
                stack.pop()
                ans -= 1
            else:
                break
        stack.append(st[i].r + st[i].x)
    MAX = max(MAX, st[i].r - st[i].x)

print(ans)
