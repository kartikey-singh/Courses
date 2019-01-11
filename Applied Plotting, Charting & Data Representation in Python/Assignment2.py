import matplotlib.pyplot as plt
import pandas as pd
import datetime as dt
df = pd.read_csv('fb441e62df2d58994928907a91895ec62c2c42e6cd075c2700843b89.csv')
for i in range(2004,2017):
    df = df[df['Date'] != str(i)+"-02-29"]
df['Data_Value'] = df['Data_Value']/10
def date_maker(x):
    add = x['Date']
    add = add[4:]
    s = str(pd.to_datetime('2014' + add) - pd.to_datetime('2014-01-01'))
    return s[:-14]
df['abs_date'] = df.apply(date_maker,axis = 1)
df['Date'] = pd.to_datetime(df['Date'])
df['Day'] = df['Date'].dt.day
df['Month'] = df['Date'].dt.month
df_late = df[df['Date'].dt.year > 2014] 
df = df[df['Date'].dt.year <= 2014] 
df_min = df[df['Element'] == "TMIN"]
df_min = (df_min.groupby(['Month','Day']).min())
df_max = df[df['Element'] == "TMAX"]
df_max = (df_max.groupby(['Month','Day']).max())
df_min_l = df_late[df_late['Element'] == "TMIN"]
df_min_l = (df_min_l.groupby(['Month','Day']).min())
df_max_l = df_late[df_late['Element'] == "TMAX"]
df_max_l = (df_max_l.groupby(['Month','Day']).max())
df_max_l = df_max_l[df_max_l['Data_Value'] > df_max['Data_Value']]
df_min_l = df_min_l[df_min_l['Data_Value'] < df_min['Data_Value']]
index_max_l = df_max_l['abs_date'].tolist()
index_min_l = df_min_l['abs_date'].tolist()
index_min = df_min['abs_date'].tolist()
index_max = df_max['abs_date'].tolist()
min_temp = df_min['Data_Value'].tolist()
max_temp = df_max['Data_Value'].tolist()
min_temp_l = df_min_l['Data_Value'].tolist()
max_temp_l = df_max_l['Data_Value'].tolist()

plt.plot(index_min,min_temp,'-g',index_max,max_temp,'r',linewidth=0.8)
plt.scatter(index_min_l,min_temp_l,marker='+',linewidth=1.7,c='blue')
plt.scatter(index_max_l,max_temp_l,marker='x',linewidth=1.7,c='black')
plt.title('Max and Min temperature variations from 2005-2014 compared with that of 2015')
plt.legend(['Min (2005-14)', 'Max (2005-14)', 'Min (2015)','Max (2015)'])
plt.tick_params(top='off', bottom='off', left='off', right='off', labelleft='on', labelbottom='on')
for spine in plt.gca().spines.values():
    spine.set_visible(False)
plt.ylabel('Celsius')
plt.gca().fill_between(range(len(min_temp)), 
                       min_temp,max_temp,
                       facecolor='pink', 
                       alpha=0.25)
plt.xticks([31,59,90,120,151,181,212,243,273,304,334,365], ["Jan", "Feb", "Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"])
plt.show()
plt.savefig('assign2.png')

