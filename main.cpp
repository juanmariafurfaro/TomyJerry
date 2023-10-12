#include <iostream>
#include <cmath>
#include <string>
#include "validaciones.h"
#define F 10
#define C 10
using namespace std;
class Mapa{
//declaracion de la clase mapa, la cual inicia el entorno en el que va a suceder el programa
private:
    char m[F][C];//mapa va a ser una matriz de caracteres de FxC
public:
    void crearMapa(){//inicializo todos los elementos del mapa a un espacio vacio
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                m[i][j]=' ';
            }
        }
    }
    void setCat(int posx,int posy){//Esta funcion utiliza las variables posx y posy me sirven para posicionar al gato, representado por un O, en el mapa
        m[posx][posy]='O';
    }
    void eliminarObjeto(int posx,int posy){//Esta funcion utiliza las variables posx y posy me sirven para ubicar en el mapa el elemento que quiero borrar sea una O o X
        m[posx][posy]=' ';
    }
    void setRaton(int posx,int posy){//Esta funcion utiliza las variables posx y posy me sirven para posicionar al raton, representado por una X, en el mapa
        m[posx][posy]='X';
    }
    bool chequearPosicion(int posx, int posy){//Esta funcion me sirve para ver si las ubicaciones de la matriz estan vacias o hay elementos
        if(m[posx][posy]==' '){
            return true;
        } else
            return false;
    }
    void mostrar(){//Esta funcion muestra el mapa y como esta compuesto el mapa por la terminal
        for (int i = 0; i < F; ++i) {
            if(i==0){
            cout<<"     "<<i<<"-";} else
                cout<<i<<"-";
        }
        cout<<"\n";
        for (int i = 0; i < F; ++i) {
            printf("%d-->",i);
            for (int j = 0; j < C; ++j) {
                printf("|%c",m[i][j]);
            }
            printf("\n");
        }
    }
};
class Raton {//declaracion del objeto raton
private://sus atributos
    double peso;
    int posx;
    int posy;
public://metodos
    Raton(double aux,int x, int y){//constructor para inicializar los atributos privados
        peso=aux;
        posx=x;
        posy=y;
    }
    //Las siguientes funciones son getters para que otras clases puedan utilizar estos atributos
    double getPeso() const{
        return peso;
    }
    int getposX () const{
        return posx;
    }
    int getposY() const{
        return posy;
    }

};
class Gato{//declaracion del objeto gato
private://sus atributos
    double energia;
    double velocidad;
    int posX;
    int posY;
    double tiempo;
    int cantidad;
public://metodos
    Gato(int x, int y,float t, int c): energia(10), velocidad(5), posX(x), posY(y), tiempo(t), cantidad(c){}//constructor

    void alimentar(Raton *ratonComido){//esta funcion alimenta al gato
        energia+=(ratonComido->getPeso()+12);//ahora la energia va a ser igual peso del raton que se come + un valor constante de 12
        cantidad++;//aumento en 1 la cantidad de ratones que se comio el gato
    }
    void correr(int x, int y){//esta funcion desplaza al gato libremente por el mapa
        velocidad=(energia/10)+5;//la velocidad es igual a la energia actual sobre 10 + 5
        double modulo= distancia(x,y);//esta funcion calcula la distancia entre la posicion del gato y a donde quiere ir
        energia=energia-modulo*0.5;//el consumo es la distancia por 0,5
        tiempo=tiempo+(modulo/velocidad);//se agrega el tiempo que el gato estuvo moviendose
    }

