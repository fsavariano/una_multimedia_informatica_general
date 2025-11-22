document.addEventListener('DOMContentLoaded', () => {

  function mostrar(id) {
    const artistasContainer = document.querySelector('.artistas-container');
    if (artistasContainer) artistasContainer.style.display = 'none';
    const titulo = document.querySelector('.titulo');
    if (titulo) titulo.style.display = 'none';

    const secciones = document.querySelectorAll('.contenido');
    secciones.forEach(sec => sec.style.display = 'none');

    const seleccionada = document.getElementById(id);
    if (seleccionada) {
      seleccionada.style.display = 'block';
    }
  }
  window.mostrar = mostrar;

  function volver() {
    location.reload();
  }
  window.volver = volver;

  // --- ABRIR IMAGEN ---
  function abrirImagen(url) {
    const visor = document.getElementById("visor");
    const grande = document.getElementById("img-grande");

    grande.src = url;
    visor.style.display = "flex";
  }
  window.abrirImagen = abrirImagen;

  // --- CERRAR AL HACER CLICK FUERA ---
  const visor = document.getElementById("visor");
  if (visor) {
    visor.addEventListener("click", (e) => {
      if (e.target === visor) {
        visor.style.display = "none";
      }
    });
  }

  // formulario
  const form = document.getElementById('form-contacto');
  const mensaje = document.getElementById('mensaje-enviado');

  if (form) {
    form.addEventListener('submit', function (event) {
      event.preventDefault();
      if (mensaje) mensaje.textContent = '¡Enviado con éxito!';
      form.reset();
    });
  }

});