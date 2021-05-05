#!/bin/bash

#Leer nombre
read -p "Ingresar nombre: " nombre
nuevoarch=$nombre".c"

#Obtener datos
autor=$(whoami)
compilador=$(gcc --version | head -n 1)
fecha=$(date)

#Agregar líneas al archivo

echo "/*" >> $nuevoarch
echo "Autor:  $autor" >> $nuevoarch
echo "Compilador:  $compilador" >> $nuevoarch
echo "Para compilar: gcc $nuevoarch -lm -o $nombre" >> $nuevoarch
echo "Fecha: $fecha" >> $nuevoarch
echo "Librerías: " >> $nuevoarch
echo "Resumen: " >> $nuevoarch
echo "Entrada: " >> $nuevoarch
echo "Salida: " >> $nuevoarch
echo "*/" >> $nuevoarch
echo " " >> $nuevoarch
echo "//Librerías" >> $nuevoarch
echo "#include <stdio.h>" >> $nuevoarch
echo "#include <math.h>" >> $nuevoarch
echo "" >> $nuevoarch

