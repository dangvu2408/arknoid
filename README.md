# arknoid game - STM32 NUCLEO-F401RE Develop Kit

Game arknoid chạy trên STM32 Nucleo-F401RE với OLED SPI (Ucglib). Điều khiển bằng nút nhấn (SW1–SW5), có buzzer báo khi nhấn nút điều khiển. Nháy đèn led khi kết thúc game.

## Cấu trúc dự án

```
.
├── Inc/
│   └── drivers/
│       └── timebase.h
|
├── Src/
│   ├── drivers/
│   │   └── timebase.c
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