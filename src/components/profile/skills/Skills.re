[%%raw "require('./Skills.css')"];

type skillItem = {
    name: string,
    logoName: string,
    star: bool
};

type skillData = {
    languages: list(skillItem),
    frameworks: list(skillItem),
    whatDescription: string
};

type skillDataJson = {
    data: skillData
};

type state = {
    languages: list(skillItem),
    frameworks: list(skillItem),
    whatDescription: string,
    isLoading: bool,
    hasErrored: bool
};

type action =
    | FetchSkills
    | UpdateSkills(skillDataJson)
    | FetchSkillsErrored;

module Decode = {
    let decodeSkill = json =>
        Json.Decode.{
            name: json |> field("name", string),
            logoName: json |> field("logoName", string),
            star: json |> field("star", bool)
        };

    let decodeSkills = json =>
        Json.Decode.{
            frameworks: json |> field("frameworks", list(decodeSkill)),
            languages: json |> field("languages", list(decodeSkill)),
            whatDescription: json |> field("whatDescription", string)
        };

    let decodeSkillsData = json =>
        Json.Decode.{
            data: json |> field("data", decodeSkills)
        };
};

let renderLoader = () =>
    <div className="Skills-loader-container">
        <div className="Skills-loader" />
    </div>;

let renderError = () =>
    <div className="Skills-section-error">
        <div className="Skills-section-error-icon">(ReasonReact.string("ER"))</div>
        (ReasonReact.string("Sorry! Something is wrong with my API!"))
    </div>;

let renderMain = (whatDescription, languages, frameworks) =>
    <div className="Skills-section-info">
        <div className="Skills-section-description">(ReasonReact.string(whatDescription))</div>
        <div className="Skills-languages">
            <div className="Skills-languages-description">(ReasonReact.string("Here are some languages I have experience with:"))</div>
            <div className="Skills-languages-list">
                (
                    languages
                    |> Array.of_list
                    |> Array.map(({name, logoName, star}) =>
                        <SkillTile
                            key=name
                            name
                            logo=logoName
                            star
                        />
                    )
                    |> ReasonReact.array
                )
            </div>
        </div>
        <div className="Skills-frameworks">
            <div className="Skills-frameworks-description">
                (ReasonReact.string("And here are some frameworks, libraries, and tools I've used:"))
            </div>
            <div className="Skills-frameworks-list">
                (
                    frameworks
                    |> Array.of_list
                    |> Array.map(({name, logoName, star}) =>
                        <SkillTile
                            key=name
                            name
                            logo=logoName
                            star
                        />
                    )
                    |> ReasonReact.array
                )
            </div>
        </div>
    </div>;

let component = ReasonReact.reducerComponent("Skills");

