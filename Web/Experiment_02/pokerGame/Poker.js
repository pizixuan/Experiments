var operator = 0; //操作者
var round = 0; //回合数    
var isFlop = false; //是否开牌
var isFlod = false; //是否弃牌
var judgement;
var back = "images/poker/back.jpg";
var data = new Array(52);
initPoker();
var array_1 = new Array(3); //玩家一的牌
var array_2 = new Array(3); //玩家二的牌

var player_1_pokerStyle;
var player_1_pokerNum;
var player_2_pokerStyle;
var player_2_pokerNum;

var player_1_maxNum;
var player_1_midNum;
var player_1_minNum;

var player_2_maxNum;
var player_2_midNum;
var player_2_minNum;


//操作区
var player_1_numberOfChips = document.getElementById("player_1_numberOfChips"); //玩家一准备下注的筹码
var player_1_numberOfChips_num = parseInt(player_1_numberOfChips.value);
var player_2_numberOfChips = document.getElementById("player_2_numberOfChips"); //玩家二准备下注的筹码
var player_2_numberOfChips_num = parseInt(player_2_numberOfChips.value);

//牌区
var player_1_pic_1 = document.getElementById("player_1_pokerCard_1"); //玩家一的牌
var player_1_pic_2 = document.getElementById("player_1_pokerCard_2");
var player_1_pic_3 = document.getElementById("player_1_pokerCard_3");
var player_2_pic_1 = document.getElementById("player_2_pokerCard_1"); //玩家二的牌
var player_2_pic_2 = document.getElementById("player_2_pokerCard_2");
var player_2_pic_3 = document.getElementById("player_2_pokerCard_3");

var player_1_pic_1_src = document.getElementById("player_1_pokerCard_1").src; //玩家一的牌
var player_1_pic_2_src = document.getElementById("player_1_pokerCard_2").src;
var player_1_pic_3_src = document.getElementById("player_1_pokerCard_3").src;
var player_2_pic_1_src = document.getElementById("player_2_pokerCard_1").src; //玩家二的牌
var player_2_pic_2_src = document.getElementById("player_2_pokerCard_2").src;
var player_2_pic_3_src = document.getElementById("player_2_pokerCard_3").src;

//战况
var player_1_ownChips = document.getElementById("player_1_ownChips"); //玩家一筹码
var player_1_ownChips_num = parseInt(player_1_ownChips.value);
var player_2_ownChips = document.getElementById("player_2_ownChips"); //玩家二筹码  
var player_2_ownChips_num = parseInt(player_2_ownChips.value);
var chipsPool = document.getElementById("chipsPool"); //筹码池  
var chipsPool_num = parseInt(chipsPool.value);
var player_1_result = document.getElementById("player_1_result"); //玩家一状态
var player_2_result = document.getElementById("player_2_result"); //玩家二状态

function init() {
    player_1_result.innerHTML = "";
    player_2_result.innerHTML = "";
    if (round == 0) { //将牌置为空
        changePicNull(player_1_pic_1); //玩家一的牌
        changePicNull(player_1_pic_2);
        changePicNull(player_1_pic_3);
        changePicNull(player_2_pic_1); //玩家二的牌
        changePicNull(player_2_pic_2);
        changePicNull(player_2_pic_3);
        document.getElementById("mainOperateButton").value = "开始";
    } else {
        document.getElementById("mainOperateButton").value = "再来一局"
    }
}

function initPoker(){
    for (var i = 0; i < 52; i++) {
        data[i] = 0;
    }
}

function changePicNull(obj) {
    obj.src = "images/null.png";
}

