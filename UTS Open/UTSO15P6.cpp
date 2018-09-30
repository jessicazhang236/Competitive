#include <bits/stdc++.h>
using namespace std;
double ans;
struct vtx{
    double a, b, c;
    vtx(double i, double j, double k) {
        a=i;
        b=j;
        c=k;
    }
    vtx() {a=0; b=0; c=0;}
};
vector<vtx> vts;
struct vtx2{
    double a, b;
    vtx2(double i, double j) {
        a=i;
        b=j;
    }
    vtx2() {a=0; b=0;}
};
struct vec{
    double i, j, k;
    vec(double a, double b, double c) {
        i=a;
        j=b;
        k=c;
    }
    vec() {i=0; j=0; k=0;}
};
struct vec2{
    double i, j;
    vec2 (double a, double b) {
        i=a;
        j=b;
    }
    vec2() {i=0; j=0;}
};
struct plane{
    vec abc;
    double d;
};
struct line{
    vec ray;
    vtx pt;
};
struct line2{
    vec2 ray;
    vtx2 pt;
};
vec add(vec a, vec b) {return vec(a.i+b.i, a.j+b.j, a.k+b.k);}
vec mns(vtx a, vtx b) {return vec(a.a-b.a, a.b-b.b, a.c-b.c);}
vec2 mns2(vtx2 a, vtx2 b) {return vec2(a.a-b.a, a.b-b.b);}
vec crs(vec a, vec b) {return vec(a.j*b.k-a.k*b.j, a.k*b.i-a.i*b.k, a.i*b.j-a.j*b.i);}
double crs2(vec2 a, vec2 b) {return a.i*b.j-a.j*b.i;}
double dot(vec a, vec b) {return a.i*b.i+a.j*b.j+a.k*b.k;}
double dot2(vec a, vtx b) {return a.i*b.a+a.j*b.b+a.k*b.c;}
vec scale(vec a) {
    double m=sqrt(dot(a, a));
    return vec(a.i/m, a.j/m, a.k/m);
}
plane pln(int m, int n, int p) {
    plane pl;
    pl.abc=crs(mns(vts[m], vts[n]), mns(vts[m], vts[p]));
    pl.d=0.0-dot2(pl.abc, vts[m]);
    return pl;
}
line ln1(int m, int n) {
    line l;
    l.ray=mns(vts[n], vts[m]);
    l.pt=vts[m];
    return l;
}
double a1(int m, int n, int p) {
    plane pl=pln(m, n, p);
    double ans=sqrt(dot(pl.abc, pl.abc));
    return ans/2.0;
}
vtx sect1(line l, plane pl) {
    double t=-(pl.d+dot2(pl.abc, l.pt))/dot(pl.abc, l.ray);
    vtx v;
    if (t<0||t>1) return {NAN, NAN, NAN};
    else return {l.pt.a+l.ray.i*t, l.pt.b+l.ray.j*t, l.pt.c+l.ray.k*t};
    return v;
}
line2 ln2(vtx2 a, vtx2 b) {
    line2 l;
    l.pt=a;
    l.ray=vec2(b.a-a.a, b.b-a.b);
    return l;
}
vtx2 times(vtx2 a, double b) {
    return vtx2(a.a*b, a.b*b);
}
double dot3(vec2 a, vec2 b) {return a.i*b.i+a.j*b.j;}
vtx2 sect2(line2 a, line2 b) {
    vec2 n=vec2(-a.ray.j, a.ray.i);
    vtx2 m=vtx2(b.pt.a+b.ray.i, b.pt.b+b.ray.j);
    double i=dot3(n, vec2(m.a-a.pt.a, m.b-a.pt.b))/dot3(n, b.ray);
    if (i<0||i>1) return {NAN, NAN};
    vtx2 p=times(b.pt, i);
    vtx2 q=times(m, 1-i);
    return vtx2(p.a+q.a, p.b+q.b);
}
double shoelace(vector<vtx2> thing) {
    if (!thing.size()) return 0.0;
    thing.push_back(thing[0]);
    double ans=0.0;
    for (int i=0; i<thing.size()-1; i++) {
        ans+=thing[i].a*thing[i+1].b;
        ans-=thing[i].b*thing[i+1].a;
    }
    return fabs(ans)/2;
}
pair<vec, vec> newUnit(int m, int n, int p) {
    plane pl=pln(m, n, p);
    vec normal=pl.abc;
    vec hor=mns(vts[n], vts[m]);
    vec perp=crs(hor, normal);
    return {scale(hor), scale(perp)};
}
vtx2 project(vtx pt, int m, int n, int p) {
    vec change=mns(pt, vts[m]);
    pair<vec, vec> New=newUnit(m, n, p);
    return vtx2(dot(change, New.first), dot(change, New.second));
}
vector<vtx2> find_sect(int m, int n, int p) {
    plane pl=pln(m, n, p);
    vector<vtx2> sect;
    if (m>3) {
        for (int i=0; i<3; i++) {
            for (int j=i+1; j<4; j++) {
                vtx pt=sect1(ln1(i, j), pl);
                if (pt.a==pt.a) sect.push_back(project(pt, m, n, p));
            }
        }
    }
    else {
        for (int i=4; i<7; i++) {
            for (int j=i+1; j<8; j++) {
                vtx pt=sect1(ln1(i, j), pl);
                if (pt.a==pt.a) sect.push_back(project(pt, m, n, p));
            }
        }
    }
    return sect;
}
vector<vtx2> reorder(vector<vtx2> sects) {
    if (sects.size()==3) return sects;
    line2 a=ln2(sects[0], sects[1]);
    line2 b=ln2(sects[2], sects[3]);
    vtx2 c=sect2(a, b);
    if (c.a==c.a) swap(sects[1], sects[2]);
    a=ln2(sects[1], sects[2]);
    b=ln2(sects[3], sects[0]);
    c=sect2(a, b);
    if (c.a==c.a) swap(sects[2], sects[3]);
    return sects;
}
bool checkSide(line2 a, vtx2 b) {
    vec2 m=mns2(b, a.pt);
    if (crs2(m, a.ray)<0) return false;
    return true;
}
vector<vtx2> clipping(vector<vtx2> sects, int m, int n, int q) {
    sects.push_back(sects[0]);
    vtx2 M=project(vts[m], m, n, q);
    vtx2 N=project(vts[n], m, n, q);
    vtx2 Q=project(vts[q], m, n, q);
    line2 a=ln2(M, N);
    vector<vtx2> carrot;
    for (int i=0; i<sects.size()-1; i++) {
        if (checkSide(a, Q)==checkSide(a, sects[i]))
            carrot.push_back(sects[i]);
        line2 b=ln2(sects[i], sects[i+1]);
        vtx2 c=sect2(a, b);
        if (c.a==c.a)
            carrot.push_back(c);
    }
    sects=carrot;
    sects.push_back(sects[0]);
    carrot.clear();
    a=ln2(N, Q);
    for (int i=0; i<sects.size()-1; i++) {
        if (checkSide(a, M)==checkSide(a, sects[i]))
            carrot.push_back(sects[i]);
        line2 b=ln2(sects[i], sects[i+1]);
        vtx2 c=sect2(a, b);
        if (c.a==c.a)
            carrot.push_back(c);
    }
    sects=carrot;
    sects.push_back(sects[0]);
    carrot.clear();
    a=ln2(M, Q);
    for (int i=0; i<sects.size()-1; i++) {
        if (checkSide(a, N)==checkSide(a, sects[i]))
            carrot.push_back(sects[i]);
        line2 b=ln2(sects[i], sects[i+1]);
        vtx2 c=sect2(a, b);
        if (c.a==c.a)
            carrot.push_back(c);
    }
    return carrot;
}
int main() {
    for (int i=0; i<8; i++) {
        vtx m;
        scanf("%lf%lf%lf", &m.a, &m.b, &m.c);
        vts.push_back(m);
    }
    for (int a=0;a<2;a++) {
	    for (int b=a+1; b<3;b++) {
            for (int c=b+1;c<4;c++) {
                ans+=a1(a, b, c)+a1(a+4, b+4, c+4);
                vector<vtx2> sects=find_sect(a, b, c);
                if (sects.size()>=3) {
                    ans-=shoelace(clipping(reorder(sects), a, b, c));
                }
                vector<vtx2> sects2=find_sect(a+4, b+4, c+4);
                if (sects2.size()<3) continue;
                ans-=shoelace(clipping(reorder(sects2), a+4, b+4, c+4));
            }
	    }
    }
    printf("%.6f", ans);
}
