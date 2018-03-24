****
*
* R McLean 7 February 2006
* 
* EL504 pentode 
* parameter extraction, from data sheets, 7 February 2006
* grid current not modeled
****
*
.SUBCKT EL504 A S G K 
+ PARAMS: Ex=1.36356218017116 Kg1=309.008226941514 Kp=24.0913886609314 Kvb=9.84050855226085 Mu=7.9025411899847
+ Exd=1.01472919685363 Kd=92.2849763943327 Ks=0.270652934579086 Kg=0.00189539610643784
+ CCG=22.0P CPG1=1.75P CCP=9.0P

Eat	at	0	Value={limit(0.636*ATAN(limit(V(A,K),0,2000)/KVB),0,1)} ; arctangent shaping
Eme	me	0	VALUE={PWR(LIMIT(V(A,K),0,2000),EXD)/KD} ; diode line
Egs	gs	0	VALUE= {V(S,K)/KP*LOG(1+EXP((1/MU+V(G,K)/V(S,K))*KP))} ; effective voltage
Egs2	gs2	0	VALUE={(PWR(V(gs),EX)+PWRS(V(gs),EX))/(KG1*0.636)} ; total space current
G1	A	K	VALUE={LIMIT(V(gs2)*V(at),0,V(me))} ; plate current 
Escrn	sc	0	VALUE={KS*V(gs2)*(1.1-V(at))} ; reverse arctan shaping for screen current
G2 S K	VALUE={Limit(V(sc),0,10)*LIMIT(V(S,K),0,10)/10} ; screen current
* no grid current data available so comment out the grid current line
*G3	G	K	VALUE={PWR(LIMIT(V(G,K)+1,0,1E6),1.5)*(1.25-V(at))*KG} ; grid current
C1	G	K	{CCG} ; CATHODE-GRID 1
C2	A	G	{CPG1} ; GRID 1-PLATE
C3	A	K	{CCP} ; CATHODE-PLATE
.ENDS EL504