// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var FontAwesomeIcon$ReasonProfile = require("../../common/font-awesome/FontAwesomeIcon.bs.js");

require('./ProfileInfo.css')
;

var profilePic = (require('./assets/prof-pic.png'));

var component = ReasonReact.statelessComponent("ProfileInfo");

function make(_children) {
  return {
          debugName: component.debugName,
          reactClassInternal: component.reactClassInternal,
          handedOffState: component.handedOffState,
          willReceiveProps: component.willReceiveProps,
          didMount: component.didMount,
          didUpdate: component.didUpdate,
          willUnmount: component.willUnmount,
          willUpdate: component.willUpdate,
          shouldUpdate: component.shouldUpdate,
          render: (function (_self) {
              return React.createElement("div", {
                          className: "ProfileInfo"
                        }, React.createElement("div", {
                              className: "ProfileInfo-inner"
                            }, React.createElement("div", {
                                  className: "ProfileInfo-inner-cell"
                                }, React.createElement("div", {
                                      className: "ProfileInfo-pic-container"
                                    }, React.createElement("img", {
                                          className: "ProfileInfo-pic-img",
                                          alt: "Zachary Wagner Profile",
                                          src: profilePic
                                        })), React.createElement("h1", undefined, "Hey, I'm Zach,"), React.createElement("h4", {
                                      className: "ProfileInfo-h4"
                                    }, "a Front End Engineer"), React.createElement("h4", {
                                      className: "ProfileInfo-h4"
                                    }, "working in Chicago"), React.createElement("h4", {
                                      className: "ProfileInfo-h4"
                                    }, "for Rippleshot"), React.createElement("div", {
                                      className: "ProfileInfo-social-icons"
                                    }, React.createElement("a", {
                                          className: "ProfileInfo-social-link ProfileInfo-linkedin-link",
                                          href: "https://www.linkedin.com/in/zacharywagner",
                                          rel: "noopener noreferrer",
                                          target: "_blank"
                                        }, ReasonReact.element(undefined, undefined, FontAwesomeIcon$ReasonProfile.make(/* :: */[
                                                  "fab",
                                                  /* :: */[
                                                    "linkedin",
                                                    /* [] */0
                                                  ]
                                                ], undefined, "ProfileInfo-social-icon", undefined, "2x", true, /* array */[]))), React.createElement("a", {
                                          className: "ProfileInfo-social-link ProfileInfo-github-link",
                                          href: "https://github.com/zwagner86",
                                          rel: "noopener noreferrer",
                                          target: "_blank"
                                        }, ReasonReact.element(undefined, undefined, FontAwesomeIcon$ReasonProfile.make(/* :: */[
                                                  "fab",
                                                  /* :: */[
                                                    "github",
                                                    /* [] */0
                                                  ]
                                                ], undefined, "ProfileInfo-social-icon", undefined, "2x", true, /* array */[])))), React.createElement("div", {
                                      className: "ProfileInfo-resume-link"
                                    }, React.createElement("a", {
                                          className: "ProfileInfo-resume-btn",
                                          href: "https://www.zacharywagner.net/resume"
                                        }, "View Resume")))));
            }),
          initialState: component.initialState,
          retainedProps: component.retainedProps,
          reducer: component.reducer,
          jsElementWrapped: component.jsElementWrapped
        };
}

exports.profilePic = profilePic;
exports.component = component;
exports.make = make;
/*  Not a pure module */
