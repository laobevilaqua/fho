

$(document).ready(function(){
    const OPERATIONS_ENUM = {
        SUM: 1,
        SUBTRACTION: 2,
        MULTIPLICATION: 3,
        DIVISION: 4
    }

    changeExercise = (exercise) => {
        $('#firstExercise').css({ display: 'none' });
        $('#secondExercise').css({ display: 'none' });
        $('#thirdExercise').css({ display: 'none' });
        $('#fourthExercise').css({ display: 'none' });
    
        switch (exercise) {
            case 1:
                $('#firstExercise').css({ display: 'block' });
                break;
            case 2:
                $('#secondExercise').css({ display: 'block' });
                break;
            case 3:
                $('#thirdExercise').css({ display: 'block' });
                break;
            case 4:
                $('#fourthExercise').css({ display: 'flex' });
                break;
        }
    }

    $('.nav-link').click(function(){
        changeExercise(+this.value);
        $('.nav-link').removeClass('active');
        $(this).addClass('active');     
    });

    changeExercise(1);

    //#region Exercise 1
    changeBackgroundParagraphEven = () => {
        $('p:even').css({ background: 'yellow' });
    }

    $("#btnMagico").click(() => {       
        $('#firstParagraph').text('Aula 2 de Programação para Web 2');
        
        $('#secondParagraph').css({ fontSize: '40px' });
        
        $('#thirdParagraph').css({ color: 'blue' });
        
        $('#fourthParagraph').css({ textAlign: 'center' });
        
        $('#fiveParagraph').css({ fontSize: '10px', color: 'green' });
        
        $('#sixParagraph').text('JavaScript não é Java');
        $('#sixParagraph').css({ color: 'red', fontWeight: 'bold' });

        changeBackgroundParagraphEven();
    }); 
    //#endregion
    
    //#region Exercise 2
    $("#toSwitchOffImgLamp").click(() => {
        $('#imgLamp').attr('src', '/assets/lamp_off.gif');
    });

    $("#turnOnImgLamp").click(() => {
        $('#imgLamp').attr('src', '/assets/lamp_on.gif');
    });
    //#endregion
    
    //#region Exercise 3
    $("#btnLamp").click(() => {
        if($('#btnLamp').text() === 'Ligar') {
            $('#imgLamp2').attr('src', '/assets/lamp_on.gif');
            $('#btnLamp').text('Desligar');
        } else {
            $('#imgLamp2').attr('src', '/assets/lamp_off.gif');
            $('#btnLamp').text('Ligar');
        }
    });
    // //#endregion
    
    // //#region Exercise 4
    $("#calculate").click(() => {
        var value1 = +$('#value1').val();
        var value2 = +$('#value2').val();
        var operation = +$('#operationsMath').val();
        var error = $('#error');
    
        if(!value1 || !value2 || !operation) {
            error.css({ display: 'block'});
            return;
        }
        error.css({ display: 'none'});
    
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
    
    });
    //#endregion
});




