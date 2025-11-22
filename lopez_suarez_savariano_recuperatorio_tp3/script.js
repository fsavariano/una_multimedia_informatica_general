
document.addEventListener('DOMContentLoaded', () => {

  // datos de ejemplo (agrega o modifica objetos aquí)
  let imagenes = [
    { "url": "img/1.jpeg", "nombre": "Proyecto 01", "descripcion": "Este es el proyecto 01 fue desarrolla" },
    { "url": "img/2.jpeg", "nombre": "Proyecto 02", "descripcion": "dossss Este es el proyecto 02 fue desarrolla" },
    { "url": "img/3.jpeg", "nombre": "Proyecto 03", "descripcion": "tresssss Este es el proyecto 03 fue desarrolla" },
    { "url": "img/4.jpeg", "nombre": "Proyecto 04", "descripcion": "cuatrooooo Este es el proyecto 04 fue desarrolla" }
  ];

  // ---- mostrar / volver expuestos globalmente para los onclick del HTML ----
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
      // inicializamos cualquier carrusel dentro de la sección que acabamos de mostrar
      initCarruselEnSeccion(seleccionada);
    }
  }
  window.mostrar = mostrar; // para que onclick="mostrar('...')" funcione

  function volver() {
    location.reload();
  }
  window.volver = volver;

  // ---- formulario (seguro: sólo si existe) ----
  const form = document.getElementById('form-contacto');
  const mensaje = document.getElementById('mensaje-enviado');
  if (form) {
    form.addEventListener('submit', function(event) {
      event.preventDefault();
      if (mensaje) mensaje.textContent = '¡Enviado con éxito!';
      form.reset();
    });
  }

  // ---- inicializador de carrusel para UNA sección ----
  // recibe el elemento <section> que contiene .carrusel, .img-contenedor, .puntos, .atras, .adelante
  function initCarruselEnSeccion(section) {
    if (!section) return;

    const carrusel = section.querySelector('.carrusel');
    const imgCont = section.querySelector('.img-contenedor');
    const puntos = section.querySelector('.puntos');
    const btnA = section.querySelector('.atras');
    const btnD = section.querySelector('.adelante');

    if (!imgCont) return; // nada que inicializar

    // guardamos estado por sección para evitar interferencias
    // usamos un atributo data-actual en el contenedor para recordar el índice
    if (typeof imgCont.dataset.actual === 'undefined') imgCont.dataset.actual = '0';
    let actual = parseInt(imgCont.dataset.actual, 10) || 0;

    // función que renderiza la imagen + texto en este contenedor
    function render() {
      // si no hay imágenes definidas, dejamos el contenedor vacío
      if (!imagenes || imagenes.length === 0) {
        imgCont.innerHTML = '';
        if (puntos) puntos.innerHTML = '';
        return;
      }

      // clamp actual
      if (actual < 0) actual = imagenes.length - 1;
      if (actual >= imagenes.length) actual = 0;
      imgCont.innerHTML = `
        <img class="img" src="${imagenes[actual].url}" alt="${imagenes[actual].nombre}" loading="lazy">
        <div class="texto">
          <h3>${imagenes[actual].nombre}</h3>
          <p>${imagenes[actual].descripcion}</p>
        </div>
      `;
      imgCont.dataset.actual = String(actual);

      // puntos
      if (puntos) {
        puntos.innerHTML = '';
        for (let i = 0; i < imagenes.length; i++) {
          puntos.innerHTML += `<p class="${i === actual ? 'bold' : ''}">.</p>`;
        }
      }
    }

    // reasignamos los controladores de los botones (asignación directa evita duplicados)
    if (btnA) btnA.onclick = () => { actual = (actual - 1 + imagenes.length) % imagenes.length; render(); };
    if (btnD) btnD.onclick = () => { actual = (actual + 1) % imagenes.length; render(); };

    // render inicial
    render();
  }

  // ---- Si querés múltiples carruseles en la página que carguen en cuanto la página arranque,
  // podés inicializarlos todos así. Lo dejamos comentado porque en tu flujo los inicializamos
  // cuando se muestran las secciones. Si preferís inicializarlos desde start, descomenta:
  //
  // document.querySelectorAll('.contenido').forEach(sec => initCarruselEnSeccion(sec));
  //

  // FIN DOMContentLoaded
});
