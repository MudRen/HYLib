// Room: /d/changcheng/FengHuoTai1-1
// Date: inca 98/08/30

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",HIY "���̨");
        set("long", WHT@LONG
�����Ƿ��̨���ڲ������ﲻ�Ǻ���������������ķ���һЩ�����
��ǽ�ı������ϵı���ȴ���������������ɼ���Ȼ����ܼ�࣬����ʿ��ȴ
û�������Լ������Ρ�
LONG
 NOR       );


        set("exits", ([
                "up"        :__DIR__"FengHuoTai1-2",
                "southdown" :__DIR__"changcheng7",
                "westdown"  :__DIR__"changcheng8",
        ]));

        setup();

}


