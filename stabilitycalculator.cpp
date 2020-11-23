#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    float  wng_ar,Hor_tl_spn,Tl_ar,MAC,LCG,y1,y2,x1,x2,y1t,y2t,x1t,x2t,AR,ART,LCGp,mach;
    int LH;
    cout<<"Enter the flight parameters"<<endl;
    
    cout<<"Wing area"<<endl;
    cin>>wng_ar;
     cout<<"Enter the wing AR"<<endl;
     cin>>AR;
       cout<<"Enter the tail AR"<<endl;
     cin>>ART;
      cout<<"Tail area"<<endl;
      cin>>Tl_ar;
       cout<<"Mean aerodynamic chord of the wing"<<endl;
        cin>>MAC;
       
        cout<<"Enter the lcg value as percentage of MAC"<<endl;
            cin>>LCGp;
            LCG=0.01*LCGp*MAC;
        // cout <<"Enter the y values of the straight line slope from higher to lower value(WING)"<<endl;
          //  cin>>y2>>y1;
            
         //    cout <<"Enter the corresponding x values of the straight line slope from higher to lower value(WING)"<<endl;
           // cin>>x2>>x1;
           
        cout<<"Assuming the tail downwash differential to be equal to 0.1 "<<endl;
         //cout <<"Enter the y values of the straight line slope from higher to lower value(TAIL)"<<endl;
           // cin>>y2t>>y1t;
           
            // cout <<"Enter the corresponding x values of the straight line slope from higher to lower value(TAIL)"<<endl;
             //cin>>x2t>>x1t;
              cout<<"Enter the aircraft mach number "<<endl;
            cin>>mach;
            
            float beta=pow((1-(mach*mach)),0.5);
//float kw=((atan((y2-y1)/(x2-x1))*180*180)/(2*(22/7)*(22/7)*(22/7)));  
//float kw=((((y2-y1)/(x2-x1))*180)/(2*(22/7)*(22/7)));   
float kw=((((0.08*180)/(2*(22/7)*(22/7)))));// 2d lift curve slope of the wing  
float CL=((2*(22/7)*AR)/(2+pow(((pow(((AR*beta)/kw),2))+4),0.5)));   
cout<<CL<<endl;   //3d lift curve slope for the wing
//float kt=((atan((y2t-y1t)/(x2t-x1t))*180*180)/(2*(22/7)*(22/7)*(22/7))); 
//float kt=((((y2t-y1t)/(x2t-x1t))*180)/(2*(22/7)*(22/7)));
float kt=((((0.07*180)/(2*(22/7)*(22/7)))));  // 2d lift curve slope of the tail   
float CLT= ((2*(22/7)*ART)/(2+pow(((pow(((ART*beta)/kt),2))+4),0.5)));
cout<<CLT<<endl; // 3d lift curve slope of the tail 
//float tangent=0;                     
cout<<"DCMA         Moment Arm"<<endl;
for(LH=0;LH<=70;LH++)
{
    
double DCMA= ( ((CL*LCG)/MAC)-(CLT*((Tl_ar*LH)/(wng_ar*MAC))));

//tangent=atan(DCMA);

if(DCMA>=-1.5&&DCMA<=-0.3)
{
     cout<<DCMA<<"   "<<LH<<"    Favoured values"<<"VH ="<<((Tl_ar*LH*0.0254)/(wng_ar*MAC))<<endl;
}
else
      cout<<DCMA<<"  "<<LH<<endl;
}
 

    
    
    
}

