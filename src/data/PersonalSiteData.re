
type skillItem = Js.t({
    .
    name: string,
    logoName: string,
    star: bool
});

type skillItemArray = array(skillItem);

type companyItem = Js.t({
    .
    name: string,
    location: string,
    fromDate: string,
    toDate: string,
    title: string,
    url: string
});

type companyItemArray = array(companyItem);

[@bs.module "personal-site-data"] [@bs.val] external languages : skillItemArray = "languages";
[@bs.module "personal-site-data"] [@bs.val] external frameworks : skillItemArray = "frameworks";
[@bs.module "personal-site-data"] [@bs.val] external companies : companyItemArray = "companies";
[@bs.module "personal-site-data"] [@bs.val] external whatSectionDescription : string = "whatSectionDescription";
[@bs.module "personal-site-data"] [@bs.val] external profileImage : string = "profileImage";
