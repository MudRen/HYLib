// /d/welcome/welcome.c
// ����II
// ����(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "��ӭ���������к���II");
  set ("long", @LONG
���������������һ��İ�������磬���뿴����������(l, look),
����֪����������ﶼ��˭(who),������Ҫ�Ĵ����ߣ�(w,s,n,e,nw,ne,
,sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)����������ȿ�������Щ���ڡ�
��������chat�ӿո�Ȼ���ټ���Ҫ˵�Ļ������졣
����(east)��������ѵ�ҡ� ����������8��·�ֱ�ͨ��
yz ���� bj ���� xy ���� dl ���� lz ���� xz ����
qz Ȫ�� wg ��� pa ƽ�� cd �ɶ� km ���� xj �½�
[1;31m��ӹ�������������һЩ������(ask jin yong about liwu)

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
