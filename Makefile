NAME = ft_containers

all: $(NAME)

$(NAME): main.o
	c++ main.o -o $@

main.o: main.cpp
	c++ $^ -c -o $@

clean:
	rm -f main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	cpplint main.cpp
