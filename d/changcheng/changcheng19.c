// Room: /d/wizhome/incahome/changcheng19.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT @LONG
�㳪�ţ����ţ���Ȼӭ�����һ���磬��������ͷ�������������
ɳ�ӡ���ļ�æ�������죬����һ��ȫû�ˡ��㿴��һ����Χ��ֻ������
�Ѿ����ٿ���ֲ������ǻ�ɳ��ʹ�˸е�һƬ������
LONG
 NOR       );

        set("outdoors", "changcheng");

        set("exits", ([
                "southwest" :__DIR__"changcheng20.c",
                "northeast"   :__DIR__"changcheng18.c",
        ]));

        setup();
        replace_program(ROOM);
}
