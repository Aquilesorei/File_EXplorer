import os
def size(path = 'C:\\Users\ADMIN\Documents\programs\Python'):

    #initialize the size
    total_size = 0

    #use the walk() method to navigate through directory tree
    for dirpath, dirnames, filenames in os.walk(path):
        for i in filenames:

            #use join to concatenate all the components of path
            f = os.path.join(dirpath, i)

            #use getsize to generate size in bytes and add it to the total size
            total_size += os.path.getsize(f)

    return total_size

print(size())
