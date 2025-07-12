const leftSide = document.getElementById("leftSide");
const rightSide = document.getElementById("rightSide");
const shuffleBtn = document.getElementById("shuffleBtn");

const rollNumbers = Array.from({ length: 48 }, (_, i) => i + 1);

function createBenches(side) {
  side.innerHTML = '';
  for (let i = 0; i < 8; i++) {
    const bench = document.createElement("div");
    bench.className = "bench";
    for (let j = 0; j < 3; j++) {
      const seat = document.createElement("div");
      seat.className = "seat";
      bench.appendChild(seat);
    }
    side.appendChild(bench);
  }
}

function fillBenches(side, seats) {
  const benches = side.querySelectorAll(".bench");
  for (let i = 0; i < 8; i++) {
    const bench = benches[i];
    const seatDivs = bench.querySelectorAll(".seat");
    for (let j = 0; j < 3; j++) {
      seatDivs[j].textContent = seats[i * 3 + j];
    }
  }
}

function getLastResetTime() {
  const now = new Date();
  const reset = new Date(now);
  reset.setHours(5, 0, 0, 0);
  if (now < reset) {
    reset.setDate(reset.getDate() - 1); // It's before 5 AM, go back one day
  }
  return reset;
}

function canShuffleToday() {
  const lastShuffle = localStorage.getItem("lastShuffle");
  if (!lastShuffle) return true;

  const lastShuffleTime = new Date(lastShuffle);
  const resetTime = getLastResetTime();

  return lastShuffleTime < resetTime; // Can shuffle only if last shuffle was before last 5 AM
}

function saveShuffle(shuffled) {
  localStorage.setItem("lastShuffle", new Date().toISOString());
  localStorage.setItem("shuffledSeats", JSON.stringify(shuffled));
}

function loadShuffle() {
  const saved = localStorage.getItem("shuffledSeats");
  if (!saved) return null;
  try {
    const parsed = JSON.parse(saved);
    return parsed.length === 48 ? parsed : null;
  } catch {
    return null;
  }
}

function shuffleSeatsHandler() {
  if (!canShuffleToday()) {
    alert("You’ve already shuffled today. Try again after 5 AM tomorrow.");
    return;
  }

  let shuffled = [...rollNumbers];
  let valid = false;

  while (!valid) {
    shuffled = [...rollNumbers].sort(() => Math.random() - 0.5);

    const left = shuffled.slice(0, 24);
    const right = shuffled.slice(24);

    const leftIndex = left.indexOf(6);
    const rightIndex = right.indexOf(6);

    if (
      (leftIndex !== -1 && Math.floor(leftIndex / 3) < 4) ||
      (rightIndex !== -1 && Math.floor(rightIndex / 3) < 4)
    ) {
      valid = true;
    }
  }

  const left = shuffled.slice(0, 24);
  const right = shuffled.slice(24);

  fillBenches(leftSide, left);
  fillBenches(rightSide, right);

  saveShuffle(shuffled);
  shuffleBtn.disabled = true;
  shuffleBtn.textContent = "Shuffled (Wait until 5 AM)";
}

window.onload = () => {
  createBenches(leftSide);
  createBenches(rightSide);

  const shuffledToday = !canShuffleToday(); // if already shuffled today

  if (shuffledToday) {
    const loaded = loadShuffle();
    if (loaded) {
      const left = loaded.slice(0, 24);
      const right = loaded.slice(24);
      fillBenches(leftSide, left);
      fillBenches(rightSide, right);
    } else {
      fillBenches(leftSide, rollNumbers.slice(0, 24));
      fillBenches(rightSide, rollNumbers.slice(24));
    }
    shuffleBtn.disabled = true;
    shuffleBtn.textContent = "Shuffled (Wait until 5 AM)";
  } else {
    // Not yet shuffled today
    fillBenches(leftSide, rollNumbers.slice(0, 24));
    fillBenches(rightSide, rollNumbers.slice(24));
    shuffleBtn.disabled = false;
    shuffleBtn.addEventListener("click", shuffleSeatsHandler);
  }
};
