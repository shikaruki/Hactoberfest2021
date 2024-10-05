#Name : Pranav Patne
#Problem Statement : Coin change

def coinChange(self, coins: List[int], amount: int) -> int:
        new_coins = sorted(coins)
        dp = [amount for _ in range(amount+1)]
        dp[0] = 0
        #dp[11]=5 means 5 coins will get 11 
        for each_amo in range(1,amount+1):
            for coin in new_coins:
                if coin <= each_amo:
                    dp[each_amo] = min(dp[each_amo], 1+dp[each_amo-coin])
                else:
                    break
        return dp[amount] if dp[amount]<=amount else -1
