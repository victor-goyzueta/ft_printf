# ft_printf

# Objetivo general de `ft_printf`

El objetivo de `ft_printf` es reproducir las funcionalidades básicas de la función estándar `printf`, pero enfocándonos en un conjunto limitado de especificadores de formato (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`). Para lograrlo, implementaremos subfunciones que manejen cada tipo de formato, así como los mecanismos necesarios para extraer y contar los caracteres impresos.

```c
int ft_printf(const char *format, ...)
```

---

## 1. Estructura General de `ft_printf`

`ft_printf` debe recorrer el string de `format`, procesando cada carácter. Al encontrar un carácter `%`, activará la función `conver_type` que, con ayuda de la lista de argumentos `va_list`, identificará y manejará el tipo de formato según el carácter especificador que siga a `%`. Las funciones esenciales incluyen:

- **`conver_type`**: Identifica el especificador de formato y llama a la función correspondiente para manejarlo.

    ```c
    static int conver_type(va_list args, char const *format)
    ```

- **Funciones específicas de impresión**: Estas funciones imprimen el valor del argumento formateado según el especificador y devuelven el valor del contador de cada carácter impreso.
    - `ft_putchar`
    - `ft_putstr`
    - `ft_putnbr`
    - `ft_putunnbr`
    - `ft_puthex`
    - `ft_putptr`

---

## 2. Manejo de Argumentos con `va_list`

Dado que `ft_printf` utiliza argumentos variables, `va_list` y las macros `va_start`, `va_arg`, y `va_end` son esenciales para gestionar estos argumentos:

- **`va_start`**: Inicializa la lista de argumentos `va_list`, apuntando al primer argumento variable.
- **`va_arg`**: Extrae cada argumento de `va_list` según el tipo de dato esperado.
- **`va_end`**: Limpia la lista de argumentos.

El prototipo para `ft_printf` debe incluir un parámetro `const char *format`, seguido de `...` para los argumentos variables.

---

## 3. Estructura y Funcionamiento de `conver_type`

La función `conver_type` se encarga de:

1. **Recibir el carácter** que sigue a `%`, representando el tipo de formato.
2. **Identificar el tipo de conversión** usando una estructura `if-else`, basada en el valor del carácter.
3. **Llamar a la función adecuada** para manejar el tipo de dato que corresponde al especificador y pasarle el valor extraído de `va_list`.

### Parámetros de `conver_type`

- `va_args`: Permite extraer el argumento correspondiente al especificador de formato.
- `char *format`: El especificador de formato que sigue al símbolo `%`.
- `int counts`: La variable a un contador para acumular el número total de caracteres impresos.

**Consideraciones**:

- Cada función específica debe retornar el número de caracteres impresos, de modo que `conver_type` acumule esta cantidad en `counts`.
- `conver_type` devuelve `-1` en caso de encontrar un especificador inválido.

---

## 4. Funciones Específicas de Impresión

Cada especificador necesita su propia función de impresión, como :
    - `ft_putchar` para carácteres individuales.
    - `ft_putstr` para cadena de carácteres.
    - `ft_putnbr` para numeros enteros.
    - `ft_putunnbr` para números enteros sin signo.
    - `ft_puthex` para bases hexadecimales.
    - `ft_putptr` para direcciones de memoria.

### Ejemplos de Comportamiento Esperado

1. **Función para caracteres (`c`)**:
    - Toma un carácter como argumento y lo imprime.
    - Aumenta el contador `counts` en uno.
2. **Función para cadenas (`s`)**:
    - Imprime cada carácter de la cadena pasada como argumento.
    - Aumenta `counts` en la cantidad de caracteres impresos.
3. **Función para enteros (`d` o `i`)**:
    - Imprime el entero del valor pasado como argumento.
    - Aumenta `count` en la cantidad de dígitos impresos, contando con el signo (`-`) si el entero fuese negativo.
4. **Función para hexadecimales (`x` o `X`)**:
    - Imprime el hexadecimal del valor pasado como argumento.
    - Aumento `count` en la cantidad de caracteres impresos.
5. **Función para direcciones de memoria (`p`)**:
    - Imprime la dirección de memoria del argumento.
    - Aumenta `count` en la cantidad de caracteres de los que conste la dirección impresa.
6. **Función para % (`%`)**:
    - Imprime el carácter %.
    - Aumenta `count` en uno.

Estas funciones deben ajustarse para devolver el número de caracteres impresos, y `conver_type` las usará para actualizar el contador total.

---

## 5. Actualización del Contador de Caracteres (`counts`)

Dado que `ft_printf` necesita llevar el conteo total de caracteres impresos, la variable `counts` en `conver_type` permite actualizar este valor de manera eficiente.

### Cómo Se Actualiza `counts`

1. En cada llamada a una función de impresión específica, se utiliza `counts += ...` para aumentar el contador.
2. Cada función de impresión devuelve el número de caracteres impresos para que `counts` se incremente correctamente.
3. En `ft_printf`, al salir de cada ciclo de formato, `counts` representa el número acumulado de caracteres impresos y se devuelve al final de la función.

---

## 6. Manejo de Errores

Si `conver_type` encuentra un especificador inválido (un carácter desconocido después de `%`), devuelve `-1`. Este valor se utiliza en `ft_printf` para detectar errores y salir de la función antes de terminar el proceso.

---

## 7. Ejecución General de `ft_printf`

El flujo de `ft_printf` puede resumirse en los siguientes pasos:

1. Inicializa `counts` en `0` y llama a `va_start`.
2. Recorre `format`, analizando cada carácter.
    - Si encuentra un `%`, llama a `conver_type`.
    - Si es un carácter regular, lo imprime directamente y actualiza `counts`.
3. Llama a `va_end` una vez que ha procesado todos los caracteres.
4. Devuelve el valor acumulado en `counts` como el total de caracteres impresos.
