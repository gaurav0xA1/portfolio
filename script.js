// Wait for DOM to be fully loaded
document.addEventListener('DOMContentLoaded', function() {
    // Back to Top Button logic
    const backToTopBtn = document.getElementById('backToTop');
    window.addEventListener('scroll', function() {
        if (window.scrollY > 200) {
            backToTopBtn.style.display = 'block';
        } else {
            backToTopBtn.style.display = 'none';
        }
    });
    backToTopBtn.addEventListener('click', function() {
        window.scrollTo({ top: 0, behavior: 'smooth' });
    });
    // HERO TYPEWRITER EFFECT
    const roles = [
        { text: 'Anup Bhattarai', prefix: "I'm\u00A0" },
        { text: 'Web Developer', prefix: 'A\u00A0' },
        { text: 'CS Student', prefix: 'A\u00A0' },
        { text: 'Tech Enthusiast', prefix: 'A\u00A0' },
        { text: 'Problem Solver', prefix: 'A\u00A0' }
    ];
    let roleIndex = 0;
    let charIndex = 0;
    let typing = true;
    const typewriterText = document.getElementById('typewriter-text');
    const typewriterPrefix = document.getElementById('typewriter-prefix');
    const TYPING_SPEED = 90;
    const ERASING_SPEED = 40;
    const DELAY_BETWEEN = 1200;

    function typeRole() {
        if (!typewriterText || !typewriterPrefix) return;
        const { text, prefix } = roles[roleIndex];
        if (typing) {
            if (charIndex === 0) {
                typewriterPrefix.textContent = prefix;
            }
            if (charIndex < text.length) {
                typewriterText.textContent += text[charIndex];
                charIndex++;
                setTimeout(typeRole, TYPING_SPEED);
            } else {
                typing = false;
                setTimeout(typeRole, DELAY_BETWEEN);
            }
        } else {
            if (charIndex > 0) {
                typewriterText.textContent = text.substring(0, charIndex - 1);
                charIndex--;
                setTimeout(typeRole, ERASING_SPEED);
            } else {
                typing = true;
                roleIndex = (roleIndex + 1) % roles.length;
                setTimeout(typeRole, 400);
            }
        }
    }
    if (typewriterText && typewriterPrefix) {
        typewriterText.textContent = '';
        typewriterPrefix.textContent = '';
        setTimeout(typeRole, 600);
    }
        // Expand contact form on button click
        const expandBtn = document.getElementById('expand-contact-form');
        const contactForm = document.getElementById('inline-contact-form');
        if (expandBtn && contactForm) {
            expandBtn.addEventListener('click', function() {
                contactForm.style.display = contactForm.style.display === 'none' ? 'block' : 'none';
                expandBtn.style.display = 'none';
            });
            // Optional: handle form submission (basic, no backend)
            contactForm.addEventListener('submit', function(e) {
                e.preventDefault();
                // Collect form data
                const name = document.getElementById('name').value;
                const email = document.getElementById('email').value;
                const company = document.getElementById('company').value;
                const message = document.getElementById('message').value;

                // Google Forms endpoint and entry keys
                const formUrl = 'https://docs.google.com/forms/d/e/1FAIpQLScWqzC4wLI4EtLkOMu7-M2_rbR23MH0YUS-vqfC9c283OvIQw/formResponse';
                const formData = new FormData();
                formData.append('entry.623687160', name);
                formData.append('entry.1948934396', email);
                formData.append('entry.1874032524', company);
                formData.append('entry.794171252', message);

                fetch(formUrl, {
                    method: 'POST',
                    mode: 'no-cors',
                    body: formData
                }).finally(() => {
                    contactForm.innerHTML = '<div class="contact-thankyou">Thank you for reaching out! I will get back to you soon.</div>';
                });
            });
        }
    // Mobile menu toggle
    const menuButton = document.querySelector('.menu-button');
    const navLinks = document.querySelector('.nav-links');

    if (menuButton && navLinks) {
        menuButton.addEventListener('click', function() {
            navLinks.classList.toggle('active');
        });

        // Close menu when clicking outside
        document.addEventListener('click', function(e) {
            if (!menuButton.contains(e.target) && !navLinks.contains(e.target)) {
                navLinks.classList.remove('active');
            }
        });
    }

    // Smooth scroll for navigation links
    const navLinksElements = document.querySelectorAll('.nav-link');
    
    navLinksElements.forEach(function(link) {
        link.addEventListener('click', function(e) {
            e.preventDefault();
            
            const targetId = this.getAttribute('href');
            const targetSection = document.querySelector(targetId);
            
            if (targetSection) {
                // Close mobile menu if open
                if (navLinks) {
                    navLinks.classList.remove('active');
                }
                
                // Smooth scroll to target with offset for fixed navbar
                const navbarHeight = document.querySelector('.navbar').offsetHeight;
                const targetPosition = targetSection.offsetTop - navbarHeight;
                
                window.scrollTo({
                    top: targetPosition,
                    behavior: 'smooth'
                });
            }
        });
    });
});

