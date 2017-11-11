; Called when we start a new game.
init_game
    ; setup everything
    LDA #-1
    STA count
    LDA #0
    STA player_x
    LDA #-$60
    STA player_y
    LDA #0
    STA bullet_active
    ;LDA #$0
    ;LDB #$0
    ;INC count
    ;PSHS D
    ;LDA count
    ;PSHS A
    STA fall

;; the main game loop.
main
    ;; check status
    LDB #01
    CMPB bullet_active
    ;; read input
    ; we care about left/right movement.
    JSR Joy_Digital
    LDA Vec_Joy_1_X
    BEQ no_movement
    BMI left_movement

right_movement
    INC player_x
    ;PULS A
    ;INC count
    ;LDA player_y
    ;LDB player_x
    ;PSHS D
    ;LDA count
    ;PSHS A
    BRA movement_done

left_movement
    DEC player_x
    
    BRA movement_done

no_movement
    ; do nothing
movement_done
    ;
    ; used to check if we are firing a bullet.
    JSR Read_Btns
    ; check if we are firing.
    BITA    #$01
    BEQ no_button
    ; preform creating on object here.
no_button
    ;; display everything.
    ; set up the displaying.
    JSR Wait_Recal
    LDA #10
    STA VIA_t1_cnt_lo
    JSR Intensity_5F
    ; Draw score first
    LDU #player_score
    LDA #$7f
    LDB #-$80
    JSR Print_Str_d
    ; Draw the player
    ; first, move to the pointer to player_x, player_y   
    ; display the enemies
    LDA player_y
    LDB player_x
    JSR Moveto_d
    ; now do the actuall drawing
    LDX #player_sprite
    JSR Draw_VLc
    ; now lets cycle through the list of enemies on the screen and display them.
    JSR Reset0Int
    LDA fall
    LDB #0
    JSR Moveto_d
    ; draw our bullet if we have one.
    LDB #01
    CMPB bullet_active
    BEQ done
    LDX #player_sprite
    JSR Draw_VLc
done
    JSR Reset0Int
    LDA #50
    LDB fall
    JSR Moveto_d
    LDX #player_sprite
    JSR Draw_VLc
    JSR Reset0Int
    LDA #10
    LDB fall
    JSR Moveto_d
    LDX #player_sprite
    JSR Draw_VLc
    JSR Reset0Int
    LDA #20
    LDB fall
    JSR Moveto_d
    LDX #player_sprite
    JSR Draw_VLc
    JSR Reset0Int
    LDA fall
    LDB #30
    JSR Moveto_d
    LDX #player_sprite
    JSR Draw_VLc
    DEC fall
    JMP main ; loop until the game ends.


fun
    ;PULS A
    INC count
    LDA player_y
    LDB player_x
    PSHS D
    LDA count
    PSHS A
    RTS
