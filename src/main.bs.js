// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var App$ReasonProfile = require("./App.bs.js");

require('./main.css')
;

const faCore = require('@fortawesome/fontawesome-svg-core');
;

const faBrandIcons = require('@fortawesome/free-brands-svg-icons');
;

const faSolidIcons = require('@fortawesome/free-solid-svg-icons');
;

faCore.library.add(faBrandIcons.fab, faSolidIcons.faBars, faSolidIcons.faStar, faSolidIcons.faTimes);
;

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, App$ReasonProfile.make(/* array */[])), "app");

/*  Not a pure module */
