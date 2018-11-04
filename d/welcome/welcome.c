// /d/welcome/welcome.c
// ∫£—ÛII
// –«–«(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "ª∂”≠π‚¡Ÿœ¿øÕ––∫£—ÛII");
  set ("long", @LONG
ƒ„ªÏªÏ„Á„Áµƒ¿¥µΩ¡À“ª∏ˆƒ∞…˙µƒ ¿ΩÁ£¨ƒ„œÎø¥ø¥ƒ„‘⁄ƒƒ¿Ô(l, look),
ƒ„œÎ÷™µ¿’‚∏ˆ ¿ΩÁ¿Ô∂º”–À≠(who),ªÚ–Ìƒ„“™Àƒ¥¶◊ﬂ◊ﬂ£¨(w,s,n,e,nw,ne,
,sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)£¨≤ªπ˝ƒ„µ√œ»ø¥ø¥”–ƒ«–©≥ˆø⁄°£
–¬ ÷«Î”√chatº”ø’∏Ò£¨»ª∫Û‘Ÿº”…œ“™Àµµƒª∞¿¥¡ƒÃÏ°£
∂´±ﬂ(east) «–¬ ÷≈‡—µ “°£ ¡ÌÕ‚’‚¿Ô”–8Ãı¬∑∑÷±Õ®œÚ
yz —Ô÷› bj ±±æ© xy œÂ—Ù dl ¥Û¿Ì lz ¿º÷› xz ¿≠»¯
qz »™÷› wg Œ‰π› pa ∆Ω∞≤ cd ≥…∂º km ¿•√˜ xj –¬ΩÆ
[1;31mΩ”π¥Ûœ¿ø¥¿¥ª·∏¯ƒ„“ª–©∞Ô÷˙µƒ(ask jin yong about liwu)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "yz" : "/d/city/kedian",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "pa" : "/d/pingan/pingankezhan",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
  "xz" : "/d/xizang/octostreet",		
  "xj" : "/d/xinjiang/nanmen",			
"east" : __DIR__"newbie4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"jing" : 1,
 //"/clone/gift/newbieliwu" : 1,
]));
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
void init()
{
	object me;
me=this_player();
if( me->query_temp("netdead")) 
"/cmds/usr/quitgame"->main(me);
	return;
}
