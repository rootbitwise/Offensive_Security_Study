# PROYECTO : HEXACEDIMAL DUMP PARSER

* **DATE:** 14-07-2026 
* **DOCUMENTS:** LOGIC DESIGN
* **PROPOSITO DEL PROGRAMA:** PRACTICAR 
* **OBJETIVO DEL PROGRAMA:** SIMULAR UN ANALIZADOR DE PAYLOADS EN HEXADECIMAL.

--- 

> **LOGICA REQUERIDA:** Declarar un buffer de carecteres que simule un input binario.
> El programa debe recorrer el buffer bit a bit hasta encontrar el '\0' null terminador
> e imprimir por pantalla dos cosas por cada caracter (si es imprimible) : el caracter 
> en formato ASCII y el mismo caracter en su representacion hexadecimal (formateado %02X)


> **CRITERIO DE EXITO:** Debe reportar la cantidad toal de los bytes procesados y manejar
> correctamente un strings que contenga espacios sin romper el flujo del programa.  

---

**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+**
**| ESPECIFICACIONES DEL CONTRATO |** 
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+**

* **INPUT:** Un buffer de caracteres (source_buffer).

* **OUTPUT:** Imprimir los caracteres en formato hexadecimal, ASCII y tambien el total de bytes procesados.

* **LIMITS:** Limitar el procesamiento de datos del buffer a 64-byte para evitar un loop infinito e usar 
    de manera explicita el '\0' en la comparacion de la condicion del loop para evitar un OOB Read.

--- 

**+-+-+-+-+-+-+-+-+-+-+**
**| LOGICA DE LA RUTA |**
**+-+-+-+-+-+-+-+-+-+-+**

> **[!]** Las variables seran especificadas como unsigned de 64, (uint64_t).

* **(1)** Declara e Inicializar el buffer de tipo unsigned de 64. 

* **(2)** Inicializar un contador en 0 para hacer un segumiento de los bits procesados.

* **(3)** Leer los carecteres del buffer, comprobar si es el caracter nulo, si no lo es, 
        capturar el bit que esta en la posicion del indice.

* **(4)** En cada iteracion por cada bit capturado, incrementar 1 al contador.

* **(5)** Dividir el total del contador entre 8 para sacar el total de bytes del buffer.

* **(6)** Si el total de bytes es mayor a 64 bytes abortar el programa, si no lo es,
        imprmir los caracteres del buffer en su representacion numerica, hexadecimal y ASCII correspondientes.

* **(7)** Repetir hasta encontrar el null terminador en el buffer '\0'

* **(8)** Imprimir el total de bytes obtenidos.

---

**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+**
**| CASOS LIMITES Y MEDIDAS DE NITIGACION |**
**+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+**

* **CASO A:** La cadena empieza con el '\0', (es un stirngs vacio).
> **MITIGACION:** La condicion del loop debe terminar inmediatamente en el indice 0.

* **CASO B:** Confundir un espacio en balnco con el null terminador.
> **MITIGACION:** Comprobar si el valor del caracter es 0 o si es cualquier valor distinto de 0. 

* **CASO C:** La cadena es maliciosa, o esta mal formada y carece de un null terminador.
> **MITIGACION:** 

---

**+-+-+-+-+-+-+-+-+-+-+-+**
**| LOGICA PSEUDOCODIGO |**
**+-+-+-+-+-+-+-+-+-+-+-+**

INICIALIZAR Y DEFINIR source_buffer[]
DEFINIR Contador = 0

    WHILE SI source_buffer[index] ES DISTINDO DE '\0' HACER 
                
       CAPTURAR EL BIT EN LA POSICION DEL INDEX
        CONTADOR =+ BIT CAPTURADO     
                    
        VALIDADOR = DIVIDIR CONTADOR ENTRE 8

            IF VALIDADOR ES MAYOR O IGUAL AL LIMITE MAXIMO PERMITIDO THEN 
                PRINT "[!] La cadena excede el limite permitido" // se aborta el programa para prevenir un OOB Read.
                BREAK LOOP
            AND IF

### **PROCESO DE EJECUCION**

        IMPRIMIR FORMATO ASCII source_buffer[index]
        IMPRIMIT FORMATO DECIMAL source_buffer[index]
        IMPRIMIR FORMATO HEXADECIMAL (formateado %02X) source_buffer[index]

    FIN DEL WHILE

IMPRIMIR EL TOTAL DE VALIDADOR

**FIN PSEUDOCODIGO** 