function changePic() { //发牌
    var nums = new Array(6);
    for (var i = 0; i < 6; i++) {
        var temp = Math.floor(Math.random() * 52);
        while (data[temp] != 0) {
            temp = Math.floor(Math.random() * 52);
        }
        if (i == 0) {
            array_1[0] = temp;
        }
        if (i == 1) {
            array_2[0] = temp;
        }
        if (i == 2) {
            array_1[1] = temp;
        }
        if (i == 3) {
            array_2[1] = temp;
        }
        if (i == 4) {
            array_1[2] = temp;
        }
        if (i == 5) {
            array_2[2] = temp;
        }
        data[temp] = -1;
        nums[i] = "images/poker/" + temp + ".jpg";
    }

    player_1_pic_1.src = nums[0];
    player_1_pic_1_src = nums[0];

    player_2_pic_1.src = nums[1];
    player_2_pic_1_src = nums[1];

    player_1_pic_2.src = nums[2];
    player_1_pic_2_src = nums[2];

    player_2_pic_2.src = nums[3];
    player_2_pic_2_src = nums[3];

    player_1_pic_3.src = nums[4];
    player_1_pic_3_src = nums[4];

    player_2_pic_3.src = nums[5];
    player_2_pic_3_src = nums[5];
}

function begin() { //点击 开始 或 再来一局
    round += 1; //回合数    
    operator = 1; //玩家一操作
    document.getElementById("round").innerHTML = "Round " + round;

    player_1_numberOfChips_num = 10; //玩家一下基本注
    player_1_numberOfChips.value = player_1_numberOfChips_num;
    player_1_ownChips_num = parseInt(player_1_ownChips.value); //重新获取
    player_1_ownChips_num = player_1_ownChips_num - 10;
    player_1_ownChips.value = player_1_ownChips_num;

    player_2_numberOfChips_num = 10; //玩家一下基本注
    player_2_numberOfChips.value = player_2_numberOfChips_num;
    player_2_ownChips_num = parseInt(player_2_ownChips.value); //重新获取
    player_2_ownChips_num = player_2_ownChips_num - 10;
    player_2_ownChips.value = player_2_ownChips_num;

    chipsPool_num = 20; //筹码池
    chipsPool.value = chipsPool_num;

    isFlop = false;
    isFlod = false;
    //发牌，先存起来
    changePic();
    for (var i = 0; i < 52; i++) {
        data[i] = 0;
    }
    reverseAll();
    init();
}

function addChipsButton(obj) { //下注
    if (isFlop == false && isFlod == false) //未开牌 未弃牌
        if ((obj.id.substring(0, 8) == "player_1" && operator == 1) || (obj.id.substring(0, 8) == "player_2" && operator == 2)) //操作者符合
            addChipsReal(obj);
}

function addChipsReal(obj) {
    if (obj.id.substring(0, 8) == "player_1") { //操作者符合
        player_1_numberOfChips_num = parseInt(player_1_numberOfChips.value); //更新下注筹码
        player_1_ownChips_num = parseInt(player_1_ownChips.value);
        player_1_ownChips_num = player_1_ownChips_num - player_1_numberOfChips_num; //玩家 拥有的筹码 - 下注筹码
        player_1_ownChips.value = player_1_ownChips_num;
        chipsPool_num = parseInt(chipsPool.value);
        chipsPool_num = chipsPool_num + player_1_numberOfChips_num; //筹码池 + 下注筹码
        chipsPool.value = chipsPool_num;
        player_2_numberOfChips.value = player_1_numberOfChips_num;
        operator = 2;
    }
    if (obj.id.substring(0, 8) == "player_2") {
        player_2_numberOfChips_num = parseInt(player_2_numberOfChips.value); //更新下注筹码
        player_1_ownChips_num = parseInt(player_1_ownChips.value);
        player_2_ownChips_num = player_2_ownChips_num - player_2_numberOfChips_num; //玩家 拥有的筹码 - 下注筹码
        player_2_ownChips.value = player_2_ownChips_num;
        chipsPool_num = parseInt(chipsPool.value);
        chipsPool_num = chipsPool_num + player_2_numberOfChips_num; //筹码池 + 下注筹码
        chipsPool.value = chipsPool_num;
        player_1_numberOfChips.value = player_2_numberOfChips_num;
        operator = 1;
    }
}

