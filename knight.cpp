#include "knight.h"
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
int levelio(int i) // HÀM TÍNH LEVELIO CỦA QUÁI
{
    i=i+1;
    int b=i%10;
    if (i>6)
    {
        if(b>5)
           {
        b=i%10;
        }
        else
            {
                b= 5;
    }
    }
    else
        {b=i%10;
    }
return b;
}

float basedamage(int HP,int x,int levelio)// HÀM TÍNH BASE DAMAGE VÀ HP CÒN LẠI SAU ĐÁNH QUÁI, b=levelio, x tương ứng hành trình -1
{
    float basedamage[]={1,1.5,4.5,7.5,9.5};
    float damage=basedamage[x-1]*levelio*10; //x<=5
    HP=HP-damage;
    return HP;
}

int mushmario(int level,int phoenixdown,int HP){   // NHẶT ĐƯỢC NẤM MUSHMARIO
int n1=((level+phoenixdown)%5+1)*3;
int a=99;
int b;
int dem=0;
int sum=0;
for(int i=1;i<=n1;i++)
{
    sum=sum+a;
    a=a-2;
}
HP=HP+(sum%100);
if (HP>1){
int x=sqrt(HP);// TÌM SỐ NGUYÊN TỐ GẦN NHẤT
for ( b=HP+1;b<1000;b++)
{
    for (int a=2;a<=x;a++)
    {
        if (b%a==0)
            dem++;
    }
    if (dem==0)
        break;
    else dem=0;
    }
HP=b;
}
    return HP;
}

int mushfibo(int HP) // NHẶT ĐƯỢC NÁM FIBO
{
    int a[18];
    a[0]=0;
    a[1]=1;
    int fibo;
    if (HP>1){
    for (int i=2;i<=17;i++)// KIỂM TRA DÃY SỐ FIBONANCI
        {a[i]=a[i-1]+a[i-2];
       int b=a[i];
       int c=a[i-1];
       if (b>=HP)
       {
           HP=c;
           break;
       }
}
    }
    else if (HP==1) HP=HP;
return HP;
}

float timmaxmin( ifstream &ifs,int HP) // TÌM MAX VÀ MIN CỦA DÃY SỐ
{
    float maxi,mini,vitri1,vitri2;
    int b;
    int n;
    ifs>>n;
    int str[100];//Khai báo biến kiểu int để lưu từng từ đọc được
    for (int i=0;i<n;){
        ifs>>str[i];
        char x;
        ifs>>x;
        i++;
    }
    maxi=-99999;
    mini=99999;
    for (int i=0;i<n;){
        b=str[i];
        if (b>=maxi)
        {
          vitri1=i;
          maxi=b;
        }
        i++;
    }
    for (int i=0;i<n;){
        b=str[i];
        if (b<=mini)
        {
            vitri2=i;
            mini=b;
        }
        i++;
    }
    //cout<<"vt1"<<vitri1<<endl;
    //cout<<"vt2"<<vitri2<<endl;
HP=HP-(vitri1+vitri2);
    return HP;
}

float mush2( ifstream &ifs,int HP) // Kiểm tra dạng dãy núi đầu hoặc cuối
{
    bool check;
    float b,c,mtx,mti,vitri,vitri1;
    float a,d;
    int str[100];
    int n,i;
    ifs>>n;// số hiện ở dòng 1
    int dem=0;
    int dem1=0;
    int dem2=0;
    int dem3=0;
    int tong=n-1; //tổng cặp
    for (i=0;i<n;){
        ifs>>str[i];
        char x;
        ifs>>x;
        //cout<<x<<endl;
        i++;
    }
    if(n>1){
    for (i=0;i<n-1;){ // kiểm tra dãy núi dạng đỉnh đầu hoặc cuối
        b=str[i];
        c=str[i+1];
        if (c>b)
        {
          dem++;
        //mti=n-1;
        //mtx=str[n-1];
        }
        else if (b>c)
        {
            dem1++;
            //mti=0;
            //mtx=str[0];

        }
        else if(b==c)
        break;
        i++;
    }

    if (dem<n-1 || dem1 <n-1){ // KIỂM TRA ĐỈNH Ở TRONG KHOẢNG DÃY
    for (int i=0;i<n-1;)
    {
        a=str[i];
        d=str[i+1];
        if (d>a)
        {
            dem2=dem2+1;
            vitri=i+1;
            i++;
        }
        else if (d<=a)
            break;
    }
    for (int y=n-1;y>0;)
    {
        int p=str[y];
        int q=str[y-1];
        if (q>p)
            {dem3=dem3+1;
            vitri1=y-1;
            y--;
            }
        else if (q<=p) break;
    }
    }


    if (dem==tong)
      {
        mti=n-1;
        mtx=str[n-1];
      }
    else if (dem1==tong)
    {
        mti=0;
        mtx=str[0];
    }
    else if (vitri==vitri1)
    {
        mti=vitri;
        mtx=a;
    }
    else
    {
       mti=-3;
       mtx=-2;
    }
    }
    if(n==1)
    {
        mti=0;
        mtx=str[0];
    }
    //cout<<"2 "<<mti<<endl;
    //cout<<"2 "<<mtx<<endl;
    HP=HP-(mtx+mti);
    //cout<<HP<<endl;
    return HP;
}

