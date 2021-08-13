var result;
const formValor = document.forms.carrinho;

const PRECOS = {
    BEBIDAS: {
        COCA: 6.00,
        AGUA: 3.50,
        SUCO: 2.50,
        GUARANA: 4.50,
        CAFE: 1.50
    },
    SALGADOS: {
        COXINHA: 2.50,
        EMPADA: 2.50,
        ESFIRRA: 2.50,
        CROQUETE: 2.50,
        PAO_DE_QUEIJO: 3.50,
        QUIBE: 2.50
    }
}

function calcularSemDesconto() {
    var salg = +formValor.selectSalgado.value;
    var beb = +formValor.selectBebida.value;

    switch (salg) {
        case 1:
            result = PRECOS.SALGADOS.COXINHA;
            break;

        case 2:
            result = PRECOS.SALGADOS.CROQUETE;
            break;

        case 3:
            result = PRECOS.SALGADOS.EMPADA;
            break;

        case 4:
            result = PRECOS.SALGADOS.ESFIRRA;
            break;

        case 5:
            result = PRECOS.SALGADOS.PAO_DE_QUEIJO;
            break;

        case 6:
            result = PRECOS.SALGADOS.QUIBE;
            break;
    }

    switch (beb) {
        case 1:
            result += PRECOS.BEBIDAS.AGUA;
            break;

        case 2:
            result += PRECOS.BEBIDAS.CAFE;
            break;

        case 3:
            result += PRECOS.BEBIDAS.COCA;
            break;

        case 4:
            result += PRECOS.BEBIDAS.GUARANA;
            break;

        case 5:
            result += PRECOS.BEBIDAS.SUCO;
            break;
    }
}

function desconto() {
    var desconto = +formValor.desconto.value;
    if (desconto) {
        result = result - (result * 0.05);
    }
}

function embalagi() {
    var embalagem = +formValor.viagem.checked;
    if (embalagem) {
        result += 1.50;
    }
}

document.getElementById('buttonCarrinho').addEventListener('click', function(e){
    e.preventDefault();
    calcular();
    
    document.getElementById('totalCompra').innerText = result.toLocaleString('pt-br', {
        style: 'currency',
        currency: 'BRL'
    });
    document.getElementById('modal-container').classList.add("open");
});


document.getElementById('btnCloseModal').addEventListener('click', function(e){
    e.preventDefault();
    document.getElementById('modal-container').classList.remove("open");
});

function calcular(e) {
    calcularSemDesconto();
    desconto();
    embalagi();
  
    // alert(result.toLocaleString('pt-br', {
    //     style: 'currency',
    //     currency: 'BRL'
    // }));
}