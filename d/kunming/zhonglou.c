// /d/kunming/jinrilou
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "��¥" );
        set("long", @LONG
����һ����¥���м�������һ���ӣ�����̵������ģ����ִ���
��������������ô�ߣ�������������ǧ���֪����������ô����ȥ
�ģ��ӵ���������һ��ľ����������������(hit)�õġ� 
LONG
        );
        
        set("exits", ([
                "down"    :__DIR__"jinrilou",
                
                
        ]));

             
        setup();
       
}

int init()
{add_action("do_hit","hit");
}

int do_hit(string arg)
{
	object me=this_player();
	if (arg=="" || !arg ) return 0;
	if (arg=="��")
	if ( (int)me->query_int() < 25 )
	{
	    if ( !(int)me->query_temp("temp") )
		{
		if ((int)me->query_str()< 25 ) return notify_fail("���ò����������\n");
		message_vision("$N����һ���ӡ�����������������ԶԶ���˳�ȥ��\n",me);
		tell_object(me,"���������ܲ�ͣ�Ļص�����������ͷ��������\n");
		me->add("qi", -10);
		me->set_temp("temp",1);
		return 1;
		}
		message_vision("$N������һ���ӡ�����������������ԶԶ���˳�ȥ��\n",me);
		tell_object(me,"������Զ�Ĵ��˳�ȥ������ֻ�����������ֻ�������������ƺ�\n"+
			"������������������ķ��⡣\n");
		me->add("qi", -10);
		if (!random(10))
		{ 
		tell_object(me,"�㾲����������������������ˮ���Ʒ紵�������...���Ȼ����\n"+
					"��ԭ����������֮�����Ǵ���Ȼ��������\n"+
					HIC "�����������ˣ�\n" NOR);
if ( (int)me->query_int() < 18 )
{
			me->add("int",1);
}
		}
		else tell_object(me,"����˼�������ôҲ����������ֻ�����ա�\n");
		me->delete_temp("temp");
	}
	else tell_object(me,"�������˵����˼����ӣ��������ġ�\n");
	return 1;
}
	  		