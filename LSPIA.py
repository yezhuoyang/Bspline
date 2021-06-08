import random
import math
import numpy as np


def get_control_par(n, p):
    t = []
    for i in range(p + 1):
        t.append(0.0)
    for i in range(n - p - 1):
        t.append((i + 1) / (n - p))
    for i in range(p + 1):
        t.append(1.0)
    return t


def read_data(name):
    file = open("./Tests/" + name + ".txt", "r")
    lines = file.readlines()
    points = np.array([[float(x) for x in line.split()[:2]] for line in lines])
    file.close()
    return points


def get_data_par(points):
    u = []
    sum = 0.0
    u.append(0)
    for i in range(len(points) - 1):
        u.append(((points[i + 1] - points[i]) ** 2).sum() ** 0.5 + u[-1])
    for i in range(len(u)):
        u[i] = u[i] / u[-1]
    return u


def calc_basis(i, u, t, p = 3):
    if p == 0:
        return t[i] <= u < t[i + 1]
    ret = 0
    if (t[i + p] - t[i]) != 0:
        ret += (u - t[i]) * calc_basis(i, u, t, p - 1) / (t[i + p] - t[i])
    if (t[i + p + 1] - t[i + 1]) != 0:
        ret += (t[i + p + 1] - u) * calc_basis(i + 1, u, t, p - 1) / (t[i + p + 1] - t[i + 1])
    return ret


if __name__ == "__main__":

    name = '03'

    n = 50  # 控制点数量
    p = 3  # 样条次数
    t = get_control_par(n, p)
    points = np.array(read_data(name))
    u = np.array(get_data_par(points))

    A = np.array([[calc_basis(i, uu, t, p) for i in range(n)] for uu in u])
    for i in range(len(A)):
        if A[i].sum() >= 1:
            A[i] = A[i] / A[i].sum()
    A = np.mat(A)

    control_points = []
    for i in range(n):
        control_points.append([0, 0])
    control_points = np.mat(control_points)
    eigenvalues, eigenvectors = np.linalg.eig(A.T * A)
    eigenvalues.sort()
    miu = 2 / (eigenvalues[0] + eigenvalues[-1])
    for i in range(10000):
        control_points = control_points + miu * A.T * (points - A * control_points)

    print(control_points)
    file = open('./Tests/' + name + '_controls.txt', 'w+')

    for cp in np.array(control_points):
        file.write(str(cp[0]) + ' ' + str(cp[1]) + ' 0\n')
    file.close()

    file = open('./Tests/' + name + '_spline.txt', 'w+')

    spline_num = 100

    for i in range(n - 1):
        if t[i] < t[i + 1]:
            for j in [((t[i + 1] - t[i]) * x / spline_num + t[i]) for x in range(spline_num)]:
                now_p = [0.0, 0.0]
                for k in range(max(0, i - p - 1), min(n - 1, i + p + 1)):
                    now_p += calc_basis(k, j, t, p) * np.array(control_points)[k]
                file.write(str(now_p[0]) + ' ' + str(now_p[1]) + ' 0\n')
    file.close()