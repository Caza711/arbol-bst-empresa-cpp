#include <iostream>
#include <string>
using namespace std;

// ===================== ESTRUCTURAS =====================

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

// ===================== CLASE BST =====================

class ArbolBST {
private:
    Nodo* raiz;

    // --- Insertar recursivo ---
    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }
        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } else {
            cout << "  [!] El codigo " << emp.codigo << " ya existe en el arbol.\n";
        }
        return nodo;
    }

    // --- Buscar recursivo ---
    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }
        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    // --- Recorridos ---
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }

    // --- Altura ---
    int altura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzq = altura(nodo->izquierdo);
        int alturaDer = altura(nodo->derecho);
        return 1 + max(alturaIzq, alturaDer);
    }

    // --- Nodos hoja ---
    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    // --- Contar hojas ---
    int contarHojas(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) return 1;
        return contarHojas(nodo->izquierdo) + contarHojas(nodo->derecho);
    }

    // --- Contar nodos ---
    int contarNodos(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + contarNodos(nodo->izquierdo) + contarNodos(nodo->derecho);
    }

    // --- Mostrar un empleado ---
    void mostrarEmpleado(Nodo* nodo) {
        cout << "  Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << "\n";
    }

public:
    ArbolBST() {
        raiz = nullptr;
    }

    // --- Metodos publicos ---

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);
        if (resultado != nullptr) {
            cout << "\n  Empleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\n  Empleado con codigo " << codigo << " no encontrado.\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\n  Raiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "  El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() {
        cout << "\n  Recorrido Inorden (orden ascendente por codigo):\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\n  Recorrido Preorden (raiz, izquierda, derecha):\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\n  Recorrido Postorden (izquierda, derecha, raiz):\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\n  Altura del arbol: " << altura(raiz) << " nivel(es)\n";
    }

    void mostrarNodosHoja() {
        cout << "\n  Nodos hoja (sin hijos):\n";
        mostrarHojas(raiz);
        cout << "  Total de hojas: " << contarHojas(raiz) << "\n";
    }

    void mostrarEstadisticas() {
        cout << "\n  === Estadisticas del arbol ===\n";
        cout << "  Total de nodos : " << contarNodos(raiz) << "\n";
        cout << "  Altura         : " << altura(raiz) << "\n";
        cout << "  Nodos hoja     : " << contarHojas(raiz) << "\n";
        if (raiz != nullptr) {
            cout << "  Raiz           : " << raiz->dato.nombre
                 << " (codigo " << raiz->dato.codigo << ")\n";
        }
    }

    bool estaVacio() {
        return raiz == nullptr;
    }
};

// ===================== SEPARADOR VISUAL =====================

void separador() {
    cout << "  ----------------------------------------\n";
}

// ===================== MAIN =====================

int main() {
    ArbolBST arbol;

    // --- Datos de prueba precargados (segun guia) ---
    cout << "  [INFO] Cargando datos de prueba...\n";

    Empleado datos[7];

    datos[0].codigo = 50; datos[0].nombre = "Empresa UTA";    datos[0].cargo = "Raiz";
    datos[1].codigo = 30; datos[1].nombre = "Gerente Ventas"; datos[1].cargo = "Nodo interno";
    datos[2].codigo = 70; datos[2].nombre = "Gerente Finanzas"; datos[2].cargo = "Nodo interno";
    datos[3].codigo = 20; datos[3].nombre = "Emp 1";          datos[3].cargo = "Hoja";
    datos[4].codigo = 40; datos[4].nombre = "Emp 2";          datos[4].cargo = "Hoja";
    datos[5].codigo = 60; datos[5].nombre = "Emp 3";          datos[5].cargo = "Hoja";
    datos[6].codigo = 80; datos[6].nombre = "Emp 4";          datos[6].cargo = "Hoja";

    for (int i = 0; i < 7; i++) {
        arbol.insertarEmpleado(datos[i]);
    }

    cout << "  [INFO] 7 empleados cargados correctamente.\n";

    // --- Menu principal ---
    int opcion;
    do {
        cout << "\n  ======================================\n";
        cout << "   MENU - ARBOL BST EMPRESARIAL\n";
        cout << "  ======================================\n";
        cout << "  1. Insertar empleado\n";
        cout << "  2. Buscar empleado por codigo\n";
        cout << "  3. Mostrar raiz del arbol\n";
        cout << "  4. Recorrido Inorden\n";
        cout << "  5. Recorrido Preorden\n";
        cout << "  6. Recorrido Postorden\n";
        cout << "  7. Mostrar altura del arbol\n";
        cout << "  8. Mostrar nodos hoja\n";
        cout << "  9. Estadisticas generales\n";
        cout << "  0. Salir\n";
        cout << "  Seleccione una opcion: ";
        cin >> opcion;
        separador();

        if (opcion == 1) {
            Empleado emp;
            cout << "  Codigo   : ";
            cin >> emp.codigo;
            cin.ignore();
            cout << "  Nombre   : ";
            getline(cin, emp.nombre);
            cout << "  Cargo    : ";
            getline(cin, emp.cargo);
            arbol.insertarEmpleado(emp);
            cout << "  Empleado insertado correctamente.\n";

        } else if (opcion == 2) {
            int codigo;
            cout << "  Ingrese codigo a buscar: ";
            cin >> codigo;
            arbol.buscarEmpleado(codigo);

        } else if (opcion == 3) {
            arbol.mostrarRaiz();

        } else if (opcion == 4) {
            arbol.mostrarInorden();

        } else if (opcion == 5) {
            arbol.mostrarPreorden();

        } else if (opcion == 6) {
            arbol.mostrarPostorden();

        } else if (opcion == 7) {
            arbol.mostrarAltura();

        } else if (opcion == 8) {
            arbol.mostrarNodosHoja();

        } else if (opcion == 9) {
            arbol.mostrarEstadisticas();

        } else if (opcion != 0) {
            cout << "  Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    cout << "\n  Programa finalizado.\n";
    return 0;
}
