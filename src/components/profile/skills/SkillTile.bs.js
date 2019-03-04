// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Logo$ReasonProfile = require("./Logo.bs.js");
var FontAwesomeIcon$ReasonProfile = require("../../common/font-awesome/FontAwesomeIcon.bs.js");

require('./SkillTile.css')
;

var component = ReasonReact.statelessComponent("SkillTile");

function make(name, logo, star, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", {
                          className: "SkillTile"
                        }, React.createElement("div", {
                              className: "SkillTile-label"
                            }, React.createElement("div", {
                                  className: "SkillTile-text"
                                }, name + " ", star ? ReasonReact.element(undefined, undefined, FontAwesomeIcon$ReasonProfile.make(/* :: */[
                                            "fas",
                                            /* :: */[
                                              "star",
                                              /* [] */0
                                            ]
                                          ], undefined, "SkillTile-icon-star", undefined, undefined, undefined, /* array */[])) : null)), React.createElement("div", {
                              className: "SkillTile-image-block"
                            }, React.createElement("div", {
                                  className: "SkillTile-image-cell"
                                }, React.createElement("img", {
                                      className: "SkillTile-image",
                                      alt: name,
                                      src: Logo$ReasonProfile.get(logo)
                                    }))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/*  Not a pure module */
