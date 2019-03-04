[%%raw "require('./main.css')"];

[%%raw "const faCore = require('@fortawesome/fontawesome-svg-core');"];
[%%raw "const faBrandIcons = require('@fortawesome/free-brands-svg-icons');"];
[%%raw "const faSolidIcons = require('@fortawesome/free-solid-svg-icons');"];
[%%raw "faCore.library.add(faBrandIcons.fab, faSolidIcons.faBars, faSolidIcons.faStar, faSolidIcons.faTimes);"];

ReactDOMRe.renderToElementWithId(<App />, "app");
