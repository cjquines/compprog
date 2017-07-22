#include <bits/stdc++.h>
using namespace std;

// tbh this week is makin me feel stressed
// so this is how i relieve my stress:
#define buumbilang int
#define doble double
#define kapid pair
#define tugano vector
#define tangkas_ng_piraso bitset
#define pangunahin main
#define kung if
#define liban else
#define para_sa for
#define habang while
#define cloob cin
#define clabas cout
#define una first
#define ikalawa second
#define halating_uri typedef
#define kawalan void
#define awto auto
#define muling_itakda reset
#define takda_alaala memset
#define laki_ng sizeof
#define lagay_palikod emplace_back
#define pps ios
#define pps_sandigan ios_base
#define takda_katiyakan setprecision
#define panatilihan fixed
#define takda_pps_marka setiosflags
#define magsync_sa_pmnpp sync_with_stdio

#define ULIT(i, a, b) para_sa(buumbilang(i) = buumbilang(a); (i) <= buumbilang(b); (i)++)
#define U una
#define I ikalawa
#define LP lagay_palikod
#define N 711
halating_uri kapid<buumbilang, buumbilang> bb;
halating_uri kapid<buumbilang, doble> bd;
halating_uri tugano<bd> tbd;

tangkas_ng_piraso<N> tr;
buumbilang n, ugat;
doble p[N][N];
bb k[N];
tbd s[N];

kawalan takda(buumbilang v, buumbilang a, buumbilang b); 

kawalan lalimang_paghanap(buumbilang v) {
  kung (v <= n) s[v].LP(v, 1);
  liban {
    lalimang_paghanap(k[v].U), lalimang_paghanap(k[v].I);
    takda(v, k[v].U, k[v].I), takda(v, k[v].I, k[v].U);
  }
}

kawalan takda(buumbilang v, buumbilang a, buumbilang b) {
  para_sa(awto it : s[a]) {
    doble pansamantala = 0;
    para_sa(awto jt : s[b])
      pansamantala += it.I * jt.I * p[it.U][jt.U];
    s[v].LP(it.U, pansamantala);
  }
}

buumbilang pangunahin() {
  pps_sandigan::magsync_sa_pmnpp(0);
  clabas << takda_pps_marka(pps::panatilihan) << takda_katiyakan(6);
  habang(cloob >> n, n) {
    tr.muling_itakda();
    takda_alaala(s, 0, laki_ng(s));
    ULIT(i, 1, n) ULIT(j, 1, n) cloob >> p[i][j];
    ULIT(i, n+1, 2*n-1) cloob >> k[i].U >> k[i].I, tr[k[i].U] = tr[k[i].I] = 1;
    ULIT(i, 1, 2*n-1) kung(!tr[i]) ugat = i;
    lalimang_paghanap(ugat);
    para_sa(awto it : s[ugat]) kung(it.U == 1)
      clabas << it.I << '\n';
  }
}