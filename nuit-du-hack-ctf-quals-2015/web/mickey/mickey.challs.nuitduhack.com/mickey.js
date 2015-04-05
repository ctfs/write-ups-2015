/*
                     cCCc
                    CCCC'c
                   cCCC'JMb
                  cCC.=<MMMr
                  CCCCC,"MMP
                 :CCCCCC,?,cC
                 b`CCCCCCcCCCC.
                :Mb``'<CCCCCC',e
                4MMMM> CCCC'uMM",
                tMMM, c`CC'MMMP<CC.    .,,,.
                ?P`ML CCC'<MMMb`CCC> c$$$???$$c,
                `';`",,,`<,MMMMM,`<><$$'c$$$$$$$b.
                ,zd$$$$$P`Cc"MMMMMbu`$'$$$P7J$$$$$h
              u$$$$$FFF"-CCCCc==""",,,.$$FJ$$$$$$$$L
            .d$$P?(JJ$$$$bc,,//%%%%%%%%,"`$$$P"d$$$$
           :$$$hJ$$$????$$$F;%%%%%%%%%%%;':<:%>`$$$$ <,
          :$$$$$$Czd$$$bc"";%:':':'``` :< :<%%%>$$P)$ .`'x,
          $$?$$$$$$$$$$$P,%%.:' `         ~%!%/J2$$$F `>):`?x
          $C9)$$$$$':x<%%'`      c$$$$hc,$$c` xC""     `.'- !X
          $$9J$$$$>:%%'`       :$$$$$$$$$$$$$$c`!:.     `'' XX'
          ($$J$$$" `%:         $$$$$$$P"`?$C  "$i-.`'!Xx:!!!!"
       ,' ??$$$uP" .          :$$$$$$$;e  ?$,,M<$b`,--~-<:xx
      ,  !.        ?Xx.       :$$$$$$$;MMM;$>?M>($F      !XX
      (  `Xh       `<`"X::    `$$$$$$$;?MM>?$>",cd       <X>
      (   `<?h.     `?;.??Xx   ?$$$$$$$hxxz6d$$$$>     ,<XX
       \    `'?hx.    !; %XXh-cdcQ$$$$$$$$$$$$$$$$bccr;<XX'
        `.    ```"!!!n+uHX?!"dP""C3$$$$$$$$$$$$$$$$$$:<XX'
           `-..`!!;;x;;,.,;; ?J$h ?$$$$$$$$$$$$$$$$".XX>
                `'!!X!!!!!!!?,?$$$,  "??$$$$$FFF" xXXX>
                  `<!!!!!!!!X!;.""$c/-:.,,  ,dP:?`??/
                    ``'XX!!!X!!!!:."??ncccdP"<!`: !'
                         ``'!!!!!!X:.`"""'<!!:!~` ?
                              `''!!!!!x:..`((.:X!!:
                                  `!!XXXX!!?!!!!!!!!:
                                   `<?!!!!!'!!!XX!?!!c
                                   du`'!!!!!!!!!!?!!!X
                                  ..?$c,`<!>'';',uc,,,.
                                  !!'-??b%zd$$$$L9P?$$$b
                               .n!!!'':;;?$$P?bP\`"?ku$F
                              :!X!!!<!<!!'?b$P"d$ !>>>>
                             !!!!!!'!!!!!'!;` d$$b'!!!!-
                            <!!!!!!<!!!!!!!! d$$$$$.`!!!.
                            !' !!!!':!!`!!!!:$$$$$PBb,;!!!,
                           '' <!!!!''>`'!!!>$$$P?b$P" `;;!!;,
                           .<!!!!!:''< '''< . . .`\     ;;<!!>
                          :!!!!!!!'!'!!!!;  .`.`.`.;   ,;`))!>)
                       ,/!!!!!!''''<!!!;>'.`.`.`.`;   ,;;;.(!>',,
                  . ,;!!!!'!X!!!:<'''/,;' .`.`.`,'   ,:,o::!(,,`!!,
        .,,x:!!'`,;!!!!!!!!><<'!!!!<;'' .`.` ,u<?u  ,$P?Co,,,,,,,,.
  .x<!!!!!!!"-'``````````''''!<''!!!' .`.` o$$$d$$$$$cJ$$$$$$$$$$$P";c$$$b
c?!X!'',;;x!!!!!!!!!!!!!'!'!<!'''',c$b    `$$$$$$$$$$$$$$$$$$$$$$CJ$$$$$$$
2XJ!!!!!X!!''``.,xuccccccccccd$$$$$$$"     `????????$$$$$$$$$$$$$$$$$$$$P"
`<!!!!!!!!!',uccccc`?$$$$$$$$$$$P"""                     ``"""""   """
   ````""` d$$$$$$$$$?$$$$$$$P"
            `?????")c$$$P" `
 */

// guess what
G = "tQVPXjoTFx+abG6D7oVUesAsxLiI7ksyRQi+E3b36L3cAKpg57SRuHzqjdE8xs8LUiIXnPFg6Apq";
I = "9RMMf1HzAKLQAKiLgJ0yecLW95vP56WZG/u0fk9aWLbr9cjvc9R/xSH8Mz7ZFPBMI9Imv8zmne3J";
Y = "XKDDpTa380DyHmbGWUy0Xp1LDC+FWxtGZ+JyO36iSWWo/ao5N/2hbPWvkuKMwbRP5Pt4yHMnMaUC";
F = "R5IuWUyjvgo8Hrpl0sD4AGUciLTqfWHLQ87GuMLuKqLWY6gP2MYfgLdcug6r5J5X9oT8eVyq/mt5";
_ = "WOLGiR0EqdGjmiXFjHtGnS2Xmq7cJ6OJYnnFvw";

// magic number is magic
y = Big;
o = 256;
u = "mad?";

// hmm
N = "Y5jSH0ovMHhisRchZUp9FMFMVbwXJsaudbV6zw+L5TF6bkqdJBX+SuqLnS5lfdXMK6BkmyJDDIsF";
D = "OEn4QkTlS2RWhKBO/enwN+3yISiiWVL4XwUjh7bzfofRUDmEErwRkMyjzaashq+P2hcSvCCqHxN/";
H = "PjfwtLyOk9tS9oCFk3IHW74edlEYZwiQ3ccT24hpGrlnlnluIoPldE1tBN9kV8/ZSIsQmYA9yU9Y";
Z = "UmLzws4deu8UynI7wea7Z0boIjv0Dhbr/0W+b/Ab9yXVnhYv5hYDEwo5FP15ivLsKe6intVyogxH";
V = "ZyIppBhxy23c8qtC/lFGDiVGRXy2grjevME9PA";

function btoi(b){
    x = y(0); z = 0;
    while(z < b.length) x = x.times(o).plus(b.charCodeAt(z++));
    return x;
}

a=btoi(atob(G+Y+I+F+_))

function it(i, j, k) {
    return i.times(i.times(k?1:j)).mod(a);
}

function enc(c) {
    i = y(c);
    p = i.e;
    while(p) i=it(i,y(c),--p);
    return i;
}

function chk(e) {
    if(btoi(atob(N+D+H+Z+V)).eq(enc(e))) window.location = "" + e + ".html";
}

$(function() {
	$("#wtf").change(function() {
		chk($(this).val());
	})
});
