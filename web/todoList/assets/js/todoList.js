//complete todos by clicking
$("ul").on("click", "li", function(){
	$(this).toggleClass("completed");
});

//delete todos by clicking icons
$("ul").on("click", "li>span", function(event){
	$(this).parent().fadeOut(500, function(){
		$(this).remove();
	});
	event.stopPropagation();
});


//toggle text input by clicking icon
$("i.flaticon-square").click(function(){
	$("input[type='text']").fadeToggle();
});

//add todos by entering text inputs
$("input[type='text']").keypress(function(event){
	if(event.which===13){
		//get new todo text from input
		var entry=$(this).val();
		//set text input with empty string
		$(this).val("");
		//create a new li and add to ul
		$("ul").append("<li><span><i class='flaticon-delete'></i></span> "+entry+"</li>");
	}
});