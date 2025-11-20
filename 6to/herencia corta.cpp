#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
    public:
        string marca;
        string estado;
        Vehiculo(string m): marca(m) {}
        void encender() {
            estado="encendido";
            cout<< marca<< " se ha encendido\n";
        }
        void apagar() {
            estado="encendido";
            cout<< marca<< " se ha apagado\n";
        }
        void frenar() {
            cout<< marca<< " está frenado\n";
        }
};

class Terrestre: public Vehiculo{
    public:
        int cantidad_ruedas;
        Terrestre(string m, int r): Vehiculo(m), cantidad_ruedas(r) {}
        void avanzar() {
            if(estado!="encendido"){
                cout<< "No puedes avanzar el auto no está encendido\n";
                return;
            }
            int metros;
            cout<< "Metros a avanzar con "<< marca<<"\n";
            cin>> metros;
            cout<< marca << " avanza "<< metros<< " metros sobre "<< cantidad_ruedas<< " ruedas\n";
        }
};

class Auto: public Terrestre{
    public:
        int puertas;
        Auto(string m, int r, int p): Terrestre(m, r), puertas(p){}
        void tocarBocina() {
            cout<< "PI PI\n";
        }
        void tipoAuto(){
            if(puertas == 2) cout<< marca<< " es un auto deportivo de 2 puertas\n";
            else if(puertas == 4) cout<< marca<<" es un auto familiar de 4 puertas\n";
            else cout<< marca<< " tiene "<< " puertas\n";
        }
};

class Deportivo: public Auto{
    public:
        Deportivo(string m, int r, int p): Auto(m, r, p) {}
        void sonido() {
            if(estado == "encendido"){
                cout<< "VROOM VROOM\n";
            } else{
                cout<< "No puedes hacer vroom vroom porqu está apagado el auto\n";
            }
        }
};

int main()
{
    Deportivo ferrari("Ferrari", 4, 2);
    ferrari.encender();
    ferrari.sonido();
    ferrari.avanzar();
    ferrari.frenar();
    ferrari.tocarBocina();
    Auto jeep("Jeep", 4, 4);
    jeep.encender();
    jeep.tocarBocina();
    jeep.apagar();
    jeep.tipoAuto();

    return 0;
}