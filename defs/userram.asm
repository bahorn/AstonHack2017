; ram starts at $C880 til $CBEA
; store the scores
high_score      EQU $CBEB ; 7 bytes at system memory high score location (last byte is terminator 0x80)
player_score    EQU $C880 ; 7 bytes for player score (last byte is terminator 0x80)

player_x        EQU player_score+7
player_y        EQU player_x+1
bullet_active   EQU player_y+1 ; stores a 1 if a bullet is active on the screen.
bullet_x        EQU bullet_active+1 ; the bullets x cord
bullet_y        EQU bullet_x+1 ; the bullets y cord.
count           EQU bullet_y+1; ; count of stack items
speed           EQU count+1;
player_speed    EQU speed+1;
temp            EQU player_speed+1;
killed          EQU temp+1;
enemy_x         EQU killed+1;
enemy_y         EQU enemy_x+1;
enemy_x_2       EQU enemy_y+1;
enemy_y_2       EQU enemy_x_2+1;
