window.addEventListener("DOMContentLoaded", function(e){
    window.requestAnimationFrame(responsiveUpdates);
}, false);

window.addEventListener("scroll", function(event){
    scrollUpdates();
}, false);

var elementCreated = false;
var temp;

function scrollUpdates(){
    if(window.scrollY >= (document.getElementById("header").offsetTop)){
        document.getElementById("header").style.opacity = "0";
        document.getElementById("movingheader").classList.add("movingHeader");
    }
    else{
        document.getElementById("header").style.opacity = "1";
        document.getElementById("movingheader").classList.remove("movingHeader");
    }
}

function responsiveUpdates(){
    window.requestAnimationFrame(responsiveUpdates);
}