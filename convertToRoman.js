function convertToRoman(num) {
  let numArr = Array.from(String(num), String);
  let roman = "";
  let key = ["","M","MM","MMM", "", "", "", "","", "",
         "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
         "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
         "","I","II","III","IV","V","VI","VII","VIII","IX"]

  let i = 4;
  while(i--) {
    roman = (key[+numArr.pop() + (i * 10)] || "") + roman;
  }
 return roman;
}
