 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ԭ");
        set("long", @LONG
������ԭ�����������š���ɽ����������һƬ�����������ɫƽ���ߣ���ã�
����Ȼ��������˵صȴ������˸ߴ���ǰ������������ƴ��Ĳ�ԭ��Զ����ѩ�嵹
ӳ����������£�������һ���Ÿߴ�İ����������ڱ��ư�Ȼ������������ʮ�
LONG
        );
        set("long_night",@LONG
��ԭ��ҹ�Ǽ�į�ģ���Զ����ĸ߿գ������������ǵ㣬�����棬ҹ���˵ĵ�
��ҡҡ�ڰڣ������ӵ��еĹ�����裬�ڵ�·���ԣ�ȫ�Ǻڳ����ĺ�ɼ���֣���ǰ
�棬�ޱߵĲ�ԭ�ڷ���ɪɪ���죬�����Ƶ����������·����ë���Ȼ��
LONG
        );
        	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,
	])); 
        set("exits", ([ 
                "east" : __DIR__"wild3",
                "west" : __DIR__"wild5",
 //��������
                "south" : __DIR__"woods1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbian");
        set("coor/x",-1060);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        
}  
