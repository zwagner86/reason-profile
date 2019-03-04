// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var SkillTile$ReasonProfile = require("./SkillTile.bs.js");

require('./Skills.css')
;

function decodeSkill(json) {
  return /* record */[
          /* name */Json_decode.field("name", Json_decode.string, json),
          /* logoName */Json_decode.field("logoName", Json_decode.string, json),
          /* star */Json_decode.field("star", Json_decode.bool, json)
        ];
}

function decodeSkills(json) {
  return /* record */[
          /* languages */Json_decode.field("languages", (function (param) {
                  return Json_decode.list(decodeSkill, param);
                }), json),
          /* frameworks */Json_decode.field("frameworks", (function (param) {
                  return Json_decode.list(decodeSkill, param);
                }), json),
          /* whatDescription */Json_decode.field("whatDescription", Json_decode.string, json)
        ];
}

function decodeSkillsData(json) {
  return /* record */[/* data */Json_decode.field("data", decodeSkills, json)];
}

var Decode = /* module */[
  /* decodeSkill */decodeSkill,
  /* decodeSkills */decodeSkills,
  /* decodeSkillsData */decodeSkillsData
];

function renderLoader(param) {
  return React.createElement("div", {
              className: "Skills-loader-container"
            }, React.createElement("div", {
                  className: "Skills-loader"
                }));
}

function renderError(param) {
  return React.createElement("div", {
              className: "Skills-section-error"
            }, React.createElement("div", {
                  className: "Skills-section-error-icon"
                }, "ER"), "Sorry! Something is wrong with my API!");
}

function renderMain(whatDescription, languages, frameworks) {
  return React.createElement("div", {
              className: "Skills-section-info"
            }, React.createElement("div", {
                  className: "Skills-section-description"
                }, whatDescription), React.createElement("div", {
                  className: "Skills-languages"
                }, React.createElement("div", {
                      className: "Skills-languages-description"
                    }, "Here are some languages I have experience with:"), React.createElement("div", {
                      className: "Skills-languages-list"
                    }, $$Array.map((function (param) {
                            var name = param[/* name */0];
                            return ReasonReact.element(name, undefined, SkillTile$ReasonProfile.make(name, param[/* logoName */1], param[/* star */2], /* array */[]));
                          }), $$Array.of_list(languages)))), React.createElement("div", {
                  className: "Skills-frameworks"
                }, React.createElement("div", {
                      className: "Skills-frameworks-description"
                    }, "And here are some frameworks, libraries, and tools I've used:"), React.createElement("div", {
                      className: "Skills-frameworks-list"
                    }, $$Array.map((function (param) {
                            var name = param[/* name */0];
                            return ReasonReact.element(name, undefined, SkillTile$ReasonProfile.make(name, param[/* logoName */1], param[/* star */2], /* array */[]));
                          }), $$Array.of_list(frameworks)))));
}

