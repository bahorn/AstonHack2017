game_over
    ; check if any keys were pressed
    
    JSR Read_Btns
    CMPA    #$00
    BEQ draw_game_over
    ; check if we got a high score and save it now.
    LDU #high_score
    LDX #player_score
    JSR New_High_Score
    JMP title_screen
    ; draw the game over screen
draw_game_over
    JSR Wait_Recal      ; recalibrate
    JSR Intensity_5F    ; set intensity
    LDU #game_over_string
    LDA #$30
    LDB #-$40
    JSR Print_Str_d
    LDU #game_over_score
    LDA #0
    LDB #-$45
    JSR Print_Str_d
    LDU #player_score
    LDA #-$20
    LDB #-$40
    JSR Print_Str_d
    LDU #any_key_string
    LDA #-$60
    LDB #-$55
    JSR Print_Str_d
    BRA game_over