    void estadoActual() const{//muestra el estado de los atributos del gato
        cout<<"La energia del gato es de: "<<energia<<" jouls"<<endl;
        cout<<"Comio: "<<cantidad<<" de ratones"<<endl;
        cout<<"Corrio por: "<<tiempo<<"s"<<endl;
    }
    bool meConvieneCazar(double distancia, double peso) const {//esta funcion booleana me va a devolver true si le conviene comerse un determinado raton
        double time= (double) distancia/velocidad;//obtengo el tiempo que le llevaria comerse ese raton
        if ((time*velocidad*0.5)<peso+12) {//si la energia que consumo es menor que la energia que gano, le coniviene comerse ese raton
            return true;
        } else {//si no no.
            cout << "No le conviene cazar el ratón" << endl;
            return false;
        }
    }
    double distancia(int x, int y) const{//esta funcion me devuelve el modulo de la distancia entre dos posiciones
        int distx,disty;
        if (posX>x)
            distx=posX-x;
        else
            distx=x-posX;
        if (posY>y)
            disty=posY-y;
        else
            disty=y-posY;
        double modulo;
        modulo=(double ) sqrt((distx*distx)+(disty*disty));
        return modulo;
    }
    void setPosicion(int x, int y){//esta funcion esta para cambiar la ubicacion del gato en determinados momentos
        posX=x;
        posY=y;
    }
    //Las siguientes funciones son getters para que otras clases puedan utilizar estos atributos
    double getEnergia() const{
        return energia;
    }
    int getposX () const{
        return posX;
    }
    int getposY() const{
        return posY;
    }

};
class Menu{//creo la clase menu, la cual se va a encargar de inicializar variables y controlar el funcionamiento del programa
public:
    static void insertarRaton(Mapa &maps,Raton &aux){//inserto el raton en el mapa
        int x,y;
        x=aux.getposX();//obtengo del raton su posicion x
        y=aux.getposY();//obtengo del raton su posicion y
        maps.setRaton(x,y);//cargo el raton en el mapa
    }
    static void insertarGato(Mapa &maps,Gato &aux){//inserto el gato en el mapa
        int x,y;
        x=aux.getposX();//obtengo del gato su posicion x
        y=aux.getposY();//obtengo del gato su posicion y
        maps.setCat(x,y);//cargo el gato en el mapa
    }
    void realizarMvimiento(Mapa & mapa,Gato &tom,Raton &aux){//efectuo el desplazamiento de del gato
        int newposx,newposy,ax,ay;//declaro variables auxialeres para las posiciones
        ax=tom.getposX();//obtengo del gato su posicion x
        ay=tom.getposY();//obtengo del gato su posicion y
        newposy=aux.getposY();//obtengo del raton su posicion x
        newposx=aux.getposX();//obtengo del raton su posicion y
        double modulo=tom.distancia(newposx,newposy);//en modulo se almacenara el resultado de la distancia entre el gato y el raton
        double auxpeso=aux.getPeso();
        if(tom.meConvieneCazar(modulo,auxpeso))//en caso de que se devuelva true de la funcion booleana se efectua la caza
        {
            tom.correr(newposx,newposy);//muevo al gato a la posicion del raton y gasta energia
            tom.alimentar(&aux);//el gato se alimenta y recupera energia
            tom.setPosicion(newposx,newposy);//actualizo la posicion del gato
            insertarGato(mapa,tom);//actualizo la posicion del gato en el mapa
            mapa.eliminarObjeto(ax,ay);//elimino el mapa al raton que se comio
        }
}
     void gestion(){
        Mapa mapa;//instancio un objeto de la clase mapa
        Raton raton1(8.0,0,0);//creo 7 objetos del tipo raton
        Raton raton2(6.0,1,7);
        Raton raton3(4.0,3,3);
        Raton raton4(9.0,6,2);
        Raton raton5(3.0,7,8);
        Raton raton6(8.0,8,3);
        Raton raton7(5.0,9,9);
        int ratones[]={0,0,0,0,0,0,0};//este vector almacena 0 que significan que al inicio del programa los 7 ratones estan vivos
        Gato tom(5,5,0,0);//creo un objeto de tipo Gato
        mapa.crearMapa();//llamo al metodo de Mapa, para inicializar el contenido del mapa
        insertarRaton(mapa,raton1);//llamo al metodo para insertar todos los ratones en el mapa
        insertarRaton(mapa,raton2);
        insertarRaton(mapa,raton3);
        insertarRaton(mapa,raton4);
        insertarRaton(mapa,raton5);
        insertarRaton(mapa,raton6);
        insertarRaton(mapa,raton7);
        insertarGato(mapa,tom);//llamo al metodo para insertar el gato en el mapa
        cout<<"\t\t\t\tBienvenido al experimento:\nUsted observa al gato TOM respresentado por una O y puede mandarlo a correr por cualquier lugar libre del espacio\nO puede seleccionar un raton(numerados del 1 al 7 de arriba hacia hacia abajao), para que tom se alimente,comiendose ese raton\nCada vez que tom corre consume energia y cuando se come un raton recupera energia\n\n"<<endl;
        system("PAUSE");
        system("cls");
        while (true){//de esta manera el programa se ejecuta siempre
            mapa.mostrar();//muestro la composicion inicial del mapa
            int respuesta;//esta variable se crea para manejar la interaccion entre el usuario y el programa
            cout<<"--------------------------------------------------------------------------"<<endl;
            cout<<"Que hace TOM:\n 1-Corre\n2-Se come un raton\n3-Ver estado actual\n4-Me canse de ver a TOM:"<<endl;
            respuesta= obtenerRespuestaValida();//se llama a la funcion para validar la entrada de datos
            if (tom.getEnergia()<0){//en caso de que el gato se queda sin energia se termina el programa
                cout<<"tom se quedo sin energia"<<endl;
                break;
            }
            else{
                if (respuesta==1){//en caso de que la respuesta sea 1 se desea que el gato corra, pero no coma ningun raton
                    {
                        int newposx, newposy;//declaro dos variables auxiliares de las posiciones a donde quiero trasladar el gato
                        cout<<"Ingrese a donde se desplazo Tom en x:"<<endl;
                        newposx=obtenerPosicionValida();//valido la entrada de datos
                        cout<<"Ingrese a donde se desplazo Tom en y:"<<endl;
                        newposy=obtenerPosicionValida();//valido la entrada de datos
                         if (mapa.chequearPosicion(newposx,newposy)){//si efectivamente la posicion del mapa esta disponible procede a realizar el traslado
                            int ax,ay;//creo variables auxiliares para almacenar las posiciones del gato actuales
                            ax=tom.getposX();
                            ay=tom.getposY();
                            tom.correr(newposx,newposy);//muevo al gato a la posicion del raton y gasta energia
                            tom.setPosicion(newposx,newposy);//actualizo la posicion del gato
                            insertarGato(mapa,tom);//actualizo la posicion del gato en el mapa
                            mapa.eliminarObjeto(ax,ay);//elimino el mapa al raton que se comio
                        }else{//caso contrario el gato no se mueve
                            cout<<"El gato no puede ir a esa posicion"<<endl;
                        }
                    }
                }else if (respuesta==2){//en caso de que quiera comerse un raton
                    int rat;//esta variables sirve para  ver que raton quiere comerse el gato
                    cout<<"Que raton se come tom??";
                    rat=obtenerRatonValido();//valido la entrada de datos
                    /*unicamente voy a comentar que pasaria si elijo comer el primero porque se repite la logica para todos*/
                    if (rat==1){
                        if (ratones[0]==0) {//primero chequeo si el raton esta vivo mediante el vector declarado previamente, en caso de estar vivo
                            realizarMvimiento(mapa, tom, raton1);//procede a llamar a la funcion para comerse al gato
                            ratones[0]=1;//actualiza el estado del raton a muero
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }else if (rat==2){
                        if (ratones[1]==0) {
                            realizarMvimiento(mapa, tom, raton2);
                            ratones[1]=1;
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }else if (rat==3){
                        if (ratones[2]==0) {
                            realizarMvimiento(mapa, tom, raton3);
                            ratones[2]=1;
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }else if (rat==4){
                        if (ratones[3]==0) {
                            realizarMvimiento(mapa, tom, raton4);
                            ratones[3]=1;
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }else if (rat==5){
                        if (ratones[4]==0) {
                            realizarMvimiento(mapa, tom, raton5);
                            ratones[4]=1;
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }else if (rat==6){
                        if (ratones[5]==0) {
                            realizarMvimiento(mapa, tom, raton6);
                            ratones[5]=1;
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }else {
                        if (ratones[6]==0) {
                            realizarMvimiento(mapa, tom, raton7);
                            ratones[6]=1;
                        } else{
                            cout<<"Tom ya se comio ese raton"<<endl;
                        }
                    }
                } else if(respuesta==3){//muestro el estado actual de los atributos del gato
                    tom.estadoActual();
                }else{//salgo del programa
                    break;
                }
            }
            cout<<""<<endl;
            system("PAUSE");
            system("cls");
        }
         tom.estadoActual();//muestro el estado final de los atributos del gato
    }
};

int main(){
    Menu menu;//creo el menu
    menu.gestion();//empiezo a gestionar el programa
    system("PAUSE");
    return 0;
}