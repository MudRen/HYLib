// Room: /d/changcheng/FengHuoTai2-1
// Date: inca 98/08/30

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",HIY "���̨");
        set("long", WHT @LONG
�����Ƿ��̨���ڲ������ﲻ�Ǻ���������������ķ���һЩ�����
��ǽ�ı������ϵı���ȴ���������������ɼ���Ȼ����ܼ�࣬����ʿ��ȴ
û�������Լ������Ρ�
LONG
 NOR       );

        set("exits", ([
                "up"       :__DIR__"FengHuoTai2-2",
                "east"     :__DIR__"changcheng13",
                "northwest":__DIR__"changcheng14",
        ]));

        setup();

}

