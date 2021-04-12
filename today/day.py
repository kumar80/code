import numpy as np

week = ['Sun',
        'Mon',
        'Tue',
        'Wed',
        'Thu',
        'Fri',
        'Sat']

coeff = [[[2, -1], [-1, 2]],
         [[2, -1, 0], [1, -2, 1], [0, -1, 2]],
         [[2, -1, 0, 0], [1, -2, 1, 0], [0, 1, -2, 1], [0, 0, -1, 2]],
         [[2, -1, 0, 0, 0], [1, -2, 1, 0, 0], [0, 1, -2, 1, 0],
          [0, 0, 1, -2, 1], [0, 0, 0, -1, 2]]
         ]


def weekDay(d, m, y):
    t = [0, 3, 2, 5, 0, 3,
         5, 1, 4, 6, 2, 4]
    y -= m < 3
    return ((y + int(y / 4) - int(y / 100)
             + int(y / 400) + t[m - 1] + d) % 7)


def sum(req):
    datesList = []
    vals = []
    dates = []
    D = [-1]*7

    for key, value in req.items():
        datesList.append(key)
        vals.append(value)

    for i in range(len(datesList)):
        date = datesList[i].split("-")
        date[1] = date[1].lstrip("0")
        date[2] = date[2].lstrip("0")

        dates.append([int(date[0]), int(date[1]), int(date[2])])

    for i, date in enumerate(dates):
        day = weekDay(date[2], date[1], date[0])
        val = vals[i]
        if(D[day] == -1):
            D[day] = 0
        D[day] += val

    res = {}
    for i in range(7):
        j = i
        k = 0
        while(j < 7 and D[j] == -1):
            j += 1
        if(j-i == 1):
            D[i] = (D[i-1] + D[(i+1) % 7]) / 2

        if(j-i > 1):
            A = np.array(coeff[j-i-2])
            aug = [0]*(j-i)
            aug[0] = D[i-1]
            aug[j-i-1] = D[j % 7]
            B = np.array(aug)
            X = np.linalg.solve(A, B)
            Xi = 0
            for k in range(i, j):
                D[k] = int(X[Xi])
                Xi += 1
            i = j

    for i in range(7):
        res[week[i]] = D[i]

    return res
