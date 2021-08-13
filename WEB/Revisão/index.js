let form;
let media = 0.0;
const SITUACAO = {
    APROVADO: 'Aprovado', 
    REPROVADO_POR_NOTA: 'Reprovado por Nota',
    REPROVADO_POR_FALTA: 'Reprovado por Falta',
    RE: 'RE'
};

calcularMedia = () => {
    media = (+form.nota1.value + 2*+form.nota2.value) / 3;
}

exibirSituacao = () => {
    situacao = SITUACAO.REPROVADO_POR_FALTA;

    if (form.presenca.value < 75) {
        alert(situacao);
        return;
    }
    if (media >= 5) {
        situacao = SITUACAO.APROVADO;
    } else if(media >= 3 && media < 5) {
        situacao = SITUACAO.RE;
    } else if(media < 3) {
        situacao = SITUACAO.REPROVADO_POR_NOTA;
    }

    alert(situacao);
}

document.getElementById('btnCalcMedia').addEventListener('click', function(e){
    e.preventDefault();
    form = document.forms.form;

    calcularMedia();
    exibirSituacao();
});
