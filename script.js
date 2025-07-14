// Mobile menu toggle
const menuButton = document.querySelector('.menu-button');
const navLinks = document.querySelector('.nav-links');
const toggleBtn = document.getElementById('toggleProjectsBtn');
const projectCards = document.querySelectorAll('.projects a.card');

menuButton.addEventListener('click', () => {
    navLinks.classList.toggle('active');
});

toggleBtn.addEventListener('click', () => {
  if (toggleBtn.textContent === 'Show More') {
    // Show all projects
    projectCards.forEach(card => {
      card.style.display = 'block';
    });
    toggleBtn.textContent = 'Show Less';
  } else {
    // Show only first 3 projects, hide rest
    projectCards.forEach((card, index) => {
      card.style.display = index < 3 ? 'block' : 'none';
    });
    toggleBtn.textContent = 'Show More';
  }
});

