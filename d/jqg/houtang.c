//houtang.c ����
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIW"����"NOR);
            set("long",@LONG
���Ǻ��ã������������ЪϢ���Ϸ�һ��������ס�����ߣ��ƹ��������
һ���ܵ�ֱͨ�����ˡ�������һ�����ȣ�ֱͨ����԰��
LONG
    );
          
            set("exits",([
                "north": __DIR__"lang1",
                "south": __DIR__"dating",
            ]));

            set("objects",([
                 __DIR__"npc/xiaotong":1,
            ]));                    
            
            set("no_fight", 1);
            setup();
            replace_program(ROOM);
}
