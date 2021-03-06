
int nbuf[1024];

typedef struct { float x, y, z; } Vector;
typedef struct { Vector i, j, k, l; } Matrix;

#define MYRAND_MAX 0x7fffffff

static int seed=-343242342, seed2=1238754567, seed3=861231231, seed4=-1757545634;
int __inline myrand() {
  return (seed=seed*seed3--^(seed2+=seed4++>>8))&0x7fffffff;
}

/*
#define  MYRAND_MAX RAND_MAX
#define myrand() rand()
*/

__inline Vector *v_create(Vector *d, float x, float y, float z) {
  d->x=x; d->y=y; d->z=z; return d;
}

__inline Vector *v_comb(Vector *d, Vector *a, float ak, Vector *b, float bk) { d->x=a->x*ak+b->x*bk; d->y=a->y*ak+b->y*bk; d->z=a->z*ak+b->z*bk; return d; }
#define v_mul(d, a, k) v_comb(d, a, k, a, 0)
#define v_add(d, a, b) v_comb(d, a, 1, b, 1)
#define v_sub(d, a, b) v_comb(d, a, 1, b, -1)

__inline Vector *v_vmul(Vector *d, Vector *a, Vector *b) { d->x=a->x*b->x; d->y=a->y*b->y; d->z=a->z*b->z; return d; }
__inline float v_dot(Vector *a, Vector *b) { return a->x*b->x+a->y*b->y+a->z*b->z; }
__inline Vector *v_norm(Vector *d) { return v_mul(d, d, 1./sqrt(v_dot(d, d))); }
__inline Vector *v_cross(Vector *d, Vector *a, Vector *b) { d->x=a->y*b->z-a->z*b->y; d->y=a->z*b->x-a->x*b->z; d->z=a->x*b->y-a->y*b->x; return d; }

__inline int ixnoise(int x, int y, int z) {
  return nbuf[nbuf[nbuf[z&1023]+y&1023]+x&1023];
}
int xnoise(int x, int y, int z) {
  int xx,yy,zz,x2,y2,z2;
  xx=x&1023; yy=y&1023; zz=z&1023;
  xx=xx*xx*(1536-xx)>>19;
  yy=yy*yy*(1536-yy)>>19;
  zz=zz*zz*(1536-zz)>>19;
  x2=1024-xx; y2=1024-yy; z2=1024-zz;
  x>>=10; y>>=10; z>>=10;
  return ((ixnoise(x,y  ,z  )*x2+ixnoise(x+1,y  ,z  )*xx)*y2
         +((ixnoise(x,y+1,z  )*x2+ixnoise(x+1,y+1,z  )*xx)*yy)>>15)*z2
        +((ixnoise(x,y  ,z+1)*x2+ixnoise(x+1,y  ,z+1)*xx)*y2
         +(((ixnoise(x,y+1,z+1)*x2+ixnoise(x+1,y+1,z+1)*xx)*yy)>>15)*zz)>>15;
}










