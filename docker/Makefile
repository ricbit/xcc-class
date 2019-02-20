all : dlx1 dlx2 dlx3 dlx-pre

dlx%.c : dlx%.w
	ctangle $^

dlx% : dlx%.c
	gcc -O3 -march=native -g -I/home/sgb -L/home/sgb $^ -o $@ -lgb
