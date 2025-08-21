#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

typedef enum { 
    DEPOSITO=1, 
    EXTRAER,
    TRANSFERIR,
    CERRAR,
}opciones_t;

struct Cuenta{
    int id;
    string nombre;
    string pin;
    int saldo;
};

void menuPrincipal(vector<Cuenta>&cuentas); //& le paso la lista og no copy
void menuUsuario(Cuenta&cuenta, vector<Cuenta>&cuentas);
void crearCuenta(vector<Cuenta>&cuentas);
string pedirPin(void);
int logIn(vector<Cuenta>&cuentas);

int main()
{
    vector<Cuenta>cuentas; //crea un vector tipo cuenta llamado cuentas
    menuPrincipal(cuentas);

    return 0;
}

void menuPrincipal(vector<Cuenta>&cuentas){
    int opcion;
    do{
        cout<< "\n---Bienvenido---";
        cout<< "\n1. Crear cuenta\n2. Iniciar sesion\n3. Salir";
        cout<< "\nIngrese una opcion:\n-->";
        cin>> opcion;

        switch(opcion){
            case 1:
                crearCuenta(cuentas);
                break;
            case 2:
                int user=logIn(cuentas);
                if (user!=-1) menuUsuario(cuentas[user], cuentas);
                else cout<< "ID o PIN incorrecto\n";
                break;
            case 3:
                cout<< "\nSaliendo...\n";
                break;
            default:
                cout<< "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    }while(opcion != 3);
}

void crearCuenta(vector<Cuenta>&cuentas){
    Cuenta nueva; //variable llamada nueva de tipo Cuenta
    cout<<"Ingrese su nombre:\n-->";
    cin>>nueva.nombre;
    nueva.pin=pedirPin();
    if (cuentas.empty()) nueva.id=1; 
    //cuentas.empty() devuelve true si no hay cuentas
    else nueva.id=cuentas.back().id + 1;
    //cuentas.back() devuelve la ultima cuenta del vector
    //en este caso solo queria el .id
    nueva.saldo=0;
    cuentas.push_back(nueva);
    //push_back inserta un nuevo elemento al final
    //es para agregar la cuenta al final del vector
    cout<< "Cuenta creada exitosamente!!\n";
    cout<< "Su ID es: "<< nueva.id <<"\n";
}

string pedirPin(void){
    string pin;
    while (1){
        cout<< "Ingrese un PIN de 4 digitos:\n";
        cin>> pin;
        if (pin.length()!=4){
            cout<< "Pin invalido. Debe tener 4 digitos\n";
            continue;
        }
        int contNum=0;
        for (int i=0; i<pin.length(); i++){
            if (isdigit(pin[i])) contNum++;
            //isdigit comprueba si es digito
        }
        if (contNum==4) break;
        cout<< "Pin invalido. Debe tener 4 digitos\n";

    }
    return pin;
}

int logIn(vector<Cuenta>&cuentas){
    int id;
    string pin;
    cout<< "Ingrese su ID\n-->";
    cin>>id;
    cout<< "Ingrese su ID\n-->";
    pin=pedirPin;
    for (int i=0; i<(int)cuentas.size(); i++){
        if (cuentas[i].id ==id && cuentas[i].pin == pin){
            return i;
        }
    }
    return -1;

}

void menuUsuario(Cuenta&cuenta, vector<Cuenta>&cuentas){
    int op, monto, iddestino;
    do{
        cout<< "\n---Bienvenido, "<< cuenta.nombre << "---";
        cout<< "Saldo actual: $" << cuenta.saldo << "\n";
        cout<< "\n1. Depositar\n2. Extraer";
        cout<<"\n3. Transferir a otra cuenta\n4. Cerrar sesion\n";
        cout<< "\nIngrese una opcion:\n-->";
        cin>> op;

        switch(op){
            case DEPOSITO:
            cout<< "\nIngrese monto a depositar.\n-->";
            cin>> monto;
            if (monto!=0){
                cuenta.saldo+=monto;                //PASAR A FUNCION
                cout<< "\nDeposito exitoso!!\n";
            }
            else cout<< "\nMonto invalido.\n"
                break;
            case EXTRAER:
            cout<< "\nIngrese monto a retirar.\n-->";
            cin>> monto;                                //PASAR A FUNCION
            if (monto>0 && cuenta.saldo=>monto){
                cuenta.saldo-=monto;
                cout<< "\nRetiro exitoso!!\n";
            }
            else cout<< "\nSaldo insuficiente o monto invalido.\n"
                break;
            case TRANSFERIR:
            cout<< "Ingrese el ID de la cuenta destino\n"
                break;
            case CERRAR:

                break;
            default:
            cout<< "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }

    } while(opcion!=5);
}
