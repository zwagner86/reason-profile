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

module API = {
    open Json.Decode;
    module Promise = Js.Promise;

    let decodeSkills =
        field(
            "data",
            list(
                optional(json =>
                    {
                        frameworks: field("frameworks", list(skillItem), json),
                        languages: field("languages", list(skillItem), json),
                        whatDescription: field("whatDescription", string, json),
                    }
                ),
            ),
        );

    let getSkills = () =>
        /*
        * This is similar to `open Json.Decode`, it allows the Promise functions
        * to be available within the parentheses
        */
        Promise.(
            Fetch.fetch("https://www.zacharywagner.net/api/v1/skills")
            |> Promise.then_(Fetch.Response.json)
            |> Promise.then_(json => decodeSkills(json) |> resolve)
            |> Promise.then_(skills =>
                skills
                |> List.filter(optionalItem =>
                    switch (optionalItem) {
                        | Some(_) => true
                        | None => false
                    }
                )
                |> List.map(item =>
                    switch (item) {
                        | Some(item) => item
                    }
                )
                |> resolve
            )
            |> Promise.catch_(_err => resolve(self.send(FetchSkillsErrored)))
        );
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

                        }
                    )
                )
            | UpdateSkills(skillData) =>
                ReasonReact.Update({
                    isLoading: false,
                    hasErrored: false,
                    languages: skillData.languages,
                    frameworks: skillData.frameworks,
                    whatDescription: skillData.whatDescription
                })
            | FetchSkillsErrored =>
                ReasonReact.Update({...state, isLoading: false, hasErrored: true})
        },
    render: self => {
        let menuClass = "Menu";

        <div className=menuClass>
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