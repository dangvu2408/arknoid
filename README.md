# arknoid game - STM32 NUCLEO-F401RE Develop Kit

arknoid là game chạy trên STM32 Nucleo-F401RE hiển thị trên màn OLED SPI (Ucglib). Điều khiển bằng nút nhấn (SW1–SW5), có buzzer báo khi nhấn nút điều khiển. Nháy đèn LED khi kết thúc game.

> Vòng đời chương trình: `MENU -> GAME -> GAME OVER/LEVEL CLEAR -> MENU`

## Tính năng của game

- 3 level: Dễ (1) - Trung bình (2) - Khó (3).
- Ấn B2 để di chuyển thanh sang trái, B4 để di chuyển thanh sang phải.
- LED nháy 6 lần khi Game Over, 3 lần khi Level Clear.
- Buzzer sẽ kêu khi ấn nút bấm.

## Cấu trúc dự án

```
.
├── Inc/
│   ├── drivers/
│   │   ├── gpio.h
|   │   └── timebase.h
│   ├── game/ 
│   │   ├── collision.h
│   │   ├── entities.h
│   │   ├── levels.h
│   │   ├── menu_ui.h
│   │   └── run_game.h
│   ├── graphic/ 
│   │   ├── display_init.h
│   │   └── render.h
│   ├── periph/ 
│   │   ├── button.h
│   │   ├── buzzer.h
│   │   └── led.h
│   └── boardconfig.c  
│
├── Src/
│   ├── drivers/
│   │   ├── gpio.c
|   │   └── timebase.c
│   ├── game/ 
│   │   ├── collision.c
│   │   ├── entities.c
│   │   ├── levels.c
│   │   ├── menu_ui.c
│   │   └── run_game.c
│   ├── graphic/ 
│   │   ├── display_init.c
│   │   └── render.c
│   ├── periph/ 
│   │   ├── button.c
│   │   ├── buzzer.c
│   │   └── led.c
│   └── main.c               
│
├── Startup/                  
├── Debug/                    
├── .project / .cproject      
├── arknoid Debug.launch  
├── STM32F401RETX_FLASH.ld    
├── STM32F401RETX_RAM.ld      
└── README.md
```