var component = ReasonReact.reducerComponent("Skills");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              return Curry._1(self[/* send */3], /* FetchSkills */0);
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1];
              var hasErrored = match[/* hasErrored */4];
              var main = match[/* isLoading */3] ? (
                  hasErrored ? null : renderLoader(/* () */0)
                ) : (
                  hasErrored ? renderError(/* () */0) : renderMain(match[/* whatDescription */2], match[/* languages */0], match[/* frameworks */1])
                );
              return React.createElement("div", {
                          className: "Skills"
                        }, React.createElement("div", {
                              className: "Skills-inner"
                            }, React.createElement("div", {
                                  className: "Skills-section"
                                }, React.createElement("div", {
                                      className: "Skills-section-header"
                                    }, "WHO?"), React.createElement("div", {
                                      className: "Skills-section-info"
                                    }, React.createElement("div", {
                                          className: "Skills-section-description"
                                        }, React.createElement("span", undefined, "Hey, what's up? My full name is "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "Zachary "), React.createElement("span", undefined, "but you can call me "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "Zach"), React.createElement("span", undefined, ". I am a "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "Software Engineer "), React.createElement("span", undefined, "with "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "full-stack experience"), React.createElement("span", undefined, ", but a passion for working in the "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "front-end"), React.createElement("span", undefined, ". For example, I made this page so I could play around with "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "ReasonML"), React.createElement("span", undefined, " and "), React.createElement("span", {
                                              className: "Skills-section-highlight"
                                            }, "ReasonReact"), React.createElement("span", undefined, "!"))), React.createElement("div", {
                                      className: "Skills-section-info"
                                    }, React.createElement("div", {
                                          className: "Skills-section-description"
                                        }, "I also made versions of this page using React and Vue!  You can get to those using the menu.  They really aren't any different.  I just wanted to be able to compare the frameworks firsthand."))), React.createElement("div", {
                                  className: "Skills-section"
                                }, React.createElement("div", {
                                      className: "Skills-section-header"
                                    }, "WHAT?"), main), React.createElement("div", {
                                  className: "Skills-section"
                                }, React.createElement("div", {
                                      className: "Skills-section-header"
                                    }, "WHERE?"), React.createElement("div", {
                                      className: "Skills-section-info"
                                    }, React.createElement("div", undefined, React.createElement("a", {
                                              className: "Skills-section-employer-link",
                                              href: "https://www.spothero.com",
                                              rel: "noopener noreferrer",
                                              target: "_blank"
                                            }, "SpotHero")), React.createElement("div", undefined, "December 2016 - Present"), React.createElement("div", undefined, "Chicago, IL"), React.createElement("div", undefined, "Front End Engineer")), React.createElement("div", {
                                      className: "Skills-section-info"
                                    }, React.createElement("div", {
                                          className: "Skills-section-employer-link"
                                        }, React.createElement("a", {
                                              className: "Skills-section-employer-link",
                                              href: "https://www.slalom.com/locations/chicago",
                                              rel: "noopener noreferrer",
                                              target: "_blank"
                                            }, "Slalom Consulting")), React.createElement("div", undefined, "December 2012 - December 2016"), React.createElement("div", undefined, "Chicago, IL"), React.createElement("div", undefined, "Senior Software Engineer")))));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* languages : [] */0,
                      /* frameworks : [] */0,
                      /* whatDescription */"",
                      /* isLoading */true,
                      /* hasErrored */false
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                if (action !== 0) {
                  return /* Update */Block.__(0, [/* record */[
                              /* languages */state[/* languages */0],
                              /* frameworks */state[/* frameworks */1],
                              /* whatDescription */state[/* whatDescription */2],
                              /* isLoading */false,
                              /* hasErrored */true
                            ]]);
                } else {
                  return /* UpdateWithSideEffects */Block.__(2, [
                            /* record */[
                              /* languages */state[/* languages */0],
                              /* frameworks */state[/* frameworks */1],
                              /* whatDescription */state[/* whatDescription */2],
                              /* isLoading */true,
                              /* hasErrored */false
                            ],
                            (function (self) {
                                fetch("https://www.zacharywagner.net/api/v1/skills").then((function (prim) {
                                            return prim.json();
                                          })).then((function (json) {
                                          var skills = decodeSkillsData(json);
                                          return Promise.resolve(Curry._1(self[/* send */3], /* UpdateSkills */[skills]));
                                        })).catch((function (_err) {
                                        return Promise.resolve(Curry._1(self[/* send */3], /* FetchSkillsErrored */1));
                                      }));
                                return /* () */0;
                              })
                          ]);
                }
              } else {
                var skillDataJson = action[0];
                return /* Update */Block.__(0, [/* record */[
                            /* languages */skillDataJson[/* data */0][/* languages */0],
                            /* frameworks */skillDataJson[/* data */0][/* frameworks */1],
                            /* whatDescription */skillDataJson[/* data */0][/* whatDescription */2],
                            /* isLoading */false,
                            /* hasErrored */false
                          ]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.Decode = Decode;
exports.renderLoader = renderLoader;
exports.renderError = renderError;
exports.renderMain = renderMain;
exports.component = component;
exports.make = make;
/*  Not a pure module */
