# Fit two types of RAMs in a 6x6 silicon die.

n = 6
items = ["D%d%d" % (i, j) for i in range(n) for j in range(n)]
print " ".join(items)
for j in xrange(n - 2):
  for i in xrange(n):
    option = []
    for k in xrange(3):
      option.append("D%d%d" % (j + k, i))
    print " ".join(option)

for j in xrange(n):
  for i in xrange(n - 1):
    option = []
    for k in xrange(2):
      option.append("D%d%d" % (j, i + k))
    print " ".join(option)
    

