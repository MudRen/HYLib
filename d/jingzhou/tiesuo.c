// /d/jingzhou/tiesuo.c
// netkill /98/9/10/
// ��ȸ����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC "��������" NOR);
        set("long", @LONG
��վ��һ��ˮ֮�е�һ�������ϣ�������ˮ�����ͣ����վ����
���û������Ṧ���Ǽ�ֲ��˶�õġ����������п�ȥ������
�����ƺ�󣬽�ˮ���������Ŀ�ȥ������ˮ����һЩ�ŹֵĶ�����
LONG
        );
    
             
        setup();
	//replace_program(ROOM);
} 

void init()
{
	add_action("do_jump","jump");
}

int do_jump (string arg)
{	object me=this_player();
	if (!arg || arg=="") return 0;
	if (arg=="down")
	{
tell_object(me,"��ܲ�����������˽��У�һ��ˮӿ��������\n");
		 me->move(__DIR__"chibi4");
		return 1;
	}	
	else return notify_fail("��Ҫ��ʲô��\n");
}