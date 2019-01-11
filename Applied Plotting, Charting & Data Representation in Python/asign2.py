import matplotlib.pyplot as plt
import pandas as pd
import datetime as dt
df = pd.read_csv('fb441e62df2d58994928907a91895ec62c2c42e6cd075c2700843b89.csv')
for i in range(2004,2017):
    df = df[df['Date'] != str(i)+"-02-29"]
# df[df['Date'] == "2008-02-29"]
# df_min["Date"].apply(lambda(x):x[:-2])
# df_min['Date'] = list(map(pd.to_datetime, df_min['Date']))
# df_max['Date'] = pd.to_datetime(df_max['Date'])
# df_max['Date'] = df_max['Date'].dt.year
def date_maker(x):
    add = x['Date']
    add = add[4:]
    s = str(pd.to_datetime('2014' + add) - pd.to_datetime('2014-01-01'))
    return s[:-14]
df['abs_date'] = df.apply(date_maker,axis = 1)
df['Date'] = pd.to_datetime(df['Date'])
df['Day'] = df['Date'].dt.day
df['Month'] = df['Date'].dt.month
# print(type(df['Day'][1]))
# df['abs_day'] = (str(2014) + str(df['Day']) + str(df['Month']))
# df['aa'] = str(df['Day'])
  
df_late = df[df['Date'].dt.year > 2014] 
df = df[df['Date'].dt.year <= 2014] 
df_min = df[df['Element'] == "TMIN"]
df_min = (df_min.groupby(['Month','Day']).min())
df_max = df[df['Element'] == "TMAX"]
df_max = (df_max.groupby(['Month','Day']).max())
# df_late
df_min_l = df_late[df_late['Element'] == "TMIN"]
df_min_l = (df_min_l.groupby(['Month','Day']).min())
df_max_l = df_late[df_late['Element'] == "TMAX"]
df_max_l = (df_max_l.groupby(['Month','Day']).max())
df_max_l = df_max_l[df_max_l['Data_Value'] > df_max['Data_Value']]
df_max_l
df_min_l = df_min_l[df_min_l['Data_Value'] < df_min['Data_Value']]
df_min_l
# df_max
# df_min
# print(pd.to_datetime(df_min['Date'][1]).year)
# min(df_min['Date'] == 
# min_dat = df_min['Date']
# min_date = list(map(pd.to_datetime, min_dat))
# max_date = df_max['Date'].tolist()
# df
index_max_l = df_max_l['abs_date'].tolist()
index_min_l = df_min_l['abs_date'].tolist()
index_min = df_min['abs_date'].tolist()
index_max = df_max['abs_date'].tolist()
min_temp = df_min['Data_Value'].tolist()
max_temp = df_max['Data_Value'].tolist()
min_temp_l = df_min_l['Data_Value'].tolist()
max_temp_l = df_max_l['Data_Value'].tolist()
# print(len(index_max_l))
# print(len(max_temp_l))
plt.plot(index_min,min_temp,'-o',index_max,max_temp,'-r',label='_nolegend_')
plt.scatter(index_min_l,min_temp_l,marker='+')
plt.scatter(index_max_l,max_temp_l,marker='x')
plt.xticks([31,59,90,120,151,181,212,243,273,304,334,365], ["Jan", "Feb", "Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"])
plt.show()