float mush3( ifstream &ifs,int n,int HP) // HÀM CHUYỂN ĐỔI DÃY SỐ VÀ TÍNH MUSH 3
{
    int b,c;
    int newstr[100];
    int str[100];
    for (int i=0;i<n;){
        ifs>>str[i];
        char x;
        ifs>>x;
        i++;
    }
    for (int i=0;i<n;i++)
    {

        if(str[i]<0)
        {
            str[i]=(17*abs(str[i])+9)%257;
        }
        else if(str[i]>=0)
        {
            str[i]=(17*str[i]+9)%257;
        }
        newstr[i]=str[i];
        //cout<<newstr[i]<<" .";
    }
    float maxi,mini,maxi2,mini2;
    int newi[100];//Khai báo biến kiểu int để lưu từng từ đọc được
    mini=9999999;
    for (int i=0;i<n;){
    c=newstr[i];
       if (c<mini)
        {
            mini2=i;
            mini=c;
        }
        i++;
    }
    maxi=-9999999;
    for (int i=0;i<n;){
        b=newstr[i];
        if (b>maxi)
        {
          maxi2=i;
          maxi=b;
        }
        i++;
    }
    //cout<<maxi2<<endl;
    //cout<<mini2<<endl;
    HP=HP-(maxi2+mini2);
    return HP; 
}

float mush4(ifstream &ifs,int n,int HP) // n là số hiện ở dòng 1 của file, TÍNH DÃY SỐ MỚI VÀ TÍNH MUSH 4
{
    int z;
    int newstr[100];
    int str[100];
    for (int i=0;i<n;){
        ifs>>str[i];
        char x;
        ifs>>x;
        i++;
    }
    for (int i=0;i<n;i++)
    {
        z=str[i];
        if(z<0)
        {
            str[i]=(17*abs(str[i])+9)%257;
        }
        else if(z>=0)
        {
            str[i]=(17*str[i]+9)%257;
        }
        newstr[i]=str[i];
    }
    float max2_3x,max2_3i,a,b,c;
    int newi[100];//Khai báo biến kiểu int để lưu từng từ đọc được
    for (int i=0;i<3;){
        newi[i]=newstr[i];
        i++;
    }
    if (n>2){
    a=newi[0];
    b=newi[1];
    c=newi[2];
    if ( a>b){ // trường hợp 1
        if (b>c || b==c || a==c)
        {
            max2_3i=1;
            max2_3x=b;
        }
        if (c>b && c<a)
        {
            max2_3i=2;
            max2_3x=c;
        }
        if (c>a)
        {
            max2_3i=0;
            max2_3x=a;
        }

    }
    if ( a<b){ //trường hợp 2
        if (c>b)
        {
            max2_3i=1;
            max2_3x=b;
        }
        if (c<b && c>a)
        {
            max2_3i=2;
            max2_3x=c;
        }
        if (c==b || c==a || c<a)
        {
            max2_3i=0;
            max2_3x=a;
        }
    }
    if ( a==b)
    {
        if (c<a)
        {
            max2_3i=2;
            max2_3x=c;
        }
        if ( c>a)
        {
            max2_3i=0;
            max2_3x=a;
        }
        if ( c==a)
        {
            max2_3i=-7;
            max2_3x=-5;
        }
    }
}
    if (n==2)
    {
        a=newi[0];
        b=newi[1];
        if (a>b)
        {max2_3i=1;
        max2_3x=b;}
        if(a<b)
        {
            max2_3i=0;
            max2_3x=a;
        }
        if(a==b)
        {
           max2_3i=-7;
            max2_3x=-5; 
        }

    }
    if(n==1)
    {
        max2_3i=-7;
            max2_3x=-5;
    }
HP = HP-(max2_3x + max2_3i);
    return HP; 
}

