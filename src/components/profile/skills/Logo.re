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
        | "angular" => angularLogo
        | "bootstrap" => bootstrapLogo
        | "cplusplus" => cplusplusLogo
        | "css" => cssLogo
        | "express" => expressLogo
        | "grunt" => gruntLogo
        | "gulp" => gulpLogo
        | "html5" => html5Logo
        | "jasmine" => jasmineLogo
        | "java" => javaLogo
        | "javascript" => javascriptLogo
        | "jquery" => jqueryLogo
        | "karma" => karmaLogo
        | "less" => lessLogo
        | "node" => nodeLogo
        | "pug" => pugLogo
        | "python" => pythonLogo
        | "react" => reactLogo
        | "redux" => reduxLogo
        | "sass" => sassLogo
        | "spring" => springLogo
        | "typescript" => typescriptLogo
        | "vue" => vueLogo
        | "webpack" => webpackLogo
        | _ => ""
    }
};
