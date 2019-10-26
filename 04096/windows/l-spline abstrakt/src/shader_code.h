/* File generated with Shader Minifier 1.1
 * http://www.ctrl-alt-test.fr
 */
#ifndef SMTEMP_H_
# define SMTEMP_H_

const char *logo_vs_glsl = ""
 "varying vec3 Q,W,C,T,R,V,H;"
 "void main()"
 "{"
   "Q=gl_Normal;"
   "vec4 z=gl_Vertex,g=gl_Color;"
   "C=g.xyz;"
   "T=g.www;"
   "T.z=step(8.,z.x*z.x);"
   "float y=T.x,x=fract(y*.2805),s=6.,n=2.7*sin(y*.3),m=sin(n),i=cos(n);"
   "mat2x2 f=mat2x2(i,m,-m,i);"
   "if(85.8<y)"
     "x=.6*fract(x*2.);"
   "if(121.6<y)"
     "x=0;"
   "T.y=x;"
   "H=T*0;"
   "if(14.6<y)"
     "s+=x*2.;"
   "if(24.<y&&y<43.||85.8<y)"
     "++H.x;"
   "z.xyz+=Q*C.z;"
   "if(.5<C.y)"
     "z.xyz+=.04*cos(y+z.xzy*90.+z.yxz*90.);"
   "W=z.xyz;"
   "if(T.z<.5)"
     "{"
       "z.xz=f*z.xz;"
       "if(.5<H.x)"
         "z.yz=f*z.yz;"
     "}"
   "Q.xy=f*Q.xy;"
   "R=W;"
   "R.z+=s;"
   "z.xy*=3./R.z;"
   "z.z*=.01;"
   "z.z+=T.z*.8;"
   "V=z.xyz;"
   "gl_Position=z;"
 "}";

const char *logo_fs_glsl = ""
 "uniform sampler2D U;"
 "varying vec3 Q,W,C,T,R,V,H;"
 "void main()"
 "{"
   "vec3 y=W-vec3(.5,.4*sin(T.x*2.5),1.);"
   "float x=T.x,z=0,s=T.y;"
   "vec4 i=vec4(3.04*max(0,dot(Q,normalize(y)))/(3.*dot(y,y)+.2)+1.3*pow(1.-abs(dot(normalize(R),Q)),9.));"
   "i.yz*=C.x;"
   "if(.5<T.z)"
     "{"
       "i*=0;"
       "while(++z<46.1)"
         "i+=texture2D(U,V.xy*.5-.5+.00024*z*vec2(cos(z*.1),sin(z*.1)));"
       "i*=.017;"
       "if(H.x>.5)"
         "i*=1.2;"
       "i.x*=sin(x*3.2);"
       "if(V.y<-.3)"
         "{"
           "vec2 n=V.xy/(-V.y+.5);"
           "z=max(0,sin(n.y*160.)*max(0,sin(n.x*60.-x*3.)));"
           "if(H.x<.5)"
             "z*=max(0,sin(n.x*10.+sin(n.y*(60.*(1.-s)))));"
           "i+=z*(.1+(1.-s*s));"
           "i.yz*=.7;"
         "}"
       "else"
         " if(.5<H.x)"
           "{"
             "vec2 n=V.xy-vec2(.1,.8-x*.01);"
             "i+=.003/dot(n,n);"
           "}"
       "if(.99<V.y)"
         "i*=0;"
     "}"
   "s=step(s,.2)*sin(s*62.4)*.2;"
   "i.yz-=s*abs(sin(V.y*780.))-.02;"
   "if(43.<x&&x<69.&&s>.02)"
     "i=vec4(1.)-i,i.x=0;"
   "gl_FragColor=i*min(1.,62.3-x*.5);"
 "}";

#endif // SMTEMP_H_
