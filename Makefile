# Copyright (c) 2023 Caio Souza. All rights reserved. #
# 42 #

NAME = containers

SOURCES = ./
SOURCES_FILES = $(wildcard *.cpp)
SOURCES_FILES_FULL = $(addprefix $(SOURCES)/,$(SOURCES_FILES))

OBJECTS = ./objects
OBJECTS_FILES = $(patsubst $(SOURCES)/%.cpp,$(OBJECTS)/%.o,$(SOURCES_FILES_FULL))

DEPENDENCIES = ./objects
DEPENDENCIES_FILES = $(OBJECTS_FILES:.o=.d)

CCFLAGS = -Wfatal-errors -Wall -Wextra -Werror -std=c++98 -pedantic-errors

all: $(NAME)

$(NAME): $(OBJECTS_FILES)
	c++ $^ -o $@

-include $(DEPENDENCIES_FILES)
$(OBJECTS)/%.o: $(SOURCES)/%.cpp
	c++ $(CCFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJECTS_FILES) $(DEPENDENCIES_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
