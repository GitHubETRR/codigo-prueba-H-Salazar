#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream> //para los archivos
using namespace std;

typedef enum {
    DEPOSITO=1,
    EXTRAER,
    TRANSFERIR,
    CERRAR
}opciones_t;

class Cuenta{
private:
    int id;
    string nombre;
    string pin;
    int saldo;

public:
    //constructor: inicializa los objetos de la clase
    Cuenta() {
        id=0;
        nombre="";
        pin="";
        saldo=0;
    }

    //acceso para los datos
    int getId() { return id; }
    void setId(int nuevoId) { id=nuevoId; }
    string getNombre() { return nombre; }
    void setNombre(string nuevoNombre) { nombre=nuevoNombre; }
    string getPin() { return pin; }
    void setPin(string nuevoPin) { pin=nuevoPin; }

    //manejo de saldo
    int getSaldo() { return saldo; }
    void setSaldo(int nuevoSaldo) { saldo=nuevoSaldo; }
    void agregarSaldo(int monto) { saldo+=monto; }
    bool retirarSaldo(int monto) { //bool porque luego lo uso en extraccion para cout es mensaje
        if (monto<=saldo) {     //pero esa comparacion tambien la puedo hacer aqui directamente
            saldo-=monto;
            return true;
        }
        return false;
    }
};

class Banco{
    private:
        vector<Cuenta>cuentas; //crea un vector tipo cuenta llamado cuentas
    public:
        void menuPrincipal();
        void menuUsuario(Cuenta&cuenta);
        void crearCuenta();
        string pedirPin(void);
        int logIn();
        void deposito(Cuenta&cuenta);
        void extracion(Cuenta&cuenta);
        Cuenta* buscarCuenta(int id);
        void transferir(Cuenta&cuenta);
        void guardarCuentas();
        void cargarCuentas();
}; 

int main()
{
    Banco banco; //creo un objeto de clase Banco
    banco.menuPrincipal();
    return 0;
}

