import turtle

wn = turtle.Screen()
wn.title("Pong by Shivam")
wn.bgcolor("black")
wn.setup(width=800, height=500)
wn.tracer(0)

# Score
score_a = 0
score_b = 0

# Paddle A
paddle_a = turtle.Turtle()                          # This makes an object in paddle_a.
paddle_a.speed(0)
paddle_a.shape("square")
paddle_a.shapesize(stretch_wid=6, stretch_len=1)
paddle_a.color("blue")
paddle_a.penup()
paddle_a.goto(-350, 0)

# Paddle B
paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape("square")
paddle_b.shapesize(stretch_wid=6, stretch_len=1)
paddle_b.color("red")
paddle_b.penup()
paddle_b.goto(350, 0)

# Ball
ball = turtle.Turtle()
ball.speed(0)
ball.shape("circle")
ball.color("yellow")
ball.penup()
ball.goto(0, 0)
ball.dx = 0.34                                         # dx means delta/change X-cordinate.
ball.dy = 0.34

# Pen
pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 210)
pen.write("Player A: 0  Player B: 0", align="center", font=("Courier", 15, "bold"))

# Function
def paddle_a_up():
    if paddle_a.ycor() > 160: exit()
    y = paddle_a.ycor()                             # This gives the Y-cordinate of paddle_a object to y.
    y += 20                                         # This increase the value of paddle_a's Y-cordinate.
    paddle_a.sety(y)                                # sety() is puting the new updated value of Y-cordinate to y.

def paddle_a_down():
    if paddle_a.ycor() < -160:
        exit()
    y = paddle_a.ycor()
    y -= 20 
    paddle_a.sety(y)

def paddle_b_up():
    if paddle_b.ycor() > 160:
        exit()
    y = paddle_b.ycor()
    y += 20
    paddle_b.sety(y)

def paddle_b_down():
    if paddle_b.ycor() < -160:
        exit()
    y = paddle_b.ycor()
    y -= 20
    paddle_b.sety(y)

# Keyboard binding
wn.listen()                                         # Here our window(wn) wait to listen the keypress.
wn.onkeypress(paddle_a_up, "w")                     # If the key is w then because of onkeypress() it run paddle_a_up function. 
wn.onkeypress(paddle_a_down, "s")
wn.onkeypress(paddle_b_up, "Up")                    # Up is for up arrow key.
wn.onkeypress(paddle_b_down, "Down")                # Down is for down arrow key.

# Main game loop
while True:
    wn.update()

    # Move the Ball
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    # Border Checking
    """
    As line-6 total height=500 and the ball is at the center of the screen so Y-cordinate is set to +250 at top
    and -250 at down as the ball size is 20px so from (0,0) it is +10 and -10 and that's how it's go.
    """
    if ball.ycor() > 240:
        ball.sety(240)
        ball.dy *= -1

    if ball.ycor() < -240:
        ball.sety(-240)
        ball.dy *= -1
    
    """
    As line-6 total width=800 and the ball is at the center of the screen so Y-cordinate is set to +400 at top
    and -400 at down as the ball size is 20px so from (0,0) it is +10 and -10 and that's how it's go.
    """
    if  ball.xcor() > 390:
        ball.goto(0, 0)
        ball.dx *= -1
        score_a += 1
        pen.clear()
        if score_a > score_b:
            pen.color("blue")
        pen.write("Player A: {}  Player B: {}".format(score_a, score_b), align="center", font=("Courier", 15, "bold"))

    if ball.xcor() < -390:
        ball.goto(0, 0)
        ball.dx *= -1
        score_b += 1
        pen.clear()
        if score_b > score_a:
            pen.color("red")
        pen.write("Player A: {}  Player B: {}".format(score_a, score_b), align="center", font=("Courier", 15, "bold"))

    
    if (ball.xcor() > 340 and ball.xcor() < 350) and (ball.ycor() < (paddle_b.ycor()+60) and ball.ycor() > (paddle_b.ycor()-60)):
        ball.setx(340)
        ball.dx *= -1

    if (ball.xcor() < -340 and ball.xcor() > -350) and (ball.ycor() < (paddle_a.ycor()+60) and ball.ycor() > (paddle_a.ycor()-60)):
        ball.setx(-340)
        ball.dx *= -1
