var numColors=6;
var colors=[];
var pickedColor;
var h1=document.getElementsByTagName("h1")[0];
var colorDisplay=document.getElementById("colorDisplay");
var messageDisplay=document.getElementById("message");
var resetButton=document.getElementById("reset");
var modeButtons=document.getElementsByClassName("mode"), numMode=modeButtons.length;
var squares=document.getElementsByClassName("square"), size=squares.length;

initalize();

function initalize(){
	reset();
	setResetButton();
	setModeButtons();
	setSquares();
}

function reset(){
	//reset h1 background color
	h1.style.background="steelblue";
	//reset button text
	resetButton.textContent="New Colors";
	//reset message text
	messageDisplay.textContent=null;
	//generate all new colors
	colors=generateColors(numColors);
	//pick a new random color from array
	pickedColor=pickColor();
	//change color display to match picked color
	colorDisplay.textContent=pickedColor;
	//change colors of squares
	for(var i=0; i<size; ++i){
		if(colors[i]){
			squares[i].style.background=colors[i];
			squares[i].style.display="block";
		}
		else{
			squares[i].style.display="none";
		}
	}
}

function setResetButton(){
	//add click event to reset button
	resetButton.addEventListener("click", function(){
		reset();
	});
}

function setModeButtons(){
	for(var i=0; i<numMode; ++i){
		//add click events to mode buttons
		modeButtons[i].addEventListener("click", function(){
			//remove selection from all modes
			for(var j=0; j<numMode; ++j){
				modeButtons[j].classList.remove("selected");
			}
			//add selection to clicked button
			this.classList.add("selected");
			//set number of colors
			this.textContent==="Easy"? numColors=3: numColors=6;
			//reset conditions
			reset();
		});
	}
}

function setSquares(){
	for(var i=0; i<size; ++i){
		//add click events to squares
		squares[i].addEventListener("click", function(){
			//compare color to picked color
			if(this.style.background!==pickedColor){
				this.style.background="#232323";
				messageDisplay.textContent="Try Again";
			}
			else{
				h1.style.background=pickedColor;
				changeColors();
				resetButton.textContent="Play Again?";
				messageDisplay.textContent="Correct!";
			}
		});
	}
}

function changeColors(){
	for(var i=0; i<size; ++i){
		//change square colors to match picked color
		squares[i].style.background=pickedColor;
	}
}

function pickColor(){
	var random=Math.floor(Math.random()*colors.length);
	return colors[random];
}

function generateColors(num){
	//make an array
	var array=[];
	//add num random colors to array
	for(var i=0; i<num; ++i){
		//push random color into array
		array.push(randomColor());
	}
	//return array
	return array;
}

function randomColor(){
	//pick a red from 0-255
	var r=Math.ceil(Math.random()*255),
	//pick a green from 0-255
	g=Math.floor(Math.random()*255),
	//pick a blue from 0-255
	b=Math.floor(Math.random()*255);
	return "rgb("+r+", "+g+", "+b+")";
}

//Previous functions
/*
easyButton.addEventListener("click", function(){
	hardButton.classList.remove("selected");
	easyButton.classList.add("selected");
	//reset h1 background color
	h1.style.background="steelblue"
	//reset button text
	resetButton.textContent="New Colors";
	//reset message text
	messageDisplay.textContent=null;

	numColors=3;
	colors=generateColors(numColors);
	pickedColor=pickColor();
	colorDisplay.textContent=pickedColor;
	for(var i=0; i<size; ++i){
		if(colors[i]){
			squares[i].style.background=colors[i];
		}
		else{
			squares[i].style.display="none";
		}
	}
});

hardButton.addEventListener("click", function(){
	easyButton.classList.remove("selected");
	hardButton.classList.add("selected");
	//reset h1 background color
	h1.style.background="steelblue"
	//reset button text
	resetButton.textContent="New Colors";
	//reset message text
	messageDisplay.textContent=null;

	numColors=6;
	colors=generateColors(numColors);
	pickedColor=pickColor();
	colorDisplay.textContent=pickedColor;
	for(var i=0; i<size; ++i){
		squares[i].style.background=colors[i];
		squares[i].style.display="block";
	}
});
*/