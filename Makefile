
build:
	asm6809 boot.asm --output main

run: build
	cd ~/Software/ParaJVE/;./ParaJVE
