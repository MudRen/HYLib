// Room: /d/wizhome/incahome/juyguan.c
// Date: inca 98/08/13

#include <ansi.h>

inherit ROOM;
string look_gaoshi();

void create()
{

        set("short","��ӹ��");
        set("long", WHT@LONG
������ǳ������������۹�==��ӹ�ء�����羰��������ɽ��Ұ�ķ�����
һ���������еķ�Ҷ������˺�ɫ������������һƬ��ɫ�ĺ��󡣵��꣬
�����ʵ۵���������ʱ�����������ľ�ɫ�������ױ������ˡ���ӹ���䡱��
�����֡�
���ڴ�������ͨ����⣬��������ȥ�������Ӿ����ӳ������ﷸ
���Ǵ������ӳ�ȥ�����Գ�ǽ�������˹ٸ��ĸ�ʾ(gaoshi),�������Ĺٱ�
Ҳ�䱸ɭ�ϣ���ʱ�����ſ��ɵ��ˡ�
LONG
NOR        );

        set("outdoors", "changcheng");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "west"           :__DIR__"changcheng1.c",
          "east"           :__DIR__"badaling.c",
          "north" : "/d/menggu/huanglu1",
          // "north"          :__DIR__"guanwai.c",
                "south"          :__DIR__"nroad2.c",
        ]));

        set("objects", ([
            "d/city/npc/wujiang" : 1,
            "d/city/npc/bing" : 5,
	]));
        setup();

}


string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n         �ڳ��й�\n          ��  ��\n";
}

