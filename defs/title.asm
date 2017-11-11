title_screen
    ; check button
    JSR Read_Btns    
    CMPA #$00
    BEQ draw_title_screen
    JMP init_game
draw_title_screen
    JSR Wait_Recal
    JSR Intensity_5F
    LDU #high_score
    LDA #$7f
    LDB #-$80
    JSR Print_Str_d
    LDU #title_screen_string
    LDA #-$30
    LDB #-$60
    JSR Print_Str_d
    LDU #any_key_string
    LDA #-$60
    LDB #-$50
    JSR Print_Str_d
    BRA title_screen
