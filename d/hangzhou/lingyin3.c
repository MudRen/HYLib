//Cracked by Kafei
// ������֮���۱���
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "������");
    set("long", @LONG
��������һ�����������������ж�ʮ������ķ��񣬴�����
����ʮ���κ����񣬵�������̬����Ĵ�С����һ����ʮ����������
ʱ���������¸�ɮǰ������˵��
LONG);

   set("exits", ([ /* sizeof() == 1 */ 
                  "south" : __DIR__"lingyinsi", 
                ])
       );
   set("objects", ([__DIR__"npc/kumu" : 1,]));
	
	set("cost", 0);
    setup();
   //  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( me->query_condition("lyjob") ) {
                me->apply_condition("lyjob", 0);
                message_vision("\n$Nվ������������Χ��ɮ˵����" + RANK_D->query_self(me) + "�е㼱�£��´��л���һ��ǰ��л������֮�ִ١�\n", me);
        }

        return ::valid_leave(me, dir);
}
