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
    STA bullet_x
    STA bullet_y

;; the main game loop.
main
    ;; check status
    LDB #00
    CMPB bullet_active
    BEQ no_bullet
    LDB #$75
    CMPB bullet_y
    BGT in_frame
    LDA #0
    STA  bullet_active
    BRA no_bullet
in_frame
    LDA bullet_y
    ADDA #5
    STA bullet_y
no_bullet
    ;; read input
    ; we care about left/right movement.
    JSR Joy_Digital
    LDA Vec_Joy_1_X
    BEQ no_movement
    BMI left_movement

right_movement
    INC player_x
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
    LDA #01
    CMPA bullet_active
    BEQ no_button
    LDA player_x
    STA bullet_x
    LDA player_y
    STA bullet_y
    LDA #1
    STA bullet_active 

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
    ; now do the actual drawing
    LDX #player_sprite
    JSR Draw_VLc
    ; now lets cycle through the list of enemies on the screen and display them.
    ; draw our bullet if we have one.
    LDB #00
    CMPB bullet_active
    BEQ done
    JSR Reset0Int
    LDA bullet_y
    LDB bullet_x
    JSR Moveto_d
    LDX #bullet_sprite
    JSR Draw_VLc
done
    DEC fall
    JMP main ; loop until the game ends.

; subroutine used to fix the pen so we can render more objects.
; use like a normal Moveto_d.
; not sure if this is actually a good way of displaying stuff,
; but it works and I'm at a hackathon.
resetpen
    JSR Reset0Int
    JSR Moveto_d
    RTS

