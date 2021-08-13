let form;
let idadeDeMaior = 18;

exibirMaioresDeIdade = () => {
    var idades = [
        +form.idade1.value,
        +form.idade2.value,
        +form.idade3.value,
        +form.idade4.value,
        +form.idade5.value,
    ];

    var maioresDeIdade = idades.filter((idade) => idade >= idadeDeMaior);
    var menoresDeIdade = idades.length - maioresDeIdade.length;

    alert(`
        ${maioresDeIdade.length} pessoas são maiores de idade(${idadeDeMaior})\n
        ${menoresDeIdade} são menores de idade
    `);
}

document.getElementById('btnValidarIdade').addEventListener('click', function(e){
    e.preventDefault();
    form = document.forms.form;

    exibirMaioresDeIdade();
});
