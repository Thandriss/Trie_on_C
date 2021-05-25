.PHONY: all test

OBJS= Trie.o
RM= del
MAKE= make
MYLIBNAME= libTrie.a

all: $(MYLIBNAME)

CFLAGS= -std=c11 -pedantic -Wall -Wextra

# Включаемые файлы следует искать в каталоге "include"
INCLUDES+= -I./include
# Make должна искать файлы *.h в каталогах include и src
vpath %.h include src
# ..., а файлы *.c - в каталоге src
vpath %.c src
#создание либы и удаление мусора
$(MYLIBNAME): $(OBJS)
	$(AR) -rsc $@ $^
	$(RM) -f $(OBJS)

# Построение объектных файлов
%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c -o $@ $<
#запуск test

-include $(OBJS:.o=.d)