int merlinkhochiu(ifstream &file_merlin_pack,int HP) //Merlin khó chịu, GẶP MERLIN ĐỂ TĂNG HP
{
    int M=0,m=0,E=0,e=0,R=0,r=0,L=0,l=0,I=0,i=0,N=0,n=0;
    int str;
    file_merlin_pack>>str;
    //cout<<str<<endl;
   // cout<<str<<endl;
    string chuoi[1000];
    int z,k;
    for (int x=0;x<=str;){
        getline(file_merlin_pack,chuoi[x]);
        int y=chuoi[x].length();
        string o=chuoi[x];
        if (o.find("Merlin") != std::string::npos || o.find("merlin") != std::string::npos)
            HP++;
             for ( z=0;z<y;z++)// GẶP CÁC CHỮ CÁI YÊU CẦU
             {
                 if (o[z]=='m')
                    m++;
                 if (o[z]=='M')
                    M++;
                if (o[z]=='e')
                    e++;
                 if (o[z]=='E')
                    E++;
                if (o[z]=='r')
                    r++;
                 if (o[z]=='R')
                    R++;
                if (o[z]=='l')
                    l++;
                 if (o[z]=='L')
                    L++;
                    if (o[z]=='i')
                    i++;
                 if (o[z]=='I')
                    I++;
                    if (o[z]=='n')
                    n++;
                 if (o[z]=='N')
                    N++;
             }
   int HP1=HP;
   if (M==0 && m==0)// BẮT ĐẦU XÉT THỨ TỰ CÁC CHỮ CÁI
    HP=HP1;
   else if (m>0 || M>0)
   {
       if (e==0 && E==0)//1 TH e
        HP=HP1;
       else if (E>0 && e==0)// có E nhưng ko có e
        {
        if (r==0 && R==0)// không có R và r
        HP=HP1;
           else if (R>0 ||r>0)// có R hoặc r
        {
            if (l==0 && L==0)// ko có L l
               HP=HP1;
               else if (L>0 ||l>0)// có L hoặc l
               {
                if (i==0 && I==0)// không có I i
                   HP=HP1;
                   else if (I>0||i>0)// có I i
                   {
                       if (n==0 && N==0)// ko có N n
                       HP=HP1;
                       else if (N>0 ||n>0)// có N n
                       HP=HP+2;
                   }
               }
        }
        }
       else if (e>0 ) //có e
       {
           if (r==0 && R==0)// ko có R r
        HP=HP1;
           else if (R>0 && r==0)// có R nhưng ko co r
        {
            if (l==0 && L==0)// ko có L l
               HP=HP1;
               else if (L>0 ||l==0) //có L hoặc l
               {
                if (i==0 && I==0)// Ko có I i
                   HP=HP1;
                   else if (I>0||i>0)// có I hoặc i
                   {
                       if (n==0 && N==0)// ko có N n
                       HP=HP1;
                       else if (N>0 ||n>0)// có N hoặc n
                       HP=HP+2;
                   }
               }
        }
           else if (r>0) // trường hợp có r
        {
            if (l==0 && L==0)
               HP=HP1;
               else if (L>0 && l==0)
               {
                if (i==0 && I==0)
                   HP=HP1;
                   else if (I>0 || i>0)
                   {
                       if (n==0 && N==0)
                       HP=HP1;
                       else if (N>0 || n>0)
                       HP=HP+2;
                   }
               }
               else if (l>0)
        {
                if (i==0 && I==0)
                   HP=HP1; 
                   else if (I>0 && i==0)
                   {
                       if (n==0 && N==0)
                       HP=HP1;
                       else if (N>0 ||n>0)
                       HP=HP+2;
                    }
                    else if (i>0)
                    {
                   if (n==0 && N==0)
                   HP=HP1;
                   else if (N>0 && n==0)
                   HP=HP+2;
                   else if (n>0)
                        {HP=HP+2;
                        }
                        
                    }
               }
           }
       }
   }

   M=0,E=0,R=0,L=0,I=0,N=0,m=0,e=0,r=0,l=0,i=0,n=0; //Reset lại từ đầu
        x++;
        }
    return HP;
}

