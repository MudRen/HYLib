// Room: /d/wizhome/incahome/changcheng13.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT @LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ���ɽ�����������ɽ
���Ѿ����ٿ������͹�ľ���ˡ�ɽ�ϴ�Ƭ�ĵط���ͺͺ�ģ��ܶ�ط��Ѿ�¶
���˴�Ƭ�Ļ���������µĳ������ѵ��򱱣����������ȥ��վ�������
�Ѿ����Ըе�ӭ������Ĵ���д��Ų���ɳ�ӣ������Ǻ��ĳ�ǽҲ����ʴ
��������䣬��Զ����һ�γ�ǽ�Ѿ���������ֻ�������ƹ�ȥ��
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"       :__DIR__"FengHuoTai2-1",
                "north"      :__DIR__"changcheng12",
        ]));

        setup();
        replace_program(ROOM);
}