function increaseChips(obj) { //加注
    if (obj.id.substring(0, 8) == "player_1" && operator == 1 && isFlop != true && isFlod != true) {
        player_1_numberOfChips_num = parseInt(player_1_numberOfChips.value);
        player_1_numberOfChips_num = player_1_numberOfChips_num + 10; //下注筹码数量 + 10
        player_1_numberOfChips.value = player_1_numberOfChips_num;
    }
    if (obj.id.substring(0, 8) == "player_2" && operator == 2 && isFlop != true && isFlod != true) {
        player_2_numberOfChips_num = parseInt(player_2_numberOfChips.value);
        player_2_numberOfChips_num = player_2_numberOfChips_num + 10; //下注筹码数量 + 10
        player_2_numberOfChips.value = player_2_numberOfChips_num;
    }
}

function decreaseChips(obj) { //减注
    if (obj.id.substring(0, 8) == "player_1" && operator == 1 && isFlop != true && isFlod != true) {
        player_1_numberOfChips_num = parseInt(player_1_numberOfChips.value);
        player_1_numberOfChips_num = player_1_numberOfChips_num - 10; //下注筹码数量 - 10
        player_1_numberOfChips.value = player_1_numberOfChips_num;
    }
    if (obj.id.substring(0, 8) == "player_2" && operator == 2 && isFlop != true && isFlod != true) {
        player_2_numberOfChips_num = parseInt(player_2_numberOfChips.value);
        player_2_numberOfChips_num = player_2_numberOfChips_num - 10; //下注筹码数量 - 10
        player_2_numberOfChips.value = player_2_numberOfChips_num;
    }
}

function flop(obj) { //开牌
    if (obj.id.substring(0, 8) == "player_1" && operator == 1) {
        if (isFlop == true) {
            frontAll();
            addChipsReal(obj); //加注
            compare();
            operator = 0;
            isFlop = false;
        } else {
            operator = 2;
            addChipsReal(obj); //加注
            isFlop = true;
        }
    }
    if (obj.id.substring(0, 8) == "player_2" && operator == 2) {
        if (isFlop == true) {
            frontAll();
            addChipsReal(obj); //加注
            compare();
            operator = 0;
            isFlop = false;
        } else {
            operator = 1;
            addChipsReal(obj); //加注
            isFlop = true;
        }
    }
}

function flod(obj) { //弃牌
    if (obj.id.substring(0, 8) == "player_1" && operator == 1 && isFlod != true) { //操作者匹配 且 无玩家弃牌才可弃牌
        judgement = 2;
        disp();
        player_1_result.innerHTML = "弃牌！";
        checkout();
        operator = 0;
    }
    if (obj.id.substring(0, 8) == "player_2" && operator == 2 && isFlod != true) {
        judgement = 1;
        disp();
        player_2_result.innerHTML = "弃牌！";
        checkout();
        operator = 0;
    }
}

function front(obj) { //正面
    if (obj.id.substring(0, 8) == "player_1" && operator == 1 && round != 0) {
        player_1_pic_1.src = player_1_pic_1_src; //亮牌
        player_1_pic_2.src = player_1_pic_2_src;
        player_1_pic_3.src = player_1_pic_3_src;
    }
    if (obj.id.substring(0, 8) == "player_2" && operator == 2 && round != 0) {
        player_2_pic_1.src = player_2_pic_1_src;
        player_2_pic_2.src = player_2_pic_2_src;
        player_2_pic_3.src = player_2_pic_3_src;
    }
}

function frontAll() {
    player_1_pic_1.src = player_1_pic_1_src; //亮牌
    player_1_pic_2.src = player_1_pic_2_src;
    player_1_pic_3.src = player_1_pic_3_src;
    player_2_pic_1.src = player_2_pic_1_src;
    player_2_pic_2.src = player_2_pic_2_src;
    player_2_pic_3.src = player_2_pic_3_src;
}

function reverse(obj) { //背面
    if (obj.id.substring(0, 8) == "player_1" && operator == 1 && round != 0) {
        player_1_pic_1.src = back; //盖牌
        player_1_pic_2.src = back;
        player_1_pic_3.src = back;
    }
    if (obj.id.substring(0, 8) == "player_2" && operator == 2 && round != 0) {
        player_2_pic_1.src = back;
        player_2_pic_2.src = back;
        player_2_pic_3.src = back;
    }
}

