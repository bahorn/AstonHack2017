; new main, with improved render pipeline.
init_game
    ; create the queue.
    PSHS
    LDA #0
    STA count
    ; make it zero.
    STA player_y
    STA player_x
game
    ; read some input so we can change player_x/y
    ; setup the display
    JSR Wait_Recal
    LDA #10
    STA VIA_t1_cnt_lo
    ; add something to the render queue. position we want it.
    ; and the 
    LDX player_sprite
    LDA player_y
    LDB player_x
    PSHS X,D

    
