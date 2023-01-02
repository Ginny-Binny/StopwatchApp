for _ in range(int(input())):
    a, b, c, d = list(map(int, input().split()))
    s = abs(a - c) + abs(b - d)
    if s:
        if s % 2 == 0:
            print(2)
        else:
            print(1)
    else:
        print(0)