function reverseAll() {
    player_1_pic_1.src = back; //盖牌
    player_1_pic_2.src = back;
    player_1_pic_3.src = back;
    player_2_pic_1.src = back;
    player_2_pic_2.src = back;
    player_2_pic_3.src = back;
}

function compare() { //比大小
    sort1(array_1);
    sort2(array_2);
    //转换
    trans();
    judgement = judge();
    disp();
    checkout(judgement);
}

function disp() {
    if (judgement == 0) {
        player_1_result.innerHTML = "<br>&nbsp;&nbsp;平局!";
        player_2_result.innerHTML = "<br>&nbsp;&nbsp;平局!";
    } else if (judgement == 1) {
        player_1_result.innerHTML = "<br>&nbsp;&nbsp;获胜!<br>&nbsp;&nbsp;+"+chipsPool_num;
        player_2_result.innerHTML = "";
    } else {
        player_1_result.innerHTML = "";
        player_2_result.innerHTML = "<br>&nbsp;&nbsp;获胜!<br>&nbsp;&nbsp;+"+chipsPool_num;
    }
}

function judge() {
    //判定阶段
    if (player_1_pokerStyle == player_2_pokerStyle) {
        if (player_1_pokerNum == player_2_pokerNum) {
            return 0;
        } else if (player_1_pokerNum > player_2_pokerNum) { //玩家一获胜
            return 1;
        } else { //玩家二获胜
            return 2;
        }
    } else if (player_1_pokerStyle < player_2_pokerStyle) {
        if ((player_1_pokerStyle == 0 || player_1_pokerStyle == 1) && player_2_pokerStyle == 7) { //特殊克拖拉机
            return 2;
        } else {
            return 1;
        }
    } else {
        if ((player_2_pokerStyle == 0 || player_2_pokerStyle == 1) && player_1_pokerStyle == 7) { //特殊克拖拉机
            return 1;
        } else {
            return 2;
        }
    }
}