void Banco::menuPrincipal(){
    cargarCuentas();
    int opcion, user;
    do{
        cout<< "\n---Bienvenido---";
        cout<< "\n1. Crear cuenta\n2. Iniciar sesion\n3. Salir";
        cout<< "\nIngrese una opcion:\n-->";
        cin>> opcion;

        switch(opcion){
            case 1:
                crearCuenta();
                break;
            case 2:
                user=logIn();
                if (user!=-1) menuUsuario(cuentas[user]); 
                //se mete a cuentas, [user] se remplaza por la pos del vector
                else cout<< "ID o PIN incorrecto\n";
                break;
            case 3:
                cout<< "\nSaliendo...\n";
                guardarCuentas();
                break;
            default:
                cout<< "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    }while(opcion!=3);
}

void Banco::crearCuenta(){
    Cuenta nueva; //variable llamada nueva de tipo Cuenta
    string nombre;
    cout<<"Ingrese su nombre:\n-->";
    cin>>nombre;
    nueva.setNombre(nombre);
    nueva.setPin(pedirPin()); 
    if (cuentas.empty()) nueva.setId(1); //era antes nueva.id=1;
    //cuentas.empty() devuelve true si no hay cuentas
    else nueva.setId(cuentas.back().getId() + 1);
    //cuentas.back() devuelve la ultima cuenta del vector
    //en este caso solo queria el .id
    nueva.setSaldo(0); 
    cuentas.push_back(nueva);
    //push_back inserta un nuevo elemento al final
    //es para agregar la cuenta al final del vector
    cout<< "Cuenta creada exitosamente!!\n";
    cout<< "Su ID es: "<< nueva.getId() <<"\n";
}

string Banco::pedirPin(void){
    string pin;
    while (1){
        cout<< "Ingrese un PIN de 4 digitos:\n";
        cin>> pin;
        if (pin.length()!=4){
            cout<< "Pin invalido. Debe tener 4 digitos\n";
            continue;//para que vuelva a ingresar pin
        }
        int contNum=0;
        for (size_t i=0; i<pin.length(); i++){
            if (isdigit(pin[i])) contNum++; //isdigit comprueba si es digito
        }
        if (contNum==4) break;
        cout<< "Pin invalido. Debe tener 4 digitos\n";

    }
    return pin;
}

int Banco::logIn(){
    int id;
    string pin;
    cout<< "Ingrese su ID\n-->";
    cin>>id;
    cout<< "Ingrese su PIN\n-->";
    pin=pedirPin();
    for (size_t i=0; i<cuentas.size(); i++){
        if (cuentas[i].getId() == id && cuentas[i].getPin() == pin){
            return i;
        }
    }
    return -1;

}

void Banco::menuUsuario(Cuenta&cuenta){
    int op;
    do{
        cout<< "\n---Bienvenido, "<< cuenta.getNombre() << "---"; 
        cout<< "\nSaldo actual: $" << cuenta.getSaldo() << "\n"; 
        cout<< "\n1. Depositar\n2. Extraer";
        cout<<"\n3. Transferir a otra cuenta\n4. Cerrar sesion\n";
        cout<< "\nIngrese una opcion:\n-->";
        cin>> op;

        switch(op){
            case DEPOSITO:
            deposito(cuenta);
                break;
            case EXTRAER:
            extracion(cuenta);
                break;
            case TRANSFERIR:
            transferir(cuenta);
                break;
            case CERRAR:
            cout<< "\nLoging out...\n";
                break;
            default:
            cout<< "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }

    } while(op!=CERRAR);
}

void Banco::deposito(Cuenta&cuenta){
    int monto;
    cout<< "\nIngrese monto a depositar.\n-->";
    cin>> monto;
    if (monto>0){
        cuenta.agregarSaldo(monto); //use metodo antes era cuenta.saldo+=monto
        cout<< "\nDeposito exitoso!!\n";
    }
    else cout<< "\nMonto invalido.\n";
}

void Banco::extracion(Cuenta&cuenta){
    int monto;
    cout<< "\nIngrese monto a retirar.\n-->";
    cin>> monto;
    if (cuenta.retirarSaldo(monto)){
        cout<< "\nRetiro exitoso!!\n";
    }
    else cout<< "\nSaldo insuficiente o monto invalido.\n";
}

Cuenta* Banco::buscarCuenta(int id){
    for (size_t i=0; i<cuentas.size(); i++){
        if (cuentas[i].getId() == id){ 
            return &cuentas[i];
        }
    }
    return nullptr;//si no encuentra el id
}

void Banco::transferir(Cuenta&cuenta){
    int iddestino, monto;
    cout<< "Ingrese el ID de la cuenta destino:\n";
    cin>> iddestino;
    Cuenta*destino=buscarCuenta(iddestino);
    if (destino!=nullptr && destino->getId()!=cuenta.getId()){ 
        cout<< "\nIngrese monto a depositar.\n-->";
        cin>> monto;
        if (monto>0 && cuenta.retirarSaldo(monto)){ 
            destino->agregarSaldo(monto); 
            cout<< "\nTransferencia exitosa!!\n";
        }
        else cout<< "\nSaldo insuficiente o monto invalido.\n";
    }
    else cout<< "\nCuenta de destino invalida\n";
}

void Banco::guardarCuentas(){
    ofstream archivo("cuentas.txt"); //ofstream archivo de salida
    if (!archivo){
        cout<< "Error\n";
        return;
    }
    for (size_t i=0; i<cuentas.size(); i++){
        archivo<< cuentas[i].getId()<< " "<< cuentas[i].getNombre()<< " "<< cuentas[i].getPin()<< " "<< cuentas[i].getSaldo()<< "\n";
        //es como un cout. los " " es para agregar un espacio entre datos
    }
    archivo.close();
}

void Banco::cargarCuentas(){
    ifstream archivo("cuentas.txt");
    cuentas.clear();
    int id, saldo;
    string nombre, pin;
    while (archivo>> id>> nombre>> pin>> saldo){
        //es como tener un cin pero lee el archivo
        Cuenta nueva;
        nueva.setId(id);
        nueva.setNombre(nombre);
        nueva.setPin(pin);
        nueva.setSaldo(saldo);
        cuentas.push_back(nueva);
    }
    archivo.close();
}