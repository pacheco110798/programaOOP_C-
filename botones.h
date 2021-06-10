using namespace::std;
#include <stdlib.h>
class botones
{
public:
    void boton(char pal[]);//transforma un texto en "boton"
    void titulo(char pal[]);//transforma n texto en "titulo"
    void aviso(char pal[]);//transforma un texto en aviso"
    void clean();//limpia pantalla
    void pausa();//limpia pantalla y espera inpt del usuario
    //void tabla()
};
void botones::clean(){
system("cls");
}
void botones::pausa(){
    cin.ignore();
    cin.ignore();
    system("cls");
}
void botones::boton(char pal[])
{
int lon=strlen(pal)+6;//calcula la longitud de la palabre y agrega 6 caracteres mas para sus margenes internos
cout<<":";
for(int i=0;i<lon;i++)
    cout<<"-";
cout<<":"<<endl;//aqui se terminas de dibujar el borde superior segun la lognitud anterior
cout<<":   "<<pal<<"   :"<<endl;////se inserta la palabra
cout<<":";//se dibuja el margen inferior
for(int i=0;i<lon;i++)
    cout<<"-";
cout<<":"<<endl;
cout<<endl;
}
void botones::titulo(char pal[])
{
int lon=strlen(pal);//longitud de la palabra
int spac=(100-lon)/2;//espacio a los lados para un total de 100 caracteres de largo estandar

for(int i=0;i<100;i++)
    cout<<".";
cout<<endl<<":";//se imprime el borde de arriba
for(int i=0;i<spac;i++)
    cout<<" ";//se imprime el primer espacio
cout<<pal;//se escribe la palabra
for(int i=0;i<spac-1;i++)
    cout<<" ";//se imprime el segndo espacio
cout<<":"<<endl;
for(int i=0;i<100;i++)
    cout<<".";//se imprime el borde inferior
cout<<endl;
}
void botones::aviso(char pal[])
{
int lon=strlen(pal);//longitud de la palabra
int spac=(96-lon);//espacio que se va a dejar para alinear el texto a la izquierda

for(int i=0;i<spac;i++)//impresion del espacio
    cout<<"-";
cout<<"<<<<"<<pal;//impresion del aviso
cout<<endl;
}


