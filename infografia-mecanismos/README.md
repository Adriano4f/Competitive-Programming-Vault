# Infografía: Máquinas, Mecanismos y Movimientos

Infografía autónoma (un solo `index.html` con CSS embebido, sin dependencias externas) para la clase **Mecanismos**.

## Cómo abrirla

Haz doble clic en `index.html` o arrástralo a cualquier navegador moderno (Chrome, Edge, Firefox). El póster tiene un ancho fijo de 1080 px.

## Exportar a PDF

1. Abre `index.html` en el navegador.
2. Pulsa `Ctrl+P` (o `Cmd+P` en macOS).
3. Destino: **Guardar como PDF**. Activa **Gráficos de fondo** para conservar los colores.

## Exportar a imagen (PNG)

Con Chrome instalado, desde la terminal:

```bash
google-chrome --headless --screenshot=infografia.png --window-size=1120,3000 index.html
```

Ajusta la altura (`3000`) si la imagen queda recortada. Alternativa: usa la extensión de captura de página completa de tu navegador o `Ctrl+Shift+P` → "Capture full size screenshot" en las DevTools de Chrome.
