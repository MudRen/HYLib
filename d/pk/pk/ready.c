// Room: /d/pk/ready.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���˳���Ϣ��");
	set("long", @LONG
����ں����ģ����ϻ���һЩճ����Ѫ���Ĳ�����żȻҲ���õ���
�˵ĳ������ֵ�ʲô�ġ�������Ž��������ţ�����ɢ����һ����Ѫ��
����ζ��
[1;31m�����������duihuan���Ի������˴���л�õý�����
�����������������ˣ�������ask ouye zi about �����������������
���û���ˣ���Ϳ�����out���뿪����
LONG
	);
	set("exits", ([
		"out" : "/d/city/wumiao",
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/ouyezi" : 1,
]));


        set("no_fight", 1);
	setup();
}

void init()
{
        add_action("do_start", "duihuan");
}

int do_start()
{
       object me;
       object room,npc,room2;
int a,b,c;
       me = this_player();       
       if (!userp(me))
          return notify_fail("����Ҳ���ʹ�ã�\n");
       if (!me->query_temp("bwdhpk"))
          return notify_fail("��һ�����Ҳû��������\n");
a=(int)me->query_temp("bwdhpk");
b=a*500;
c=a*300;
        me->add("combat_exp", b);
        me->add("potential",c);
message_vision(HIG"һ����Χ��$N,$N��ʧ�����ˡ�\n"NOR, me);
tell_object(me, "�㱻������"+chinese_number(b)+"�㾭��ֵ��\n"+chinese_number(c)+"��Ǳ��\n");
message("channel:chat", HIC"������ս����"HIR + " "+me->query("name")+"������:"+chinese_number(a)+"��   "+HIG"����"+chinese_number(b)+"�����"+chinese_number(c)+"��Ǳ��\n"NOR,users() );
me->set_temp("bwdhpk",0);
me->delete_temp("bwdhpk");

           return 1;
 
}
