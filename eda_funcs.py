def missingDataSummary(df1):

    nevents = len(df1.index)

    import numpy as np
    import pandas as pd
    import statsmodels.stats.proportion as ssp
	

    CP = lambda num, denum: list(ssp.proportion_confint(num, denum, alpha=0.05,
                                                        method='beta'))  # Clopper-Pearson interval based on Beta distribution

    s1 = df1.isna().apply(np.sum, axis=1).value_counts()  # pandas.Series
    s1 = s1.sort_index()
    d1 = s1.to_frame(name='miss rate, counts')  # convert pandas.Series to pandas DataFrame
    d1['miss rate, %'] = d1.apply(lambda x: x[0] / nevents * 100, axis=1)
    d1['tmp'] = d1.apply(lambda x: CP(x[0], nevents), axis=1)
    d1[['err. low, %', 'err. up, %']] = pd.DataFrame(d1.tmp.values.tolist()) * 100
    del d1['tmp']
    d1 = d1.round(decimals=1)

    print(d1)
    return d1;


