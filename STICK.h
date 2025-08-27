import random

class PickUpSticksGame:
    def __init__(self):
        self.sticks = 27
        self.current_player = 'human'

    def play_game(self):
        print("Welcome to Pick‑Up Sticks!")
        print("There are 27 sticks. Take 1, 2, or 3 per turn. Avoid taking the last stick.")

        while self.sticks > 0:
            print(f"\nSticks remaining: {self.sticks}")
            if self.current_player == 'human':
                self.human_turn()
            else:
                self.computer_turn()
            self.current_player = 'computer' if self.current_player == 'human' else 'human'

        loser = 'Human' if self.current_player == 'human' else 'Computer'
        print(f"\nGame over! {loser} took the last stick and loses.")

    def human_turn(self):
        choice = None
        while choice not in (1, 2, 3):
            try:
                choice = int(input("Your turn — how many sticks? (1‑3): "))
            except ValueError:
                choice = 0
            if choice not in (1, 2, 3):
                print("Invalid. Pick 1, 2, or 3.")
        self.sticks -= choice

    def computer_turn(self):
        choice = random.randint(1, min(3, self.sticks))
        print(f"Computer picks up {choice} stick{'s' if choice > 1 else ''}.")
        self.sticks -= choice

if __name__ == "__main__":
    game = PickUpSticksGame()
    game.play_game()
