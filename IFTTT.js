//正确代码：
/*
const axios = require('axios');
// IFTTT Webhooks URL，将 YOUR_EVENT_NAME 替换为你在 IFTTT 上创建的事件名称
const iftttWebhooksUrl = 'https://maker.ifttt.com/trigger/SIT314/with/key/dfch1J4mPyUIj1jqSffUMc8DOr5eTTd6Ws0jzarIm47';

// 发送 POST 请求给 IFTTT
async function sendToIFTTT(data) {
  try {
    const response = await axios.post(iftttWebhooksUrl, { value1: data });
    console.log('IFTTT Response:', response.data);
  } catch (error) {
    console.error('Error sending data to IFTTT:', error.message);
  }
}

// 示例：发送数据给 IFTTT
const dataToSend = 'SIT314';
sendToIFTTT(dataToSend);
*/

//测试代码
