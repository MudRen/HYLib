#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�����Ǻ��ָ��Ļ�԰��Ժ�������˸�ɫ����ľջ����ƾ��ж�ʤ��
����ҩ������֪���׾������°ס�һ��ѩ���������¡��Ͼ���˫���ࡢ
������������̡���������˺졢���������ܽ�ء�����Ժ���м���
��ɫ�ر��޵Ļƻ�������Ƶ������һ������������Ӻ���ɻ�����
���Ǵ����ô����Ľ�Ѯ����
LONG
        );

        set("exits", ([
                "east" : __DIR__"dongxiang",
        ]));
        set("objects", ([
                __DIR__"obj/juhua1" : 1,
        ]));

        set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
        if (!(me->query_temp("biqi"))
        && !wizardp(me)
        && userp(me) ) {
                me->set_temp("last_damage_from", "�н�Ѯ������"); 
                me->receive_wound("qi", me->query("qi")+200 );
		return notify_fail("��ͻȻ�ŵ���һ�����������,ͻȻͷ��Ŀ��ˤ���ڵء�\n");
        } 
        return ::valid_leave(me, dir);
}

