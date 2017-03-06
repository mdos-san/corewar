all: corewar asm

corewar:
	make -C vm
	cp vm/corewar .

asm:
	make -C src_asm
	cp src_asm/asm .

clean:
	make clean -C src_asm
	make clean -C vm

fclean: clean
	make fclean -C src_asm
	make fclean -C vm
	rm -rf corewar asm

re: fclean all
