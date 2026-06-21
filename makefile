# Derleyici ve Bayraklar
CC = clang
CFLAGS = -Wall -Wextra -Werror -fPIC -O3 -std=c11
INCLUDES = -I./include

# Dosya İsimleri
SRC = hcb_server.c
OBJ = $(SRC:.c=.o)
STATIC_LIB = libhcb_server.a

# İşletim sistemine göre dinamik kütüphane uzantısını belirleme
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    SHARED_LIB = libhcb_server.dylib
else
    SHARED_LIB = libhcb_server.so
endif

# Varsayılan hedef (Sadece 'make' yazıldığında çalışır)
all: $(STATIC_LIB) $(SHARED_LIB)

# Object dosyalarını derleme
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Statik kütüphane oluşturma
$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

# Dinamik kütüphane oluşturma
$(SHARED_LIB): $(OBJ)
	$(CC) -shared -o $@ $^

# Temizlik komutu ('make clean')
clean:
	rm -f *.o *.a *.so *.dylib

.PHONY: all clean
