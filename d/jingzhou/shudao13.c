// Room: /d/chengdu/shudao13
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "���" NOR );
        set("long", @LONG
�����������������µ�����ϣ���·ʮ����խ�����ﲻʱ����
ǿ����û���������˺��٣���Ŀ��ȥ����Բ��������û�����̣���
���Ǽӿ첽���߰ɡ�
LONG
        );
        set("exits", ([
  "northeast" :  __DIR__"shudao12",
  "northwest" : __DIR__"shudao14",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

