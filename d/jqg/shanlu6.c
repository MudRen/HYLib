// shanlu6.c
// By River 98/09
// Modify 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
       set("short", HIW"�����"NOR);
       set("long", @LONG
����Ŀ�Ĺˣ�ԭ��������һ������֮������������ľï�ܣ�Զ��ʯׯ����
����������֮ң����������������������Ω�������ȵף����Է��ۣ���ɽ�żţ�
΢��������ãã����ֻ��һ�˶��ѡ�
LONG
        );
       set("exits", ([ 
              "southdown"  : __DIR__"shanlu5",
       ]));
       set("outdoors", "�����");
       setup();
       replace_program(ROOM);
}
