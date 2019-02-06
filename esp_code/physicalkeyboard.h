const char Physical[] PROGMEM = R"=====(
<html>
  <head>
    <meta charset="UTF-8">
        <title>Teclado Automático</title>
        <style>
        .enlaceboton {
            font-family: Verdana, Geneva, Tahoma, sans-serif;
            font-size: 12pt;
            font-weight: bold;
            padding: 4px;
            background-color: darkgrey;
            color:black;
            text-decoration: none;
        }
        .enlaceboton:link,
        .enlaceboton:visited {
            border-top: 1px solid #cccccc;
            border-bottom: 2px solid #666666;
            border-left: 1px solid #cccccc;
            border-right: 2px solid #666666;
        }
        .enlaceboton:hover {
            border-top: 1px solid #666666;
            border-bottom: 2px solid #cccccc;
            border-left: 1px solid #666666;
            border-right: 2px solid #cccccc;  
        }
        </style>
        <script>
        function mobileCheck() { 
            var mainId = document.getElementById("main");
                if( navigator.userAgent.match(/Android/i)
                || navigator.userAgent.match(/webOS/i)
                || navigator.userAgent.match(/iPhone/i)
                || navigator.userAgent.match(/iPad/i)
                || navigator.userAgent.match(/iPod/i)
                || navigator.userAgent.match(/BlackBerry/i)
                || navigator.userAgent.match(/Windows Phone/i)
                ){
                    mainId.innerHTML = '<textarea id="output" col="100" row="30" ></textarea>';
                    }
                    else {
          mainId.innerHTML = '<div id="output"></textarea></div>';
                    }
                    }
        </script>
  </head>
<body onload="mobileCheck()">
    <a class="enlaceboton" name="F1" alt="F1" href="#" onclick='input_form("rawpress ","KEY_F1")'>F1</a>
    <a Class="enlaceboton" name="F2" alt="F2" href="#" onclick='input_form("rawpress ","KEY_F2")'>F2</a>
    <a Class="enlaceboton" name="F3" alt="F3" href="#" onclick='input_form("rawpress ","KEY_F3")'>F3</a>
    <a Class="enlaceboton" name="F4" alt="F4" href="#" onclick='input_form("rawpress ","KEY_F4")'>F4</a>
    <a Class="enlaceboton" name="F5" alt="F5" href="#" onclick='input_form("rawpress ","KEY_F5")'>F5</a>
    <a Class="enlaceboton" name="F6" alt="F6" href="#" onclick='input_form("rawpress ","KEY_F6")'>F6</a>
    <a Class="enlaceboton" name="F7" alt="F7" href="#" onclick='input_form("rawpress ","KEY_F7")'>F7</a>
    <a Class="enlaceboton" name="F8" alt="F8" href="#" onclick='input_form("rawpress ","KEY_F8")'>F8</a>
    <a Class="enlaceboton" name="F9" alt="F9" href="#" onclick='input_form("rawpress ","KEY_F9")'>F9</a>
    <a Class="enlaceboton" name="F10" alt="F10" href="#" onclick='input_form("rawpress ","KEY_F10")'>F10</a>
    <a Class="enlaceboton" name="F11" alt="F11" href="#" onclick='input_form("rawpress ","KEY_F11")'>F11</a>
    <a Class="enlaceboton" name="F12" alt="F12" href="#" onclick='input_form("rawpress ","KEY_F12")'>F12</a>
    <a Class="enlaceboton" name="runwin" alt="runwin" href="#" onclick='input_form("runwin","")'>Runwin</a>
    <a Class="enlaceboton" name="rungnome" alt="rungnome" href="#" onclick='input_form("rungnome","")'>Rungnome</a>
    <a Class="enlaceboton" name="winmac" alt="winmac" href="#" onclick='input_form("winmac","")'>Winmac</a>
    <a Class="enlaceboton" name="release" alt="release" href="#" onclick='input_form("release","")'>Release</a>

    <p> Teclea para ver el resultado</p>
  <!--<textarea id="output1" col="100" row="30" ></textarea> -->
  <div id="main"></div>
