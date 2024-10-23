// Setup canvas
const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");
canvas.width = 400;
canvas.height = 600;

let player = { x: 180, y: 550, width: 40, height: 20, dx: 5 };
let objects = [];
let score = 0;
let gameOver = false;

// Keypress events
document.addEventListener("keydown", keyDownHandler);
document.addEventListener("keyup", keyUpHandler);

let rightPressed = false;
let leftPressed = false;

function keyDownHandler(e) {
    if (e.key === "Right" || e.key === "ArrowRight") {
        rightPressed = true;
    } else if (e.key === "Left" || e.key === "ArrowLeft") {
        leftPressed = true;
    }
}

function keyUpHandler(e) {
    if (e.key === "Right" || e.key === "ArrowRight") {
        rightPressed = false;
    } else if (e.key === "Left" || e.key === "ArrowLeft") {
        leftPressed = false;
    }
}

// Create random falling objects
function createObject() {
    const x = Math.random() * (canvas.width - 20);
    objects.push({ x: x, y: 0, width: 20, height: 20, dy: 2 });
}

// Move player
function movePlayer() {
    if (rightPressed && player.x < canvas.width - player.width) {
        player.x += player.dx;
    } else if (leftPressed && player.x > 0) {
        player.x -= player.dx;
    }
}

// Update game objects and check for collisions
function updateObjects() {
    for (let i = 0; i < objects.length; i++) {
        const obj = objects[i];
        obj.y += obj.dy;

        // Check if player catches the object
        if (obj.y + obj.height >= player.y && obj.y + obj.height <= player.y + player.height &&
            obj.x + obj.width > player.x && obj.x < player.x + player.width) {
            score++;
            objects.splice(i, 1);
        }

        // Check if object hits the ground
        if (obj.y + obj.height > canvas.height) {
            gameOver = true;
        }
    }
}

// Draw player
function drawPlayer() {
    ctx.fillStyle = "#ff0000";
    ctx.fillRect(player.x, player.y, player.width, player.height);
}

// Draw objects
function drawObjects() {
    ctx.fillStyle = "#0000ff";
    for (let obj of objects) {
        ctx.fillRect(obj.x, obj.y, obj.width, obj.height);
    }
}

// Draw score
function drawScore() {
    document.getElementById("score").innerText = "Score: " + score;
}

// Main game loop
function gameLoop() {
    if (gameOver) {
        alert("Game Over! Final Score: " + score);
        document.location.reload();
        return;
    }

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    movePlayer();
    drawPlayer();
    updateObjects();
    drawObjects();
    drawScore();

    requestAnimationFrame(gameLoop);
}

// Spawn new objects periodically
setInterval(createObject, 1000);

// Start the game loop
gameLoop();
