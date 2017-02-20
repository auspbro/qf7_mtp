CC=gcc
#CC=/opt/buildroot-gcc463/usr/bin/mipsel-buildroot-linux-uclibc-gcc

# Please install libbluetooth-dev for bluetooth test development
# ex: sudo apt-get install libbluetooth-dev
CFLAG=-lbluetooth -lpthread -static
OUT_DIR=obj
OBJS_=main.o led.o bt.o als.o carrier.o
OBJS=${patsubst %,${OUT_DIR}/%,${OBJS_}}

mtp_server: ${OBJS}
	${CC} -o $@ $^ ${CFLAG}

${OUT_DIR}/%.d: %.c
	@mkdir -p ${@D}
	@set -e; rm -f $@; \
	${CC} -MM $(CFLAG) $< > $@.$$$$; \
	sed 's,^,${OUT_DIR}/,g' < $@.$$$$ > $@.$$$$.tmp; \
	sed 's,\($*\)\.o[ :]*,\1.o $@: ,g' < $@.$$$$.tmp > $@; \
	rm -f $@.$$$$; rm -f $@.$$$$.tmp

${OUT_DIR}/%.o: %.c
	${CC} -c -o $@ $< ${CFLAG}

-include ${OBJS:.o=.d}

.PHONY: clean
clean:
	-rm -rf $(OUT_DIR) mtp_server
