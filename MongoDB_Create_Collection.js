const mongoose = require('mongoose');
mongoose.connect('mongodb+srv://zhaiz:15711120452Tom@sit314.s98fj1x.mongodb.net/?retryWrites=true&w=majority');

const Led = require('./models/project');

const leddata = {
  id: 2,
  name: "LED1_status",
  address: "221 Burwood Hwy, Burwood VIC 3125",
  time: Date.now(),
  LED: 0
}

const low = 0;
const high = 1;
reading = Math.floor(Math.random() * (high - low) + low);
leddata.LED = reading;
const jsonString = JSON.stringify(leddata);
console.log(jsonString);

const newLED = new Led(leddata);
newLED.save().then(doc => {
  console.log(doc);
}).then(() => {
  mongoose.connection.close();
});
