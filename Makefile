.PHONY: all test

OBJS= Trie.o
RM= del
MAKE= make
MYLIBNAME= libTrie.a

all: $(MYLIBNAME)

#-Wno-pedantic-ms-format в попытках избежать конфликтов из-за size_t
CFLAGS= -std=c11 -pedantic -Wall -Wextra

# Включаемые файлы следует искать в каталоге "include"
INCLUDES+= -I./include

#создание либы и удаление мусора
$(MYLIBNAME): $(OBJS)
	$(AR) -rsc $@ $^
	$(RM) -f $(OBJS)

# Построение объектных файлов
%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -c -o $@ $<
#запуск test

-include $(OBJS:.o=.d)