let make = (_children) => {
    ...component,
    initialState: () => {
        languages: [],
        frameworks: [],
        whatDescription: "",
        isLoading: true,
        hasErrored: false
    },
    reducer: (action, state) =>
        switch (action) {
            | FetchSkills =>
                ReasonReact.UpdateWithSideEffects(
                    {...state, isLoading: true, hasErrored: false},
                    (
                        self => {
                            Js.Promise.(
                                Fetch.fetch("https://www.zacharywagner.net/api/v1/skills")
                                |> then_(Fetch.Response.json)
                                |> then_(json =>
                                    json
                                    |> Decode.decodeSkillsData
                                    |> (skills => self.send(UpdateSkills(skills)))
                                    |> resolve
                                )
                                |> catch(_err =>
                                    Js.Promise.resolve(self.send(FetchSkillsErrored))
                                )
                                |> ignore
                            )
                        }
                    )
                )
            | UpdateSkills(skillDataJson) =>
                ReasonReact.Update({
                    isLoading: false,
                    hasErrored: false,
                    languages: skillDataJson.data.languages,
                    frameworks: skillDataJson.data.frameworks,
                    whatDescription: skillDataJson.data.whatDescription
                })
            | FetchSkillsErrored =>
                ReasonReact.Update({...state, isLoading: false, hasErrored: true})
        },
    didMount: self => self.send(FetchSkills),
    render: self => {
        let {
            isLoading,
            hasErrored,
            whatDescription,
            frameworks,
            languages
        } = self.state;

        let main =
            switch (isLoading, hasErrored) {
                | (true, false) => renderLoader()
                | (false, true) => renderError()
                | (false, false) => renderMain(whatDescription, languages, frameworks)
                | _ => (ReasonReact.null)
            };

        <div className="Skills">
            <div className="Skills-inner">
                <div className="Skills-section">
                    <div className="Skills-section-header">(ReasonReact.string("WHO?"))</div>
                    <div className="Skills-section-info">
                        <div className="Skills-section-description">
                            <span>(ReasonReact.string("Hey, what's up? My full name is "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("Zachary "))</span>
                            <span>(ReasonReact.string("but you can call me "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("Zach"))</span>
                            <span>(ReasonReact.string(". I am a "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("Software Engineer "))</span>
                            <span>(ReasonReact.string("with "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("full-stack experience"))</span>
                            <span>(ReasonReact.string(", but a passion for working in the "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("front-end"))</span>
                            <span>(ReasonReact.string(". For example, I made this page so I could play around with "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("ReasonML"))</span>
                            <span>(ReasonReact.string(" and "))</span>
                            <span className="Skills-section-highlight">(ReasonReact.string("ReasonReact"))</span>
                            <span>(ReasonReact.string("!"))</span>
                        </div>
                    </div>
                    <div className="Skills-section-info">
                        <div className="Skills-section-description">
                            (ReasonReact.string("I also made versions of this page using React and Vue!  You can get to those using the menu.  They really aren't any different.  I just wanted to be able to compare the frameworks firsthand."))
                        </div>
                    </div>
                </div>
                <div className="Skills-section">
                    <div className="Skills-section-header">(ReasonReact.string("WHAT?"))</div>
                    main
                </div>
                <div className="Skills-section">
                    <div className="Skills-section-header">(ReasonReact.string("WHERE?"))</div>
                    <div className="Skills-section-info">
                        <div>
                            <a
                                className="Skills-section-employer-link"
                                href="http://rippleshot.com"
                                target="_blank"
                                rel="noopener noreferrer"
                            >
                                (ReasonReact.string("Rippleshot"))
                            </a>
                        </div>
                        <div>(ReasonReact.string("September 2019 - Present"))</div>
                        <div>(ReasonReact.string("Chicago, IL"))</div>
                        <div>(ReasonReact.string("Front End Engineer"))</div>
                    </div>
                    <div className="Skills-section-info">
                        <div>
                            <a
                                className="Skills-section-employer-link"
                                href="https://www.spothero.com"
                                target="_blank"
                                rel="noopener noreferrer"
                            >
                                (ReasonReact.string("SpotHero"))
                            </a>
                        </div>
                        <div>(ReasonReact.string("December 2016 - August 2019"))</div>
                        <div>(ReasonReact.string("Chicago, IL"))</div>
                        <div>(ReasonReact.string("Front End Engineer"))</div>
                    </div>
                    <div className="Skills-section-info">
                        <div className="Skills-section-employer-link">

                            <a
                                className="Skills-section-employer-link"
                                href="https://www.slalom.com/locations/chicago"
                                target="_blank"
                                rel="noopener noreferrer"
                            >
                                (ReasonReact.string("Slalom Consulting"))
                            </a>
                        </div>
                        <div>(ReasonReact.string("December 2012 - December 2016"))</div>
                        <div>(ReasonReact.string("Chicago, IL"))</div>
                        <div>(ReasonReact.string("Senior Software Engineer"))</div>
                    </div>
                </div>
            </div>
        </div>
    },
};
