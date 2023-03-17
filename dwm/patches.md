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

## Rama 03-fullgaps
En esta rama pongo unos parches para la gestión más bonita/estética de gestor de ventanas. El primero me pone gaps entre las ventas. El segundo permite tener un layout diferente en cada uno de los tags del DWM. Por último el parche para esconder los tags que no están siendo utilizados y hacer algo más de sitio así.

01. dwm-fullgaps-20200508-7b77734.diff
02. dwm-pertag-20200914-61bb8b2.diff
03. dwm-hide_vacant_tags-6.3.diff

## Rama 04-Scratchpads
En esta rama uso el partche named scratchpads que me mola como funciona. Para evitar que me salgan las ventanas por ahí donde no quiero, voy a añadir el partch alwayscenter (todas las ventanas flotantes, scratchpads, etc. iran al centro de la pantalla)

01. dwm-namedscratchpads-6.2.diff
02. dwm-alwayscenter-20200625-f04cac6.diff
03. dwm-cursorwarp-20210222-61bb8b2.diff

Utilizo además el "cursorwarp" de forma que cuando cambio de monitor o de ventana en el stack, el cursor se vaya con el foco. -- Hay varias opciones de cursorwarp, y por otra parte, el parche está implementado de forma mucho más fácil  que el parche "warp".

## Rama 05-gridlayout
Un Layout que me gusta bastante y que me resulta muy útil es el layout en grid.

01. dwm-gridmode-5.8.2.diff

Este layout tiene que "configurarse" un poco --  Primero, hay que cambiar el listado de layouts como sigue en el fichero **config.def.h** para poder seguir usando correctamente el plugin para rotar los layouts (cyclelaouts -- si no se hace peta el dwm):

```
...
#include "grid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
	{ NULL,       NULL },
};
```

Por otra parte, éste layout no tiene gaps. Por ello, he hecho un parche para el layout fundamental que está implementado en el fichero **grid.c**-

Instalo además un parche para poner las ventanas en "fullscreen" y volverlas a poner normal.

02. dwm-fullscreen-6.2.diff
