# Configuración de DWM
Lo primero que hago es cambiar el fichero config.def.h de forma que la tecla MODKEY sea la tecla "Win" y no la tecla "Alt" `#define MODKEY Mod4Mask`

01. dwm-restartsig-20180523-6.2.diff
02. dwm-autostart-20161205-bb3bd6f.diff
03. dwm-status2d-systray-6.4.diff
  Permite poner comandos del tipo con colores: `xsetroot -name "[status2d] ^c#FF0000^red text with blue rectangle^c#55cdfc^^r3,3,14,14^^f20^^c#FFFFFF^^b#f7a8b8^ and white text on pink background "`
  
  Además, cambio la tecla de cerrar ventana/quitar dwm -- Me mata esa combinación.
  
  Esto es el principio de todo y mi rama "master" --
  
## Rama 02-cycle-layouts
En esta rama voy a poner el parche cycle layouts para que puedan rotar los layouts, que se puedan rotar las ventanas dentro de la pila y que se añadan las ventanas al final del stack en lugar de al principio.

04. dwm-cyclelayouts-20180524-6.2.diff
05. dwm-movestack 
	 En la que tengo un pequeño "reject" en el fichero config.def.h, pero se resuelve muy fácil

06. 	dwm-attachbottom-6.3.diff
  	También me genera un "reject" en el fichero dwm.c pero sin mayor complicación.

