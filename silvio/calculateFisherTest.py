import ROOT

nbins = 14

chi2 = {}
chi2[3] = 3927.91068876
chi2[4] = 16.4987982036
chi2[5] = 6.32408665554
chi2[6] = 5.66839047663
chi2[7] = 5.67070474852

chi2Alt = {}
chi2Alt[3] = 3927.91068876
chi2Alt[4] = 9.96554956639
chi2Alt[5] = 5.93892583765
chi2Alt[6] = 6.00571075381
chi2Alt[7] = 6.25531530996

## NB n2>n1 !
def fisher(n1,n2,chi2):
  fisher = ((chi2[n1]-chi2[n2])/(n2-n1))/(chi2[n2]/(nbins-n2))
  return fisher

def CL(fisher, n1):
  cl = 1.0 - ROOT.TMath.FDistI(fisher, 1.0, nbins - n2)
  return cl

fish_ = {}
cl_ = {}

print("")
print("NOMINAL")
print("Fisher\tCL")
for n1 in chi2.keys():
  n2 = n1+1
  if not (n2 in chi2.keys()): continue
  fish = fisher(n1,n2,chi2) 
  cl = CL(fish,n1)
  fish_[n1] = fish
  cl_[n1] = cl
  print("%d vs %d\t%f\t%f"%(n1,n2,fish,cl))


fishAlt_ = {}
clAlt_ = {}

print("")
print("ALTERNATIVE")
print("Fisher\tCL")
for n1 in chi2Alt.keys():
  n2 = n1+1
  if not (n2 in chi2Alt.keys()): continue
  fish = fisher(n1,n2,chi2Alt) 
  cl = CL(fish,n1)
  fishAlt_[n1] = fish
  clAlt_[n1] = cl
  print("%d vs %d\t%f\t%f"%(n1,n2,fish,cl))


lt_chi2 =    (chi2[3],chi2[4],chi2[5],chi2[6],chi2[7]) 
lt_chi2Alt = (chi2Alt[3],chi2Alt[4],chi2Alt[5],chi2Alt[6],chi2Alt[7]) 
lt_f_CL =    (fish_[3],cl_[3],fish_[4],cl_[4],fish_[5],cl_[5],fish_[6],cl_[6]) 
lt_f_CLAlt =    (fishAlt_[3],clAlt_[3],fishAlt_[4],clAlt_[4],fishAlt_[5],clAlt_[5],fishAlt_[6],clAlt_[6]) 

lt_all = lt_chi2 + lt_chi2Alt + lt_f_CL + lt_f_CLAlt

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