#include <stdio.h> 
#include <iostream>
using namespace std;


class segmenttree {

    public: 
        int l, r;  //el pair left rigth
        int p;     //id del nodo
        int val;
        segmenttree * nIzq; //puntero ziquierda
        segmenttree * nDer; //puntero derecha

        segmenttree(int a[], int id, int left, int right){
            p=1;
            l=left;
            r=right;
            p=id;            
            if( l != r) {
                 nIzq= new segmenttree(a,p*2, l, (int)(l+r)/2); // mi super recursividad izquierda
                 nDer = new segmenttree (a,2*p+1, (int)(l+r)/2+1,r); // mi super recursividad derecha
                 if(nIzq->val > nDer->val){
                     val = nIzq->val;
                 }else{
                      val = nDer->val;
                 }
            }
            if(l == r ){
                val=a[l];
            }
            cout<<"P: "<<p<<" [l,r]:"<<l<<","<<r<<"  Val:"<<val<<"\n";
        };



    /**
     * Funcion para obtener el màximo elemento de un segmento.
    */

        int getMaximo(int iz, int der, segmenttree * nodeI){
            int maximoIzq=0;
            int maximoDer=0;
  
            //Información de Izquierda
            if(nodeI->nIzq->r<iz || der < nodeI->nIzq->l){                                                  //Primera presmisa NO INTERSECAN
//                cout<<"Entra IZ.1!!: ["<<nodeI->nIzq->l<<","<<nodeI->nIzq->r<<"-->"<<iz<<","<<der<<"]\n";
                maximoIzq=-99999;
            }

            if(iz <= nodeI->nIzq->l && der >= nodeI->nIzq->r ){                                             //Tercera premisa LO CONTIENE TOTAL
  //          cout<<"Entra IZ.3!!: ["<<nodeI->nIzq->l<<","<<nodeI->nIzq->r<<"-->"<<iz<<","<<der<<"]\n";
                maximoIzq = nodeI->nIzq->val;
                
            }else{                                                                                         //Segunda premisa PARCIALMENTE
                    if((iz > nodeI->nIzq->l && iz <= nodeI->nIzq->r && der > nodeI->nIzq->r) || (iz < nodeI->nIzq->l && der >= nodeI->nIzq->l && der <= nodeI->nIzq->r) ){ 
    //                     cout<<"Entra IZ.2!!: ["<<nodeI->nIzq->l<<","<<nodeI->nIzq->r<<"-->"<<iz<<","<<der<<"]\n";
                        maximoIzq = getMaximo(iz, der, nodeI->nIzq) ;
                    }
            }


            /**
            /*Información de Derecha
            * Recorre revusrivamente por la derecha
            **/
            if(nodeI->nDer->r < iz || der < nodeI->nDer->l){                                                    //Primera presmisa NO INTERSECAN
                     // cout<<"Entra DER.1!!: ["<<nodeI->nIzq->l<<","<<nodeI->nIzq->r<<"-->"<<iz<<","<<der<<"]\n";
                maximoDer = -99999;
            }


            if(iz <= nodeI->nDer->l && der >= nodeI->nDer->r ){                                                 //Tercera premisa LO CONTIENE TOTAL
                //cout<<"Entra der.3!!: ["<<nodeI->nDer->l<<","<<nodeI->nDer->r<<"-->"<<iz<<","<<der<<"]\n";
                maximoIzq = nodeI->nDer->val;
                
            }else{                                                                                              //Segunda premisa PARCIALMENTE
                    if((iz > nodeI->nDer->l && iz <= nodeI->nDer->r && der > nodeI->nDer->r) || (iz < nodeI->nDer->l && der >= nodeI->nDer->l && der <= nodeI->nDer->r) ){ 
                       //  cout<<"Entra der.2!!: ["<<nodeI->nDer->l<<","<<nodeI->nDer->r<<"-->"<<iz<<","<<der<<"]\n";
                        maximoIzq = getMaximo(iz, der, nodeI->nDer) ;
                    }

            }

            //filtrar Resultado
           if(maximoIzq > maximoDer) {
               return maximoIzq;
           }
           else{
               return maximoDer;
           }
        }



        

};

int main() 
{ 
  
    int a[]={-1,2,5,0};
    int arrSize = sizeof(a)/sizeof(a[0]);
    int left = 0;
    int right = arrSize-1;
    int id=1;
    
    
    segmenttree * var = new segmenttree(a,id,left, right);
   cout<<"RPTA:"<< var->getMaximo(1,3, var)<<"\n";


    return 0; 
} 