<script>
    window.addEventListener("keydown",function(event){
 
if( navigator.userAgent.match(/Android/i)
                || navigator.userAgent.match(/webOS/i)
                || navigator.userAgent.match(/iPhone/i)
                || navigator.userAgent.match(/iPad/i)
                || navigator.userAgent.match(/iPod/i)
                || navigator.userAgent.match(/BlackBerry/i)
                || navigator.userAgent.match(/Windows Phone/i)
                ){
  var PelementLegth = document.getElementById("output").value.length;
    
  setTimeout(function(){    
  var element = document.getElementById("output");
  var elementLegth = element.value.length; 
  let str2 = event.key;
  var InitElement = elementLegth + (PelementLegth - elementLegth); 
  if (parseInt(InitElement,10) > parseInt(elementLegth,10)){input_form("rawpress ","KEY_BACKSPACE");}
  else if (str2 == "Enter"){input_form("rawpress ","KEY_RETURN");}
  else {
   var str = element.value.substring(InitElement,elementLegth);
   input_form("print ",str);
   }
    
  },50);
      }else{
            var NspecialKey = true; 
            let str = event.key;
      if (str == "Backspace"){
        var removeCharacter = document.getElementById("output");
        removeCharacter.removeChild(removeCharacter.lastChild);
        input_form("rawpress ","KEY_BACKSPACE");
      }else{
      let el = document.createElement ("span");
      if (str == "CapsLock"){
                input_form("rawpress ","KEY_CAPS_LOCK");
                NspecialKey= false;}
      var SpecialCharacter = ["Meta","Control","AltGraph","ContextMenu","Shift","End","Tab",
                                    "Escape","Alt","Home","PageDown","PageUp","Delete","Insert","ArrowRight","ArrowLeft","ArrowUp","ArrowDown"];
      let SpecialCharacter_Value ={
                Meta:"KEY_HOME",Control:"KEY_RIGHT_CTRL",Shift:"KEY_LEFT_SHIFT",
                End:"KEY_END",Tab:"KEY_TAB",Escape:"KEY_ESC",Alt:"KEY_LEFT_ALT",
                Home:"KEY_HOME",PageDown:"KEY_PAGE_DOWN",PageUP:"KEY_PAGE_UP",Delete:"KEY_DELETE",
                Insert:"KEY_INSERT",ArrowLeft:"KEY_LEFT_ARROW",ArrowRight:"KEY_RIGHT_ARROW",ArrowUp:"KEY_UP_ARROW",ArrowDown:"KEY_DOWN_ARROW"}
           
      if (SpecialCharacter.indexOf(str) >=  0){
        input_form("press ",SpecialCharacter_Value[str]);
        NspecialKey= false;}
      if (str == "Enter"){ str = "<br/>";input_form("rawpress ","KEY_RETURN");}
                        
      el.innerHTML = str;
      
      if (NspecialKey){
                document.getElementById("output").appendChild(el);
          input_form("print ",str);
      } 
      } 
      }  
        },true);

function input_form(action,value){
 document.getElementById("Sinput").setAttribute("value",value);
 var textarea;
 textarea = document.getElementById("tecla");
 textarea.innerHTML = action + value;
 document.forms["myForm"].submit();
}
        </script>
<form hidden="1" name="myForm" action="/runlivepayload" method="post" id="sendForm" target="iframe">
    <input type="radio" name="livepayloadpresent" value="1" hidden="1" checked="checked">
    <textarea id="tecla" style ="width: 100%;" form="sendForm" rows="1" cols="100" name="livepayload" hidden="1">Press:200</textarea>
    <input id="Sinput" type="submit" form="sendForm" value="">
</form>
<iframe style="visibility:hidden;"src="/runlivepayload" name="iframe"></iframe>
<hr>
<a href="/"><- BACK TO INDEX</a><br><br>
</body>
</html>
)=====";
