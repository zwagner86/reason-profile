[@bs.module "@fortawesome/react-fontawesome"] external reactClass: ReasonReact.reactClass = "FontAwesomeIcon";

[@bs.obj]
external makeProps:
    (
        ~icon: array(string),
        ~id: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        ~size: string=?,
        ~fixedWidth: bool=?,
        unit
    ) => _ = "";

let make = (~icon, ~id=?, ~className=?, ~style=?, ~size=?, ~fixedWidth=?, children) =>
    ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props=makeProps(~icon=Array.of_list(icon), ~id?, ~className?, ~style?, ~size?, ~fixedWidth?, ()),
        children,
    );