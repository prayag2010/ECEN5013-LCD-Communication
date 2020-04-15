C_FILES := \
			epd1in541.c \
			epdif1.c \
			main.c

EXE := epaper

all: out

out: ${C_FILES}
	gcc ${C_FILES} -lwiringPi -o ${EXE} 

clean:
	rm ${EXE}
