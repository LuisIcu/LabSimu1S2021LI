#!/bin/bash

#1. Crear archivo "climaguate" donde estén los datos descargados de wttr.in/Guatemala
curl -o climaguate wttr.in/Guatemala

#2. Crear archivo "climaguate7" donde estén las primeras 7 líneas de ese archivo
touch climaguate7
head -n 7 climaguate > climaguate7

#3. Mostrar el archivo "climaguate7" en terminal
cat climaguate7

#4. Eliminamos "climaguate" y "climaguate7"
rm climaguate
rm climaguate7
