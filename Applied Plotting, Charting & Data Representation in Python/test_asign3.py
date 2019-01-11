import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import mpl_toolkits.axes_grid1.inset_locator as mpl_il

plt.figure()
data = np.random.rand(10)
plt.plot(data)

def onclick(event):
    plt.clf()
    plt.plot(data)
    plt.set_title('Event at pixels {},{} \nand data {},{}'.format(event.x, event.y, event.xdata, event.ydata))

# tell mpl_connect we want to pass a 'button_press_event' into onclick when the event is detected

# plt.show()
plt.gcf().canvas.mpl_connect('button_press_event', onclick)	
plt.show()