var Init=function(){function J(a,c){var b=Math.sin(6.283184*a);return 1===c?0>b?-1:1:2===c?a%1-.5:3===c?(b=a%1*4,2>b?b-1:3-b):b}function u(a,b,c,l,p,t,u,z,B,E,A,G,w,F,I,N,R,S,T,U,O,V,Z,aa,f,ba,ca){var m,e,v,K,P,L,M,W,C,D,h,g,q,n,X,Y;O=Math.pow(2,O-8)/7350;var da=Math.pow(2,f-8)/7350;for(e=0;e<H;e+=2)d[e]=0,d[e+1]=128;for(v=K=0;v<a.length;++v)for(P=a[v],e=0;32>e;++e){if(P&&(m=b[P-1][e]))for(L=M=0,X=.00390625*Math.pow(1.059463094,m+12*(c-8)-128),Y=.00390625*Math.pow(1.059463094,m+12*(u-8)-128),W=S/
255,C=D=0,m=G+w+F-1;0<=m;--m){f=m+K;h=J(f*da,ca)*ba/512+.5;q=1;m<G?q=m/G:m>=G+w&&(q-=(m-G-w)/F);g=X;Z&&(g+=h);l&&(g=g*q*q);L+=g;n=J(L,t)*p;g=Y;z&&(g=g*q*q);M+=g;n+=J(M,E)*B;A&&(n+=(2*Math.random()-1)*A*q);n*=q/255;g=R;aa&&(g*=h);g=1.5*Math.sin(3.141592*g/44100);C+=g*D;h=W*(n-D)-C;D+=g*h;switch(N){case 1:n=h;break;case 2:n=C;break;case 3:n=D;break;case 4:n=C+h}g=J(f*O,0)*V/512+.5;n=39*n*I;f<<=2;h=d[f]+(d[f+1]<<8)+n*(1-g);d[f]=h&255;d[f+1]=h>>8&255;h=d[f+2]+(d[f+3]<<8)+n*g;d[f+2]=h&255;d[f+3]=h>>8&
255}K+=7350}v=7350*T>>1;g=U/255;for(m=0;m<Q-v;++m)e=4*m,f=4*(m+v),h=d[f]+(d[f+1]<<8)+(d[e+2]+(d[e+3]<<8)-32768)*g,d[f]=h&255,d[f+1]=h>>8&255,h=d[f+2]+(d[f+3]<<8)+(d[e]+(d[e+1]<<8)-32768)*g,d[f+2]=h&255,d[f+3]=h>>8&255;for(e=0;e<H;e+=2)h=r[e]+(r[e+1]<<8)+d[e]+(d[e+1]<<8)-32768,r[e]=h&255,r[e+1]=h>>8&255}function w(b,c,d){p=a.createShader(c);a.shaderSource(p,b);a.compileShader(p);a.attachShader(d,p)}function z(a,b,c){for(var d=0;d<a.length;++d)if(b>=a[d].t1&&b<=a[d].t2)return a[d].p1+a[d].v*(b-a[d].t1);
return c}document.body.innerHTML="";document.body.style.cursor="none";document.body.style.backgroundColor="#000";document.body.style.overflow="hidden";document.body.style.margin="0px";document.body.style.padding="0px";document.body.style.outline="0px";for(var b=8/1.5,Q=44100*(29*b+10),H=4*Q,p=Math.ceil(Math.sqrt(2*Q/2)),c=document.createElement("canvas").getContext("2d"),d=c.createImageData(p,p).data,r=c.createImageData(p,p).data,c=p*p*4-2;0<=c;c-=2)r[c]=0,r[c+1]=128;u([0,0,0,0,1,1,1,1,0,4,0,1,1,
3,2,5,1,1,1,3,1,0,4,0,1,0,1],[[149,0,0,0,0,0,149,0,147,0,147,0,0,0,0,0,0,0,142,142,0,0,145,145,0,0,142,0,0,0,0,0],[144,0,0,0,0,0,0,0,144,0,0,0,0,0,0,0,144,144,0,0,144,144,0,0,144,144,156,156,168,168,180,180],[144,0,144,0,0,0,144,0,149,0,161,0,149,0,0,0,0,0,147,147,0,0,145,145,157,0,145,0,0,0,142,0],[149,0,0,0,0,0,149,0,157,0,157,0,157,0,0,0,0,0,156,0,0,0,163,0,0,0,161,0,0,0,0,0],[180,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]],8,0,102,3,7,1,97,0,0,2727,6363,3636,151,3,4100,213,
2,191,2,231,0,1,4,45,0);u([3,3,1,3,1,3,1,3,1,3,3,3,3,3,2,4,3,3,3,1,3,3,3,1,3,1,3,3,3],[[137,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,149,0,0,0,0,0,0,0,137,0,0,0,0,0],[137,0,0,0,0,0,0,0,149,0,0,0,0,0,0,0,0,0,161,0,0,0,0,0,180,0,0,0,0,0,0,0],[137,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,137,0,0,0,0,0,0,0,137,0,0,0,0,0],[180,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,149,0,0,0,0,0,0,0,137,0,0,0,0,0]],7,0,127,0,6,0,61,2,0,14545,61818,5454,113,2,2900,185,2,216,7,91,0,1,5,196,0);u([0,0,1,0,0,1,1,0,1,0,2,0,1,1,0,3,0,1,0,1,0,2,
0,1,0,1,0,1],[[149,0,0,0,0,0,149,0,0,0,0,0,0,0,0,0,0,0,142,0,0,0,145,0,0,0,0,0,0,0,0,0],[149,0,0,0,0,0,149,0,0,0,0,0,0,0,0,0,0,0,157,0,0,0,156,0,0,0,0,0,0,0,0,0],[156,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,149,0,0,0,140,0,0,0,144,0,0,0,137,0,0,149]],7,0,168,0,8,1,78,0,0,3636,56363,9090,144,3,3800,217,2,218,2,217,0,1,3,130,0);u([0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,3,1,1,1,1,1,1,1,1,1,1,1,1],[[149,149,0,0,0,0,0,0,149,0,0,0,0,0,0,0,149,149,0,0,0,0,0,0,149,0,0,149,0,0,0,0],[149,0,0,0,0,0,0,0,149,0,0,0,0,0,0,0,149,0,
0,0,149,0,0,0,149,0,0,0,149,0,0,0],[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,149,149,0,0]],6,1,255,0,6,1,255,0,0,0,1818,11818,36,2,7500,254,0,18,0,0,0,0,0,0,0);u([0,0,0,0,3,3,3,3,3,3,3,3,1,3,2,0,1,1,1,1,1,3,3,3,3,3,3,3],[[0,0,149,0,0,0,149,0,0,0,0,0,149,149,0,0,0,0,0,0,149,0,149,0,0,0,0,0,149,0,149,0],[0,0,0,0,149,0,0,0,0,0,0,0,149,0,0,0,0,0,149,0,0,0,149,0,0,0,149,0,0,0,149,0],[0,0,0,0,149,0,149,0,0,0,149,0,0,0,0,0,0,0,0,0,149,0,149,0,0,0,0,0,149,0,0,0]],7,1,0,0,9,1,0,0,53,100,3636,
9090,36,4,4400,155,2,28,2,45,0,1,2,214,0);var E;l1=H-8;l2=l1-36;wave=atob("UklGRjhuuQFXQVZFZm10IBAAAAABAAIARKwAABCxAgAEABAAZGF0YRRuuQE=");for(c=0;c<H;){x="";for(k=0;256>k&&c<H;++k,c+=2)y=4*(r[c]+(r[c+1]<<8)-32768),y=-32768>y?-32768:32767<y?32767:y,x+=String.fromCharCode(y&255,y>>8&255);wave+=x}p="data:audio/wav;base64,"+btoa(wave);wave=null;E=new Audio(p);var l=[3,0,3,0,-3,0,-3,0,.8,.6,.8,1280,.29,.39,.49,720],c=document.createElement("canvas");c.width=l[11];c.height=l[15];c.style.position="absolute";
c.style.top=((window.innerHeight-c.height)/2).toString()+"px";c.style.left=((window.innerWidth-c.width)/2).toString()+"px";var a=c.getContext("webgl");document.body.appendChild(c);var F=a.createBuffer(),N=a.createFramebuffer();a.bindFramebuffer(a.FRAMEBUFFER,N);var A=a.createTexture();a.bindTexture(a.TEXTURE_2D,A);a.texParameteri(a.TEXTURE_2D,a.TEXTURE_WRAP_S,a.CLAMP_TO_EDGE);a.texParameteri(a.TEXTURE_2D,a.TEXTURE_WRAP_T,a.CLAMP_TO_EDGE);a.texParameteri(a.TEXTURE_2D,a.TEXTURE_MIN_FILTER,a.NEAREST);
a.texParameteri(a.TEXTURE_2D,a.TEXTURE_MAG_FILTER,a.NEAREST);a.getExtension("OES_texture_float");a.texImage2D(a.TEXTURE_2D,0,a.RGBA,c.width,c.height,0,a.RGBA,a.FLOAT,null);a.framebufferTexture2D(a.FRAMEBUFFER,a.COLOR_ATTACHMENT0,a.TEXTURE_2D,A,0);a.bindBuffer(a.ARRAY_BUFFER,F);a.bufferData(a.ARRAY_BUFFER,new Float32Array([1,1,1,-3,-3,1]),a.STATIC_DRAW);a.enableVertexAttribArray(0);a.vertexAttribPointer(0,2,a.FLOAT,!1,0,0);var B=a.createProgram(),t=a.createProgram();highp="precision highp float;";
w(highp+"attribute vec3 A;void main(){gl_Position=vec4(A,1);}",35633,B);a.attachShader(t,p);w(highp+"uniform mat4 U;float s(vec3 a){a.x+=a.y*57.+a.z*21.;return sin(cos(a.x)*a.x);}float t(vec3 a){vec3 b,c;b=floor(a);c=smoothstep(0.,1.,a-b);return mix(mix(mix(s(b),s(b+vec3(1,0,0)),c.x),mix(s(b+vec3(0,1,0)),s(b+vec3(1,1,0)),c.x),c.y),mix(mix(s(b+vec3(0,0,1)),s(b+vec3(1,0,1)),c.x),mix(s(b+vec3(0,1,1)),s(b+1.),c.x),c.y),c.z)*.5+.5;}float u(vec3 a){return t(a*.06125)*.5+t(a*.125)*.25+t(a*.25)*.125;}float v(vec3 a,float b){float c=length(a)-b;return c;}float w(vec3 a,vec3 b){vec3 c=abs(a)-b;return min(max(c.x,max(c.y,c.z)),0.)+length(max(c,0.));}vec3 x(in vec3 a,in vec3 b,out vec3 c){c=floor((.5*b+a)/b);return mod(.5*b+a,b)-.5*b;}vec3 y(vec3 a,float b){float c,d;c=cos(b);d=sin(b);vec3 e=a;e.y=c*a.y-d*a.z;e.z=d*a.y+c*a.z;return e;}vec3 z(vec3 a,float b){float c,d;c=cos(b);d=sin(b);vec3 e=a;e.x=c*a.x+d*a.z;e.z=-d*a.x+c*a.z;return e;}float A(in vec3 a,out int b){vec3 c,d,e;c=vec3(0);d=x(a,vec3(.5,3,.5),c);e=z(d,U[0].w*.01*sin(length(c)));float f,g,h;f=w(e,vec3(.25));e=y(a,U[0].w*.1);g=max(-w(e,vec3(6)),f);h=v(a,3.)+u(a*10.*sin(U[1].w));b=1;if(h<g)b=0;return min(g,h);}vec3 B(float a,vec3 b,vec3 c,vec3 d,vec3 e){return b+c*cos(6.28318*(d*a+e));}vec3 C(in int a,in vec3 b,out bool c,out float d){vec3 e=vec3(1);c=true;d=20.;if(a==1){e=B(smoothstep(0.,1.,length(b)/36.),vec3(.5),vec3(.5),vec3(2,1,0),vec3(.5,.2,.25));c=false;d=10.;}return e;}vec3 D(vec3 a,vec3 b,vec3 c,vec3 d,vec3 e){float f,g,h;f=length(b-c);g=1.-exp(-f*.05);h=max(dot(d,e),0.);vec3 i=mix(U[3].xyz,U[2].xyz,pow(h,8.));return mix(a,i,g);}vec3 E(vec3 a){vec3 b,d;b=vec3(.1/U[2].w,0,0);int c=0;d=vec3(A(a+b.xyy,c)-A(a-b.xyy,c),A(a+b.yxy,c)-A(a-b.yxy,c),A(a+b.yyx,c)-A(a-b.yyx,c));return normalize(d);}float F(in vec3 a,in vec3 b,in float c,out vec3 d,out int e){vec3 f=vec3(0);float g,h,i,j,k,l,m;g=1e-4;h=0.;i=1.2;j=0.;k=g;l=1e3;m=sign(A(a,e));for(int n=0;n<128;++n){f=b*g+a;float o,p,r;o=m*A(f,e);p=abs(o);bool q=i>1.&&p+j<h;if(q){h-=i*h;i=1.;}else h=o*i;j=p;r=p/g;if(!q&&r<l){k=g;l=r;}if(!q&&r<.1/U[2].w||g>c)break;g+=h;}if(g>=c)return c;d=E(b*k+a);return k;}float G(vec3 a,vec3 b,float c){float d,e;d=sign(c);e=d*.5+.5;int f=0;for(int g=0;g<6;++g)e-=(float(g)*c-A(a+b*float(g)*c*d,f))/exp2(float(g));return max(min(e,1.),0.);}float H(in vec3 a,inout vec3 b,inout vec3 c,inout vec3 d,out int e){c=reflect(c,d);float f=F(a,c,20.,d,e);b=f*c+a;return f;}vec3 I(vec3 a,vec3 b,vec3 c,vec3 d,vec3 e,float f){float g,h,k,l,m;g=dot(a,b);h=max(0.,g);vec3 i,j,n;i=normalize(d);j=reflect(-b,a);k=max(dot(j,d),0.);l=pow(k,f);m=G(c,a,.5);n=m*U[2].xyz+h*U[3].xyz+l*vec3(.1,.19,.22);return n*e;}vec3 J(vec3 a,vec3 b,vec3 c,vec3 d,int e){bool f=false;float g=.1;vec3 h,i;h=C(e,b,f,g);i=I(a,c,b,d,h,g);for(int j=0;j<3;++j)if(f){vec3 k=4.*1e-4*a+b;float l=H(k,b,d,a,e);if(l<20.){h=C(e,b,f,g);i+=I(a,c,b,d,h,g);i*=.5;}else{i+=D(i,b,k,d,c);i*=.5;break;}}return i;}mat3 K(vec3 a,vec3 b,float c){vec3 d,e,f,g;d=normalize(b-a);e=vec3(sin(c),cos(c),0);f=normalize(cross(d,e));g=normalize(cross(f,d));return mat3(f,g,d);}void main(){const float a=40.;vec2 b,c;b=gl_FragCoord.xy/vec2(U[2].w,U[3].w);c=-1.+2.*b;c.x*=U[2].w/U[3].w;vec3 d,e,g,h,k,l,m,n;d=U[0].xyz;e=U[1].xyz;mat3 f=K(d,e,0.);g=normalize(f*vec3(c.xy,1.57079633));h=vec3(0);int i=0;float j,o;j=F(d,g,a,h,i);k=g*j+d;l=normalize(d-e);m=U[3].xyz;if(j<a)m=J(h,k,l,g,i);m=D(m,k,d,g,l);n=vec3(.299,.587,.114);o=dot(m,n);m=vec3(o)*m;m=pow(m,vec3(.8));m=smoothstep(0.,1.,m);gl_FragColor=vec4(m,1);}",
35632,B);a.linkProgram(B);w(highp+"uniform sampler2D S;uniform float B;void main(){const vec2 a=vec2(1280,720);vec2 b=gl_FragCoord.xy/a.xy;float c,d,g,h,i;c=3./a.y;d=3./a.x;vec4 e=vec4(.1531,.12245,.0918,.051);gl_FragColor=texture2D(S,vec2(b.x,b.y))*.1633;gl_FragColor+=texture2D(S,vec2(b.x,b.y))*.1633;for(int f=0;f<4;++f)gl_FragColor+=texture2D(S,vec2(b.x-(float(f)+1.)*c,b.y))*e[f]+texture2D(S,vec2(b.x,b.y-(float(f)+1.)*d))*e[f]+texture2D(S,vec2(b.x+(float(f)+1.)*c,b.y))*e[f]+texture2D(S,vec2(b.x,b.y+(float(f)+1.)*d))*e[f];gl_FragColor+=texture2D(S,b)*1.5;gl_FragColor.rgb+=B;g=.005;h=.8;i=distance(b,vec2(.5));gl_FragColor.rgb*=smoothstep(.8,g*.799,i*(h+g));}",
35632,t);a.linkProgram(t);var I=-4,R=[{t1:0,t2:4*b,p1:-4,v:3/(4*b)},{t1:8*b,t2:12*b,p1:-1,p2:0,v:1/(4*b)},{t1:28.5*b,t2:29*b,p1:0,p2:-4,v:-4/(.5*b)}],S=[{t1:0,t2:12*b,p1:0,v:Math.PI/(12*b)},{t1:14*b,t2:16*b,p1:Math.PI,p2:2*Math.PI,v:Math.PI/(2*b)}],T=[{t1:0,t2:14*b,p1:3,v:3/(14*b)},{t1:14.5*b,t2:16*b,p1:6,p2:-6,v:-10/(1.5*b)}],U=[{t1:15*b,t2:16*b,p1:0,v:1/b}],V=[{t1:16*b,t2:29*b,p1:3,v:-27/(13*b)}];E.play();mainloop=function(){l[3]=E.currentTime;I=z(R,l[3],I);l[7]=z(S,l[3],l[7]);l[0]=z(T,l[3],l[0]);
l[1]=z(U,l[3],l[1]);l[2]=z(V,l[3],l[2]);a.bindFramebuffer(a.FRAMEBUFFER,N);a.useProgram(B);a.bindBuffer(a.ARRAY_BUFFER,F);a.uniformMatrix4fv(a.getUniformLocation(B,"U"),!1,l);a.drawArrays(a.TRIANGLES,0,3);a.bindTexture(a.TEXTURE_2D,A);a.bindFramebuffer(a.FRAMEBUFFER,null);a.useProgram(t);a.bindBuffer(a.ARRAY_BUFFER,F);a.uniform1i(a.getUniformLocation(t,"S"),0);a.uniform1f(a.getUniformLocation(t,"B"),I);a.bindTexture(a.TEXTURE_2D,A);a.drawArrays(a.TRIANGLES,0,3);E.ended?cancelAnimationFrame(mainloop):
requestAnimationFrame(mainloop)};mainloop()};