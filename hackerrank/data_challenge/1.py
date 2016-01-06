import scipy.stats as st

z_score = st.norm.ppf(0.9)
ans = z_score*200.00+2000.00
print ("%.2f"%ans)
