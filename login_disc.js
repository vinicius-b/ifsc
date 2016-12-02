   (function(){
           var httpRequest;
       var nome = document.getElementById("nome");
           var senha = document.getElementById("senha");
           var button =document.getElementById("login-button");
           button.addEventListener("click", efetuaLogin);
           nome.addEventListener('keyup', validaEnterkey);
           senha.addEventListener('keyup', validaEnterkey);
   
 
          function validaEnterkey(e){
            if(e.keyCode == 13) efetuaLogin();
          }
  
         function efetuaLogin() {
           var data = {
		    "disciplinas":
		    [
			{
			    "codigo": "DES29001" 
			},
			{
			    "codigo": "CAL29001" 
			},
			{
			    "codigo": "ELI29001" 
			}
		    ]
		}
            makeRequest('https://200.135.37.74/js/horariodisciplina', data);
            clearInputs();
          };
  
        function makeRequest(url, data) {
          if (window.XMLHttpRequest) { // Mozilla, Safari, ...
             httpRequest = new XMLHttpRequest();
          }
          httpRequest.onreadystatechange = alertContents;
          httpRequest.open('POST', url);
          httpRequest.setRequestHeader('Content-Type', 'application/json');
          httpRequest.send(JSON.stringify(data));
        }
  
        function clearInputs(){
          nome.value = "";
          senha.value = "";
        }
        function alertContents() {
          if (httpRequest.readyState === 4) {
            if (httpRequest.status === 200) {
  				data_recv = httpRequest.responseText;
                var json_res = JSON.stringify(data_recv);
                alert(json_res);

            }else{
	         alert(httpRequest.responsetext);
            }
          }
        }
        })();
  
