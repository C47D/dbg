# DBG

Librería para mandar mensajes de depuración por el puerto serial del microcontrolador.

# ¿Como funciona?

La librería redefine la funcion `_putchar` enviando por la UART el caracter recibido,
con esto todas las llamadas a `printf` llaman a nuestro `_putchar`.

Si necesitas portar la librería a microcontroladores que no sean de ST, solo cambia
el contenido de `_putchar` con la funcion que se encarga de enviar caracteres por el serial.

# ¿Como utilizar la libreria?

1. Clona este repositorio en tu proyecto:
```
git clone --recurse-submodules https://github.com/C47D/dbg.git
```

2. Entra al directorio `dbg` y actualiza los submodulos
```
cd dbg
git submodule update --init --recursive
```

## Agregar como submodulo

Para agregar la librería como submodulo (estando en la raiz de tu directorio):
```
$ git submodule add https://github.com/C47D/dbg.git
$ cd dbg
$ git submodule init
$ git submodule update
```
