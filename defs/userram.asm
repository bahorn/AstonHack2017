; ram starts at $C880 til $CBEA
; store the scores
player_score    EQU $C880 ; this is 6 bytes.
high_score      EQU player_score+7 ; 6 bytes again

player_x        EQU high_score+7
player_y        EQU player_x+1
bullet_active   EQU player_y+1 ; stores a 1 if a bullet is active on the screen.
bullet_x        EQU bullet_active+1 ; the bullets x cord
bullet_y        EQU bullet_x+1 ; the bullets y cord.
count           EQU bullet_y+1; ; count of stack items
enemy_x         EQU count+1;
enemy_y         EQU enemy_x+1;
speed           EQU enemy_y+1;
temp            EQU speed+1;
