CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
SF = src/*.c 
LIB = -lSDL2 -lSDL2main  -lSDL2_image -Wno-switch -lm -lSDL2_ttf
EFN = endgame

all: install

install:
	@${CLANG} -o ${EFN} ${SF} ${LIB}

uninstall: 
	@rm -rf ${EFN}

clean:


reinstall:
	@rm -rf ${EFN}
	@${CLANG} -o ${EFN} ${SF} ${LIB}
