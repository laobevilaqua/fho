var self = this;

var firstParagraphElement;
var secondParagraphElement;
var thirdParagraphElement;
var fourthParagraphElement;
var fiveParagraphElement;
var sixParagraphElement;

var imgLamp;
var imgLamp2;
var btnLamp;

var firstExercise;
var secondExercise;
var thirdExercise;
var fourthExercise;

var OPERATIONS_ENUM = {
    SUM: 1,
    SUBTRACTION: 2,
    MULTIPLICATION: 3,
    DIVISION: 4
}

onloadWindow = () => {
    firstParagraphElement = document.getElementById("firstParagraph");
    secondParagraphElement = document.getElementById("secondParagraph");
    thirdParagraphElement = document.getElementById("thirdParagraph");
    fourthParagraphElement = document.getElementById("fourthParagraph");
    fiveParagraphElement = document.getElementById("fiveParagraph");
    sixParagraphElement = document.getElementById("sixParagraph");

    firstExercise = document.getElementById('firstExercise');
    secondExercise = document.getElementById('secondExercise');
    thirdExercise = document.getElementById('thirdExercise');
    fourthExercise = document.getElementById('fourthExercise');

    imgLamp = document.getElementById('imgLamp');
    imgLamp2 = document.getElementById('imgLamp2');
    btnLamp = document.getElementById('btnLamp');

    changeExercise(1);
}

changeExercise = (exercise) => {
    firstExercise.style.display = 'none';
    secondExercise.style.display = 'none';
    thirdExercise.style.display = 'none';
    fourthExercise.style.display = 'none';

    switch (exercise) {
        case 1:
            firstExercise.style.display = 'block';
            break;
        case 2:
            secondExercise.style.display = 'block';
            break;
        case 3:
            thirdExercise.style.display = 'block';
            break;
        case 4:
            fourthExercise.style.display = 'flex';
            break;
    }

    var buttonsMenu = document.getElementsByClassName('nav-link');

    for (let i = 0; i < buttonsMenu.length; i++) {
        buttonsMenu[i].classList.remove('active');
    }
    buttonsMenu[exercise - 1].classList.add('active');
}

//#region Exercise 1
changeBackground = () => {
    var allParagraphs = document.getElementsByTagName('p');
    
    for (let i = 0; i < allParagraphs.length; i++) {
        if (!( (i +1 ) % 2 )) {
            var paragraph = allParagraphs.item(i);
            paragraph.style.background = 'yellow';
        }
    }
}

onClickButton = () => {
    firstParagraphElement.innerHTML = 'Aula 2 de Programação para Web 2';
    
    secondParagraphElement.style.fontSize = '40px';
    
    thirdParagraphElement.style.color = 'blue';
    
    fourthParagraphElement.style.textAlign = 'center';

    fiveParagraphElement.style.fontSize = '10px';
    fiveParagraphElement.style.color = 'green';
    
    sixParagraphElement.style.innerHTML = 'JavaScript não é Java';
    sixParagraphElement.style.fontSize = 'red';
    sixParagraphElement.style.fontWeight = 'bolder';

    changeBackground();
}

//#endregion

//#region Exercise 2
toSwitchOffImgLamp = () => {
    imgLamp.setAttribute('src', '/assets/lamp_off.gif');
}

turnOnImgLamp = () => {
    imgLamp.setAttribute('src', '/assets/lamp_on.gif');
}
//#endregion

//#region Exercise 3
toogleImgLamp = () => {
    if(btnLamp.innerHTML === 'Ligar') {
        imgLamp2.setAttribute('src', '/assets/lamp_on.gif');
        btnLamp.innerHTML = 'Desligar';
    } else {
        imgLamp2.setAttribute('src', '/assets/lamp_off.gif');
        btnLamp.innerHTML = 'Ligar';
    }
}

//#endregion

//#region Exercise 4
calculate = () => {
    var value1 = +document.getElementById('value1').value;
    var value2 = +document.getElementById('value2').value;
    var operation = +document.getElementById('operationsMath').value;
    var error = document.getElementById('error');

    if(!value1 || !value2 || !operation) {
        error.style.display = 'block';
        return;
    }

    error.style.display = 'none';

    switch (operation) {
        case OPERATIONS_ENUM.SUM:
            alert(value1 + value2);
            break;
        case OPERATIONS_ENUM.SUBTRACTION:
                alert(value1 - value2);
            break;
        case OPERATIONS_ENUM.MULTIPLICATION:
                alert(value1 * value2);
            break;
        case OPERATIONS_ENUM.DIVISION:
                alert(value1 / value2);
            break;
    }
}

//#endregion