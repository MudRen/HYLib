// /d/xingxiu/silk3.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"��Ħ��"NOR);
        set("long", @LONG
��Ħ����������������Χɽ�ƶ��ͣ���ɽ���ţ�һ����������Ͽ����̶��
Ԩ��Ī�⡣�״��л�����̶�ɳ�����������̶��̶���Ħ�³ɱ��������漣��
�ʴ��پ������������������˿��쾮���Ĺ��̡��������ǳ��ɽ����������
ʯ�š�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "eastdown" : __DIR__"silk31",
                "westdown" : __DIR__"silk4",
                "north" : __DIR__"silk3a",
        ]));

        setup();
//        replace_program(ROOM);
}

