// nroad6.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
������һɽ·�ϣ�������һ����Сɽ��Զ�����Կ��������ѩ
��ɽ�⡣��Χ�������Ѿ����ѿ��õ��ˡ�
LONG );
        set("exits",([
                "north"   : __DIR__"nroad7",
                "southup" : __DIR__"nroad5",
        ]));
        set("objects",([
                __DIR__"npc/huatiegan" : 1,
        ]));
//	set("no_clean_up", 0);
        set("outdoors", "xueshan");
        setup();
//        replace_program(ROOM);
}

void init()
{
	object me = this_player();
	if (!me->query_temp("szj/shui")) return;
	call_out("clone_shui", 1, me);
}

void clone_shui(object me)
{
	object *ob,obj;
	int i,j;

	if( environment(me) != this_object()) return;

	j=0;
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if ( (!userp(ob[i])) && ((string)ob[i]->query("id")=="shui sheng"))
		j=1;
	}
	if (!j) {
		obj=new(__DIR__"npc/shuisheng.c");
		obj->move(environment(me));
		message_vision(HIC"ֻ���ö����ᣬ������һ��������һ�����������������Ž��߳�����\n"NOR, me);
	}
}
