 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ԭ");
        set("long", @LONG
ԶԶ�����������ߵ�����ķ��ݣ�ǰ����һ�������ı߳ǣ����ס���к��ˣ�
Ҳ�в��ˡ�ż����ƥ����۹�������ǰ�����������߽�����ɫ�Ҵң��糾���ͣ���
��Ĺ����ң��Լ���Я�ű��У��ܹİ��������ת˲���š�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"wild6",
        ]));
	set("objects", ([
"quest/skills2/wunon/dalie/dalie" : 2,

	])); 
        set("outdoors", "zangbei");
        set("coor/x",-1090);
        set("coor/y",170);
        set("coor/z",0);
        setup();
} 
