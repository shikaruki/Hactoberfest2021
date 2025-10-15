import math
import random

def canon_game():
    print("Welcome to the Canon Game!")

    # Set up the target
    target_distance = random.randint(50, 150)
    print(f"Your target is at {target_distance} meters away.")

    # Gravity
    g = 9.8  # m/s^2

    tries = 5
    for attempt in range(1, tries + 1):
        print(f"\nAttempt {attempt} of {tries}")
        angle = float(input("Enter the canon angle in degrees (e.g., 45): "))
        velocity = float(input("Enter the initial velocity in m/s (e.g., 30): "))
        
        # Calculate distance
        angle_rad = math.radians(angle)
        shot_distance = (velocity ** 2) * math.sin(2 * angle_rad) / g
        print(f"Your shot traveled {shot_distance:.2f} meters.")

        # Check if hit
        if abs(shot_distance - target_distance) <= 5:
            print("Congratulations! You hit the target!")
            break
        elif shot_distance > target_distance:
            print("You overshot the target.")
        else:
            print("You fell short of the target.")
    else:
        print("Game over! Better luck next time.")

canon_game()
