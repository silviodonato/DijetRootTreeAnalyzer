import ROOT

chi2File = "chi2.txt"

def lineToNum(l):
  return float(l.split(",")[0])

txt = open(chi2File)
ls = txt.readlines()

chi2 = {}
chi2[3] = lineToNum(ls[0])
chi2[4] = lineToNum(ls[1])
chi2[5] = lineToNum(ls[2])
chi2[6] = lineToNum(ls[3])
chi2[7] = lineToNum(ls[4])

chi2Alt = {}
chi2Alt[3] = lineToNum(ls[5])
chi2Alt[4] = lineToNum(ls[6])
chi2Alt[5] = lineToNum(ls[7])
chi2Alt[6] = lineToNum(ls[8])
chi2Alt[7] = lineToNum(ls[9])

print("chi2 = %s"%str(chi2))
print("chi2Alt = %s"%str(chi2Alt))

nbins = 19


## NB n2>n1 !
def fisher(n1,n2,chi2,chi2_n2=0):
  if chi2_n2==0: chi2_n2 = chi2
  fisher = ((chi2[n1]-chi2_n2[n2])/(n2-n1))/(chi2_n2[n2]/(nbins-n2))
  return fisher

def CL(fisher, n2):
  cl = 1.0 - ROOT.TMath.FDistI(fisher, 1.0, nbins - n2)
  return cl

fish_ = {}
cl_ = {}

print("")
print("NOMINAL")
print("\tChi2")
for n1 in chi2.keys():
  print("%d\t%.2f"%(n1, chi2[n1]))

print("")
print("\tFisher\tCL")
for n1 in chi2.keys():
  n2 = n1+1
  if not (n2 in chi2.keys()): continue
  fish = fisher(n1,n2,chi2) 
  cl = CL(fish,n2)
  fish_[n1] = fish
  cl_[n1] = cl
  print("%d vs %d\t%f\t%f"%(n1,n2,fish,cl))

fishAlt_ = {}
clAlt_ = {}

print("")
print("ALTERNATIVE")
print("\tChi2")
for n1 in chi2Alt.keys():
  print("%d\t%.2f"%(n1, chi2Alt[n1]))

print("")
print("\tFisher\tCL")
for n1 in chi2Alt.keys():
  n2 = n1+1
  if not (n2 in chi2Alt.keys()): continue
  fish = fisher(n1,n2,chi2Alt) 
  cl = CL(fish,n2)
  fishAlt_[n1] = fish
  clAlt_[n1] = cl
  print("%d vs %d\t%f\t%f"%(n1,n2,fish,cl))


lt_chi2 =    (chi2[3],chi2[4],chi2[5],chi2[6],chi2[7]) 
lt_chi2Alt = (chi2Alt[3],chi2Alt[4],chi2Alt[5],chi2Alt[6],chi2Alt[7]) 
lt_f_CL =    (fish_[3],cl_[3],fish_[4],cl_[4],fish_[5],cl_[5],fish_[6],cl_[6]) 
lt_f_CLAlt =    (fishAlt_[3],clAlt_[3],fishAlt_[4],clAlt_[4],fishAlt_[5],clAlt_[5],fishAlt_[6],clAlt_[6]) 

lt_all = lt_chi2 + lt_chi2Alt + lt_f_CL + lt_f_CLAlt

test_alt = 5
test_nom = 4
 

print("Alternative%d vs Nominal %d"%(test_alt,test_nom))
fish = fisher(test_alt,test_nom,chi2Alt,chi2)
print("Fisher =  %.2f"%(fish))
cl = CL(fish,test_nom)
print("CL =  %.2f"%(cl))


print("Nominal%d vs Alternative %d"%(test_nom,test_alt))
fish = fisher(test_nom,test_alt,chi2,chi2Alt)
print("Fisher =  %.2f"%(fish))
cl = CL(fish,test_alt)
print("CL =  %.2f"%(cl))

print("  ###  LATEX  ###  ")
print(r""" \begin{table}[th]
   \centering
   \normalsize
   \begin{tabular}{|c|c|}
     \hline
     \multicolumn{2}{|c|}{Nominal Family} \\
     \hline
               & $\chi^2$ \\
     \hline
     3Par & %.0f  \\
     4Par & %.1f  \\
     5Par & %.2f  \\
     6Par & %.2f  \\
     7Par & %.2f  \\
     \hline
     \multicolumn{2}{|c|}{Alternative Family} \\
     \hline
     3Par & %.0f  \\
     4Par & %.1f  \\
     5Par & %.2f  \\
     6Par & %.2f  \\
     7Par & %.2f  \\
     \hline
   \end{tabular}
   \caption{$\chi^2 of the fits$.}
   \label{table:Chi2}
 \end{table}

 \begin{table}[th]
   \centering
   \normalsize
   \begin{tabular}{|c|c|c|}
     \hline
     \multicolumn{3}{|c|}{Nominal Family} \\
     \hline
               & F-value & CL \\
     \hline
     3Par-4Par & %.0f  & %.3f \\
     4Par-5Par & %.1f  & %.3f \\
     5Par-6Par & %.2f  & %.3f \\
     6Par-7Par & %.2f  & %.3f \\
     \hline
     \multicolumn{3}{|c|}{Alternative Family} \\
     \hline
     3Par-4Par & %.0f & %.3f \\ 
     4Par-5Par & %.1f & %.3f \\ 
     5Par-6Par & %.2f & %.3f \\ 
     5Par-6Par & %.2f & %.3f \\ 
     \hline
   \end{tabular}
   \caption{Fisher test results are reported for each family.}
   \label{table:Fvalue}
 \end{table}"""%lt_all)