function trans() {

    console.log(player_1_minNum);
    console.log(player_1_midNum);
    console.log(player_1_maxNum);
    console.log(player_2_minNum);
    console.log(player_2_midNum);
    console.log(player_2_maxNum);

    //玩家一转换
    if ((Math.floor(array_1[0] / 13) == Math.floor(array_1[1] / 13)) && (Math.floor(array_1[1] / 13) == Math.floor(array_1[2] / 13))) { //三张花色相同 顺子 单子
        //顺子和单子
        if (player_1_minNum == 1) { //有A的情况
            if (player_1_midNum == 12 && player_1_maxNum == 13) { // Q K A 的情况  最大的顺子
                player_1_pokerStyle = 2
                player_1_pokerNum = 14;
            } else if ((player_1_midNum + 1 == player_1_maxNum) && (player_1_midNum - 1 == player_1_minNum)) { // A 2 3 的情况 最小的顺子
                player_1_pokerStyle = 2
                player_1_pokerNum = player_1_maxNum;
            } else { //花色相同的 A 单子
                player_1_pokerStyle = 3;
                player_1_pokerNum = 14;
            }
        } else if (player_1_minNum != 1) { //没有A的情况
            if ((player_1_midNum + 1 == player_1_maxNum) && (player_1_midNum - 1 == player_1_minNum)) { //顺子
                player_1_pokerStyle = 2;
                player_1_pokerNum = player_1_maxNum;
            } else { //单子
                player_1_pokerStyle = 3;
                player_1_pokerNum = player_1_maxNum;
            }
        }
    } else { //三张花色并不完全相同 豹子 顺子 对子 单子 
        //豹子
        if (player_1_maxNum == player_1_midNum == player_1_minNum) {
            player_1_pokerStyle = 1;
            if (player_1_minNum == 1) { //有A的情况
                player_1_pokerNum = 14;
            } else {
                player_1_pokerNum = player_1_maxNum;
            }
        }
        //顺子 对子 单子
        if (player_1_minNum == 1) { //有A的情况
            if (player_1_midNum == 12 && player_1_maxNum == 13) { // Q K A 的情况  最大的顺子
                player_1_pokerStyle = 4
                player_1_pokerNum = 14;
            } else if ((player_1_midNum + 1 == player_1_maxNum) && (player_1_midNum - 1 == player_1_minNum)) { // A 2 3 的情况 最小的顺子
                player_1_pokerStyle = 4
                player_1_pokerNum = player_1_maxNum;
            } else if (player_1_minNum == player_1_midNum) { //有A的情况 即 对A
                player_1_pokerStyle = 5;
                player_1_pokerNum = 14;
            } else if (player_1_midNum == player_1_maxNum) { // 有A 的非A对子
                player_1_pokerStyle = 5;
                player_1_pokerNum = player_1_maxNum;
            } else if (player_1_midNum != player_1_minNum && player_1_maxNum != player_1_midNum) { //花色不同的 A 单子
                player_1_pokerStyle = 6;
                player_1_pokerNum = 14;
            }
        } else if (player_1_minNum != 1) { //没有A的情况
            if ((player_1_midNum + 1 == player_1_maxNum) && (player_1_midNum - 1 == player_1_minNum)) { //顺子
                player_1_pokerStyle = 4;
                player_1_pokerNum = player_1_maxNum;
            } else if (player_1_midNum == player_1_minNum || player_1_midNum == player_1_maxNum) { //没有A的对子
                player_1_pokerStyle = 5;
                player_1_pokerNum = player_1_midNum;
            } else if (player_1_midNum != player_1_minNum && player_1_midNum != player_1_maxNum) { //单子
                player_1_pokerStyle = 6;
                player_1_pokerNum = player_1_maxNum;
            }
        }
        //花色不同的 2 3 5
        if ((Math.floor(array_1[0] / 13) != Math.floor(array_1[1] / 13) && Math.floor(array_1[0] / 13) != Math.floor(array_1[2] / 13) && Math.floor(array_1[1] / 13) != Math.floor(array_1[2] / 13)) && (player_1_minNum == 2 && player_1_midNum == 3 && player_1_maxNum == 5)) {
            player_1_pokerStyle = 7;
            player_1_pokerNum = player_1_maxNum;
        }
    }



    //玩家二转换
    if ((Math.floor(array_2[0] / 13) == Math.floor(array_2[1] / 13)) && (Math.floor(array_2[1] / 13) == Math.floor(array_2[2] / 13))) { //三张花色相同 顺子 单子
        //顺子和单子
        if (player_2_minNum == 1) { //有A的情况
            if (player_2_midNum == 12 && player_2_maxNum == 13) { // Q K A 的情况  最大的顺子
                player_2_pokerStyle = 2
                player_2_pokerNum = 14;
            } else if ((player_2_midNum + 1 == player_2_maxNum) && (player_2_midNum - 1 == player_2_minNum)) { // A 2 3 的情况 最小的顺子
                player_2_pokerStyle = 2
                player_2_pokerNum = player_2_maxNum;
            } else { //花色相同的 A 单子
                player_2_pokerStyle = 3;
                player_2_pokerNum = 14;
            }
        } else if (player_2_minNum != 1) { //没有A的情况
            if ((player_2_midNum + 1 == player_2_maxNum) && (player_2_midNum - 1 == player_2_minNum)) { //顺子
                player_2_pokerStyle = 2;
                player_2_pokerNum = player_2_maxNum;
            } else { //单子
                player_2_pokerStyle = 3;
                player_2_pokerNum = player_2_maxNum;
            }
        }
    } else { //三张花色并不完全相同 豹子 顺子 对子 单子 
        //豹子
        if (player_2_maxNum == player_2_midNum == player_2_minNum) {
            player_2_pokerStyle = 1;
            if (player_2_minNum == 1) { //有A的情况
                player_2_pokerNum = 14;
            } else {
                player_2_pokerNum = player_2_maxNum;
            }
        }
        //顺子 对子 单子
        if (player_2_minNum == 1) { //有A的情况
            if (player_2_midNum == 12 && player_2_maxNum == 13) { // Q K A 的情况  最大的顺子
                player_2_pokerStyle = 4
                player_2_pokerNum = 14;
            } else if ((player_2_midNum + 1 == player_2_maxNum) && (player_2_midNum - 1 == player_2_minNum)) { // A 2 3 的情况 最小的顺子
                player_2_pokerStyle = 4
                player_2_pokerNum = player_2_maxNum;
            } else if (player_2_minNum == player_2_midNum) { //有A的情况 即 对A
                player_2_pokerStyle = 5;
                player_2_pokerNum = 14;
            } else if (player_2_midNum == player_2_maxNum) { // 有A 的非A对子
                player_2_pokerStyle = 5;
                player_2_pokerNum = player_2_maxNum;
            } else if (player_2_midNum != player_2_minNum && player_2_maxNum != player_2_midNum) { //花色不同的 A 单子
                player_2_pokerStyle = 6;
                player_2_pokerNum = 14;
            }
        } else if (player_2_minNum != 1) { //没有A的情况
            if ((player_2_midNum + 1 == player_2_maxNum) && (player_2_midNum - 1 == player_2_minNum)) { //顺子
                player_2_pokerStyle = 4;
                player_2_pokerNum = player_2_maxNum;
            } else if (player_2_midNum == player_2_minNum || player_2_midNum == player_2_maxNum) { //没有A的对子
                player_2_pokerStyle = 5;
                player_2_pokerNum = player_2_midNum;
            } else if (player_2_midNum != player_2_minNum && player_2_midNum != player_2_maxNum) { //单子
                player_2_pokerStyle = 6;
                player_2_pokerNum = player_2_maxNum;
            }
        }
        //花色不同的 2 3 5
        if ((Math.floor(array_2[0] / 13) != Math.floor(array_2[1] / 13) && Math.floor(array_2[0] / 13) != Math.floor(array_2[2] / 13) && Math.floor(array_2[1] / 13) != Math.floor(array_2[2] / 13)) && (player_2_minNum == 2 && player_2_midNum == 3 && player_2_maxNum == 5)) {
            player_2_pokerStyle = 7;
            player_2_pokerNum = player_2_maxNum;
        }
    }
}

