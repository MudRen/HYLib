// Room: /d/chengdu/shudao14
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "���" NOR );
        set("long", @LONG
�����������������µ�����ϣ���·ʮ����խ��������һ����
ɽ��Ҫȥ�ɶ��Ļ������뷭��������ɽ������һƬ�������������̡�
LONG
        );
        set("exits", ([
  "westup" :  __DIR__"shudao15",
  "southeast" : __DIR__"shudao13",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

