#include <ansi.h>
inherit ROOM;

int valid_leave();
void create()
{
	set("short", WHT"�ƶ�ħ����"NOR);
	set("long", HIW @LONG
����һ����������Զ�ŵ�ħ�������ϻ���һ���޴��ħ����
������һ������㣬�����ͨ�������Ƶ�(yidong)ʲô�ط�ȥ�� 
LONG HIW );
	set("exits", ([
//		"west" : __DIR__"migong2",
//		"down" : "/d/migong/lev1/dong21",
                           	]));
                set("no_clean_up", 0);
	setup();
	}


void init()
{
        add_action("do_go","yidong");
}

int do_go(string arg)
{
string msg,mapm,rooms;
int i;
	object *inv;
	int sizeinv;
        object room;
object me=this_player();
 	if (!arg)
	return notify_fail("��Ҫȥ�ڼ����Թ���(lev16-22)\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�㱳�����������Ĺ����͵���ȥ��\n");
       		
		}

        msg=me->query("jobtarget");

	if(arg!="lev16" && arg!="lev17" && arg!="lev18" && arg!="lev19"
	&& arg!="lev20"&& arg!="lev21"&& arg!="lev22")
	 	return notify_fail("��Ҫȥ�ڼ����Թ���(lev16-22)\n");
    if (me->query("neili")<1000)
	return notify_fail("�����������!\n");

    if (me->query_condition("migongmove"))
	return notify_fail("��ո��ù��ƶ��㣬�Ȼ�������!\n");

me->apply_condition("migongmove",18);
me->delete("vendetta/authority");
        me->add("neili",-800);
	if(arg=="lev16") {
        if (present("fire hat", me) ) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev16/dong22");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}
	if(arg=="lev17") {
        if (present("water armor", me) ) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev17/dong22");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}
	if(arg=="lev18") {
        if (present("earth shield", me) ) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev18/dong22");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}
	if(arg=="lev19") {
        if (present("air boot", me) ) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev19/dong22");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}
	if(arg=="lev20") {
        if (present("light jian", me) ) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev20/dong22");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}
	if(arg=="lev21") {
        if (present("dark jian", me) ) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev21/dong22");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}
	if(arg=="lev22") {
        if (present("dark jian", me) ||
        present("light jian", me)) 
{
        message_vision(HIW "һ����������$N!\n" NOR, me);
me->move("/d/migong/lev22/dong01");
}
else message_vision(HIR "$N��û��ȥ�����ʸ�\n" NOR, me);
}

return 1;
}