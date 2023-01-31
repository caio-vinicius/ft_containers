# Copyright (c) 2023 Caio Souza. All rights reserved. #
# 42 #

NAME = containers

SOURCES = ./
#SOURCES_FILES = $(wildcard *.cpp)
SOURCES_FILES = aux.cpp main.cpp map_constructors.cpp
SOURCES_FILES_FULL = $(addprefix $(SOURCES)/,$(SOURCES_FILES))

OBJECTS = ./objects
OBJECTS_FILES_FT = $(patsubst $(SOURCES)/%.cpp,$(OBJECTS)/ft_%.o,$(SOURCES_FILES_FULL))
OBJECTS_FILES_STD = $(patsubst $(SOURCES)/%.cpp,$(OBJECTS)/std_%.o,$(SOURCES_FILES_FULL))

DEPENDENCIES = ./objects
DEPENDENCIES_FILES = $(OBJECTS_FILES:.o=.d)

CCFLAGS = -Wfatal-errors -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP -g

all: ft_$(NAME) #std_$(NAME)

ft_$(NAME): $(OBJECTS_FILES_FT)
	c++ $^ -o $@

#std_$(NAME): $(OBJECTS_FILES_STD)
#	c++ $^ -o $@

-include ($(DEPENDENCIES_FILES))

$(OBJECTS)/ft_%.o: $(SOURCES)/%.cpp Makefile
	c++ $(CCFLAGS) -c $< -o $@

#-include $(DEPENDENCIES_FILES)
#$(OBJECTS)/std_%.o: $(SOURCES)/%.cpp Makefile
#	c++ $(CCFLAGS) -D STD=1 -c $< -o $@

clean:
	rm -f $(OBJECTS_FILES_FT) $(OBJECTS_FILES_STD) $(DEPENDENCIES_FILES)

fclean: clean
	rm -f ft_$(NAME) std_$(NAME)

re: fclean all
