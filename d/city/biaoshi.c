// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "�����ھ�");
        set("long", @LONG
    ���������ݳǵ��ھ֡�һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ
�����ɶ�ߵ���ˣ���������Ʈ����������ý�������һͷ������צ��
ʨ�ӡ�����������д�š������ھ֡��ĸ����֣������������վ��Ƿ�����
���ϰ������������ܷ�Ϊ�������¡�
LONG);

        set("exits", ([
                "north" : __DIR__"ximen",
        ]));
       set("no_beg",1);
      set("no_fight", 1);

        set("outdoors", "city");
        setup();
}