function f(a, b) { //排序函数
    return (a - b); //返回比较参数
}

function sort1(array_1) {
    var newArray = [];
    for (i = 0; i < 3; i++) {
        newArray[i] = array_1[i] % 13 + 1;
    }
    newArray.sort(f);

    player_1_minNum = newArray[0];
    player_1_midNum = newArray[1];
    player_1_maxNum = newArray[2];
}

function sort2(array_2) {
    var newArray = [];
    for (i = 0; i < 3; i++) {
        newArray[i] = array_2[i] % 13 + 1;
    }
    newArray.sort(f);

    player_2_minNum = newArray[0];
    player_2_midNum = newArray[1];
    player_2_maxNum = newArray[2];
}

function checkout() { //结算
    chipsPool_num = parseInt(chipsPool.value);
    chipsPool.value = 0;
    player_1_ownChips_num = parseInt(player_1_ownChips.value);
    player_2_ownChips_num = parseInt(player_2_ownChips.value);
    if (judgement == 0) { //平局
        player_1_ownChips_num = player_1_ownChips_num + Math.floor(chipsPool_num / 2);
        player_1_ownChips.value = player_1_ownChips_num;
        player_2_ownChips_num = player_2_ownChips_num + Math.floor(chipsPool_num / 2);
        player_2_ownChips.value = player_2_ownChips_num;
    } else if (judgement == 1){ //玩家一获胜
        player_1_ownChips_num = player_1_ownChips_num + chipsPool_num;
        player_1_ownChips.value = player_1_ownChips_num;
    }
    else{ //玩家二获胜
        player_2_ownChips_num = player_2_ownChips_num + chipsPool_num;
        player_2_ownChips.value = player_2_ownChips_num;
    }
}