// Room: /d/chengdu/shudao3
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "����С·" NOR );
        set("long", @LONG
�����ڳ������ϵ�һ��С·�ϣ������Ž�ˮ��������������
Ҳ���ú�Щ������������ȥ��ֻ��Ⱥɽ���࣬��֪�δ��ǹ�;��
LONG
        );
        set("exits", ([
  "northeast" :  __DIR__"shudao2",
  "west" : __DIR__"shudao4",
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

