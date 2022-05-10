#include "cifrador.h"

using namespace std;

Cifrador::Cifrador()
{

}

string Cifrador::quitarTildes(string aux)
{
    char vocal_sin[]="aeiou",vocal_con[]="αινσϊ";
    int i,j;
    for (i=0;i<=aux.length();i++)
    {
        for (j=0;j<5;j++)
        {
            if (vocal_con[j]==aux[i])
                aux[i]=vocal_sin[j];
        }
    }
    return aux;
}

int Cifrador::binarioToDecimal(string aux)
{
    stringstream ss;
    int n;
    ss.clear();
    ss.str();
    ss<<aux;
    ss>>n;
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}


string Cifrador::toBinaryRev(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    int i=0,zeros=8;
    while(r[i])
    {
        i++;
    }
    zeros=zeros-i;
    while(zeros>0)
    {
        r="0"+r;
        zeros--;
    }
    return r;
}

string Cifrador::ascii(string aux)
{
    stringstream ss;
    string msg="";
    int i=0;
    while(aux[i])
    {
        string sa;
        int ia=int(aux[i]);
        ss.str("");
        ss.clear();
        ss<<ia;
        sa=ss.str();
        msg+=sa+" ";
        i++;
    }
    return msg;
}

string Cifrador::encripta(string data)
{
    data=quitarTildes(data);
    data=ascii(data);
    int i=0,tam=0;
    string aux="";
    stringstream ss;
    while(data[i])
    {
        if(data[i]==' ')
        {
            tam++;
        }
        i++;
    }

    int datos[tam];
    int j=0;
    i=0;
    while(data[i])
    {
        if(data[i]==' ')
        {
            ss.clear();
            ss.str();
            ss<<aux;
            ss>>datos[j];
            j++;
            aux="";
        }
        else
        {
            aux+=data[i];
        }

        i++;
    }


    int key_1=datos[tam%7],key_2=datos[tam%11];
    for(i=0;i<tam;i++)
    {
        if(i == tam%7 || i == tam%11)
        {
            //...
        }
        else if((i+tam)%2==0)
        {
            if((key_1+datos[i])>255)
                datos[i]-=key_1;
            else
                datos[i]+=key_1;

        }
        else
        {
            if((key_2+datos[i])>255)
                datos[i]-=key_2;
            else
                datos[i]+=key_2;
        }

    }

    string res="";
    string key_xor=toBinaryRev(tam%255);
    string bin_datos[tam];
    for(i=0;i<tam;i++)
    {
        bin_datos[i]=toBinaryRev(datos[i]);
        j=0;
        while(bin_datos[i][j])
        {
            if(bin_datos[i][j]==key_xor[j])
            {
                bin_datos[i][j]='0';
            }
            else
            {
                bin_datos[i][j]='1';
            }
            j++;
        }
        res+=bin_datos[i]+"2";
    }

    return res;
}


string Cifrador::desencripta(string data)
{
    int i=0,j=0,tam=0;
    while(data[i])
    {
        if(data[i]=='2')
            tam++;
        i++;
    }
    i=0;
    string bin_datos[tam];
    string binaux="";
    while(data[i])
    {
        if(data[i]=='2')
        {
            bin_datos[j]=binaux;
            binaux="";
            j++;
        }
        else
            binaux+=data[i];
        i++;
    }


    int datos[tam];
    string key_xor=toBinaryRev(tam%255);
    for(i=0;i<tam;i++)
    {
        j=0;
        while(bin_datos[i][j])
        {
            if(bin_datos[i][j]==key_xor[j])
            {
                bin_datos[i][j]='0';
            }
            else
            {
                bin_datos[i][j]='1';
            }
            j++;
        }
    }

    for(i=0;i<tam;i++)
    {
        datos[i]=binarioToDecimal(bin_datos[i]);
    }

    int key_1=datos[tam%7],key_2=datos[tam%11];
    for(i=0;i<tam;i++)
    {
        if(i == tam%7 || i == tam%11)
        {
            //...
        }
        else if((i+tam)%2==0)
        {
            if(datos[i]+(key_1*2)>255)
                datos[i]-=key_1;
            else
                datos[i]+=key_1;

        }
        else
        {
            if(datos[i]+(key_2*2)>255)
                datos[i]-=key_2;
            else
                datos[i]+=key_2;
        }


    }
    string res="";
    for(i=0;i<tam;i++)
    {
        char c;
        c=datos[i];
        res+=c;
    }

    return res;

}
