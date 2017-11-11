; ram starts at $C880 til $CBEA
; store the scores
player_score    EQU $C880 ; this is 6 bytes.
high_score      EQU player_score+7 ; 6 bytes again

player_x        EQU high_score+7
player_y        EQU player_x+1
speed           EQU player_y+1
active_floors   EQU speed+1
