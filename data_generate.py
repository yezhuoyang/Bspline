import random
import math

if __name__ == '__main__':
    center = [0.5, 0.5]
    d = 0.4
    N = 1000

    t = []
    for i in range(N):
        t.append(random.uniform(0, 1))
    t.sort()

    M = 5

    for x in t:
        alpha = 2 * math.pi * x
        dd = d * (math.sin(alpha * M) * 0.3 + 0.7)
        print(center[0] + dd * math.cos(alpha), center[1] + dd * math.sin(alpha), 0)
