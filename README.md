# 🌳 Arbol Binario de Busqueda (BST) - Organigrama Empresarial

**Asignatura:** Estructura de Datos  
**Facultad:** FISEI - Universidad Tecnica de Ambato  
**Ciclo:** Enero - Julio 2026  
**Estudiante:** Justin Ojeda  

---

## 📋 Objetivo

Implementar en C++ un Arbol Binario de Busqueda (BST) para organizar empleados de una empresa
usando un codigo numerico como clave. El ejercicio se relaciona con el organigrama empresarial,
donde se identifican raiz, niveles, nodos internos y hojas.

---

## 👤 Integrantes del Grupo

| Rol | Nombre | Responsabilidad |
|-----|--------|-----------------|
| Lider | Justin Ojeda | Coordina el avance y revisa el repositorio |
| Programador 1 | Justin Ojeda | Implementa estructura Nodo y funcion insertar |
| Programador 2 | Justin Ojeda | Implementa busqueda y recorridos |
| Programador 3 | Justin Ojeda | Implementa altura y hojas |
| Documentador | Justin Ojeda | Crea README, capturas y explicacion |
| Expositor | Justin Ojeda | Presenta funcionamiento y conclusiones |

---

## 📁 Estructura del Repositorio
50 (Empresa UTA)
    /                \
    30 (G. Ventas)    70 (G. Finanzas)
/       \           /        
20(H)    40(H)      60(H)     80(H)
---

## 🔨 Compilacion y Ejecucion

**Linux / Mac:**
```bash
g++ main.cpp -o arbol -std=c++11
./arbol
```

**Windows (Dev-C++ / MinGW):**
```bash
g++ main.cpp -o arbol.exe -std=c++11
arbol.exe
```

---

## 📸 Capturas de Ejecucion

### Compilacion exitosa
![Compilacion](capturas/captura1_compilacion.png)

### Menu principal
![Menu](capturas/captura2_menu.png)

### Insercion y busqueda de empleados
![Insercion y busqueda](capturas/captura3_insercion_busqueda.png)

### Recorridos Inorden y Preorden
![Recorridos](capturas/captura4_recorridos.png)

### Recorrido Postorden
![Postorden](capturas/captura5_postorden.png)

### Altura, nodos hoja y estadisticas
![Estadisticas](capturas/captura6_altura_hojas_stats.png)

---

## 📚 Conceptos Clave

| Termino | Definicion | Ejemplo en el arbol |
|---------|-----------|---------------------|
| Raiz | Nodo inicial del arbol, sin padre | Codigo 50 - Empresa UTA |
| Nodo interno | Nodo con al menos un hijo | Codigos 30 y 70 |
| Hoja | Nodo sin hijos | Codigos 20, 40, 60, 80 |
| Nivel | Distancia desde la raiz hasta un nodo | Nivel 0: raiz, Nivel 1: 30 y 70 |
| Altura | Nivel maximo del arbol | Altura = 3 |
| BST | Hijo izquierdo menor, derecho mayor | 50 > 30 (izq), 50 < 70 (der) |

---

## 📊 Rubrica de Evaluacion

| Criterio | Puntaje |
|----------|---------|
| Implementacion correcta del arbol BST | 2.0 |
| Insercion y busqueda funcional | 2.0 |
| Recorridos correctamente implementados | 1.5 |
| Altura, raiz y hojas correctamente mostradas | 1.5 |
| Uso adecuado de GitHub y commits grupales | 1.0 |
| README, capturas y documentacion | 1.0 |
| Exposicion clara del funcionamiento | 1.0 |
| **TOTAL** | **10.0** |

---

## ✅ Evidencia Entregada

- [x] Link del repositorio GitHub
- [x] Codigo fuente en C++ (`main.cpp`)
- [x] README completo con documentacion
- [x] Capturas de ejecucion del programa
- [x] Explicacion de conceptos: raiz, nodo interno, hoja, nivel y altura
- [x] Commits del estudiante en el historial

---

## 💡 Conclusion

El Arbol Binario de Busqueda (BST) permite organizar informacion jerarquica de manera eficiente.
La busqueda, insercion y recorridos tienen complejidad O(log n) en casos balanceados, lo que lo
hace ideal para directorios empresariales y estructuras de datos ordenadas.

A traves de este ejercicio se identificaron correctamente los conceptos fundamentales de los
arboles: raiz, nodos internos, hojas, niveles y altura, aplicandolos en un contexto empresarial
real con el organigrama de la empresa UTA.

---

*Justin Ojeda — FISEI UTA — Ciclo Enero-Julio 2026*
