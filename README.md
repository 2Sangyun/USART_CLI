# USART_CLI
## This is CLI using USART communication. Target Board is NUCLEO-F429ZI.

### 1. Command Set
> history
>
> help
>
> md
>
> download
>
> run


### 2. Explain Commands

- history
  > You can use this command by "history" or "history [num]".
  > 
  > This command will show you previous commands that you wrote.

- help
  > This command will show you Command Sets.

- md 
  > This command will provide "Memory Read" Function.
  >
  > You can use this command by "md 0x08000000 64".
  >
  > Last number will Nth power of 2.

- download
  > This command will download Firmware(.bin file) in Application Sector. (In Flash Memory)
  > 
  > As Like As IAP(In Application Programming).

- run
  > This command provide Jump to Application Sector.
  > 
  > Before you use, must operate "download" command.


### 3. Other Function
- Up & Down direction key
- Tab key
  > Provide Automatic completion Func.
