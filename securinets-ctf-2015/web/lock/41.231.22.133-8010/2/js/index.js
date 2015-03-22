$(function () {


    var comboArray = [0, 0, 0, 0, 0];


    var gridIncrement = $(".lock-dial ul").css('line-height').replace('px', '') / 2;
    var numNums = $(".lock-dial:eq(0) ul li").length;
    var halfHeight = gridIncrement * numNums;
    var initTop = -(halfHeight - gridIncrement);

    $(".lock-dial ul").css('top', initTop);

    $(".lock-dial ul").draggable({
        grid: [0, gridIncrement],
        axis: 'y',
        drag: function () {

            var dragDir = $(this).css('top').replace('px', '') < initTop ? "up" : "down";

            if (dragDir == "up") {
                var curNum = parseInt($(this).find('li:last-child').text()) + 1;
                if (curNum < 10) {
                    $(this).append('<li>' + curNum + '</li>');
                } else {
                    $(this).append('<li>0</li>');
                }
                ;
            } else {
                var curNum = parseInt($(this).find('li:first-child').text()) - 1;
                var thisTop = parseInt($(this).css('margin-top').replace('px', ''));

                $(this).css({
                    marginTop: thisTop - (gridIncrement * 2)
                });

                if (curNum > -1) {
                    $(this).prepend('<li>' + curNum + '</li>');
                } else {
                    $(this).prepend('<li>9</li>');
                }
                ;
            }
            ;
        },
        stop: function () {


            //MATHS
            var negOrPos = $(this).css('margin-top').replace('px', '') > 0 ? 1 : -1;
            var thisTopTotal = parseInt($(this).css('top').replace('px', '')) + Math.abs(initTop);
            var marginMinified = parseInt(Math.abs($(this).css('margin-top').replace('px', ''))) - thisTopTotal;
            var numIncs = Math.floor(marginMinified / (halfHeight * 2));
            var totalDif = numIncs * (halfHeight * 2);
            var topTen = (marginMinified - totalDif) * negOrPos;
            var activeIndex = Math.abs(topTen / (gridIncrement * 2)) + (halfHeight / (gridIncrement * 2));

            $(this).attr("data-combo-num", $(this).find('li').eq(activeIndex).text()).css({
                top: -315,
                marginTop: topTen
            }).find('li').slice(20).remove();

            for (var i = 0; i < $(".lock-dial ul").length; i++) {
                comboArray[i] = $(".lock-dial ul:eq(" + i + ")").attr("data-combo-num");
            }
            $.ajax({
                url: '/2/fresult.php',
                type: 'GET',
                dataType: 'json',
                data: 'x=' + comboArray.join(''),
                success: function (data) {
                    if (data.result == 5) {


                        $('.lock-dial ul').draggable('disable');
                        $('#lock-wrapper').addClass("unlocked");
                        $('.lock-dial').each(function(){
                            var $this = $(this);
                            $this.find('ul').delay(400).css('color', '#0f0').fadeOut(function(){
                                $this.animate({
                                    marginTop: 150
                                }, function(){
                                    $this.fadeOut(function(){
                                        $('.welcome-message').fadeIn();
                                    });
                                });
                            });
                        });
                        $('.welcome-message').fadeIn();
                        $('#welcome').html(data.flag);

                    } else {
                        $('#zone_result').html(data.result);
                    }
                }
            });

        }
    });

})
