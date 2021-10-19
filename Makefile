NAME = ft_containers
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = includes/containers/Vector.hpp\
			includes/containers/Stack.hpp\
			includes/containers/Map.hpp\
			includes/iterator/RandomAccessIterator.hpp\
			includes/iterator/ReverseIterator.hpp\
			includes/iterator/IteratorTraits.hpp\
			includes/utils/Tools.hpp\
			includes/utils/TypeTraits.hpp\
			includes/utils/RBTree.hpp\
			includes/iterator/RBTIterators.hpp
SRCS =	srcs/main.cpp\
		srcs/vector_test.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp $(HEADERS)
		@echo "\033[35m┌─┐┌┬┐   ┌─┐┌─┐┌┐┌┌┬┐┌─┐┬┌┐┌┌─┐┬─┐┌─┐\033[0m"
		@echo "\033[34m├┤  │    │  │ ││││ │ ├─┤││││├┤ ├┬┘└─┐\033[0m"
		@echo "\033[36m└   ┴────└─┘└─┘┘└┘ ┴ ┴ ┴┴┘└┘└─┘┴└─└─┘\033[0m"
		@echo "\033[34m_____________________________________\n\033[0m"
		@echo "\033[33m"
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)
		@echo "\033[0m"

$(NAME): $(OBJS) $(HEADERS)
		@echo "\033[1m\033[36mLinking\033[0m"
		@echo "\033[33m"
		$(CC) -o $(NAME) $(OBJS)
		@echo "\033[0m"
		@echo "\033[1m\033[32mDone !\n\033[0m"

all : $(NAME)

clean :
		rm -rf srcs/*.o
		@echo "\033[91m...\033[0m"

fclean : clean
		rm -rf $(NAME)
		@echo "\033[1m\033[31mCleaned\033[0m"

re : fclean all

.PHONY: clean fclean re all