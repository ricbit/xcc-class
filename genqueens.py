# N Queens using dlx1, includes all symmetries.

n = int(raw_input())
items = ["R%d C%d" % (i,i) for i in range(n)]
diag = []
diag.extend(["P%d" % x for x in range(0, 2*n - 1)])
diag.extend(["S%d" % x for x in range(-n+1, n)])
print "%s | %s" % (" ".join(items), " ".join(diag))
for j in range(n):
  for i in range(n):
    print "R%d C%d P%d S%d" % (j, i, j + i, j - i)
 
