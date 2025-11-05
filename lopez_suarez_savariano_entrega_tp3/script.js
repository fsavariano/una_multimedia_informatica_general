function mostrar(id) {
  const aside = document.querySelector('aside');
  if (aside) {
    aside.style.display = 'none';
  }
  const secciones = document.querySelectorAll('.contenido');
  secciones.forEach(sec => {
    sec.style.display = 'none';
  });
  const seleccionada = document.getElementById(id);
  if (seleccionada) {
    seleccionada.style.display = 'block';
  }
}
function volver() {
  location.reload(); 
}
const form = document.getElementById('form-contacto');
const mensaje = document.getElementById('mensaje-enviado');

form.addEventListener('submit', function(event) {
  event.preventDefault();
  mensaje.textContent = '¡Enviado con éxito!'; // imprime el mensaje
  form.reset(); // limpia los campos
});