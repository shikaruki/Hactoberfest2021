import time
from plyer import notification

while True:
    notification.notify(
        title="**Please Drink Water Now!!",
        message="Drinking Water Helps Maintain the Balance of Body Fluids. So please drink at least 4 liters of water everyday!",
        timeout=10

    )
    time.sleep(5)
