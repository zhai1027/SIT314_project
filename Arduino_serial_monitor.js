//同步Arduino串口监视器生成数据至CMD终端
var SerialPort = require('serialport').SerialPort;
//{}内全部数据可以从设备管理器找到
const Arduino_port = 'COM9';

let serialPort = new SerialPort(
    {
        path: Arduino_port,
        baudRate: 9600,
        dataBits: 8,
        parity: 'none',
        stopBits: 1,
        flowControl: false,
        autoOpen: false
    }, false);

//检测是否可以找到串口监视器以及port 9600
serialPort.open(function (error) {
    if (error) {
        console.log("Open the port " + Arduino_port + "Error detected:" + error);
    } else {
        console.log("The port has been found, opening");
        serialPort.on('data', function (data) {
            //不解码会导致其输出缓冲区的数字字母组合
            const buffer = data;
            const decodedString = buffer.toString('utf8');
            console.log('Data from the Arduino port monitor:', decodedString);
            //仅获取最后一位字符串的输出，目的是为了  Value: 1  只捕捉最后一位数字
            //const temperature_capture = decodedString.slice(-1);
            //console.log("The decodedString is:" + temperature_capture);
            //console.log("");
            var capture_str = decodedString;
            var capture_num = capture_str.replace(/[^\d]/g, " ").trim();
            console.log("Captured number: " + capture_num);
            const led_capture = capture_num;
        })
    }
});