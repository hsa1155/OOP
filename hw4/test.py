import matplotlib.pyplot as plt

corList = []
hullList = []

with open("Output_brutal.txt", 'r') as f:
    n = int(f.readline())

    # get the corordinate of the points that inside the 'hull'
    for i in range(n):
        cor = f.readline()
        cor = cor.split()
        temp = (float(cor[0]), float(cor[1]))
        corList.append(temp)
    
    dummy = f.readline()    # the '\n'
    n = int(f.readline())
    
    # get the corordinate of the points that consist the 'hull'
    for i in range(n):
        cor = f.readline()
        cor = cor.split()
        temp = (float(cor[0]), float(cor[1]))
        corList.append(temp)
        hullList.append(temp)

    # draw the points
    for point in corList:
        plt.scatter(point[0], point[1], color = 'b')

    # draw the boundary
    for i in range(len(hullList) - 1):
        plt.plot([hullList[i][0], hullList[i + 1][0]], [hullList[i][1], hullList[i + 1][1]], color = 'r')
    plt.plot([hullList[-1][0], hullList[0][0]], [hullList[-1][1], hullList[0][1]], color = 'r')

    # set some attribute
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title("Convex Hull")

    plt.grid(linestyle = '-.')
    plt.show()