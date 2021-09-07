const url = "https://api.adviceslip.com/advice";
const settings = {
    method: 'GET'
};
fetch(url, settings)
.then(response => response.json())
.then(data => {
    console.log(data);
    let id = data.slip.id;
	let advice = data.slip.advice;
	document.body.innerHTML = "<h2>Consumindo o método GET da API-REST adviceslip</h2><h3>Advice number " + id + ": " + advice + "</h3>"
})
.catch(err => console.log(err));

//Use this website to render: https://jsfiddle.net/