//LUCAS 2000-6-18
// dadian.c
inherit ROOM;

string look_duilian();
#include <ansi.h>;

void create()
{
        set("short", "������");
        set("long", 
"������������ǵĸ���֮��--�����������������������
�δ��£����Ŷ����ڴ��ټ����ˣ�����ʩ�������ǽ�ϣ�����
һ�����˵�Ф���ǵ��������Ǵ�����ʦ���������������Ͽ�
��һ������(duilian)���Աߵı������Ϸ����˺��������ĳ�����
�ö����һ����,�����ĸ����֡�"HIB"

                       ÷ѩ����
\n"NOR
 );
        set("outdoors", "lingxiao");
        set("item_desc",([
                "duilian"         :       (: look_duilian :),
        ]));
        set("exits", ([
                "east"  : __DIR__"fudian2",
                "west"  : __DIR__"fudian1",
                "north"  : __DIR__"qianyuan",
                "out"  : __DIR__"meiroad1",
        ]));
set("valid_startroom", "1");
        set("objects", ([
                __DIR__"npc/lu" : 1,
                __DIR__"npc/dizi" : 3,
                "quest/menpai/lingxiao/shi" : 1,
                "d/biwu/champion_lx" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        "/clone/board/lingxiao_b"->foo();
} 

string look_duilian()
{
        return
        "\n"
        "    ����������������������������������\n"
        "    ������������������������  ��������\n"
        "    ������������          ÷����������\n"
        "    ������������          ������������\n"
        "    ������������          �㡡��������\n"
        "    ������������          �ԡ���������\n"
        "    ����������ĥ          �ࡡ��������\n"
        "    ������������          ������������\n"
        "    ������������          ������������\n"
        "    ����������������������������������\n"
        "    ����������������������������������\n";
}