static float parti[32768*4];
float emmental(float *p, float k, float s, float z) {
  float x=
    xnoise((p[0]+7566.8766)*k, (p[1]+2334.675)*k, (p[2]+6547.9257)*k)*4*(1/2048.0)-1;
  s*=k;
  x=1-x*x*z; if (x<-1) x=-1;
  if (s<1000.0) x+=1000.0/s-1;
  if (s>2000.0) x+=(s-2000.0)*0.0005;
  if (x<0) x=0; if (x>1) x=1; return x;
}
void presumu() {
  float *p, r, s;
  int i, j, k;


	const float bla=64.0f*exp(-8.0f);

	for (i=0; i<1024; i++) nbuf[i]=i;
  for (i=0; i<1024; i++) j=myrand()&1023, k=nbuf[i], nbuf[i]=nbuf[j], nbuf[j]=k;
  
  for (p=parti; p<parti+sizeof(parti)/sizeof(parti[0]); p+=4) {
    if ((p-parti&511)==0)
		{
			realframebuffer[119*320+32+rfbbla]=0xc0c0ff;
			realframebuffer[120*320+32+rfbbla++]=0xc0c0ff;
			ptc_update(realframebuffer);
		}
    do {
      do {
//        s=myrand()*(1.0f/MYRAND_MAX); s=64.0f*exp(-s*8.0f);
        s=64.0f*exp(myrand()*(-8.0f/MYRAND_MAX));
        do {
          p[0]=(myrand()*(1.0f/MYRAND_MAX)-0.5f)*32768.0f;
          p[1]=(myrand()*(1.0f/MYRAND_MAX)-0.5f)*32768.0f;
          p[2]=(myrand()*(1.0f/MYRAND_MAX)-0.5f)*32768.0f;
          r=p[0]*p[0]+p[1]*p[1]+p[2]*p[2];
        } while (r>16384.0f*16384.0f);
        r=(s-bla)/sqrt(r); p[0]*=r; p[1]*=r; p[2]*=r;
        r=p[0]*p[0]+(p[1]-16.0f)*(p[1]-16.0f)+p[2]*p[2];
      } while (r>1024.0f/* || r*(MYRAND_MAX/1024.0f)<myrand()*/);
      r=32768.0f*emmental(p, 656100.0f, s, 10.0f)*emmental(p, 218700.0f, s, 10.0f)*emmental(p, 72900.0f, s, 10.0f)
             *emmental(p, 24300.0f, s, 10.0f)*emmental(p, 8100.0f, s, 10.0f)*emmental(p, 2700.0f, s, 20.0f)
             *emmental(p, 900.0f, s, 30.0f)*emmental(p, 300.0f, s, 30.0f)*emmental(p, 50.0f, s, 100.0f);
    } while (r*(MYRAND_MAX/32768.0f)<myrand() *.0006125f);
		
    p[3]=(s-52.0f*exp(-8.0f))*5.0f;
  }
}
void teematriisi1(Matrix *m, Vector *pos, Vector *tgt, Vector *yvec) {
  Vector vi, vj, vk;
  v_sub(&vk, tgt, pos); v_norm(&vk);
  v_cross(&vi, &vk, yvec); v_norm(&vi);
  v_cross(&vj, &vi, &vk); v_norm(&vj);
  m->i.x=vi.x; m->i.y=vj.x; m->i.z=vk.x;
  m->j.x=vi.y; m->j.y=vj.y; m->j.z=vk.y;
  m->k.x=vi.z; m->k.y=vj.z; m->k.z=vk.z;
  m->l.x=-pos->x*vi.x-pos->y*vi.y-pos->z*vi.z;
  m->l.y=-pos->x*vj.x-pos->y*vj.y-pos->z*vj.z;
  m->l.z=-pos->x*vk.x-pos->y*vk.y-pos->z*vk.z;
}
void teesumu(short *buf, float t) {
  int x, y, x2, y2, x3, y3, i;
  static int tmp[240*160];
  float r, xx, yy, zz;
  float *p, *pe;
  Vector pos, dir, yvec;
  Matrix cam;

  for (i=0; i<240*160; i++) tmp[i]=0;

  r=-cos(t*0.003);
  r=exp(r*5);
  pos.x=sin(t*0.0101); pos.y=cos(t*0.0123); pos.z=sin(t*0.0097); v_norm(&pos);
  pos.x*=r;  pos.y*=r;  pos.z*=r; 
  v_comb(&dir, v_create(&dir, 0,16,0), r*exp(-5), &dir, 0);
  v_comb(&pos, &pos, 1, &dir, 1);
  teematriisi1(&cam, &pos, &dir, v_create(&yvec, 1, 0.5, 0.5));
  v_create(&yvec, 50, 100, 1);
  v_vmul(&cam.i, &cam.i, &yvec); v_vmul(&cam.j, &cam.j, &yvec);
  v_vmul(&cam.k, &cam.k, &yvec); v_vmul(&cam.l, &cam.l, &yvec);
  cam.i.x+=80*cam.i.z; cam.j.x+=80*cam.j.z; cam.k.x+=80*cam.k.z; cam.l.x+=80*cam.l.z;
  cam.i.y+=120*cam.i.z; cam.j.y+=120*cam.j.z; cam.k.y+=120*cam.k.z; cam.l.y+=120*cam.l.z;

  pe=parti+sizeof(parti)/sizeof(parti[0]);
  for (p=parti; p<pe; p+=4) {
    zz=p[0]*cam.i.z+p[1]*cam.j.z+p[2]*cam.k.z+cam.l.z;
    if (*(int*)&zz>0) {
      zz=1.0/zz;
      xx=p[0]*cam.i.x+p[1]*cam.j.x+p[2]*cam.k.x+cam.l.x;
      x2=floor((xx+p[3]  )*zz+.5f); if (x2<0) continue;
      x3=floor((xx-p[3]  )*zz+.5f); if (x3>159) continue;
      yy=p[0]*cam.i.y+p[1]*cam.j.y+p[2]*cam.k.y+cam.l.y;
      y2=floor((yy+p[3]*2)*zz+.5f); if (y2<0) continue;
      y3=floor((yy-p[3]*2)*zz+.5f); if (y3>239) continue;
      x=floor(xx*zz+.5f); y=floor(yy*zz+.5f);
      if (x <0) x =0; if (y <0) y =0; if (x >159) x =159; if (y >239) y =239;
      if (x3<0) x3=0; if (y3<0) y3=0; if (x2>159) x2=159; if (y2>239) y2=239;
      y*=160; y2*=160; y3*=160;
      tmp[y3+x3]++;  tmp[y2+x3]--;  tmp[y3+x2]--;  tmp[y2+x2]++;
      tmp[y +x ]+=3; tmp[y2+x ]-=3; tmp[y +x2]-=3; tmp[y2+x2]+=3;
    }
  }

  buf[0]=tmp[0]<<4;
  for (x=1; x<160; x++) buf[x]=(tmp[x]+=tmp[x-1])<<4;
  for (y=160; y<240*160; y+=160) {
    buf[y]=(tmp[y]+=tmp[y-160])<<4; if (buf[y]>=32) buf[y]-=32;
    for (x=y+1; x<y+160; x++) {
      buf[x]=(tmp[x]+=tmp[x-1]+tmp[x-160]-tmp[x-161])<<4;
      if (buf[x]>=32) buf[x]-=32;
    }
  }

//	int i;
//	for (i=0; i<241*160; i++) buf[i]=0;


}