int demtihon1(bool tihon,int demtihon)// ĐẾM SỐ LẦN TÍ HON
{
    if (tihon==true)
        demtihon++;
    return demtihon;
}
int demech1(bool ech,int demech)// ĐẾM SỐ LẦN BIẾN ẾCH
{
    if (ech==true)
        demech++;
return demech;
}

//Hàm chuyển đổi chỉ dành cho 2 số hạng
int chuyendoi(string k)
{
  int a;
  int b=k[0];
  int c=k[1];
  int leng=k.length();
  if(leng==2)
  a=(b-48)*10+(c-48);
  else if (leng==1)
  a=b-48;
return a;

}
// Hàm chuyển đổi dành cho nhiều số hạng
int chuyendoi2(string k)
{
    int n=k.length();
    int chuoi=0;
    for (int i=0;i<n;i++){   // ĐỔI KIỂU
   int b=k[i];
        chuoi=((b-48)*pow(10,(n-1)-i))+chuoi;
        }
    return chuoi;
}
// BẮT ĐẦU HÀNH TRÌNH
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
  bool arthur,lancelot;
  bool ech=false;
  bool tihon=false;
  int demhanhtrinh=0;//SỐ HÀNH TRÌNH PHẢI ĐI
  int demtihon=0;
  int checklancelot=0;
  int demech=0;
  int demaslep=0;
  int demmerlin=0; 
  string dayso[100];// gán chuỗi sự kiện 13 vào đây
  int sttnam=0;// đếm số nấm ma
  int so_nam_ma_xh=0;// số sự kiện 13.... xuất hiện, và tên file xh
  int hanhtrinh[1000];
  int level1;//Dùng để đưa level trở lại level1 khi có thuốc giải shiren
  char boquaa;// BỎ QUA ĐỂ GÁN BIẾN// gán để đếm số lần gặp nấm ma
  string line;
  string linee; // Dùng gọi ra từng hàng
  ifstream ifs(file_input);
  getline(ifs,file_input);
  stringstream shs(file_input);
  shs>>HP>>level>>remedy>>maidenkiss>>phoenixdown;
  //cout<<HP<<endl;
  //cout<<level<<endl;
  //cout<<remedy<<endl;
  //cout<<maidenkiss<<endl;
  //cout<<phoenixdown<<endl;
  // Gán giá trị ban đầu để display, đọc dòng thứ 1

  //đọc dòng thứ 2
        string a;
        while (ifs >> a)
        {
            int len=a.length();
            if(len>2)
            {
                hanhtrinh[demhanhtrinh] = 13;
                dayso[so_nam_ma_xh]=a;
                so_nam_ma_xh++;
            
            }
            else 
            {
                hanhtrinh[demhanhtrinh]=chuyendoi(a);
            }
            demhanhtrinh++;
        }
        so_nam_ma_xh--;// giảm bớt để về dãy file
    linee = dayso[so_nam_ma_xh];// dãy cuối cùng là dãy của tên file
    so_nam_ma_xh--;
    //cout<<linee<<endl;
    //cout<<dayso[1]<<endl;
    
      rescue=-1;
  if (HP==999) //KIỂM TRA ARTHUR
    arthur=true;
  else arthur=false;
  if (HP>2){
  for (int v=2;v<=sqrt(HP);v++)// KIỂM TRA LANCELOT
  {
      if (HP%v==0)
        checklancelot++;
  }
  if (checklancelot==0)
    lancelot=true;
  else lancelot=false;
     // cout<<"la lancelot"<<endl;

    }
    if (HP==2)
    lancelot=true;
  int MAXHP=HP;
  //Đọc dòng thứ 3 của file
  //getline (ifs,line);
  size_t j=linee.find(",");
  size_t k=linee.find(",",j+1);
  string mush=linee.substr(0,j);
  string asclep=linee.substr(j+1,k-j-1);
  string merlin=linee.substr(k+1);
  // Bắt đầu cuộc hành trình
    for (int z=0;z<demhanhtrinh-1;z++)
  {
     // if (rescue==0)
      //break;
      if (rescue==-1 || rescue==1){
      if (hanhtrinh[z]==0)// Bắt đầu xét từng hành trình,, HÀNH TRÌNH =0 THÌ WIN
      {
          rescue=1;
          display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
          break;
      }
      if (hanhtrinh[z]>0 && hanhtrinh[z]<6) // Hành trình nếu gặp quái từ 1- 5
      {

                if(arthur==false && lancelot==false){
          int x=hanhtrinh[z];
          int a=levelio(z);
          if(level>a)       // Đánh thắng quái
          {
              rescue=-1;
              if(level<10) // Kiểm tra level
              level++;
          }
          if (level<a) //Đánh thua quái
          {
               HP=basedamage(HP,x,a);
                if (HP<=0)
                 {
                 if (phoenixdown <=0)
                {
                    rescue=0; //setup thông số rescue
                }
                 else if (phoenixdown>0)
                 {
                  HP=MAXHP;
                  phoenixdown=phoenixdown-1;
                  rescue=-1;
                   tihon=false;
                  if (ech==true)
                   {
                    level=level1;
                    ech=false;
                   }
                 }

          }
          }
          if(level==a)
            rescue=-1;
         
     if ( tihon==true)
     {
        if (remedy>0){
         remedy=remedy-1;
         tihon=false;
         rescue=-1;
         HP=HP*5;
     }
     }
      if ( ech==true)
     {
        if (maidenkiss>0){
         maidenkiss=maidenkiss-1;
         ech=false;
         rescue=-1;
         level=level1;
     }
     }
     }
     else if (arthur==true || lancelot==true)
     level=level+1;
        if (HP>MAXHP)
        HP=MAXHP;
        if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        if(level>10)
        level=10;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
     display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
          }             //// Kết thúc hành trình gặp quái từ 1-5


      if(hanhtrinh[z]==6 ) // ĐÁNH NHAU VỚI SHAMAN
      {
          if (arthur==false && lancelot==false){
            if(ech==false && tihon==false){ //check điều kiện
          int x=hanhtrinh[z];
          int a=levelio(z);
          if(level>a)
          {
              if (level<10)
              level=level+2;
              else level=10;
              tihon=false;
          }
          else if(level<a)
          {
             if (remedy==0)
              {
                  tihon=true;
                  // dùng để xét điều kiện
                  if(HP<5)
                    HP=1;
                  if (HP > 4)
                  HP=HP/5;
              }
              else if (remedy>0)
              {
                  remedy=remedy-1;
                  tihon=false;
              }
              else if (maidenkiss>0 || remedy>0)
              {
                  tihon=false;
                  ech=false;
              }
          }
          else if (level==a)
          rescue=-1;
            }
          }
          else if (arthur==true || lancelot==true)
          level=level+2;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        if(level>10)
        level=10;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }// kết thúc đánh nhau với shaman



      if(hanhtrinh[z]==7 ) // ĐÁNH NHAU VỚI SHIREN
      {
          if (arthur==false && lancelot==false){
            if(ech==false && tihon==false){
          int x=hanhtrinh[z];
          int a=levelio(z);
          level1=level;
          if(level>a)
          {
              if (level<10)
              level=level+2;
              else level=10;
              ech=false;
          }
          else if(level<a)
          {
            if (maidenkiss==0)
              {
                  ech=true;
                  // dùng để xét điều kiện
                  level=1;

              }
              if (maidenkiss>0)
              {
                  maidenkiss=maidenkiss-1;
                  ech=false;
                  level=level1;
              }

          }
          else if(level==a)
          rescue=-1;
          }
        }
        else if (arthur==true || lancelot == true)
        {
            if(level<10)
            level=level+2;
            else level=10;
        }
        
            if (HP>MAXHP)
                HP=MAXHP;
        if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        if (level>10)
        level=10;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      // Kết thúc đánh nhau với siren


      if (hanhtrinh[z]==11)                 //NHẶT ĐƯỢC NẤM MUSH MARIO
      {
          HP=mushmario(level,phoenixdown,HP);
        if(HP>MAXHP)
            HP=MAXHP;
            if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
          display(HP,level,remedy,maidenkiss,phoenixdown,rescue);

      }
      if(hanhtrinh[z]==12) //Nhặt đc nấm fibo
      {
          HP=mushfibo(HP);
        if (HP>MAXHP)
            HP=MAXHP;
            if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      if (hanhtrinh[z]==15)//+ remedy
      {
        remedy=remedy+1;
       if (tihon==true)
    {
        if(remedy>0)
    {
        tihon=false;
        remedy=remedy-1;
        HP=HP*5;
    }
    }
            if (z==demhanhtrinh-2)
        rescue=1;
          if (remedy>99)
       remedy=99;
       demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
      display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      if (hanhtrinh[z]==16)//+maidenkiss
      {
          maidenkiss=maidenkiss+1;
      if (ech==true){// hàm check
    if (maidenkiss>0)
    {
        ech=false;
        maidenkiss=maidenkiss-1;
        level=level1;
    }
    }
        if (z==demhanhtrinh-2)
        rescue=1;
        if(maidenkiss>99)
        maidenkiss=99;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
          display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      if(hanhtrinh[z]==17)//+phoenixdown
      {
          phoenixdown=phoenixdown+1;
          if(HP<=0){
        if(phoenixdown>0)
    {
        phoenixdown=phoenixdown-1;
        HP=MAXHP;
        tihon=false;
        if (ech==true)
        {
        level=level1;
        ech=false;
        }
    }
    }
            if (z==demhanhtrinh-2)
        rescue=1;
            if (phoenixdown>99)
            phoenixdown=99;
            demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
          display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      if (hanhtrinh[z]==13)// NHẶT NẤM MUSH GHOST
      {
          //checktihon(tihon,remedy);
           //int b=hanhtrinh[z];
           int msn[1000];
            string day_nam = dayso[sttnam].substr(2);
              

            for (int i = 0; i < day_nam.length(); i++)
            {
                msn[i] = int(day_nam[i]) - 48;
                //cout<<"nam"<<msn[i]<<endl;
                //cout<<i<<endl;
            }
          for ( int i=0;i<day_nam.length();i++){
            //cout<<"namm"<<msn[i]<<endl;// CHẠY  XÉT ĐIỀU KIỆN
            if(rescue==-1 || rescue==1){
              if(msn[i]==1)
              {
                 ifstream file_mush_ghost(mush);
                    
                   HP=timmaxmin(file_mush_ghost,HP);
                   if(HP>MAXHP)
                   HP=MAXHP;
                    if(HP<=0){
        if(phoenixdown>0)
    {
        phoenixdown=phoenixdown-1;
        HP=MAXHP;
         tihon=false;
        if (ech==true)
        {
        level=level1;
        ech=false;
        }
       // rescue=-1;
    }
    else 
    {
                           rescue=0;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                   //rescue=0;
    }
    }
                   }
               if(msn[i]==2)
     {

                  ifstream file_mush_ghost(mush);
                   HP=mush2(file_mush_ghost,HP);
                   if(HP>MAXHP)
                   HP=MAXHP;
                  // cout<<HP<<endl;
                if(HP<=0){
        if(phoenixdown>0)
    {
        phoenixdown=phoenixdown-1;
        HP=MAXHP;
         tihon=false;
        if (ech==true)
        {
        level=level1;
        ech=false;
        }
      //  rescue=-1;
    }
    else 
    {
        rescue=0;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
    }

              }
              if (msn[i]==3)
              {

                ifstream file_mush_ghost(mush);
                int dodai;
                file_mush_ghost>>dodai;
                HP=mush3(file_mush_ghost,dodai,HP);
                if(HP>MAXHP)
                HP=MAXHP;
            if(HP<=0){
        if(phoenixdown>0)
    {
        phoenixdown=phoenixdown-1;
        HP=MAXHP;
        tihon=false;
        if (ech==true)
        {
        level=level1;
        ech=false;
        }
        //rescue =-1;
    }
    else 
    {
                           rescue=0;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                   //rescue=0;
    }
    }
              }
              if (msn[i]==4)
              {
                int dodai;
                  ifstream file_mush_ghost(mush);
                file_mush_ghost>>dodai;
                HP=mush4(file_mush_ghost,dodai,HP);
                if(HP>MAXHP)
                HP=MAXHP;
    if(HP<=0){
        if(phoenixdown>0)
    {
        phoenixdown=phoenixdown-1;
        HP=MAXHP;
         tihon=false;
        if (ech==true)
        {
        level=level1;
        ech=false;
        }
        //rescue=-1;
    }
    else 
    {
                           rescue=0;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
    }
                   
              }// xong cái 4
            }
            else if(rescue==0) break;
          }
            if (HP>MAXHP)
        HP=MAXHP;
        if (z==demhanhtrinh-2 && HP>0)
        rescue=1;
        if (HP<=0)
        rescue=0;
        sttnam++; // cộng vào để xét tiếp th sau
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
           if (rescue==1 || rescue ==-1)
                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      } 


      if (hanhtrinh[z]==19)// GẶP ASSLEP
      {
        int stop=0;
          if (demaslep==0){// CHECK ĐÃ GẶP HAY CHƯA
          demaslep++;
          ifstream  file_aclepius_pack(asclep);
          string str1,str2;
          //for (int i=0;i<1;i++)
          file_aclepius_pack>>str1;
          file_aclepius_pack>>str2;
        
          //cout<<str1<<endl;
          //cout<<str2<<endl;
          int strr1=chuyendoi2(str1);
          int strr2=chuyendoi2(str2);
          //cout<<strr1<<endl;
          //cout<<strr2<<endl;

      
int c; // gán chuỗi
string thuoc[1000];
string boqua;
for (int i=0;i<strr1;i++)
{
   int dem=0;// reset lại đếm
    for (int n=0;n<strr2;n++)
    {
        if (dem<3){               // kiểm tra đã lấy 3 loại thuốc hay chưa
        file_aclepius_pack>>thuoc[n];
        string b=thuoc[n];
        if(b.length()==2)
            c=chuyendoi(b);
          //  cout<<c<<endl;
        if (c==16)
        {
            remedy++;
            dem++;
           if (tihon==true)
    {
        if(remedy>0)
    {
        tihon=false;
        remedy=remedy-1;
        HP=HP*5;
        if(HP>MAXHP)
        HP=MAXHP;
    }
    }
        }//xong 16
        if (c==17)
        {
            maidenkiss++;
            dem++;
            if (ech==true){
    if (maidenkiss>0)
    {
        ech=false;
        maidenkiss=maidenkiss-1;
        level=level1;
    }
    }
        }//xong 17
        if (c==18)
        {
            phoenixdown++;
            dem++;
              if(HP<=0){
        if(phoenixdown>0)
    {
        phoenixdown=phoenixdown-1;
        HP=MAXHP;
         tihon=false;
        if (ech==true)
        {
        level=level1;
        ech=false;
        }
    }
              }
    }//xong 18

        }
    else if (dem==3)
        {
          file_aclepius_pack>>boqua;
        }
        
    }
}
if (remedy>99)
    remedy=99;
if(phoenixdown>99)
    phoenixdown=99;
if(maidenkiss>99)
    maidenkiss=99;
        demaslep=demaslep++;
            if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
          }
          else// NẾU ĐÃ GẶP RỒI THÌ BỎ QUA VÀ CẬP NHẬT THÔNG SỐ
          {
            if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      }
      if (hanhtrinh[z]==18) //Gặp merlin cho túi hồi máu
      {
        if(demmerlin==0){
            demmerlin++;
          ifstream  file_merlin_pack(merlin);
        
          HP=merlinkhochiu(file_merlin_pack,HP);
          if (HP>MAXHP)
                    HP=MAXHP;
        if (HP>MAXHP)
        HP=MAXHP;
        if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      else// đã gặp merlin rồi
      {
            if (z==demhanhtrinh-2)
        rescue=1;
        if (HP<=0)
        rescue=0;
        demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      }
      if (hanhtrinh[z]==99)// GẶP BOWSER
      {
          if ( arthur==true)
          {
              level=10;
            
           if (z==demhanhtrinh-2)
               rescue=1;
               else rescue=-1;
          }

          if (lancelot==true && level>7)
          {
              level=10;
             if (z==demhanhtrinh-2)
        rescue=1;
        else rescue=-1;
          }
          if (arthur==false && lancelot==false )
          {
            if(level==10)
            {
        if (HP>MAXHP)
        HP=MAXHP;
        if (z==demhanhtrinh-2)
        rescue=1;
        else rescue=-1;
            }
             
              if(level<10)
              {
        if (HP>MAXHP)
        HP=MAXHP;
                rescue=0;
              }
            
          }
          demtihon=demtihon1(tihon,demtihon);
        demech=demech1(ech,demech);
        if (demtihon==4 && HP>0 )
           {
               tihon=false;
               HP=HP*5;}
    
        if (demech==4 && HP>0)
            {ech=false;
            level=level1;}
    
        if (HP>MAXHP)
        HP=MAXHP;
          display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
      }
      }
      }
}    