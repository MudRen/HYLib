#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"��Ȧ"NOR);
        set("long", @LONG
�����е�һ�鸣�ء�������ʿͨ�������˴������������кܶ���ʳ����
������ĺõط��������������������(cizhusi)���Զ���������ҪǮ
�ܶ�ģ�������!!
[32m
                       ������!������
                       ��Ҫ��!����ࡣ
                                       
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/city/wumiao",
  "west" : "/d/city/zhufang2",
]));


	set("fadaizhu",1);
	set("citybiwu",1);
	set("pingan",1);
	set("no_death_penalty",1);
	set("no_fight",1);
	setup();
}

void init()
{
        add_action("do_quit2","quit");
        add_action("do_levelup","cizhusi");
}
int do_quit(string arg)
{
	if(arg=="all") {
        write(this_player()->query("name")+"�����ĵ�����ɣ�\n");
        return 1;
	}
	if(arg=="corpse") {
        write(this_player()->query("name")+"�����ĵ�����ɣ�\n");
        return 1;
}  
}
int do_quit2(string arg)
{
        write(this_player()->query("name")+"�����ĵ�����ɣ�\n");
        return 1;
}
int  do_levelup(string arg)
{
	object me, ob;
	object gold;
	int cost = 1;
	int i,j,base,current;
	string id,name ;	
	string file,newfile,filestring;
	me = this_player();
	id = me->query("id");
if (me->query("combat_exp") > 500000)
return notify_fail("ֻҪ������ܳ���ʳ!\n");
if (me->query("food")*2 > me->max_food_capacity())
return notify_fail("�����ڲ�����������˯���ɣ�\n");

message_vision(HIY "$N��ͷ���ʳ�����ҳ�һͨ�����ڳԱ���!!\n" NOR,me);
if (random(12)==9)
{
if (random(4)==0)
{
        ob=new("/clone/money/silver");
        ob->set_amount(random(100)+1);
        ob->move(me);
message_vision(HIR "$N�������Ե���һ������!!\n" NOR,me);
}
else if (random(4)==1)
{
        ob=new("/clone/money/coin");
        ob->set_amount(random(100)+1);
        ob->move(me);
message_vision(HIR "$N�������Ե���һЩͭ��!!\n" NOR,me);
}
else if (random(4)==2)
{
        ob=new("/clone/money/gold");
        ob->set_amount(random(20)+1);
        ob->move(me);
message_vision(HIR "$N�������Ե���һЩ�ƽ�!!\n" NOR,me);
}
else if (random(4)==3)
{
        ob=new("/clone/money/1000-cash");
        ob->set_amount(random(3)+1);
        ob->move(me);
message_vision(HIR "$N�������Ե���һЩ��Ʊ!!\n" NOR,me);
}
else 
{
        ob=new("/clone/money/silver");
        ob->set_amount(random(100)+1);
        ob->move(me);
message_vision(HIR "$N�������Ե���һ������!!\n" NOR,me);
}
}
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
	return 1;
}