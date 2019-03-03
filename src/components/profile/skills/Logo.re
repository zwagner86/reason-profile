let angularLogo : string = [%raw "require('./assets/logos/angular.png')"];
let bootstrapLogo : string = [%raw "require('./assets/logos/bootstrap.png')"];
let cplusplusLogo : string = [%raw "require('./assets/logos/cplusplus.png')"];
let cssLogo : string = [%raw "require('./assets/logos/css.png')"];
let expressLogo : string = [%raw "require('./assets/logos/express.png')"];
let gruntLogo : string = [%raw "require('./assets/logos/grunt.png')"];
let gulpLogo : string = [%raw "require('./assets/logos/gulp.png')"];
let html5Logo : string = [%raw "require('./assets/logos/html5.png')"];
let jasmineLogo : string = [%raw "require('./assets/logos/jasmine.png')"];
let javaLogo : string = [%raw "require('./assets/logos/java.png')"];
let javascriptLogo : string = [%raw "require('./assets/logos/javascript.png')"];
let jqueryLogo : string = [%raw "require('./assets/logos/jquery.png')"];
let karmaLogo : string = [%raw "require('./assets/logos/karma.png')"];
let lessLogo : string = [%raw "require('./assets/logos/less.png')"];
let nodeLogo : string = [%raw "require('./assets/logos/node.png')"];
let pugLogo : string = [%raw "require('./assets/logos/pug.png')"];
let pythonLogo : string = [%raw "require('./assets/logos/python.png')"];
let reactLogo : string = [%raw "require('./assets/logos/react.png')"];
let reduxLogo : string = [%raw "require('./assets/logos/redux.png')"];
let sassLogo : string = [%raw "require('./assets/logos/sass.png')"];
let springLogo : string = [%raw "require('./assets/logos/spring.png')"];
let typescriptLogo : string = [%raw "require('./assets/logos/typescript.png')"];
let vueLogo : string = [%raw "require('./assets/logos/vue.png')"];
let webpackLogo : string = [%raw "require('./assets/logos/webpack.png')"];

let get = logoName => {
    switch (logoName) {
        | "angularLogo" => angularLogo
        | "bootstrapLogo" => bootstrapLogo
        | "cplusplusLogo" => cplusplusLogo
        | "cssLogo" => cssLogo
        | "expressLogo" => expressLogo
        | "gruntLogo" => gruntLogo
        | "gulpLogo" => gulpLogo
        | "html5Logo" => html5Logo
        | "jasmineLogo" => jasmineLogo
        | "javaLogo" => javaLogo
        | "javascriptLogo" => javascriptLogo
        | "jqueryLogo" => jqueryLogo
        | "karmaLogo" => karmaLogo
        | "lessLogo" => lessLogo
        | "nodeLogo" => nodeLogo
        | "pugLogo" => pugLogo
        | "pythonLogo" => pythonLogo
        | "reactLogo" => reactLogo
        | "reduxLogo" => reduxLogo
        | "sassLogo" => sassLogo
        | "springLogo" => springLogo
        | "typescriptLogo" => typescriptLogo
        | "vueLogo" => vueLogo
        | "webpackLogo" => webpackLogo
        | _ => ""
    }
};
