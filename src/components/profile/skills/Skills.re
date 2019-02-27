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
    | UpdateSkills(skillData)
    | FetchSkillsErrored;

let component = ReasonReact.reducerComponent("Skills");

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
        Js.log(self.state);

        <div className="Menu">
            <div className="Menu-links">
                <a
                    href="https://www.zacharywagner.net"
                    className="Menu-link"
                >
                    (ReasonReact.string("Home"))
                </a>
                <a
                    href="https://www.zacharywagner.net/resume"
                    className="Menu-link"
                >
                    (ReasonReact.string("Resume"))
                </a>
                <div className="Menu-link-divider-block">
                    <div className="Menu-link-divider">
                        <span>(ReasonReact.string("Other Versions"))</span>
                    </div>
                </div>
                <a
                    href="https://www.zacharywagner.net"
                    className="Menu-link"
                >
                    (ReasonReact.string("React"))
                </a>
                <a
                    href="https://vue.zacharywagner.net"
                    className="Menu-link"
                >
                    (ReasonReact.string("Vue"))
                </a>
            </div>
        </div>
    },
};